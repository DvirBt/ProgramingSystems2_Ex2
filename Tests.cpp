// email: dvirbto@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "SquareMat.hpp"
using namespace std;
using namespace Mat;

/**
 * This class contains all the tests for the different operators that were requiered to be implemented
 */

struct checkMatrices {

    SquareMat mat1, mat2, mat3, transpose;
    checkMatrices() : mat1(3), mat2(3), mat3(4), transpose(3) {

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
    }
};

TEST_CASE_FIXTURE(checkMatrices, "checkValidation function") {

    CHECK_NOTHROW(mat1.checkValidation(mat2));
    CHECK_THROWS(mat1.checkValidation(mat3));
    // invalid matrices -> throw
    CHECK_THROWS(SquareMat(0));
    CHECK_THROWS(SquareMat(-2));
}

TEST_CASE_FIXTURE(checkMatrices, "operator '+'") {

    SquareMat result = mat1 + mat2;
    CHECK(result[0][0] == 10);
    CHECK(result[0][1] == 12);
    CHECK(result[0][2] == 14);
    CHECK(result[1][0] == 12);
    CHECK(result[1][1] == 14);
    CHECK(result[1][2] == 16);
    CHECK(result[2][0] == 14);
    CHECK(result[2][1] == 16);
    CHECK(result[2][2] == 18);

    CHECK_THROWS(mat1+mat3); // size does not match -> throw
}

TEST_CASE_FIXTURE(checkMatrices, "operator '-'") {

    SquareMat result = mat2 - mat1;
    CHECK(result[0][0] == 10);
    CHECK(result[0][1] == 10);
    CHECK(result[0][2] == 10);
    CHECK(result[1][0] == 10);
    CHECK(result[1][1] == 10);
    CHECK(result[1][2] == 10);
    CHECK(result[2][0] == 10);
    CHECK(result[2][1] == 10);
    CHECK(result[2][2] == 10);

    CHECK_THROWS(mat1-mat3); // size does not match -> throw
}

TEST_CASE_FIXTURE(checkMatrices, "operator '-' Unary") {

    SquareMat result = -mat1; // oposite signs
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == -1);
    CHECK(result[0][2] == -2);
    CHECK(result[1][0] == -1);
    CHECK(result[1][1] == -2);
    CHECK(result[1][2] == -3);
    CHECK(result[2][0] == -2);
    CHECK(result[2][1] == -3);
    CHECK(result[2][2] == -4);

    result = -mat3;
    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 1);
    CHECK(result[0][2] == 1);
    CHECK(result[1][0] == 1);
    CHECK(result[1][1] == 1);
    CHECK(result[1][2] == 1);
    CHECK(result[2][0] == 1);
    CHECK(result[2][1] == 1);
    CHECK(result[2][2] == 1);
    CHECK(result[3][0] == 1);
    CHECK(result[3][1] == 1);
    CHECK(result[3][2] == 1);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '*' matrices multiplication") {

    SquareMat result = mat1 * mat2;
    CHECK(result[0][0] == 35);
    CHECK(result[0][1] == 38);
    CHECK(result[0][2] == 41);
    CHECK(result[1][0] == 68);
    CHECK(result[1][1] == 74);
    CHECK(result[1][2] == 80);
    CHECK(result[2][0] == 101);
    CHECK(result[2][1] == 110);
    CHECK(result[2][2] == 119);

    CHECK_THROWS(mat1*mat3); // size does not match -> throw
}

