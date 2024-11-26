
#include "Menu.h"

Menu::Menu(School& _school)
{
    this->school = _school;
    this->on = true;
};

Menu::~Menu(){};

void Menu::EjecutarComando(char input)
{
    input = toupper(input);

    switch (input)
    {
    case 'L': // Log in
        {
            string user, password;
            cout<<"Introduce usuario: ";
            cin>>user;
            cout<<"Introduce password: ";
            cin>>password;
            school.autenticar(user, password);
        }
        
        break;
    case 'O': // Log off
        school.salirAdmin();
        break;
    case 'S': // Salir del loop
        on = false;
        break;
    case 'P': // Pagar
        school.pagarProfesores();
        break;
    case 'C': // Recolectar dinero
        school.recolectarColegiatura();
        break;
    case 'I': // Info
        school.printInfo();
        break;
    case 'H': // Help
        MostrarComandos();
        break;

    default:
        cout<<"Comando no reconocido. Utiliza 'H' para ver los comandos disponibles"<<endl;
        break;
    }
};

void Menu::MostrarComandos()
{

    cout<<"\e[38;5;243m";
    cout<<"<H> - Mostrar comandos "<<endl;

    cout<<"<L> - Log In"<<endl;
    cout<<"<O> - Log Off"<<endl;
    cout<<"<S> - Salir"<<endl;
    
    cout<<"<P> - Pagar profesores"<<endl;
    cout<<"<C> - Cobrar alumnos"<<endl;
    cout<<"<A> - Aumentar colegiatura"<<endl; // Falta

    cout<<"<I> - Info general"<<endl; 
    cout<<"<E> - Imprimir miembro especifico"<<endl; // Falta
    cout<<"<L> - Lista de miembros"<<endl; // Falta
    cout<<"<N> - Nuevo miembro"<<endl;  // Falta
    

    cout<<"\e[0;0m";
};