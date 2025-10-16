#include <iostream>
#include "SparseMatrix.h"	
using namespace std;
int main() {
	SparseMatrix A;
	SparseMatrix B;
	A.add(2, 0, 0);
	A.add(6, 0, 1);
	A.add(0, 1, 10);


	B.add(7, 0, 4);
	B.add(1, 4, 0);
	B.add(2, 0, 9);

	cout << "Matriz A:" << endl;	
	A.printStoredValues();
	cout << "Matriz B:" << endl;	
	B.printStoredValues();	
	
}
{

}