TEST_CASE_FIXTURE(checkMatrices, "operator '*' scalar multiplication") {

    // check mat * scalar
    SquareMat result = (mat1 * 0);
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 0);
    CHECK(result[0][2] == 0);
    CHECK(result[1][0] == 0);
    CHECK(result[1][1] == 0);
    CHECK(result[1][2] == 0);
    CHECK(result[2][0] == 0);
    CHECK(result[2][1] == 0);
    CHECK(result[2][2] == 0);

    // check scalar * mat
    result = 0 * mat2;
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 0);
    CHECK(result[0][2] == 0);
    CHECK(result[1][0] == 0);
    CHECK(result[1][1] == 0);
    CHECK(result[1][2] == 0);
    CHECK(result[2][0] == 0);
    CHECK(result[2][1] == 0);
    CHECK(result[2][2] == 0);

    // check scalar != 0
    result = mat3 * (-2);
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 2);
    CHECK(result[0][2] == 2);
    CHECK(result[1][0] == 2);
    CHECK(result[1][1] == 2);
    CHECK(result[1][2] == 2);
    CHECK(result[2][0] == 2);
    CHECK(result[2][1] == 2);
    CHECK(result[2][2] == 2);
    CHECK(result[3][0] == 2);
    CHECK(result[3][1] == 2);
    CHECK(result[3][2] == 2);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '%' multiplication") {

    SquareMat result = mat1 % mat2;
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 11);
    CHECK(result[0][2] == 24);
    CHECK(result[1][0] == 11);
    CHECK(result[1][1] == 24);
    CHECK(result[1][2] == 39);
    CHECK(result[2][0] == 24);
    CHECK(result[2][1] == 39);
    CHECK(result[2][2] == 56);

    CHECK_THROWS(mat1 % mat3); // size does not match -> throw
}

TEST_CASE_FIXTURE(checkMatrices, "operator '%' modulo") {

    SquareMat result = mat2 % 4;
    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 3);
    CHECK(result[0][2] == 0);
    CHECK(result[1][0] == 3);
    CHECK(result[1][1] == 0);
    CHECK(result[1][2] == 1);
    CHECK(result[2][0] == 0);
    CHECK(result[2][1] == 1);
    CHECK(result[2][2] == 2);

    // invalid inputs
    CHECK_THROWS(mat1 % -1);
    CHECK_THROWS(mat1 % 0);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '/'") {

    SquareMat result = (mat1 / 2);
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 0.5);
    CHECK(result[0][2] == 1);
    CHECK(result[1][0] == 0.5);
    CHECK(result[1][1] == 1);
    CHECK(result[1][2] == 1.5);
    CHECK(result[2][0] == 1);
    CHECK(result[2][1] == 1.5);
    CHECK(result[2][2] == 2);

    // invalid inputs
    CHECK_NOTHROW(mat1 / -1);
    CHECK_THROWS(mat1 / 0);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '^'") {

    SquareMat result = mat1 ^ 3;
    CHECK(result[0][0] == 30);
    CHECK(result[0][1] == 54);
    CHECK(result[0][2] == 78);
    CHECK(result[1][0] == 54);
    CHECK(result[1][1] == 96);
    CHECK(result[1][2] == 138);
    CHECK(result[2][0] == 78);
    CHECK(result[2][1] == 138);
    CHECK(result[2][2] == 198);

    result = mat1 ^ 0; // digonal matrix, 1 in the cross
    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 0);
    CHECK(result[0][2] == 0);
    CHECK(result[1][0] == 0);
    CHECK(result[1][1] == 1);
    CHECK(result[1][2] == 0);
    CHECK(result[2][0] == 0);
    CHECK(result[2][1] == 0);
    CHECK(result[2][2] == 1);

    CHECK_THROWS(mat1 ^ -1); // invalid input
}

TEST_CASE_FIXTURE(checkMatrices, "operator ++ - post") {

    SquareMat result = mat3++;
    CHECK(result[0][0] == -1);
    CHECK(result[0][1] == -1);
    CHECK(result[0][2] == -1);
    CHECK(result[1][0] == -1);
    CHECK(result[1][1] == -1);
    CHECK(result[1][2] == -1);
    CHECK(result[2][0] == -1);
    CHECK(result[2][1] == -1);
    CHECK(result[2][2] == -1);
    CHECK(result[3][0] == -1);
    CHECK(result[3][1] == -1);
    CHECK(result[3][2] == -1);

    CHECK(mat3[0][0] == 0);
    CHECK(mat3[0][1] == 0);
    CHECK(mat3[0][2] == 0);
    CHECK(mat3[0][3] == 0);
    CHECK(mat3[1][0] == 0);
    CHECK(mat3[1][1] == 0);
    CHECK(mat3[1][2] == 0);
    CHECK(mat3[1][3] == 0);
    CHECK(mat3[2][0] == 0);
    CHECK(mat3[2][1] == 0);
    CHECK(mat3[2][2] == 0);
    CHECK(mat3[2][3] == 0);
    CHECK(mat3[3][0] == 0);
    CHECK(mat3[3][1] == 0);
    CHECK(mat3[3][2] == 0);
    CHECK(mat3[3][3] == 0);
}

