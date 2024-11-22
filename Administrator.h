
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream> 
#include <string>
using namespace std;


class Administrator
{
    private:
    string usuario;
    string password;
    bool loggedIn;

    public:
    Administrator(string _usuario, string _password);
    ~Administrator();

    bool esUsuario(string _usuario);
    void cambiarPassword(string _password);
    bool logIn(string _passwordIntento); // Regresa si fue existoso el intento
    void logOff();
    bool on(); // Regresa loggedIn

};

#endif
