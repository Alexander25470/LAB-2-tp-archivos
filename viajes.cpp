#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "funciones.h"

Viajes nuevoViaje()
{
    Viajes reg;
    int opc;
    system("cls");
    //----------------------------------------------
    cout<<"ID VIAJE: ";
    reg.idviaje = id_automatico(reg);
    cout<<reg.idviaje<<endl;
    //----------------------------------------------
    do{
        cout << "DNI CHOFER: ";
        cargarCadena(reg.dni, 10);
    }while(buscarNumeroDNI(reg.dni)!=-1);
    //----------------------------------------------
    cout << "ID CLIENTE   : ";
    cin>>reg.idclient;
    //----------------------------------------------
    cout << "F. DE VIAJE: " << endl;
    reg.fechaViaje = cargarFecha(true);
    //----------------------------------------------
     do
    {
        cout << "HORA VIAJE: ";
        cin >> reg.horaSalida;
    } while (reg.horaSalida < 0 || reg.horaSalida > 23);
    //----------------------------------------------
    do{
        cout<<" INGRESE KILOMETRAJE DEL VIAJE: ";
        cin>>reg.kilom;
    }while(reg.kilom<=0);
    //----------------------------------------------
    do{
    cout<<" IMPORTE VIAJE: ";
    cin>>reg.impor;
    }while(reg.impor<=0);
    //-----------------------------------------------
    cout << "IMPORTE PATENTE : ";
    cin.ignore();
    cargarCadena(reg.patent, 50);
    //--------------------------------------------------
    do
    {
        cout << "CALIFICACION: ";
        cin >> reg.calific;
    } while (reg.calific < 0 || reg.calific > 5);
    //----------------------------------------------------
    reg.estado = true;
    cin.ignore();
    return reg;
}

bool grabarViaje(Viajes reg)
{
    FILE *p;
    bool write;
    p = fopen("cargarViaje.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO";
        return 0;
    }
    write = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return write;
}

void cargarViaje()
{
    Viajes reg;
    int pos;
    bool grabo;
    reg = nuevoViaje();
    grabo = grabarViaje(reg);
    if (grabo == true)
    {
        cout << "EL REGISTRO SE REALIZO CON EXITO." << endl;
    }
    else
    {
        cout << "ERROR AL GRABAR REGISTRO. " << endl;
    }
}


int id_automatico(Viajes reg){
    FILE *p;
    int total;
    p=fopen("cargarViaje.dat", "rb");
    if(p==NULL){
        reg.idviaje=1;
        return reg.idviaje;
    }
    fseek(p, 0, SEEK_END);
    total = ftell(p);
    reg.idviaje = total / sizeof(Viajes) + 1;
    fclose(p);
    return reg.idviaje;
}

void mostrarViaje(Viajes reg)
{
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    //----------------------------------------------
    cout<<"ID VIAJE: ";
    cout<<reg.idviaje<<endl;
    //----------------------------------------------
    cout << "DNI CHOFER: ";
    cout <<reg.dni<<endl;
    //----------------------------------------------
    cout << "ID CLIENTE   : ";
    cout <<reg.idclient<<endl;
    //----------------------------------------------
    cout << "F. DE VIAJE: " << endl;
    //cout << reg.fechaViaje;
    //----------------------------------------------

    cout << "HORA VIAJE: ";
    cout <<  reg.horaSalida<<endl;
    //----------------------------------------------

    cout<<"KILOMETRAJE DEL VIAJE: ";
    cout << reg.kilom<<endl;
    //----------------------------------------------
    cout<<" IMPORTE VIAJE: ";
    cout << reg.impor<<endl;
    //-----------------------------------------------
    cout << "PATENTE : ";
    cout << reg.patent<<endl;
    //--------------------------------------------------
    cout << "CALIFICACION: ";
    cout <<  reg.calific<<endl;
    //----------------------------------------------------
    if (reg.estado == true)
    {
        //rlutil::setColor(rlutil::GREEN);
        cout << "ESTADO: ACTIVO" << endl;
    }
    else
    {
        if (reg.estado == false)
        {
            //rlutil::setColor(rlutil::RED);
            cout << "ESTADO: INACTIVO" << endl;
        }
    }
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

void mostrarViajes()
{
    FILE *p;
    Viajes reg;
    p = fopen("cargarViaje.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO.";
        return;
    }
    while (fread(&reg, sizeof(Viajes), 1, p) == 1)
    {
        mostrarViaje(reg);
    }
    fclose(p);
}

void mostrarViajeID()
{
    int id;
    Viajes reg;
    cout << "INGRESE EL ID DEL VIAJE: ";
    cin>>id;
    cout << "---------------------" << endl;
    FILE *p;
    p = fopen("cargarViaje.dat", "rb");
    if (p == NULL)
        return;
    while (fread(&reg, sizeof(reg), 1, p) == 1)
    {
        if (id == reg.idviaje)
        {
            cout << endl
                 << "Encontrado" << endl;
            mostrarViaje(reg);
        }
    }
    fclose(p);
}
