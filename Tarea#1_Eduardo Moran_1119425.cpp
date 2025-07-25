#include "pch.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Biblioteca.h"
#include "UsuarioRegular.h"
#include "UsuarioPremium.h"
#include "Libro.h"
#include "Usuario.h"

using namespace std;
using namespace System;

int main()
{
    Biblioteca biblio;
	biblio.agregarLibro(Libro("Cien a�os de soledad", "Gabriel Garc�a M�rquez"));
	biblio.agregarLibro(Libro("El amor en los tiempos del c�lera", "Gabriel Garc�a M�rquez"));
	biblio.agregarLibro(Libro("1984", "George Orwell"));
	
	biblio.agregarUsuario(new UsuarioRegular("usuario1", "password1"));
	biblio.agregarUsuario(new UsuarioPremium("usuario2", "password2"));
	biblio.mostrarLibros();
	biblio.mostrarUsuarios();

	biblio.prestarLibro("Cien a�os de soledad", "usuario1", "password1");
	biblio.mostrarLibros();
	biblio.mostrarLibrosPrestados("usuario1", "password1");
	biblio.devolverLibro("Cien a�os de soledad", "usuario1", "password1");
	biblio.mostrarLibros();
	biblio.mostrarLibrosPrestados("usuario1", "password1");
	biblio.prestarLibro("1984", "usuario2", "password2");
	biblio.mostrarLibros();
	biblio.mostrarLibrosPrestados("usuario2", "password2");

	

    
    return 0;
}
