// email: dvirbto@gmail.com

#include "SquareMat.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace Mat;
using namespace std;

/**
 * This class represents the cpp file of the squared matrix
 * All it's required operators are implemented in this file
 */

namespace Mat
{
    /**
     * The constructor of SquareMat
     * Initializes the size of the matrix to the given input and all it's variables to 0
     * @param n - the size (rows and columns) of the matrix
     * @throws logic_error - if the given size of the matrix is not positive
     */
    SquareMat::SquareMat(int n) : size(n) {

        if (size <= 0)
            throw logic_error{"The number of the rows and columns must be positive!"};

        squareMatrix = new double*[n];
        for (int i = 0; i < n; i++) {
            squareMatrix[i] = new double[n];
            for (int j = 0; j < n; j++)
                squareMatrix[i][j] = 0;
        }
    }

    /**
     * Deep copy constructor
     * @param copy - the matrix that should be copied
     * @throws logic_error - if the given size of the matrix is not positive
     */
    SquareMat::SquareMat(const SquareMat& copy) : size(copy.getSize()) {

        if (size <= 0)
            throw logic_error{"The number of the rows and columns must be positive!"};

        squareMatrix = new double*[size];
        for (int i = 0; i < size; i++) {
            squareMatrix[i] = new double[size];
            for (int j = 0; j < size; j++)
                squareMatrix[i][j] = copy[i][j];
        }
    }

    /**
     * Deconstructor of the SquareMat
     * Deletes all the allocated memory
     */
    SquareMat::~SquareMat() {
        
        for (int i = 0; i < size; i++) {
            delete[] squareMatrix[i];
        }
        delete[] squareMatrix;
    }

    // Geters 

    int SquareMat::getSize() const {
        return size;
    }

    double** SquareMat::getMatrix() const {
        return squareMatrix;
    }

