#include "pch.h"
#include "Libro.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;
Libro::Libro(string titulo, string autor) : titulo(titulo), autor(autor), prestado(false) {}

string Libro::getTitulo() const {
	return titulo;
}

string Libro::getAutor() const {
	return autor;
}

bool Libro::esPrestado() const {
	return prestado;
}

void Libro::prestar() {
	if (!prestado) {
		prestado = true;
	} else {
		cout << "El libro ya está prestado." << endl;
	}
}

void Libro::devolver() {
	if (prestado) {
		prestado = false;
	} else {
		cout << "El libro no está prestado." << endl;
	}
}

