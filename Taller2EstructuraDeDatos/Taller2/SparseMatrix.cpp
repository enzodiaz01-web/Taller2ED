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
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}