//
// Created by Dara on 14/05/2020.
//

#ifndef U6_T5_CLASS_SISTEMA_BIBLIOTECA_LIBRO_H
#define U6_T5_CLASS_SISTEMA_BIBLIOTECA_LIBRO_H


class Libro
{
private:
    char titulo[100];
    char autor[100];
    char isbn[100];
    char editorial[100];

public:
    Libro();
    Libro(char[100], char[100],char[100], char[100]);

    void consultar_libro();

};


#endif //U6_T5_CLASS_SISTEMA_BIBLIOTECA_LIBRO_H
