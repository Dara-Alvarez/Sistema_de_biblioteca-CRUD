//
// Created by Dara on 14/05/2020.
//

# include  <iostream>
# include  <cstring>
#include "Usuario.h"

using namespace std;

Usuario::Usuario() {

}

Usuario::Usuario(char nombre[100], int edad,char nacionalidad[100])
{
    strcpy(this->nombre,nombre);
    this->edad=edad;
    strcpy(this->nacionalidad,nacionalidad);
}

void Usuario::consultar_usuario()
{
    cout<<"Nombre: "<<this->nombre<<endl;
    cout<<"Edad: "<<this->edad<<endl;
    cout<<"Nacionalidad: "<<this->nacionalidad<<endl;
}