TEST_CASE_FIXTURE(checkMatrices, "operator -- - post") {

    SquareMat result = mat3--;
    CHECK(result[0][0] == -1);
    CHECK(result[0][1] == -1);
    CHECK(result[0][2] == -1);
    CHECK(result[1][0] == -1);
    CHECK(result[1][1] == -1);
    CHECK(result[1][2] == -1);
    CHECK(result[2][0] == -1);
    CHECK(result[2][1] == -1);
    CHECK(result[2][2] == -1);
    CHECK(result[3][0] == -1);
    CHECK(result[3][1] == -1);
    CHECK(result[3][2] == -1);

    CHECK(mat3[0][0] == -2);
    CHECK(mat3[0][1] == -2);
    CHECK(mat3[0][2] == -2);
    CHECK(mat3[0][3] == -2);
    CHECK(mat3[1][0] == -2);
    CHECK(mat3[1][1] == -2);
    CHECK(mat3[1][2] == -2);
    CHECK(mat3[1][3] == -2);
    CHECK(mat3[2][0] == -2);
    CHECK(mat3[2][1] == -2);
    CHECK(mat3[2][2] == -2);
    CHECK(mat3[2][3] == -2);
    CHECK(mat3[3][0] == -2);
    CHECK(mat3[3][1] == -2);
    CHECK(mat3[3][2] == -2);
    CHECK(mat3[3][3] == -2);
}

TEST_CASE_FIXTURE(checkMatrices, "operator ++ - pre") {

    SquareMat result = ++mat3;
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 0);
    CHECK(result[0][2] == 0);
    CHECK(result[1][0] == 0);
    CHECK(result[1][1] == 0);
    CHECK(result[1][2] == 0);
    CHECK(result[2][0] == 0);
    CHECK(result[2][1] == 0);
    CHECK(result[2][2] == 0);
    CHECK(result[3][0] == 0);
    CHECK(result[3][1] == 0);
    CHECK(result[3][2] == 0);

    CHECK(mat3[0][0] == 0);
    CHECK(mat3[0][1] == 0);
    CHECK(mat3[0][2] == 0);
    CHECK(mat3[0][3] == 0);
    CHECK(mat3[1][0] == 0);
    CHECK(mat3[1][1] == 0);
    CHECK(mat3[1][2] == 0);
    CHECK(mat3[1][3] == 0);
    CHECK(mat3[2][0] == 0);
    CHECK(mat3[2][1] == 0);
    CHECK(mat3[2][2] == 0);
    CHECK(mat3[2][3] == 0);
    CHECK(mat3[3][0] == 0);
    CHECK(mat3[3][1] == 0);
    CHECK(mat3[3][2] == 0);
    CHECK(mat3[3][3] == 0);
}

TEST_CASE_FIXTURE(checkMatrices, "operator -- - pre") {

    SquareMat result = --mat3;
    CHECK(result[0][0] == -2);
    CHECK(result[0][1] == -2);
    CHECK(result[0][2] == -2);
    CHECK(result[1][0] == -2);
    CHECK(result[1][1] == -2);
    CHECK(result[1][2] == -2);
    CHECK(result[2][0] == -2);
    CHECK(result[2][1] == -2);
    CHECK(result[2][2] == -2);
    CHECK(result[3][0] == -2);
    CHECK(result[3][1] == -2);
    CHECK(result[3][2] == -2);

    CHECK(mat3[0][0] == -2);
    CHECK(mat3[0][1] == -2);
    CHECK(mat3[0][2] == -2);
    CHECK(mat3[0][3] == -2);
    CHECK(mat3[1][0] == -2);
    CHECK(mat3[1][1] == -2);
    CHECK(mat3[1][2] == -2);
    CHECK(mat3[1][3] == -2);
    CHECK(mat3[2][0] == -2);
    CHECK(mat3[2][1] == -2);
    CHECK(mat3[2][2] == -2);
    CHECK(mat3[2][3] == -2);
    CHECK(mat3[3][0] == -2);
    CHECK(mat3[3][1] == -2);
    CHECK(mat3[3][2] == -2);
    CHECK(mat3[3][3] == -2);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '~'") {

    SquareMat result = ~transpose;
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 1);
    CHECK(result[0][2] == 2);
    CHECK(result[1][0] == 0);
    CHECK(result[1][1] == 1);
    CHECK(result[1][2] == 2);
    CHECK(result[2][0] == 0);
    CHECK(result[2][1] == 1);
    CHECK(result[2][2] == 2);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '[]' - read only") {

    const SquareMat result = mat1;
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 1);
    CHECK(result[0][2] == 2);
    CHECK(result[1][0] == 1);
    CHECK(result[1][1] == 2);
    CHECK(result[1][2] == 3);
    CHECK(result[2][0] == 2);
    CHECK(result[2][1] == 3);
    CHECK(result[2][2] == 4);

    // this will not compile!
    // result[0][0] = 10;
}

