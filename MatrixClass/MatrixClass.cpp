#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	Matrix m1;
	for (int i = 0; i < m1.getRows(); i++) {
		for (int j = 0; j < m1.getCols(); j++) {
			m1.setValue(i, j, 2);
		}
	}

	Matrix m2(2, 1);

	for (int i = 0; i < m2.getRows(); i++) {
		for (int j = 0; j < m2.getCols(); j++) {
			m2.setValue(i, j, 2);
		}
	}

	cout << m1;
	cout << m2;
	cout << m1 * m2;
}