// email: dvirbto@gmail.com

#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include <iostream>
using namespace std;

/**
 * This class represents a squared matrix represented as an array and it's size
 * The below operators are implemented in the cpp file
 */

namespace Mat
{
    class SquareMat
    {
        private:
            double** squareMatrix;
            int size;

        public:
            SquareMat(int n);
            SquareMat(const SquareMat& copy);
            ~SquareMat();
            double** getMatrix() const;
            int getSize() const;
            void checkValidation(const SquareMat& mat) const;

            // Operators
            SquareMat operator+(const SquareMat& mat) const; // this + mat
            SquareMat operator-(const SquareMat& mat) const; // this + mat
            SquareMat operator-() const;// Unary
            SquareMat operator*(const SquareMat& mat) const; // mat1 * mat2
            SquareMat operator*(double number) const; // matrix * scalar
            friend SquareMat operator*(double number, SquareMat& mat); // scalar * matrix, friend for non-member (2 elements)
            SquareMat operator%(const SquareMat& mat) const; // % each variable
            SquareMat operator%(double number) const; // module
            SquareMat operator/(double number) const; // divide
            SquareMat operator^(int power) const; // power
            SquareMat& operator++(); // pre ++
            SquareMat& operator--(); // pre --
            SquareMat operator++(int) const; // post ++
            SquareMat operator--(int) const; // post --
            SquareMat operator~() const;
            const double* operator[](int i) const; // read only
            double* operator[](int i); // gain access to modify
            bool operator==(const SquareMat& mat) const;
            bool operator!=(const SquareMat& mat) const;
            bool operator<(const SquareMat& mat) const;
            bool operator>(const SquareMat& mat) const;
            bool operator<=(const SquareMat& mat) const;
            bool operator>=(const SquareMat& mat) const;
            double operator!() const;
            SquareMat& operator=(const SquareMat& mat);
            SquareMat& operator+=(const SquareMat& mat);
            SquareMat& operator-=(const SquareMat& mat);
            SquareMat& operator*=(const SquareMat& mat);
            SquareMat& operator*=(double number);
            SquareMat& operator/=(double number);
            SquareMat& operator%=(const SquareMat& mat);
            SquareMat& operator%=(double number);
            friend ostream& operator<<(ostream& output, const SquareMat& mat); // non member, ostream for outputs
    };
}

#endif //SQUAREMAT_H