TEST_CASE_FIXTURE(checkMatrices, "operator '[]' - allow changes") {

    SquareMat result = mat1;
    CHECK(result[0][0] == 0);
    CHECK(result[0][1] == 1);
    CHECK(result[0][2] == 2);
    CHECK(result[1][0] == 1);
    CHECK(result[1][1] == 2);
    CHECK(result[1][2] == 3);
    CHECK(result[2][0] == 2);
    CHECK(result[2][1] == 3);
    CHECK(result[2][2] == 4);

    // now this will compile!
    result[0][0] = 10;
    CHECK(result[0][0] == 10);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '==' check equal sums of matrices") {

    CHECK_FALSE(mat1 == mat2); // not equal
    CHECK(mat3 == mat3); // same -> equal
    // check with a new matrix not in the same size
    SquareMat temp(4);
    temp[0][0] = 9;
    CHECK(transpose == temp);
    temp[1][1] = -25;
    CHECK_FALSE(transpose == temp);
    CHECK(mat3 == temp);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '!=' check if sums of matrices not equal") {

    CHECK(mat1 != mat2); // not equal -> true
    CHECK_FALSE(mat3 != mat3); // equal -> false
    // check with a new matrix not in the same size
    SquareMat temp(4);
    temp[0][0] = 9;
    CHECK_FALSE(transpose != temp);
    temp[1][1] = -25;
    CHECK(transpose != temp);
    CHECK_FALSE(mat3 != temp);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '<'") {

    // sum of: mat1 = 18, mat2 = 108, mat3 = -16, transpose = 9
    CHECK(mat1 < mat2);
    CHECK_FALSE(mat3 < mat3);
    SquareMat temp(4);
    temp[0][0] = 10;
    // sum of temp = 10
    CHECK(transpose < temp);
    temp[1][1] = -30;
    // sum of temp = -20
    CHECK_FALSE(transpose < temp);
    CHECK(temp < mat3);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '>'") {

    // sum of: mat1 = 18, mat2 = 108, mat3 = -16, transpose = 9
    CHECK_FALSE(mat1 > mat2);
    CHECK_FALSE(mat3 > mat3);
    SquareMat temp(4);
    temp[0][0] = 10;
    // sum of temp = 10
    CHECK_FALSE(transpose > temp);
    temp[1][1] = -30;
    // sum of temp = -20
    CHECK(transpose > temp);
    CHECK_FALSE(temp > mat3);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '<='") {

    // sum of: mat1 = 18, mat2 = 108, mat3 = -16, transpose = 9
    CHECK(mat1 <= mat2);
    CHECK(mat3 <= mat3);
    SquareMat temp(4);
    temp[0][0] = 8;
    // sum of temp = 8
    CHECK_FALSE(transpose <= temp);
    temp[1][2] = 1;
    // sum of temp = 9
    CHECK(transpose <= temp);
    temp[1][1] = 1;
    // sum of temp = 10
    CHECK(transpose <= temp);
    temp[0][2] = -25;
    // sum of temp = -15
    CHECK_FALSE(temp <= mat3);
    temp[0][2] = -26;
    // sum of temp = -16
    CHECK(temp <= mat3);
    temp[0][2] = -27;
    // sum of temp = -17
    CHECK(temp <= mat3);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '>='") {

    // sum of: mat1 = 18, mat2 = 108, mat3 = -16, transpose = 9
    CHECK_FALSE(mat1 >= mat2);
    CHECK(mat3 >= mat3);
    SquareMat temp(4);
    temp[0][0] = 8;
    // sum of temp = 8
    CHECK(transpose >= temp);
    temp[1][2] = 1;
    // sum of temp = 9
    CHECK(transpose >= temp);
    temp[1][1] = 1;
    // sum of temp = 10
    CHECK_FALSE(transpose >= temp);
    temp[0][2] = -25;
    // sum of temp = -15
    CHECK(temp >= mat3);
    temp[0][2] = -26;
    // sum of temp = -16
    CHECK(temp >= mat3);
    temp[0][2] = -27;
    // sum of temp = -17
    CHECK_FALSE(temp >= mat3);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '!'") {

    CHECK(!transpose == 0); // transpose contains a row of 0
    CHECK(!mat1 == 0);
    CHECK(!mat2 == 0);
    CHECK(!mat3 == 0);

    SquareMat temp(3);
    temp[0][0] = 2;
    temp[0][1] = -1;
    temp[0][2] = 5;
    temp[1][0] = 3;
    temp[1][1] = 3;
    temp[1][2] = 4;
    temp[2][0] = 4;
    temp[2][1] = -2;
    temp[2][2] = -8;

    CHECK(!temp == -162);

    // single variable
    SquareMat temp2(1);
    temp2[0][0] = 10;
    CHECK(!temp2 == 10);

    SquareMat temp3(2);
    temp3[0][0] = 2;
    temp3[0][1] = 3;
    temp3[1][0] = 3;
    temp3[1][1] = 4;

    CHECK(!temp3 == -1);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '='") {

    // check if temp has the properties of mat1
    SquareMat temp = mat1;
    CHECK(temp.getSize() == mat1.getSize());
    CHECK(temp[0][0] == 0);
    CHECK(temp[0][1] == 1);
    CHECK(temp[0][2] == 2);
    CHECK(temp[1][0] == 1);
    CHECK(temp[1][1] == 2);
    CHECK(temp[1][2] == 3);
    CHECK(temp[2][0] == 2);
    CHECK(temp[2][1] == 3);
    CHECK(temp[2][2] == 4);

    temp = mat3;
    // check if temp has the properties of mat3
    CHECK_FALSE(temp.getSize() == mat1.getSize());
    CHECK(temp.getSize() == mat3.getSize());
    CHECK(temp[0][0] == -1);
    CHECK(temp[0][1] == -1);
    CHECK(temp[0][2] == -1);
    CHECK(temp[0][3] == -1);
    CHECK(temp[1][0] == -1);
    CHECK(temp[1][1] == -1);
    CHECK(temp[1][2] == -1);
    CHECK(temp[1][3] == -1);
    CHECK(temp[2][0] == -1);
    CHECK(temp[2][1] == -1);
    CHECK(temp[2][2] == -1);
    CHECK(temp[2][3] == -1);
    CHECK(temp[3][0] == -1);
    CHECK(temp[3][1] == -1);
    CHECK(temp[3][2] == -1);
    CHECK(temp[3][3] == -1);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '+='") {

    mat1 += mat2;
    CHECK(mat1[0][0] == 10);
    CHECK(mat1[0][1] == 12);
    CHECK(mat1[0][2] == 14);
    CHECK(mat1[1][0] == 12);
    CHECK(mat1[1][1] == 14);
    CHECK(mat1[1][2] == 16);
    CHECK(mat1[2][0] == 14);
    CHECK(mat1[2][1] == 16);
    CHECK(mat1[2][2] == 18);

    CHECK_THROWS(mat1 += mat3); // sizes are not equal -> throw

    mat3 += mat3;
    CHECK(mat3[0][0] == -2);
    CHECK(mat3[0][1] == -2);
    CHECK(mat3[0][2] == -2);
    CHECK(mat3[0][3] == -2);
    CHECK(mat3[1][0] == -2);
    CHECK(mat3[1][1] == -2);
    CHECK(mat3[1][2] == -2);
    CHECK(mat3[1][3] == -2);
    CHECK(mat3[2][0] == -2);
    CHECK(mat3[2][1] == -2);
    CHECK(mat3[2][2] == -2);
    CHECK(mat3[2][3] == -2);
    CHECK(mat3[3][0] == -2);
    CHECK(mat3[3][1] == -2);
    CHECK(mat3[3][2] == -2);
    CHECK(mat3[3][3] == -2);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '-='") {

    mat1 -= mat2;
    CHECK(mat1[0][0] == -10);
    CHECK(mat1[0][1] == -10);
    CHECK(mat1[0][2] == -10);
    CHECK(mat1[1][0] == -10);
    CHECK(mat1[1][1] == -10);
    CHECK(mat1[1][2] == -10);
    CHECK(mat1[2][0] == -10);
    CHECK(mat1[2][1] == -10);
    CHECK(mat1[2][2] == -10);

    CHECK_THROWS(mat1 -= mat3); // sizes are not equal -> throw

    mat3 -= mat3;
    CHECK(mat3[0][0] == 0);
    CHECK(mat3[0][1] == 0);
    CHECK(mat3[0][2] == 0);
    CHECK(mat3[0][3] == 0);
    CHECK(mat3[1][0] == 0);
    CHECK(mat3[1][1] == 0);
    CHECK(mat3[1][2] == 0);
    CHECK(mat3[1][3] == 0);
    CHECK(mat3[2][0] == 0);
    CHECK(mat3[2][1] == 0);
    CHECK(mat3[2][2] == 0);
    CHECK(mat3[2][3] == 0);
    CHECK(mat3[3][0] == 0);
    CHECK(mat3[3][1] == 0);
    CHECK(mat3[3][2] == 0);
    CHECK(mat3[3][3] == 0);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '/='") {

    transpose /= 2;
    CHECK(transpose[0][0] == 0);
    CHECK(transpose[0][1] == 0);
    CHECK(transpose[0][2] == 0);
    CHECK(transpose[1][0] == 0.5);
    CHECK(transpose[1][1] == 0.5);
    CHECK(transpose[1][2] == 0.5);
    CHECK(transpose[2][0] == 1);
    CHECK(transpose[2][1] == 1);
    CHECK(transpose[2][2] == 1);

    CHECK_THROWS(mat1 /= 0); // invalid input -> throw

    mat3 /= -1;
    CHECK(mat3[0][0] == 1);
    CHECK(mat3[0][1] == 1);
    CHECK(mat3[0][2] == 1);
    CHECK(mat3[0][3] == 1);
    CHECK(mat3[1][0] == 1);
    CHECK(mat3[1][1] == 1);
    CHECK(mat3[1][2] == 1);
    CHECK(mat3[1][3] == 1);
    CHECK(mat3[2][0] == 1);
    CHECK(mat3[2][1] == 1);
    CHECK(mat3[2][2] == 1);
    CHECK(mat3[2][3] == 1);
    CHECK(mat3[3][0] == 1);
    CHECK(mat3[3][1] == 1);
    CHECK(mat3[3][2] == 1);
    CHECK(mat3[3][3] == 1);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '*=' - scalar") {

    mat1 *= 2;
    CHECK(mat1[0][0] == 0);
    CHECK(mat1[0][1] == 2);
    CHECK(mat1[0][2] == 4);
    CHECK(mat1[1][0] == 2);
    CHECK(mat1[1][1] == 4);
    CHECK(mat1[1][2] == 6);
    CHECK(mat1[2][0] == 4);
    CHECK(mat1[2][1] == 6);
    CHECK(mat1[2][2] == 8);

    mat3 *= (-1);
    CHECK(mat3[0][0] == 1);
    CHECK(mat3[0][1] == 1);
    CHECK(mat3[0][2] == 1);
    CHECK(mat3[0][3] == 1);
    CHECK(mat3[1][0] == 1);
    CHECK(mat3[1][1] == 1);
    CHECK(mat3[1][2] == 1);
    CHECK(mat3[1][3] == 1);
    CHECK(mat3[2][0] == 1);
    CHECK(mat3[2][1] == 1);
    CHECK(mat3[2][2] == 1);
    CHECK(mat3[2][3] == 1);
    CHECK(mat3[3][0] == 1);
    CHECK(mat3[3][1] == 1);
    CHECK(mat3[3][2] == 1);
    CHECK(mat3[3][3] == 1);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '*=' - matrix") {

    mat1 *= transpose;
    CHECK(mat1[0][0] == 5);
    CHECK(mat1[0][1] == 5);
    CHECK(mat1[0][2] == 5);
    CHECK(mat1[1][0] == 8);
    CHECK(mat1[1][1] == 8);
    CHECK(mat1[1][2] == 8);
    CHECK(mat1[2][0] == 11);
    CHECK(mat1[2][1] == 11);
    CHECK(mat1[2][2] == 11);

    CHECK_THROWS(mat1 *= mat3); // sizes are not equal -> throw

    mat3 *= mat3;
    CHECK(mat3[0][0] == 4);
    CHECK(mat3[0][1] == 4);
    CHECK(mat3[0][2] == 4);
    CHECK(mat3[0][3] == 4);
    CHECK(mat3[1][0] == 4);
    CHECK(mat3[1][1] == 4);
    CHECK(mat3[1][2] == 4);
    CHECK(mat3[1][3] == 4);
    CHECK(mat3[2][0] == 4);
    CHECK(mat3[2][1] == 4);
    CHECK(mat3[2][2] == 4);
    CHECK(mat3[2][3] == 4);
    CHECK(mat3[3][0] == 4);
    CHECK(mat3[3][1] == 4);
    CHECK(mat3[3][2] == 4);
    CHECK(mat3[3][3] == 4);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '%=' - scalar") {

    mat1 %= 3;
    CHECK(mat1[0][0] == 0);
    CHECK(mat1[0][1] == 1);
    CHECK(mat1[0][2] == 2);
    CHECK(mat1[1][0] == 1);
    CHECK(mat1[1][1] == 2);
    CHECK(mat1[1][2] == 0);
    CHECK(mat1[2][0] == 2);
    CHECK(mat1[2][1] == 0);
    CHECK(mat1[2][2] == 1);

    // invalid inputs
    CHECK_THROWS(mat1 %= 0);
    CHECK_THROWS(mat1 %= -1);

    mat3 %= 1;
    CHECK(mat3[0][0] == 0);
    CHECK(mat3[0][1] == 0);
    CHECK(mat3[0][2] == 0);
    CHECK(mat3[0][3] == 0);
    CHECK(mat3[1][0] == 0);
    CHECK(mat3[1][1] == 0);
    CHECK(mat3[1][2] == 0);
    CHECK(mat3[1][3] == 0);
    CHECK(mat3[2][0] == 0);
    CHECK(mat3[2][1] == 0);
    CHECK(mat3[2][2] == 0);
    CHECK(mat3[2][3] == 0);
    CHECK(mat3[3][0] == 0);
    CHECK(mat3[3][1] == 0);
    CHECK(mat3[3][2] == 0);
    CHECK(mat3[3][3] == 0);
}

