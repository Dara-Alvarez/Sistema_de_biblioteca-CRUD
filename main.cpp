#include <iostream>
#include "Usuario.h"
#include "Libro.h"

#include "cmake-build-debug/Prestamo.h"

using namespace std;


//opcion que controla los menus
int opcion=0;

//Contadores
int contador_libros=0;
int contador_usuarios=0;
int contador_prestamos=0;

char fecha_devolucion[100];

Libro libros[10];
Usuario usuarios[10];
Prestamo prestamos[100];


void menu_principal()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"      M E N U  P R I N C I P A L      "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"                                      "<<endl;
    cout<<"      1.Administrar usuarios          "<<endl;
    cout<<"      2.Administrar libros            "<<endl;
    cout<<"      3.Administrar prestamos         "<<endl;
    cout<<"                                      "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>opcion;

    cout<<endl;
}

void menu_usuario()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"        Administrar usuarios          "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"            1.Registrar               "<<endl;
    cout<<"            2.Editar                  "<<endl;
    cout<<"            3.Consultar               "<<endl;
    cout<<"            4.Eliminar                "<<endl;
    cout<<"            5.Menu principal          "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>opcion;

    cout<<endl;
}

void menu_libro()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"          Administrar libros          "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"            1.Registrar               "<<endl;
    cout<<"            2.Editar                  "<<endl;
    cout<<"            3.Consultar               "<<endl;
    cout<<"            4.Eliminar                "<<endl;
    cout<<"            5.Menu principal          "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>opcion;

    cout<<endl;
}

void menu_prestamos()
{
    cout<<endl;

    cout<<"--------------------------------------"<<endl;
    cout<<"        Administrar prestamos         "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"         1.Realizar prestamo          "<<endl;
    cout<<"         2.Devolver libro             "<<endl;
    cout<<"         3.Consultar prestamo         "<<endl;
    cout<<"         4.Menu principal             "<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Opcion:";
    cin>>opcion;

    cout<<endl;
}

void mostrar_libros(Libro libros[10],int contador_libros)
{
    cout<<"--------------------------------------"<<endl;
    cout<<"              Libros                  "<<endl;
    for (int i = 0; i < contador_libros; ++i)
    {
        cout<<"Libro "<<i<<endl;
        libros[i].consultar_libro();
    }
    cout<<"--------------------------------------"<<endl;
}


Usuario registrar_usuario()
{
    char nombre[100];
    int edad=0;
    char nacionalidad[100];

    cout<<"Nombre:"<<endl;
    cin>>nombre;
    cout<<"Edad:"<<endl;
    cin>>edad;
    cout<<"Nacionalidad:"<<endl;
    cin>>nacionalidad;

    return Usuario(nombre,edad,nacionalidad);
}


Libro registrar_libro()
{
    char titulo[100];
    char autor[100];
    char isbn[100];
    char editorial[100];

    cout<<"Titulo:"<<endl;
    cin>>titulo;
    cout<<"Autor:"<<endl;
    cin>>autor;
    cout<<"ISBN:"<<endl;
    cin>>isbn;
    cout<<"Editorial:"<<endl;
    cin>>editorial;

    return Libro(titulo,autor,isbn,editorial);
}

Prestamo registrar_prestamo(int libro)
{
    int usuario=0;
    char fecha_prestamo[100];

    cout<<"Numero de usuario"<<endl;
    cin>>usuario;
    cout<<"Fecha de prestamo"<<endl;
    cin>>fecha_prestamo;

    return Prestamo(usuario,libro,fecha_prestamo);
}



