#include <fstream>
#include "School.h"

School::School()
{
    nombre = "";
    dinero = 0.0;
    colegiatura = 0.0;
    inicializarDatos();
};

School::School(std::string _nombre, double _colegiatura)
{
    nombre = _nombre;
    colegiatura = _colegiatura;
    dinero = 0;
    inicializarDatos();
};

School::~School()
{
    
};

void School::inicializarDatos() 
{
    int n;
    ifstream admins;
    admins.open("administradores.txt");
    admins>>n;
    admins.ignore();
// Declara  Administradores
    for (int i=0; i<n; i++)
    {
        string usuario, password;
        getline(admins, usuario);
        getline(admins, password);
        Administrator admin(usuario, password);
        cout<<usuario<<" "<<password<<endl;
        administradores.push_back(admin);
        autenticar(usuario, password);
    }
    admins.close();
    
// Toma la cantidad de profesores
    ifstream profs;
    profs.open("profesores.txt");
    profs>>n;
    profs.ignore();
// Agrega los profesores a la escuela
    for (int i=0; i<n; i++)
    {
        string nombre, matricula;
        double salario;
        getline(profs, nombre);
        getline(profs, matricula);
        profs>>salario;
        profs.ignore();
        Professor prof(nombre, matricula, salario);
        AddProfesor(prof);
    }
    profs.close();

// Toma la cantidad de estudiantes
    ifstream ests;
    ests.open("estudiantes.txt");
    ests>>n;
    ests.ignore();
// Agrega los estudiantes a la escuela
    for (int i=0; i<n; i++)
    {
        string nombre, matricula;
        float beca;
        getline(ests, nombre);
        getline(ests, matricula);
        ests>>beca;
        ests.ignore();
        Student est(nombre, matricula, beca);
        AddEstudiante(est);
    }
    ests.close();
    salirAdmin();
};

void School::aumentarColegiatura(double cantidad)
{   
    if (!esAdmin())
    { 
        noAdminMensaje();
        return; 
    }

    if (cantidad <= 0)
    {
        cout<<"\e[0;31m";
        cout<<"La cantidad tiene que ser un numero mayor a 0.\n";
        cout<<"\e[0;0m";
        return;
    }

    colegiatura += cantidad;
    cout<<"Se ha aumentado la colegiatura en $"<<cantidad<<". La nueva colegiatura es: $"<<colegiatura<<"\n";
};


void School::recolectarColegiatura()
{
    if (!esAdmin())
    { 
        noAdminMensaje();
        return; 
    }

    double ganancia = 0;
    for (int i = 0; i < estudiantes.size(); i++)
    {
        ganancia += estudiantes[i].recolectarDinero(colegiatura);
    }

    dinero += ganancia;
    cout<<"Se ha recolectado un total de $"<<ganancia<<" entre "<<estudiantes.size()<<" estudiantes.\n";
};

double School::pagarProfesores()
{
    if (!esAdmin())
    { 
        noAdminMensaje();
        return 0; 
    }

    if (!dineroSuficiente())
    { 
        cout<<"\e[0;31m";
        cout<<"ERROR: No hay suficiente dinero.\n";
        cout<<"\e[0;0m";
        return 0; 
    }
    
    double dineroUsado = 0;
    for(int i = 0; i < profesores.size(); i++)
    {
        dineroUsado += profesores[i].pagar();
    }
    
    dinero -= dineroUsado;
    cout<<"Se pago un total de $"<<dineroUsado<<" entre "<<profesores.size()<< " profesores.\n";
    return dinero;
};

bool School::dineroSuficiente()
{
    double dineroRequerido = 0;

    for(Professor p:profesores)
    {
        dineroRequerido += p.getSalario();
    }

    return dineroRequerido <= dinero;
};

void School::autenticar(std::string usuario, std::string contrasena)
{
    if (esAdmin())
    {
        cout<<"El usuario ya esta autenticado\n";
        return;
    }

    for (int i = 0; i < administradores.size(); i++)
    {
        if (administradores[i].esUsuario(usuario))
        {
            administradores[i].logIn(contrasena);
            
            if (administradores[i].on())
            {
                cout<<"Log In exitoso.\n";
                return;
            }
        }
    }
    cout<<"Usuario o contrasena incorrecto\n";
};

void School::salirAdmin()
{
    if (!esAdmin())
    {
        cout<<"Usted no es administrador.\n";
        return;
    }

    for (int i = 0; i < administradores.size(); i++)
    {
        administradores[i].logOff();
    }
    cout<<"Usted ya no es administrador.\n";
};

void School::printInfo()
{
    cout<<"SCHOOL: "<<nombre<<"\n";
    cout<<"Colegiatura: $"<<colegiatura<<"\n";
    cout<<"Dinero: $"<<dinero<<"\n";
    cout<<"Professores: "<<profesores.size()<<"\n";
    cout<<"Alumnos:     "<<estudiantes.size()<<"\n";
}

void School::printLista()
{
    cout<<"Profesores:\n";
    for (int i = 0; i < profesores.size(); i++)
    {
        cout<<"- "<<profesores[i].getNombre()<<" ("<<profesores[i].getMatricula()<<")\n";
    }
    
    cout<<"Estudiantes:\n";
    for (int i = 0; i < estudiantes.size(); i++)
    {
        cout<<"- "<<estudiantes[i].getNombre()<<" ("<<estudiantes[i].getMatricula()<<")\n";
    }
};

void School::printMiembro(string _matricula)
{
    for (int i = 0; i < profesores.size(); i++)
    {
        if (profesores[i].esProfesor(_matricula))
        {
            profesores[i].printInfo();
            return;
        }   
    }
    
    for (int i = 0; i < estudiantes.size(); i++)
    {
        if (estudiantes[i].esEstudiante(_matricula))
        {
            estudiantes[i].printInfo();
            return;
        }
    }
    
    cout<<"\e[0;31m";
    cout<<"ERROR: no se a encontrado nadie con la matricula "<<_matricula<<"\n";
    cout<<"\e[0;0m";
};

void School::AddEstudiante(Student& _estudiante)
{
    estudiantes.push_back(_estudiante);
}

void School::AddProfesor(Professor& _professor)
{
    if (!esAdmin())
    { 
        noAdminMensaje();
        return; 
    }
    
    profesores.push_back(_professor);
}

void School::AddAdministrador(Administrator& _admin)
{
    if (!esAdmin())
    { 
        noAdminMensaje();
        return; 
    }

    if (administradores.size() >= 3)
    {
        cout<<"Limite de administradores alcanzado\n";
        return;
    }
    
    administradores.push_back(_admin);
}

bool School::esAdmin()
{
    for (Administrator admin:administradores)
    {
        if (admin.on())
        {
            return true;
        }
    }

    return false;
};

void School::noAdminMensaje()
{
    cout<<"\e[0;31m";
    cout<<"ERROR: No se puede ejecutar esta accion sin ser administrador \n";
    cout<<"\e[0;0m";
}