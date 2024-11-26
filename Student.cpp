#include "Student.h"

Student::Student() : nombre(""), matricula(""), estadoDeCuenta(0.0f), beca(0.0f) {}

Student::Student(string _nombre, string _matricula, float _beca) : nombre(_nombre), matricula(_matricula), estadoDeCuenta(0.0f), beca(_beca) {}

Student::~Student() {}

void Student::setBeca(float _becaNueva) {
    beca = _becaNueva;
}

float Student::getBeca() {
    return beca;
}

bool Student::esEstudiante(string _matricula) {
    return this->matricula == _matricula;
}

double Student::recolectarDinero(double _colegiatura) {  
    float cantidadAPagar = _colegiatura * (1 - beca);
    estadoDeCuenta -= cantidadAPagar;
    return cantidadAPagar;
}

void Student::printInfo() {
    cout << "Estudiante: " << nombre << "\n";
    cout << "Matrícula: " << matricula << "\n";
    cout << "Estado de cuenta: $" << estadoDeCuenta << "\n";
    cout << "Beca: " << (beca * 100) << "%\n";
}

