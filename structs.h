#pragma once

struct Fecha{
 int dia, mes, anio;
};

struct choferes{
    char dni[10];
    char apellido[50];
    char nombre[50];
    Fecha fechaIngreso;
    char cuit[20];
    int tipoReg;
    Fecha vencimientoRegistro;
    char telefono[15];
    bool esPropietario;
    bool estado;
};
