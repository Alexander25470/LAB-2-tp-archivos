#pragma once
#include "structs.h"
///PROTOTIPOS
Fecha cargarFecha(bool registro);
void cargarCadena(char *cadena,int tam, bool pv=true);
Choferes nuevoChofer(Choferes reg);
int buscarNumeroCUIT(char *cuit);
void cargarChofer();
bool leerChofer(int pos, Choferes *pReg);
bool grabarChofer(Choferes reg);
void modificarChofer();
void mostrar_por_dni();
void bajaChofer();
int buscarNumeroDNI(char *nDNI);
void mostrarChofer(Choferes reg);
void mostrarChoferes();

//PROTOTIPOS VIAJES
int id_automatico(Viajes reg);
Viajes nuevoViaje();
bool grabarViaje(Viajes reg);
void cargarViaje();
void mostrarViaje(Viajes reg);
void mostrarViajes();
void mostrarViajeID();
///FIN PROTOTIPOS
