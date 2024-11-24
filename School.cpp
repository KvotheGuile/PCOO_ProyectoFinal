
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
};

School::~School()
{
    
};

void School::aumentarColegiatura(double cantidad)
{

};

void School::recolectarColegiatura()
{

};

void School::pagarProfesores()
{

};

bool School::dineroSuficiente()
{
    return false;
};

void School::autenticar(std::string usuario, std::string contrasena)
{

};
