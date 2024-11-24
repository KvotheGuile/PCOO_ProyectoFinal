
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
    school1.printInfo();
    school1.autenticar("Mateo", "12345678");
    school1.aumentarColegiatura(900);
    school1.printInfo();

    return 0;
}
