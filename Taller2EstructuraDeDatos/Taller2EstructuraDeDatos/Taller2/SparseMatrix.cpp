#include <iostream>
#include "SparseMatrix.h"
using namespace std;

// Constructor
SparseMatrix::SparseMatrix() {
    start = nullptr;
}

// Destructor
SparseMatrix::~SparseMatrix() {
    Node* current = start;
    while (current != nullptr) {
        Nodo* temp = current;
        current = current->next;
        delete temp;
    }
}
//Insertar un dato en una coordenada especifica
void SparseMatrix::add(int valor, int PosX, int PosY) {
    if (valor = 0) return;
    if (start == nullptr) {
		start = new Nodo(PosX, PosY, valor);        
        return;
    }
    Nodo* current = start;
	Nodo* prev = nullptr;   
    while (current != nullptr) {
        if (current->x == PosX && current->y == PosY) {
            current->valor = valor;
            return;
        }
        prev = current;
        current = current->next;
    }
	prev->next = new Nodo(PosX, PosY, valor);   
}
//Imprimir todos los valores distintos de 0
void SparseMatrix::printStoredValues() {
    Nodo* current = start;
    while (current != nullptr) {
        cout <<"(" << current->x << ", " << current->y << ") = " << current->valor << endl;
        current = current->next;
    }
}
// Lo que falta

//Obtener el valor de una posicion especifica   

//Eliminar un valor en una posicion especifica  

// Calcular densidad, Formula: (numero de elementos distintos de 0) / (numero total de elementos)

//Multiplicare con otra matriz poco poblada