
#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream> 
#include <string>
using namespace std;

class Professor
{
    private:
    string nombre;
    string matricula;
    double salario;
    double saldo;

    public:
    Professor();
    Professor(string _nombre, string _matricula, double _salario);
    ~Professor();

    string getNombre();
    string getMatricula();

    double getSalario();
    void setSalario(double);
    void aumentarSalario(double);
    double pagar();

    void printInfo();
};

#endif
