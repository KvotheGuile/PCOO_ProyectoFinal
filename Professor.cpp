#include "Professor.h"
#include <iostream> 
#include <string>
using namespace std;

Professor::Professor(){
    nombre = "";
    matricula = "";
    salario = 0;
    saldo = 0;
};
Professor::Professor(string _nombre, string _matricula, double _salario){
    nombre = _nombre;
    matricula = _matricula;
    salario = _salario;
    saldo = 0;
};

Professor::~Professor(){};

string Professor::getNombre()
{
    return nombre;
};

string Professor::getMatricula()
{
    return matricula;
};

bool Professor::esProfesor(string _matricula)
{
    return this->matricula == _matricula;
};

double Professor::getSalario(){
    return salario;
};
void Professor::setSalario(double _salario){
    salario = _salario;
};
void Professor::aumentarSalario(double valor){
    salario += valor;
};
double Professor::pagar(){
    saldo += salario;
    return salario;
};
void Professor::printInfo(){
    cout << "Nombre: " << nombre << endl;
    cout << "Matricula: " << matricula << endl;
    cout << "Salario: " << salario << endl;
    cout << "Saldo: " << saldo << endl;
}