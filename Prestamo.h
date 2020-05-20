//
// Created by Dara on 17/05/2020.
//

#ifndef U6_T5_CLASS_SISTEMA_BIBLIOTECA_PRESTAMO_H
#define U6_T5_CLASS_SISTEMA_BIBLIOTECA_PRESTAMO_H

class Prestamo
{
private:
    int usuario=0;
    int libro=0;
    char fecha_prestamo[100];
    char fecha_devolucion[100];
    int estatus=0; //prestamo inactivo


public:
    Prestamo();
    Prestamo(int,int,char[100]);

    int get_usuario();
    int get_libro();
    int get_estatus();

    void devolucion(char[]);

    void consultar_prestamo();


};


#endif //U6_T5_CLASS_SISTEMA_BIBLIOTECA_PRESTAMO_H
