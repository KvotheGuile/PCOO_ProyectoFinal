
#include "Administrator.h"

Administrator::Administrator(string _usuario, string _password): usuario(_usuario), password(_password), loggedIn(false) {};

bool Administrator::esUsuario(string _usuario) {return usuario == _usuario;};

void Administrator::cambiarPassword(string _password) 
{
    password = _password;
    cout<<"La nueva contraseña es: "<<password<<endl;
};

// Intenta ingresar y regresa si fue existoso el intento
bool Administrator::logIn(string _passwordIntento) {
    if (password == _passwordIntento) {
        loggedIn = true;
    }
    return on();
}; 
void Administrator::logOff() {loggedIn = false;};
// Regresa loggedIn
bool Administrator::on() {return loggedIn;};

Administrator::~Administrator(){};