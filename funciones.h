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

///PROTOTIPOS VIAJES
int id_automatico(Viajes reg);
Viajes nuevoViaje();
bool grabarViaje(Viajes reg);
void cargarViaje();
void mostrarViaje(Viajes reg);
void mostrarViajes();
void mostrarViajeID();
void bajaViaje();
int buscarNumeroID(int id);
bool leerViaje(int pos, Viajes *pReg);
bool modificarRegistroViaje(Viajes reg, int pos);


///PROTOTIPOS BACKUPS
void crearBackUp();///CREA BACK UP CHOFERES
void restaurarBackUp();///RESTAURA BACK UP CHOFERES
void crearBackUpViajes();///CREA BACKUP VIAJES
void restaurarBackUpViajes();/// RESTAURA BACK UP VIAJES
void restaurarBackUpInicioViajes();///RESTAURA BACK UP INICIO VIAJES
void restaurarBackUpInicioChof();/// RESTAURAR BACK UP INICIO CHOFERES
///FIN PROTOTIPOS
