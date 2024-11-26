
#include <iostream>
#include "School.h"
#include "Administrator.h"
#include "Professor.h"
#include "Student.h"

int main()
{
    // Variable del loop principal
    bool loopOn = true;

    // Declarar miembros iniciales
    Administrator admin1("Mateo", "12345678");
    Administrator admin2("Sebas", "abcd");

    School school1("Escuela Amanecer", 80, admin1);

    Professor prof1("Eduardo", "M00A1", 50);
    Professor prof2("Dario", "M00B2", 60);
    Professor prof3("César", "M00C3", 40);
    
    Student est1("Sebastian", "E012I", 0.5);
    Student est2("Ignacio", "E024J", 0.2);
    Student est3("Hector", "E036K", 0.7);
    Student est4("Lopez", "E048L", 0);

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
    
    school1.printInfo();

    while (loopOn)
    {
        char input;
        cout<<endl;
        cout<<"<L> - Log In"<<endl;
        cout<<"<O> - Log Off"<<endl;
        cout<<"<S> - Salir"<<endl;
        
        cout<<"<P> - Pagar profesores"<<endl;
        cout<<"<R> - Recolectar dinero de alumnos"<<endl;
        
        cout<<"<I> - Info general"<<endl;
        cout<<"<R> - Recolectar dinero de alumnos"<<endl;

        cout<<">>> ";
        cin>>input;

        switch (input)
        {
        case 'L': // Log in
            {
                string user, password;
                cout<<"Introduce usuario: ";
                cin>>user;
                cout<<"Introduce password: ";
                cin>>password;
                school1.autenticar(user, password);
            }
            
            break;
        case 'S': // Salir del loop
            loopOn = false;
            break;
        default:
            cout<<"Comando no reconocido."<<endl;
            break;
        }
    }

    cout<<"Saliendo del programa.";
    return 0;
}
