
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
    
    std::vector<Student> estudiantes;
    std::vector<Professor> profesor;
    std::vector<Administrador> administrador;

    public:
    School();
    School(std::string nombre, double colegiatura);
    ~School();

    void recolectarColegiatura();
};

#endif