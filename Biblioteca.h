#pragma once
#include <string>
#include "Libro.h"
#include "Usuario.h"
#include <vector>

class Biblioteca
{
private:
	vector<Libro> libros;
	vector<IUsuario*> usuarios;

public:
	Biblioteca() = default;

	void agregarLibro(const Libro& libro);

	void agregarUsuario(IUsuario* usuario);
	void prestarLibro(const std::string& titulo, const std::string& user, const std::string& password);
	void devolverLibro(const std::string& titulo, const std::string& user, const std::string& password);
	void mostrarLibros() const;
	void mostrarUsuarios() const;
	void mostrarLibrosPrestados(const std::string& user, const std::string& password) const;
	void mostrarLibrosDisponibles() const;


};

