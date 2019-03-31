#include "Matrix.h"
#include <iostream>

using namespace std;

// Default Constructor
// Default Values of Arguments of this functions are:
// rows = 2, cols = 2
Matrix::Matrix(int rows, int cols)
{
	// Store the rows and cols in the 
	// attributes for later use
	this->rows = rows;
	this->cols = cols;

	// Allocate the memory
	// Creating Array of Pointers 
	ptr = new int* [rows];

	for (int i = 0; i < rows; i++) {

		// Allocating each pointer
		ptr[i] = new int[cols];
		
		// Assigning a Default Value of Zero
		for (int j = 0; j < cols; j++) ptr[i][j] = 0;
	}
}

// Copy Constructor
Matrix::Matrix(const Matrix& obj)
{
	// Store the rows and cols in the 
	// attributes for later use
	this->rows = obj.rows;
	this->cols = obj.cols;

	// Allocate the memory
	// Creating Array of Pointers 
	ptr = new int* [rows];

	for (int i = 0; i < rows; i++) {

		// Allocating each pointer
		ptr[i] = new int[cols];

		// Assigning a Value of Object to be copied
		for (int j = 0; j < cols; j++) ptr[i][j] = obj.ptr[i][j];
	}
}

Matrix Matrix::add(const Matrix& obj) const {
	if (rows != obj.rows || cols != obj.cols) {
		cerr << "Can't add Matrices with different Dimensions";
		return *this;
	}

	// Creating a new Matrix Object
	Matrix temp(rows, cols);

	// Adding and storing the result in Temp Matrix
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp.ptr[i][j] = ptr[i][j] + obj.ptr[i][j];

	return temp;
}

Matrix Matrix::subtract(const Matrix& obj) const {
	if (rows != obj.rows || cols != obj.cols) {
		cerr << "Can't substract Matrices with different Dimensions";
		return *this;
	}

	// Creating a new Matrix Object
	Matrix temp(rows, cols);

	// Substractin and storing the result in Temp Matrix
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp.ptr[i][j] = ptr[i][j] - obj.ptr[i][j];

	return temp;
}

Matrix Matrix::multiply(const Matrix& obj) const {
	if (cols != obj.rows) {
		cerr << "Can't multiply!" << endl;
		return *this;
	}

	Matrix temp(obj.rows, obj.cols);

	for (int i = 0; i < obj.rows; i++)
		for (int j = 0; j < obj.cols; j++)
			for (int k = 0; k < cols; k++)
				temp.ptr[i][j] += ptr[i][k] + obj.ptr[k][j];

	return temp;
}

void Matrix::print(ostream& out) const {
	for (int i = 0; i < rows; i++) {
		out << "| ";
		for (int j = 0; j < cols; j++) {
			out << ptr[i][j];
			if (j != cols - 1) cout << "\t";
		}
		out << " |" << endl;
	}
}

void Matrix::setValue(int x, int y, int value) {
	ptr[x][y] = value;
}

int Matrix::getValue(int x, int y) {
	return ptr[x][y];
}

int Matrix::getCols() {
	return cols;
}

int Matrix::getRows() {
	return rows;
}

Matrix operator+(const Matrix& o1, const Matrix& o2) {
	return o1.add(o2);
}

Matrix operator-(const Matrix& o1, const Matrix& o2) {
	return o1.subtract(o2);
}

Matrix operator*(const Matrix& o1, const Matrix& o2) {
	return o1.multiply(o2);
}

ostream& operator<<(ostream& out, const Matrix& obj) {
	obj.print(out);
	return out;
}


Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete[] ptr[i];
	}
	delete[] ptr;
}
