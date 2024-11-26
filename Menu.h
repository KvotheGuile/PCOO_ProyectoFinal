#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "School.h"
using namespace std;

class Menu
{
    private:
    School school;
    bool on;

    public:
    Menu(School& _school);
    ~Menu();

    void Open();
    void MostrarComandos();
    void EjecutarComando(char input);

};

#endif