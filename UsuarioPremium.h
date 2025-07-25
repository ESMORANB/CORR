#pragma once
#include "Usuario.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class UsuarioPremium : public IUsuario
{
private:
		string nombre;
		string password;
		vector<string> librosPrestados;

public:

	UsuarioPremium(string nombre, string password);
	bool verificarCredenciales(const string& user, const string& password) override;
	void prestarLibro(const string& titulo) override;
	void devolverLibro(const string& titulo) override;
	void mostrarLibrosPrestados() override;
	string getNombre() const override;
	
		
};

