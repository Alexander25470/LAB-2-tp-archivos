#pragma once

struct Fecha{
 int dia, mes, anio;
};

struct Choferes{
    char dni[10];
    char apellido[50];
    char nombre[50];
    char cuit[20];
    char telefono[15];
    int tipoReg;
    Fecha fechaIngreso;
    Fecha vencimientoRegistro;
    bool esPropietario;
    bool estado;
};

struct Viajes {

    int IDViaje;
    int Hora_sa;
    int IDClien;
    int Calific;
    float Kilom;
    float Impor;
    char Patent;
    bool Estado;
    struct Choferes;
    struct Fecha;

};