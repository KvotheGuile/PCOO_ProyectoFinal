
#include "School.h"

School::School()
{
    nombre = "";
    dinero = 0.0;
    colegiatura = 0.0;
};

School::School(std::string _nombre, double _colegiatura, Administrator& admin)
{
    nombre = _nombre;
    colegiatura = _colegiatura;
    administradors.push_back(admin);
};

School::~School()
{
    
};

void School::aumentarColegiatura(double cantidad)
{   
    if (!esAdmin()){ return; }

};

void School::recolectarColegiatura()
{
    if (!esAdmin()){ return; }

};

void School::pagarProfesores()
{
    if (!esAdmin()){ return; }

};

bool School::dineroSuficiente()
{
    double dineroRequerido = 0;

    for(Professor p:profesores)
    {
        dineroRequerido += p.getSalario();
    }

    return dineroRequerido <= dinero;
};

void School::autenticar(std::string usuario, std::string contrasena)
{
    for (int i = 0; i < administradors.size(); i++)
    {
        if (administradors[i].esUsuario(usuario))
        {
            administradors[i].logIn(contrasena);
            break;
        }
    }
};

bool School::esAdmin()
{
    for (int i = 0; i < administradors.size(); i++)
    {
        if (administradors[i].on())
        {
            return true;
        }
    }

    return false;
};