//
// Created by Dara on 14/05/2020.
//

#ifndef U6_T5_CLASS_SISTEMA_BIBLIOTECA_USUARIO_H
#define U6_T5_CLASS_SISTEMA_BIBLIOTECA_USUARIO_H


class Usuario
{
private:
    char nombre[100];
    int edad=0;
    char nacionalidad[100];

public:
    Usuario();
    Usuario(char[100], int,char[100]);

    void consultar_usuario();

};


#endif //U6_T5_CLASS_SISTEMA_BIBLIOTECA_USUARIO_H
