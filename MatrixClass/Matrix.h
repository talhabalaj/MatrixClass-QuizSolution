#include <iostream>
using namespace std;
 class Matrix
{
	 int rows;
	 int cols;
	 int** ptr;
public:
	Matrix(int = 2, int = 2);
	Matrix(const Matrix&);
	Matrix add(const Matrix&) const;
	Matrix subtract(const Matrix&) const;
	Matrix multiply(const Matrix&) const;
	void print(ostream& = cout) const;
	void setValue(int, int, int);
	int getValue(int, int);
	int getRows();
	int getCols();
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
	~Matrix();
};

