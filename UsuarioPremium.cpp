#include "pch.h"
#include "UsuarioPremium.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

UsuarioPremium::UsuarioPremium(string nombre, string password) : nombre(nombre), password(password) {}
	
bool UsuarioPremium::verificarCredenciales(const string& user, const string& password) {
	return this->nombre == user && this->password == password;
}

void UsuarioPremium::prestarLibro(const string& titulo) {
	librosPrestados.push_back(titulo);
	cout << "Libro '" << titulo << "' prestado a " << nombre << "." << endl;
}

void UsuarioPremium::devolverLibro(const string& titulo) {
	auto it = find(librosPrestados.begin(), librosPrestados.end(), titulo);
	if (it != librosPrestados.end()) {
		librosPrestados.erase(it);
		cout << "Libro '" << titulo << "' devuelto por " << nombre << "." << endl;
	} else {
		cout << "El libro '" << titulo << "' no está prestado a " << nombre << "." << endl;
	}
}

void UsuarioPremium::mostrarLibrosPrestados() {
	if (librosPrestados.empty()) {
		cout << "No hay libros prestados a " << nombre << "." << endl;
	} else {
		cout << "Libros prestados a " << nombre << ":" << endl;
		for (const auto& titulo : librosPrestados) {
			cout << "- " << titulo << endl;
		}
	}
}

string UsuarioPremium::getNombre() const {
	return nombre;
}


