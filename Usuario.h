#pragma once
#include <string>
#include<iomanip>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
class IUsuario
{
public:
	virtual bool verificarCredenciales(const string& user, const string& password) = 0;
	virtual void prestarLibro(const string& titulo ) = 0;
	virtual void devolverLibro(const string& titulo) = 0;
	virtual void mostrarLibrosPrestados() = 0;
	virtual string getNombre() const = 0;

};

