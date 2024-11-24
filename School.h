
#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <vector>

#include "Student.h"
#include "Professor.h"
#include "Administrator.h"

class School
{
    private:
    std::string nombre;
    double dinero;
    double colegiatura;
    
    //std::vector<Student> estudiantes;
    //std::vector<Professor> profesor;
    //std::vector<Administrator> administrador;

    public:
    School();
    School(std::string _nombre, double _colegiatura);
    ~School();

    void aumentarColegiatura(double _cantidad);
    void recolectarColegiatura();
    void pagarProfesores();
    
    bool dineroSuficiente();
    void autenticar(std::string _usuario, std::string _contrasena);
};

#endif