int main()
{
    //Banderas
    bool flag_principal=true;
    bool flag_usuario= true;
    bool flag_libro= true;
    bool flag_prestamo= true;
    bool temporal=true;

    //Numero del arreglo
    int no=0;


    //Encabezado
    cout<<endl;
    cout<<"         B I B L I O T E C A"<<endl;
    //Encabezado

    while (flag_principal)
    {

        menu_principal();

        flag_usuario= true;
        flag_libro= true;
        flag_prestamo= true;

        switch (opcion)
        {
            case 1:
                //Administrar usuario

                while(flag_usuario)
                {
                    menu_usuario();

                    switch (opcion)
                    {
                        case 1:
                            //Registrar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"          Registrar usuario           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            usuarios[contador_usuarios]=registrar_usuario();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Registro exitoso          "<<endl;
                            cout<<"--------------------------------------"<<endl;
                            cout<<"Numero de usuario:"<<contador_usuarios<<endl;

                            contador_usuarios++;

                            break;

                        case 2:
                            //Editar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"             Editar usuario           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de usuario:";
                            cin>>no;

                            cout<<"--------------------------------------"<<endl;
                            usuarios[no].consultar_usuario();
                            cout<<"--------------------------------------"<<endl;
                            usuarios[no]=registrar_usuario();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"             Usuario editado          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 3:
                            //Consultar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"          Consultar usuario           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de usuario:";
                            cin>>no;

                            usuarios[no].consultar_usuario();

                            cout<<"--------Informacion de prestamo-------"<<endl;
                            for(int i=0;i<contador_prestamos;i++)
                            {
                                if(prestamos[i].get_usuario()==no)
                                {
                                    //imprime el detalle del libro
                                    libros[prestamos[no].get_usuario()].consultar_libro();
                                    //imprime el detalle del prestamo
                                    prestamos[i].consultar_prestamo();
                                }
                            }

                            break;

                        case 4:
                            //Eliminar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Eliminar usuario          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de usuario:";
                            cin>>no;

                            usuarios[no]=Usuario();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"           Usuario eliminado          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 5:
                            //Menu principal
                            flag_usuario= false;
                            break;
                    }
                }
                break;


            case 2:
                //Administrar libros

                while(flag_libro)
                {
                    menu_libro();

                    switch (opcion)
                    {
                        case 1:
                            //Registrar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Registrar libro           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            libros[contador_libros]=registrar_libro();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Registro exitoso          "<<endl;
                            cout<<"--------------------------------------"<<endl;
                            cout<<"Numero de libro:"<<contador_libros<<endl;

                            contador_libros++;

                            break;

                        case 2:
                            //Editar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"              Editar libro            "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de libro:";
                            cin>>no;

                            cout<<"--------------------------------------"<<endl;
                            libros[no].consultar_libro();
                            cout<<"--------------------------------------"<<endl;
                            libros[no]=registrar_libro();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"              Libro editado           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 3:
                            //Consultar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"            Consultar libro           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de libro:";
                            cin>>no;

                            libros[no].consultar_libro();

                            cout<<"--------Informacion de prestamo-------"<<endl;
                            for(int i=0;i<contador_prestamos;i++)
                            {
                                if(prestamos[i].get_libro()==no)
                                {
                                    //imprime el detalle del usuario
                                    usuarios[prestamos[no].get_usuario()].consultar_usuario();
                                    //imprime el detalle del prestamo
                                    prestamos[i].consultar_prestamo();
                                }
                            }

                            break;

                        case 4:
                            //Eliminar
                            cout<<"--------------------------------------"<<endl;
                            cout<<"             Eliminar libro           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de libro:";
                            cin>>no;

                            libros[no]=Libro();

                            cout<<"--------------------------------------"<<endl;
                            cout<<"             Libro eliminado          "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 5:
                            //Menu principal
                            flag_libro= false;
                            break;
                    }
                }
                break;

            case 3:
                //Administrar prestamos

                while(flag_prestamo)
                {
                    menu_prestamos();

                    switch (opcion)
                    {
                        case 1:
                            //Realizar prestamo
                            cout<<"--------------------------------------"<<endl;
                            cout<<"                Prestamo              "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            mostrar_libros(libros,contador_libros);

                            cout<<"Ingrese el numero del libro:"<<endl;
                            cin>>no;

                            temporal= true;

                            for (int i = 0; i <contador_prestamos ; ++i)
                            {
                                //Si entra al if el libro esta prestado
                                if(no==prestamos[i].get_libro() and prestamos[i].get_estatus()==1)
                                {
                                    temporal=false;
                                }
                            }

                            if(temporal==true) //si nunca entro al if el libro no esta prestado
                            {
                                prestamos[contador_prestamos]=registrar_prestamo(no);

                                cout<<"--------------------------------------"<<endl;
                                cout<<"            Prestamo exitoso          "<<endl;
                                cout<<"--------------------------------------"<<endl;
                                cout<<"Numero de prestamo:"<<contador_prestamos<<endl;

                                contador_prestamos++;

                            } else{
                                cout<<"El libro ya esta prestado"<<endl;
                            }

                            break;

                        case 2:
                            //Devolver libro
                            cout<<"--------------------------------------"<<endl;
                            cout<<"              Devolucion              "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de prestamo:";
                            cin>>no;

                            cout<<"--------------------------------------"<<endl;
                            libros[prestamos[no].get_libro()].consultar_libro();
                            cout<<"--------------------------------------"<<endl;

                            cout<<"--------------------------------------"<<endl;
                            prestamos[no].consultar_prestamo();
                            cout<<"--------------------------------------"<<endl;


                            if (prestamos[no].get_estatus()==1)
                            {
                                cout<<"Fecha de devolucion:"<<endl;
                                cin>>fecha_devolucion;

                                prestamos[no].devolucion(fecha_devolucion);

                                cout<<"--------------------------------------"<<endl;
                                cout<<"          Devolucion exitosa          "<<endl;
                                cout<<"--------------------------------------"<<endl;
                            } else
                            {
                                cout<<"El prestamo ha finalizado anteriormente"<<endl;
                            }

                            break;

                        case 3:
                            //Consultar prestamo
                            cout<<"--------------------------------------"<<endl;
                            cout<<"         Consultar prestamo           "<<endl;
                            cout<<"--------------------------------------"<<endl;

                            cout<<"Numero de prestamo:";
                            cin>>no;

                            cout<<"--------------------------------------"<<endl;
                            usuarios[prestamos[no].get_usuario()].consultar_usuario();
                            cout<<"--------------------------------------"<<endl;

                            cout<<"--------------------------------------"<<endl;
                            libros[prestamos[no].get_libro()].consultar_libro();
                            cout<<"--------------------------------------"<<endl;

                            cout<<"--------------------------------------"<<endl;
                            prestamos[no].consultar_prestamo();
                            cout<<"--------------------------------------"<<endl;

                            break;

                        case 4:
                            //Menu principal
                            flag_prestamo= false;
                            break;
                    }

                }

                break;

        }

    }



    return 0;
}



