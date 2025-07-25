#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
class Libro
{
private:

	string titulo;
	string autor;
	bool prestado;

public:

	Libro(string titulo, string autor);
	
	string getTitulo() const;
	string getAutor() const;
	bool esPrestado() const;
	void prestar();
	void devolver();
};

