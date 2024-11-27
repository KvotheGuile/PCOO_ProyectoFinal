
#include "Menu.h"

Menu::Menu(School& _school)
{
    this->school = _school;
    this->on = true;
};

Menu::~Menu(){};

void Menu::Open()
{
    on = true;
    char input;
    cout<<"\033[2J";
    school.printInfo();
    MostrarComandos();
    
    while (on)
    {        
        cout<<"\n>>> "; 
        cin>>input;    

        // Esta linea ayuda para que no se quede trabado en un input previo y se limpie el cin
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        EjecutarComando(input); 
    }
    
};

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
    case 'M': // Info
        school.printLista();
        break;
    case 'E': // Info
        {
            string matricula;
            cout<<"Introduce Matricula: ";
            cin>>matricula;
            cout<<"\n";
            school.printMiembro(matricula);
        }
        break;
    case 'H': // Help
        MostrarComandos();
        break;
    case 'A':
        {
            double cantidad;
            cout<<"Introduzca la cantidad que se va a aumentar: ";
            cin>>cantidad;
            school.aumentarColegiatura(cantidad);
        }
        break;
    default:
        cout<<"Comando no reconocido. Utiliza 'H' para ver los comandos disponibles"<<endl;
        break;
    }
};

void Menu::MostrarComandos()
{

    cout<<"\e[38;5;251m";
    cout<<"<H> - Mostrar comandos "<<endl;

    cout<<"<L> - Log In"<<endl;
    cout<<"<O> - Log Off"<<endl;
    cout<<"<S> - Salir"<<endl;
    
    cout<<"<P> - Pagar profesores"<<endl;
    cout<<"<C> - Cobrar alumnos"<<endl;
    cout<<"<A> - Aumentar colegiatura"<<endl; 

    cout<<"<I> - Info general"<<endl; 
    cout<<"<E> - Imprimir miembro especifico"<<endl; 
    cout<<"<M> - Lista de miembros"<<endl; 
    

    cout<<"\e[0;0m";
};