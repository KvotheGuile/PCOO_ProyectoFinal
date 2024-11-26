
#include <iostream>
#include "School.h"
#include "Administrator.h"
#include "Professor.h"
#include "Student.h"

int main()
{
    Administrator admin1("Mateo", "12345678");
    School school1("Escuela Amanecer", 100, admin1);

    school1.printInfo();
    school1.aumentarColegiatura(900);
    
    do{
        string user, password;
        cout<<"Introduzca Usuario: ";
        cin>>user;
        cout<<"Introduzca Contraseña: ";
        cin>>password;
        school1.autenticar(user, password);
    }
    while (!school1.esAdmin());

    school1.autenticar("Mateo", "12345678");
    
    school1.aumentarColegiatura(200);
    school1.printInfo();

    return 0;
}
