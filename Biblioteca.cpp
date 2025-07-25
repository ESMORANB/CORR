#include "pch.h"
#include "Biblioteca.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void Biblioteca::agregarLibro(const Libro& libro) {
	libros.push_back(libro);
}
void Biblioteca::agregarUsuario(IUsuario* usuario) {
	usuarios.push_back(usuario);
}
void Biblioteca::prestarLibro(const std::string& titulo, const std::string& user, const std::string& password) {
	for (auto& usuario : usuarios) {
		if (usuario->verificarCredenciales(user, password)) {
			for (auto& libro : libros) {
				if (libro.getTitulo() == titulo && !libro.esPrestado()) {
					libro.prestar();
					usuario->prestarLibro(titulo);
					return;
				}
			}
			cout << "El libro '" << titulo << "' no está disponible." << endl;
			return;
		}
	}
	cout << "Credenciales incorrectas." << endl;
}
void Biblioteca::devolverLibro(const std::string& titulo, const std::string& user, const std::string& password) {
	for (auto& usuario : usuarios) {
		if (usuario->verificarCredenciales(user, password)) {
			for (auto& libro : libros) {
				if (libro.getTitulo() == titulo && libro.esPrestado()) {
					libro.devolver();
					usuario->devolverLibro(titulo);
					return;
				}
			}
			cout << "El libro '" << titulo << "' no está prestado." << endl;
			return;
		}
	}
	cout << "Credenciales incorrectas." << endl;
}
void Biblioteca::mostrarLibros() const {
	cout << "Libros en la biblioteca:" << endl;
	for (const auto& libro : libros) {
		cout << "- " << libro.getTitulo() << " por " << libro.getAutor() 
			 << (libro.esPrestado() ? " (prestado)" : " (disponible)") << endl;
	}
}
void Biblioteca::mostrarUsuarios() const {
	cout << "Usuarios registrados:" << endl;
	for (const auto& usuario : usuarios) {
		cout << "- " << usuario->getNombre() << endl;
	}
}
void Biblioteca::mostrarLibrosPrestados(const std::string& user, const std::string& password) const {
	for (const auto& usuario : usuarios) {
		if (usuario->verificarCredenciales(user, password)) {
			usuario->mostrarLibrosPrestados();
			return;
		}
	}
	cout << "Credenciales incorrectas." << endl;
}
void Biblioteca::mostrarLibrosDisponibles() const {
	cout << "Libros disponibles:" << endl;
	for (const auto& libro : libros) {
		if (!libro.esPrestado()) {
			cout << "- " << libro.getTitulo() << " por " << libro.getAutor() << endl;
		}
	}
}


