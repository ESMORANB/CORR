#pragma once
#include "Usuario.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class UsuarioRegular : public IUsuario
{
	string nombre;
	string password;
	vector<string> librosPrestados;
	static const int LIMITE = 3;

public:

	UsuarioRegular(string nombre, string password);
	bool verificarCredenciales(const string& user, const string& password) override;
	void prestarLibro(const string& titulo) override;
	void devolverLibro(const string& titulo) override;
	void mostrarLibrosPrestados() override;
	string getNombre() const override;


};

