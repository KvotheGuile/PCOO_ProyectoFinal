
#include <iostream>
#include <cctype>
#include "School.h"
#include "Administrator.h"
#include "Professor.h"
#include "Student.h"
#include "Menu.h"

int main()
{

    School school1("Escuela Amanecer", 80);

    Menu(school1).Open();

    cout<<"Saliendo del programa.";
    return 0;
}
