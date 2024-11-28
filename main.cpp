
#include <iostream>
#include <cctype>
#include "School.h"
#include "Administrator.h"
#include "Professor.h"
#include "Student.h"
#include "Menu.h"

int main()
{
    // Variable del loop principal
    bool loopOn = true;

    // Declarar miembros
    Administrator admin1("Mateo", "12345678");
    Administrator admin2("Sebas", "abcd");

    School school1("Escuela Amanecer", 80, admin1);

    Professor prof1("Alondra", "M010", 50);
    Professor prof2("Dario", "M022", 60);
    Professor prof3("Cesar", "M034", 40);
    
    Student est1("Hector", "E012", 0.5);
    Student est2("Ignacio", "E024", 0);
    Student est3("Gabriela", "E036", 0.7);
    Student est4("Lopez", "E048", 0);
    Student est5("Maria", "E056", 0.3);

    // Add todos los miembros iniciales de la escuela
    school1.autenticar("Mateo", "12345678");
    school1.AddAdministrador(admin2);
    school1.AddProfesor(prof1);
    school1.AddProfesor(prof2);
    school1.AddProfesor(prof3);
    school1.AddEstudiante(est1);
    school1.AddEstudiante(est2);
    school1.AddEstudiante(est3);
    school1.AddEstudiante(est4);
    school1.AddEstudiante(est5);
    school1.salirAdmin();
    
    Menu(school1).Open();

    cout<<"Saliendo del programa.";
    return 0;
}
