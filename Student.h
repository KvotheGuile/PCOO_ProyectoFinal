
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream> 
#include <string>
using namespace std;

class Student
{
    private:
    string nombre;
    string matricula;
    double estadoDeCuenta;
    float beca;

    public:
    Student();
    Student(string _nombre, string _matricula, float _beca);

    void setBeca(float _becaNueva);
    float getBeca();
    
    bool esEstudiante(string _matricula);
    double recolectarDinero(double _colegiatura); 
    /* ^^^ Ingresas la colegiatura, aplica la beca.
    Esta cantidad se le resta al estado de cuenta y luego se regresa
    */

    void printInfo();
};

#endif