TEST_CASE_FIXTURE(checkMatrices, "operator '%=' - matrix") {

    mat1 %= mat2;
    CHECK(mat1[0][0] == 0);
    CHECK(mat1[0][1] == 11);
    CHECK(mat1[0][2] == 24);
    CHECK(mat1[1][0] == 11);
    CHECK(mat1[1][1] == 24);
    CHECK(mat1[1][2] == 39);
    CHECK(mat1[2][0] == 24);
    CHECK(mat1[2][1] == 39);
    CHECK(mat1[2][2] == 56);

    CHECK_THROWS(mat1 %= mat3); // sizes are not equal -> throw

    mat3 %= mat3;
    CHECK(mat3[0][0] == 1);
    CHECK(mat3[0][1] == 1);
    CHECK(mat3[0][2] == 1);
    CHECK(mat3[0][3] == 1);
    CHECK(mat3[1][0] == 1);
    CHECK(mat3[1][1] == 1);
    CHECK(mat3[1][2] == 1);
    CHECK(mat3[1][3] == 1);
    CHECK(mat3[2][0] == 1);
    CHECK(mat3[2][1] == 1);
    CHECK(mat3[2][2] == 1);
    CHECK(mat3[2][3] == 1);
    CHECK(mat3[3][0] == 1);
    CHECK(mat3[3][1] == 1);
    CHECK(mat3[3][2] == 1);
    CHECK(mat3[3][3] == 1);
}

TEST_CASE_FIXTURE(checkMatrices, "operator <<") {

    // see prints
    cout << "Matrix 1:" << endl;
    cout << mat1 << endl;

    cout << "Matrix 2:" << endl;
    cout << mat2 << endl;

    cout << "Matrix 3:" << endl;
    cout << mat3 << endl;

    cout << "Transpose:" << endl;
    cout << transpose << endl;
}