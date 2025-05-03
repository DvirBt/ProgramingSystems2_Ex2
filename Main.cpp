// email: dvirbto@gmail.com

#include <iostream>
#include <stdexcept>
#include "SquareMat.hpp"

using namespace std;
using namespace Mat;

/**
 * This class represents the main of the project
 */

void print_result(bool result)
{
    if (result)
        cout << "true" << endl;
    
    else
        cout << "false" << endl;
}

int main()
{
    SquareMat mat1(3);
    SquareMat mat2(3);
    SquareMat mat3(4);
    SquareMat transpose(3);
    SquareMat equalToMat1(2);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat1[i][j] = i + j;
            mat2[i][j] = j + i + 10;
            transpose[i][j] = i;
        }
    }

    for (int i = 0 ; i < 4; i++)
        for (int j = 0; j < 4; j++)
            mat3[i][j] = -1;

    equalToMat1[0][0] = 3;
    equalToMat1[0][1] = 7;
    equalToMat1[1][0] = 11;
    equalToMat1[1][1] = -3;

    cout << endl << "The given matrices are:" << endl;
    cout << "-----------------------" << endl << endl;
    cout << "Matrix 1:" << endl;
    cout << "---------" << endl;
    cout << mat1 << endl;

    cout << "Matrix 2:" << endl;
    cout << "---------" << endl;
    cout << mat2 << endl;

    cout << "Matrix 3:" << endl;
    cout << "---------" << endl;
    cout << mat3 << endl;

    cout << "Transpose:" << endl;
    cout << "----------" << endl;
    cout << transpose << endl;

    cout << "Equal to matrix 1:" << endl;
    cout << "------------------" << endl;
    cout << equalToMat1 << endl;

    // show operators functionality
    cout << "---------" << endl;
    cout << "Operators" << endl;
    cout << "---------" << endl;

    SquareMat temp = mat1 + mat2;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '+': mat1 + mat2" << endl;
    cout << "-------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = mat2 - mat1;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '-': mat2 - mat1" << endl;
    cout << "-------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = -mat3;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '-'(unary): mat3" << endl;
    cout << "-------------------------" << endl;
    cout << mat3 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = mat1 * mat2;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '*': mat1 * mat2" << endl;
    cout << "-------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = mat1 * 5;
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "operator '*': mat1 * scalar (=5)" << endl;
    cout << "--------------------------------" << endl;
    cout << mat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = 2 * mat2;
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "operator '*': scalar (=2) * mat2" << endl;
    cout << "--------------------------------" << endl;
    cout << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = mat1 % mat2;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '%': mat1 % mat2" << endl;
    cout << "-------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = mat1 % 2;
    cout << endl;
    cout << "----------------------" << endl;
    cout << "operator '%': mat1 % 2" << endl;
    cout << "----------------------" << endl;
    cout << mat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = mat2 / 4;
    cout << endl;
    cout << "----------------------" << endl;
    cout << "operator '/': mat1 / 4" << endl;
    cout << "----------------------" << endl;
    cout << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    temp = mat1 ^ 3;
    cout << endl;
    cout << "----------------------" << endl;
    cout << "operator '^': mat1 ^ 3" << endl;
    cout << "----------------------" << endl;
    cout << mat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << temp << endl;

    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "operator '++'(postfix): transpose++" << endl;
    cout << "-----------------------------------" << endl;
    cout << transpose << endl;
    temp = transpose++;
    cout << "Postfix:" << endl; 
    cout << "-------" << endl << temp << endl;
    cout << "Actual" << endl;
    cout << "------" << endl << transpose << endl;

    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "operator '++'(prefix): ++transpose" << endl;
    cout << "----------------------------------" << endl;
    cout << transpose << endl;
    temp = ++transpose;
    cout << "Prefix:" << endl; 
    cout << "-------" << endl << temp << endl;
    cout << "Actual" << endl;
    cout << "------" << endl << transpose << endl;

    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "operator '--'(postfix): transpose--" << endl;
    cout << "-----------------------------------" << endl;
    cout << transpose << endl;
    temp = transpose--;
    cout << "Postfix:" << endl; 
    cout << "-------" << endl << temp << endl;
    cout << "Actual" << endl;
    cout << "------" << endl << transpose << endl;

    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "operator '--'(prefix): --transpose" << endl;
    cout << "----------------------------------" << endl;
    cout << transpose << endl;
    temp = --transpose;
    cout << "Prefix:" << endl; 
    cout << "-------" << endl << temp << endl;
    cout << "Actual" << endl;
    cout << "------" << endl << transpose << endl;

    bool result = mat1 == mat2;
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '==': mat1 == mat2" << endl;
    cout << "---------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl; 
    print_result(result);

    result = mat1 == equalToMat1;
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "operator '==': mat1 == equalToMat1" << endl;
    cout << "----------------------------------" << endl;
    cout << mat1 << endl << equalToMat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 != mat2;
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '!=': mat1 != mat2" << endl;
    cout << "---------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 != equalToMat1;
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "operator '!=': mat1 != equalToMat1" << endl;
    cout << "----------------------------------" << endl;
    cout << mat1 << endl << equalToMat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 < mat2;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '<': mat1 < mat2" << endl;
    cout << "-------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 < equalToMat1;
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "operator '<': mat1 < equalToMat1" << endl;
    cout << "--------------------------------" << endl;
    cout << mat1 << endl << equalToMat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 > mat2;
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '>': mat1 > mat2" << endl;
    cout << "-------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 > equalToMat1;
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "operator '>': mat1 > equalToMat1" << endl;
    cout << "--------------------------------" << endl;
    cout << mat1 << endl << equalToMat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 <= mat2;
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '<=': mat1 <= mat2" << endl;
    cout << "---------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 <= equalToMat1;
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "operator '<=': mat1 <= equalToMat1" << endl;
    cout << "----------------------------------" << endl;
    cout << mat1 << endl << equalToMat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 >= mat2;
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '>=': mat1 >= mat2" << endl;
    cout << "---------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    result = mat1 >= equalToMat1;
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "operator '>=': mat1 >= equalToMat1" << endl;
    cout << "----------------------------------" << endl;
    cout << mat1 << endl << equalToMat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl;
    print_result(result);

    cout << endl;
    cout << "-------------------" << endl;
    cout << "operator '!': !mat1" << endl;
    cout << "-------------------" << endl;
    cout << mat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << !mat1 << endl;

    cout << endl;
    cout << "--------------------------" << endl;
    cout << "operator '!': !equalToMat1" << endl;
    cout << "--------------------------" << endl;
    cout << equalToMat1 << endl;
    cout << "Result:" << endl; 
    cout << "-------" << endl << !equalToMat1 << endl;

    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '+=': mat1 += mat2" << endl;
    cout << "---------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    mat1 += mat2;
    cout << "Result:" << endl; 
    cout << "-------" << endl << mat1 << endl;

    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '-=': mat1 -= mat2" << endl;
    cout << "---------------------------" << endl;
    cout << mat1 << endl << mat2 << endl;
    mat1 -= mat2;
    cout << "Result:" << endl; 
    cout << "-------" << endl << mat1 << endl;

    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '*=': mat2 *= mat1" << endl;
    cout << "---------------------------" << endl;
    cout << mat2 << endl << mat1 << endl;
    mat2 *= mat1;
    cout << "Result:" << endl; 
    cout << "-------" << endl << mat2 << endl;

    cout << endl;
    cout << "-------------------------" << endl;
    cout << "operator '/=': mat1 /= 2" << endl;
    cout << "-------------------------" << endl;
    cout << mat1 << endl;
    mat1 /= 2;
    cout << "Result:" << endl; 
    cout << "-------" << endl << mat1 << endl;

    cout << endl;
    cout << "------------------------" << endl;
    cout << "operator '*=': mat1 *= 2" << endl;
    cout << "------------------------" << endl;
    cout << mat1 << endl;
    mat1 *= 2;
    cout << "Result:" << endl; 
    cout << "-------" << endl << mat1 << endl;

    cout << endl;
    cout << "---------------------------" << endl;
    cout << "operator '%=': mat2 %= mat1" << endl;
    cout << "---------------------------" << endl;
    cout << mat2 << endl << mat1 << endl;
    mat2 %= mat1;
    cout << "Result:" << endl; 
    cout << "-------" << endl << mat2 << endl;

    cout << endl;
    cout << "------------------------" << endl;
    cout << "operator '%=': mat1 %= 2" << endl;
    cout << "------------------------" << endl;
    cout << mat1 << endl;
    mat1 %= 2;
    cout << "Result:" << endl; 
    cout << "-------" << endl << mat1 << endl;

    return 0;
}