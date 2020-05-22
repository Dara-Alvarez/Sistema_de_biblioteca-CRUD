//
// Created by Dara on 17/05/2020.
//
#include <iostream>
# include  <cstring>
#include "Prestamo.h"

using namespace std;


Prestamo::Prestamo() {

}

Prestamo::Prestamo(int usuario, int libro, char fecha_prestamo[100])
{
    this->usuario=usuario;
    this->libro=libro;
    strcpy(this->fecha_prestamo,fecha_prestamo);
    this->estatus=1;//prestamo activo

}

int Prestamo::get_usuario()
{
    return this->usuario;
}


int Prestamo::get_libro()
{
    return this->libro;
}

void Prestamo::devolucion(char fecha_devolucion[100])
{
    strcpy(this->fecha_devolucion,fecha_devolucion);
    this->estatus=0;
}


void Prestamo::consultar_prestamo()
{

    cout<<"Fecha del prestamo:"<<this->fecha_prestamo<<endl;

    if(this->estatus==1)
    {
        cout<<"Estado del prestamo: Ocupado"<<endl;
    } else
    {
        cout<<"Estado del prestamo: Devuelto"<<endl;
        cout<<"Fecha de devolucion:"<< this->fecha_devolucion<<endl;
    }

}

int Prestamo::get_estatus()
{
    return this->estatus;
}







