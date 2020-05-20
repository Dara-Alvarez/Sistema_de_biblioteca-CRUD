//
// Created by Dara on 14/05/2020.
//

# include  <iostream>
# include  <cstring>
#include "Libro.h"

using namespace std;

Libro::Libro() {

}

Libro::Libro(char titulo[100], char autor[100],char isbn[100], char editorial[100])
{
    strcpy(this->titulo,titulo);
    strcpy(this->autor,autor);
    strcpy(this->isbn,isbn);
    strcpy(this->editorial,editorial);
}

void Libro::consultar_libro()
{
    cout<<"Titulo: "<<this->titulo<<endl;
    cout<<"Autor: "<<this->autor<<endl;
    cout<<"ISBN: "<<this->isbn<<endl;
    cout<<"Editorial: "<<this->editorial<<endl;
}

