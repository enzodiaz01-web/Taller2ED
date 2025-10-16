#include <iostream>
#include "SparseMatrix.h"
using namespace std;

// Constructor
SparseMatrix::SparseMatrix() {
    start = nullptr;
}

// Destructor
SparseMatrix::~SparseMatrix() {
    Nodo* current = start;
    while (current != nullptr) {
        Nodo* temp = current;
        current = current->next;
        delete temp;
    }
}

//Insertar un dato en una coordenada especifica
void SparseMatrix::add(int valor, int PosX, int PosY) {
    if (valor == 0) return;
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

//Obtener el valor de una posicion especifica   
int SparseMatrix::getPosicion(int PosX, int PosY) {
    Nodo* current = start;

    while (current != nullptr) {
        
        if (current->x == PosX && current->y == PosY) {
            return current->valor;
        }
        current = current->next;
    }

    return 0;
}
//Eliminar un valor en una posicion especifica  
void SparseMatrix::deleteEnPosision(int PosX, int PosY) {
    if (start == nullptr) return; 

    Nodo* current = start;
    Nodo* prev = nullptr;

    while (current != nullptr) {
        if (current->x == PosX && current->y == PosY) {
            
            if (current == start) {
                start = current->next;
            }
            
            else {
                prev->next = current->next;
            }

            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Calcular densidad, Formula: (numero de elementos distintos de 0) / (numero total de elementos)
double SparseMatrix::densidad(int filas, int columnas) {
    if (filas <= 0 || columnas <= 0) return 0.0;

    int count = 0;
    Nodo* current = start;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    int total = filas * columnas;
    double densidad = (double)count / total * 100.0;
    return densidad;
}

//Multiplicar con otra matriz poco poblada
SparseMatrix* SparseMatrix::multiply(SparseMatrix* segunda) {
    SparseMatrix* resultado = new SparseMatrix();
    if (start == nullptr || segunda->start == nullptr) return resultado;
	Nodo* currentA = start; 
    while (currentA != nullptr) {
        Nodo* currentB = segunda->start;
        while (currentB != nullptr) {
            if (currentA->y == currentB->x) {
                int valorPrev = resultado->get(currentA->x, currentB->y);
            }
			currentB = currentB->next;  
        }
		currentA = currentA->next;
    }
	return resultado;   
}