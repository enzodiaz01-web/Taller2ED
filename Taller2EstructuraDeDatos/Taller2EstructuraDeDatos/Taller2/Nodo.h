#pragma once
struct Nodo {
	int x;
	int y;
	int valor;
	Nodo* siguiente;
	Nodo(int PosX, int PosY, int val) {
		valor = val;
		x = PosX;
		y = PosY;
		next = nullptr;
	}
};
