
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream> 
#include <string>
using namespace std;


class Administrador
{
    private:
    string usuario;
    string password;
    bool loggedIn;

    public:
    Administrador(string _usuario, string _password);
    ~Administrador();

    bool esUsuario(string _usuario);
    void cambiarPassword(string _password);
    bool logIn(string _passwordIntento); // Regresa si fue existoso el intento
    void logOff();
    bool on(); // Regresa loggedIn

};

#endif
