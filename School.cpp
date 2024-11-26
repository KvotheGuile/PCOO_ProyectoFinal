
#include "School.h"

School::School()
{
    nombre = "";
    dinero = 0.0;
    colegiatura = 0.0;
};

School::School(std::string _nombre, double _colegiatura, Administrator& admin)
{
    nombre = _nombre;
    colegiatura = _colegiatura;
    administradors.push_back(admin);
    dinero = 0;
};

School::~School()
{
    
};

void School::aumentarColegiatura(double cantidad)
{   
    if (!esAdmin())
    { 
        noAdminMensaje();
        return; 
    }
    colegiatura += cantidad;
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
    for(Professor p:profesores)
    {
        dineroUsado += p.pagar();
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

    for (int i = 0; i < administradors.size(); i++)
    {
        if (administradors[i].esUsuario(usuario))
        {
            administradors[i].logIn(contrasena);
            cout<<"Log In exitoso.\n";
            return;
        }
    }
    cout<<"Usuario o contraseña incorrecto\n";
};

void School::salirAdmin()
{
    if (!esAdmin())
    {
        cout<<"Usted no es administrador.\n";
        return;
    }

    for (int i = 0; i < administradors.size(); i++)
    {
        administradors[i].logOff();
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

    if (administradors.size() >= 3)
    {
        cout<<"Limite de administradores alcanzado\n";
        return;
    }
    
    administradors.push_back(_admin);
}

bool School::esAdmin()
{
    for (Administrator admin:administradors)
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
    cout<<"ERROR: No se puede ejecutar esta accion sin ser administrador\n";
    cout<<"\e[0;0m";
}