    /**
     * This function gets a matrix and checks if the size of the rows and columns are equal to this matrix's size
     * @param mat - the given matrix
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
    void SquareMat::checkValidation(const SquareMat& mat) const {
        if (size != mat.getSize())
            throw length_error{"The matrices are not in the same size!"};
    }

    // Operators

    /**
     * Overloading '+' operator which adds a given matrix to this matrix
     * @param mat - the given matrix
     * @return a matrix by value after the addition
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
     SquareMat SquareMat::operator+(const SquareMat& mat) const {

        checkValidation(mat);

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMat[i][j] = squareMatrix[i][j] + mat[i][j];
            }
        }

        return returnMat;
    }

    /**
     * Overloading '-' operator which substracts a given matrix to this matrix
     * @param mat - the given matrix
     * @return a matrix by value after the substraction
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
    SquareMat SquareMat::operator-(const SquareMat& mat) const{

        checkValidation(mat);

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMat[i][j] = squareMatrix[i][j] - mat[i][j];
            }
        }

        return returnMat;
    }

    /**
     * Overloading '-' operator which changes all the signs of the variables to the opposite ones
     * @param mat - the given matrix
     * @return a matrix by value after the change
     */
    SquareMat SquareMat::operator-() const {

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMat[i][j] = (-1)*squareMatrix[i][j];
            }
        }

        return returnMat;
    }

    /**
     * Overloading '*' operator which multiply a given matrix with this matrix
     * @param mat - the given matrix
     * @return a matrix by value after the multiplication
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
    SquareMat SquareMat::operator*(const SquareMat& mat) const {

        checkValidation(mat);

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                double sum = 0;
                for (int k = 0; k < size; k++) {
                    sum += squareMatrix[i][k] * mat[k][j]; // sigma k=1 until k=n => Cij = Aik*Bkj
                }
                returnMat[i][j] = sum;
            }
        }

        return returnMat;
    }

    /**
     * Overloading '*' operator which multiplies all the variables in the matrix with a given number
     * @param number - the given number
     * @return a matrix by value after the multiplication
     */
    SquareMat SquareMat::operator*(double number) const {

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMat[i][j] = squareMatrix[i][j] * number;
            }
        }

        return returnMat;
    }

    /**
     * The same overloading '*' operator but in different positions
     */
    SquareMat operator*(double number, SquareMat& mat) {

        return mat * number;
    }

    /**
     * Overloading '%' operator which multiplies each variable in this matrix and in the given matrix by their position
     * @param mat - the given matrix
     * @return a matrix by value after the multiplication
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
    SquareMat SquareMat::operator%(const SquareMat& mat) const {

        checkValidation(mat);

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMat[i][j] = squareMatrix[i][j] * mat[i][j];
            }
        }

        return returnMat;
    }

    /**
     * Overloading '%' operator which checks the remainder of each variable with a given number
     * This function uses fmod to calculate the remainder
     * @param number - the given number
     * @return a matrix by value after the modulo
     * @throws logic_error - if the number is negative
     */
    SquareMat SquareMat::operator%(double number) const {

        if (number <= 0)
            throw logic_error{"The number must be positive!"};

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMat[i][j] = fmod(squareMatrix[i][j], number);
            }
        }

        return returnMat;
    }

    /**
     * Overloading '/' operator which divides each variable with a given number
     * @param number - the given number
     * @return a matrix by value after the division
     * @throws logic_error - if the number is 0 the division in not defined nor allowed
     */
    SquareMat SquareMat::operator/(double number) const {

        if (number == 0)
            throw logic_error{"Division by 0 is not allowed!"};

        SquareMat returnMat(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMat[i][j] = squareMatrix[i][j] / number;
            }
        }

        return returnMat;
    }

    /**
     * Overloading '^' operator which powers the matrix by a given number
     * @param number - the given number
     * @return a matrix by value after the power
     * @throws logic_error - if the number is below 0
     */
    SquareMat SquareMat::operator^(int power) const {

        if (power < 0)
            throw logic_error{"The power can not be negative!"};

        // deep copy
        SquareMat returnMat = *this; 
        SquareMat temp = *this;

        // if the power is 0 - a diagonal matrix with '1' accross all the diagonal variables
        if (power == 0) {

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == j)
                        returnMat[i][j] = 1;
                    else
                        returnMat[i][j] = 0;
                }
            }
        }

        else {

            // the first multiplication counts as two multiplications thefore -> power-1
            for (int i = 0; i < power-1; i++) {
                returnMat = returnMat * temp;
            }
        }

        return returnMat;
    }

    /**
     * Overloading '++' operator which adds 1 to all the variables in the matrix
     * This is the prefix method
     * @return a pointer (reference) to this object
     */
    SquareMat& SquareMat::operator++() { // pre

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                squareMatrix[i][j] += 1;
        }

        return *this; // the reference to this object
    }

    /**
     * Overloading '--' operator which substracts 1 from all the variables in the matrix
     * This is the prefix method
     * @return a pointer (reference) to this object
     */
    SquareMat& SquareMat::operator--() { // pre

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                squareMatrix[i][j] -= 1;
        }

        return *this; // the reference to this object
    }

    /**
     * Overloading '++' operator which adds 1 to all the variables in the matrix
     * This is the postfix method - uses dummy flag to differ the function signitures from one to another
     * @return a pointer (reference) to this object before the addition
     */
    SquareMat SquareMat::operator++(int) const { // post

        SquareMat temp = *this; // create the reference
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                squareMatrix[i][j] += 1;
        }

        return temp; // the reference to this object before the change
    }

    /**
     * Overloading '--' operator which substracts 1 from all the variables in the matrix
     * This is the postfix method - uses dummy flag to differ the function signitures from one to another
     * @return a pointer (reference) to this object before the substraction
     */
    SquareMat SquareMat::operator--(int) const { // post

        SquareMat temp = *this; // create the reference
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                squareMatrix[i][j] -= 1;
        }

        return temp; // the reference to this object before the change
    }

    /**
     * Overloading '[]' operator which grants access to the matrix in a given index
     * This method is a read-only method - using const!
     * @param i - the given index
     * @return a pointer to the array in the given index
     * @throws length_error - if the index is negative or equals-above the size of the matrix
     */
    const double* SquareMat::operator[](int i) const {

        if (i >= size) // this->getSize()
            throw length_error{"The given input is greater than the size of the matrix!"};

        if (i < 0)
            throw length_error{"The given input can not be negative!"};

        return squareMatrix[i];
    }

    /**
     * Overloading '[]' operator which grants access to the matrix in a given index
     * This method permits changes - not using const!
     * @param i - the given index
     * @return a pointer to the array in the given index
     * @throws length_error - if the index is negative or equals-above the size of the matrix
     */
    double* SquareMat::operator[](int i) {

        if (i >= size) // this->getSize()
            throw length_error{"The given input is greater than the size of the matrix!"};

        if (i < 0)
            throw length_error{"The given input can not be negative!"};

        return squareMatrix[i];
    }

    /**
     * Overloading '~' operator which changes a row to be a column
     * @return a matrix by value after the position change
     */
    SquareMat SquareMat::operator~() const {

        SquareMat returnMatrix(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                returnMatrix[j][i] = squareMatrix[i][j]; // store variable (i,j) as variable (j,i)
            }
        }

        return returnMatrix;
    }

    /**
     * Overloading '==' operator which checks if this matrix and a given one are equal
     * Two matrices are equal if their sum are equal
     * @param mat - the given matrix
     * @return true if the matrices are equal. Otherwise, returns false
     */
    bool SquareMat::operator==(const SquareMat& mat) const {

        // sum matrix 1
        double sum1 = 0;
        for (int i = 0; i < size; i++) {
            for (int j =0; j < size; j++) {
                sum1 += squareMatrix[i][j];
            }
        }

        // sum matrix 2
        double sum2 = 0;
        for (int i = 0; i < mat.getSize(); i++) {
            for (int j = 0; j < mat.getSize(); j++) {
                sum2 += mat[i][j];
            }
        }

        return sum1 == sum2; // return true if they are equal and false - if not
    }

    /**
     * Overloading '!=' operator which checks if this matrix and a given one are not equal
     * Two matrices are not equal if their sum are not equal
     * @param mat - a given matrix
     * @return true if the matrices are not equal. Otherwise, returns true
     */
    bool SquareMat::operator!=(const SquareMat& mat) const {

        return !(*this == mat); // check if the matrices are equal and perfrom NOT operand on the result
    }

    /**
     * Overloading '<' operator which checks if a *given* matrix is grater than this matrix
     * A matrix is grater than other if it's sum is grater then the other's sum
     * @param mat - a given matrix
     * @return true if the given matrix is grater. Otherwise, returns false
     */
    bool SquareMat::operator<(const SquareMat& mat) const {

        // if the matrices are equal - this matrix is not grater than the given one
        if (squareMatrix == mat.getMatrix())
            return false;

        // sum this matrix
        double sum1 = 0;
        for (int i = 0; i < size; i++) {
            for (int j =0; j < size; j++) {
                sum1 += squareMatrix[i][j];
            }
        }

        // sum matrix 2
        double sum2 = 0;
        for (int i = 0; i < mat.getSize(); i++) {
            for (int j = 0; j < mat.getSize(); j++) {
                sum2 += mat[i][j];
            }
        }

        // if the other matrix is grater -> return true
        if (sum1 < sum2)
            return true;

        return false; // else -> return false
    }

    /**
     * Overloading '>' operator which checks if *this* matrix is grater than a give one
     * A matrix is grater than other if it's sum is grater then the other's sum
     * @param mat - a given matrix
     * @return true if this matrix is grater. Otherwise, returns false
     */
    bool SquareMat::operator>(const SquareMat& mat) const {

        return mat < *this; // using the previous operator but changed the positions
    }

    /**
     * Overloading '<=' operator which checks if *this* matrix is grater or equals to a give one
     * A matrix is grater or equal to other matrix if it's sum is grater or equals to the other's sum
     * @param mat - a given matrix
     * @return true if the given matrix is grater or equals. Otherwise, returns false
     */
    bool SquareMat::operator<=(const SquareMat& mat) const {

        // using the previous overloaded operators
        if (*this < mat || *this == mat)
            return  true;

        return false;
    }

    /**
     * Overloading '>=' operator which checks if *this* matrix is grater or equals to a given one
     * A matrix is grater or equal to other matrix if it's sum is grater or equals to the other's sum
     * @param mat - a given matrix
     * @return true if the this matrix is grater or equals. Otherwise, returns false
     */
    bool SquareMat::operator>=(const SquareMat& mat) const {

        // using the previous overloaded operators
        // valid by changing positions
        return mat <= *this;
    }

    /**
     * This function gets a matrix and an index of a column and returns the minor of the given matrix
     * @param mat - the given matrix 
     * @param col - the index of the column
     * @returns a matrix which represents the minor
     */
    SquareMat getDeterminantMat(const SquareMat& mat, int col) {

        SquareMat temp(mat.getSize()-1); // create a new matrix as the size of the given one minus one - minor matrix
        for (int i = 0; i < temp.getSize(); i++) { // the first row is not calcualted -> i+1**
            int colIndex = 0; // init current column index
            for (int j = 0; j < mat.getSize(); j++) {
                if (j == col) // don't count the column of the minor
                    continue;

                temp[i][colIndex] = mat[i+1][j]; // i+1**
                colIndex++; // increment by 1
            }
        }

        return temp; // return the minor matrix
    }

    /**
     * This function gets a matrix and returns it's determinant by recursion
     * @param mat - the given matrix
     * @returns the determinant of the given matrix
     */
    double calculateDeterminant(const SquareMat& mat) {

        // stop if the size is 2
        if (mat.getSize() == 2)
            return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

        int size = mat.getSize();
        double sum = 0; // to calculate the determinant
        // the deteminant will be performed on the first row
        for (int col = 0; col < size; col++) {
            SquareMat relevantMat = getDeterminantMat(mat, col); // get the minor matrix
            if (col%2 == 0) // if the number is even -> +
                sum += mat[0][col] * calculateDeterminant(relevantMat); // recursive call to calcualte the determinant of the minor
            else // if the number is odd -> -
                sum -= mat[0][col] * calculateDeterminant(relevantMat); // same recursize call
        }

        return sum; // return the determinant
    }

    /**
     * Overloading '!' operator which calculates the determinant of this matrix
     * @return the determinant of this matrix
     */
    double SquareMat::operator!() const {

        // size=1 -> the determinant is the variable
        if (size == 1)
            return squareMatrix[0][0];

        return calculateDeterminant(*this);
    }

    /**
     * Overloading '=' operator which copies a given SquareMat object to this object
     * We don't have a garbage collector so we need to delete the memory of the current this object
     * and only than initialize all the new data
     * @param mat - a given matrix
     * @return pointer to the "new" this object
     */
    SquareMat& SquareMat::operator=(const SquareMat& mat) {

        // check if they are the same address in the memory (same objects)
        // can't use this* == mat because of the operator that we overloaded...
        if (this == &mat)
            return *this;

        // free the memory first
        for (int i = 0; i < size; i++) {
            delete[] squareMatrix[i];
        }
        delete[] squareMatrix;

        // set the new data
        size = mat.getSize();
        // new memory allocation
        squareMatrix = new double*[size];
        for (int i = 0; i < size; i++) {
            squareMatrix[i] = new double[size];
            for (int j = 0; j < size; j++) {
                squareMatrix[i][j] = mat[i][j];
            }
        }

        return *this; // return a pointer to the object
    }

    /**
     * Overloading '+=' operator which adds to this matrix the other variables in the given matrix
     * and stores the result in this object
     * @param mat - a given matrix
     * @return a pointer to this "new" object after the addition
     * @throws logic_error - if the given size of the matrix is not positive
     */
    SquareMat& SquareMat::operator+=(const SquareMat& mat) {

        // check validation
        checkValidation(mat);

        // using the previous operators
        *this = *this + mat;
        return *this;
    }

    /**
     * Overloading '-=' operator which substracts from this matrix a given one
     * and stores the result in this object
     * @param mat - a given matrix
     * @return a pointer (reference) to this "new" object after the substraction
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
    SquareMat& SquareMat::operator-=(const SquareMat& mat) {

        checkValidation(mat);

        *this = *this - mat;
        return *this;
    }

    /**
     * Overloading '/=' operator which divides all this matrix variables by a given number
     * and stores the result in this object
     * @param number - a given number
     * @return a pointer (reference) to this "new" object after the division
     * @throws logic_error - if the number is 0
     */
    SquareMat& SquareMat::operator/=(double number) {

        *this = *this / number; // the throw will happen here
        return *this;
    }

    /**
     * Overloading '/=' operator which multiplies all this matrix variables by a given number
     * and stores the result in this object
     * @param number - a given number
     * @return a pointer (reference) to this "new" object after the multiplication
     */
    SquareMat& SquareMat::operator*=(double number) {

        *this = *this * number;
        return *this;
    }

    /**
     * Overloading '*=' operator which multiplies this matrix variable with the matching position variable in a given matrix
     * and stores the result in this object
     * @param mat - a given matrix
     * @return a pointer (reference) to this "new" object after the multiplication
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
    SquareMat& SquareMat::operator*=(const SquareMat &mat) {

        checkValidation(mat);

        *this = *this * mat;
        return *this;
    }

    /**
     * Overloading '%=' operator which calculates the remainder of each variable in this matrix variable with a given number
     * and stores the result in this object
     * @param number - the given number
     * @return a pointer (reference) to this "new" object after the calcualtion of all the remainders
     * @throws logic_error - if the number is negative
     */
    SquareMat &SquareMat::operator%=(double number) {

        *this = *this % number;
        return *this;
    }

    /**
     * Overloading '%=' operator which multiplies each variable in this matrix with the matching position variable of a given matrix
     * and stores the result in this object
     * @param mat - the given matrix
     * @return a pointer (reference) to this "new" object after the multiplication 
     * @throws length_error - if the rows and columns are not equal in both matrices
     */
    SquareMat& SquareMat::operator%=(const SquareMat &mat) {

        checkValidation(mat);

        *this = *this % mat;
        return *this;
    }

    /**
     * Overloading '<<' operator which prints the matrix in a certain way
     * @param output - the output that will be presented
     * @param mat - the given matrix
     * @return a print output of the matrix
     */
    ostream& operator<<(ostream& output, const SquareMat& mat) {

        for (int i = 0; i < mat.size; i++) {
            output << "|";
            for (int j = 0; j < mat.size; j++) {
                output << " " << mat.squareMatrix[i][j];
            }
            output << " |" << endl;
        }
        return output;
    }
}