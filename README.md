ProgrammingSystems2 - Assignment 2
-
This repository will contain the second assignment in the course Programming Systems 2.

In this assignment we (the students) were required to implement a squared matrix that we were taught in Linear Algebra course.
I choose to implement this matrix using two properties:
size(int) - the number of rows and column in the matrix.
squareMatrix(double**) - represents the matrix by two arrays of double.

We were requested to:
-
1. Overload operators.
2. Understand the matter of copy constructor, the difference between pointers and references, and the three principle.
3. Use friend functions.
4. Create Test class to check functionality.
5. Create a Makefile to run the project.

My project includes the following files under the namespace 'Mat':
-
SquareMat Class (hpp, cpp files) - mainly contains the properties of the squared matrix, the supported functions and operators signitures and the implementation of each function.
Tests Class (cpp file) - contains all the tests using TEST_CASE_FIXTURE which offers an initial data members to work with.
Main Class (cpp file) - conatins a few matrices and shows the uses of all the operators.
Makefile - supports the rules Main - runs the main, test - runs the Tests, valgrind (checks for memory leak) and clean. Note: the 'make valgrind command' is being performed on the tests file.

Note: each class has has a description and each function is explained in terms of it's purpose, inputs, returns and throws (if such exists).

Information sources that I used:
-
1. Squared matrix - https://en.wikipedia.org/wiki/Square_matrix
2. Overloading operators - https://www.geeksforgeeks.org/operator-overloading-cpp/
3. Friend function - https://www.geeksforgeeks.org/friend-class-function-cpp/
4. Friend function - https://www.programiz.com/cpp-programming/friend-function-class
5. Determinant - https://www.geeksforgeeks.org/determinant-of-a-square-matrix/
6. Matrix calculator - https://matrixcalc.org/
7. Matrix multiplication - https://en.wikipedia.org/wiki/Matrix_multiplication
8. ostream - https://www.programiz.com/cpp-programming/ostream
9. I also used the presentations that are given in the Moodle.
