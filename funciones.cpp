#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "funciones.h"

Choferes nuevoChofer()
{
    Choferes reg;
    int opc;
    system("cls");
    do{
        cout << "DNI: ";
        cargarCadena(reg.dni, 10);
    }while(buscarNumeroDNI(reg.dni)!=-1);

    cout << "NOMBRE CHOFER   : ";
    cargarCadena(reg.nombre, 50);

    cout << "APELLIDO CHOFER : ";
    cargarCadena(reg.apellido, 50);

    cout << "F. DE INGRESO: " << endl;
    reg.fechaIngreso = cargarFecha(true);
    //--------------------------------------------------
    cin.ignore();
    do{
        cout << "CUIT: ";
        cargarCadena(reg.cuit, 20);
    }while(buscarNumeroCUIT(reg.cuit)!=-1);

    //----------------------------------------------------
    do
    {
        cout << "TIPO REGISTRO: ";
        cin >> reg.tipoReg;
    }while (reg.tipoReg < 0 || reg.tipoReg > 3);
    //----------------------------------------------------

    cout << "FECHA VTO DEL REGISTRO: " << endl;
    reg.vencimientoRegistro = cargarFecha(false);

    cout << "TELEFONO: ";
    cin.ignore();
    cargarCadena(reg.telefono, 15);
    cout << "PROPIETARIO: " << endl;
    cout << "1) SI.";
    cout << "2) NO.";
    cout << endl;

    opc = getch();
    switch (opc)
    {
    case 1:
        reg.esPropietario = true;
        break;
    case 2:
        reg.esPropietario = false;
        break;
    }
    reg.estado = true;
    return reg;
}

bool leerChofer(int pos, Choferes *pReg)
{
    FILE *p;
    bool leyo;
    p = fopen("cargarChofer.dat", "rb");
    if (p == NULL)
        return false;
    fseek(p, pos * sizeof(Choferes), 0);
    leyo = fread(pReg, sizeof(Choferes), 1, p);
    fclose(p);
    return leyo;
}

bool grabarChofer(Choferes reg)
{
    FILE *p;
    bool write;
    p = fopen("cargarChofer.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO";
        return 0;
    }
    write = fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return write;
}

void cargarChofer()
{
    Choferes reg;
    int pos;
    bool grabo;
    reg = nuevoChofer();
    pos = buscarNumeroDNI(reg.dni);
    if (pos != -1)
    {
        cout << "YA EXISTE EL DNI" << endl;
        system("pause");
        return;
    }
    grabo = grabarChofer(reg);
    if (grabo == true)
    {
        cout << "EL REGISTRO SE REALIZO CON EXITO." << endl;
    }
    else
    {
        cout << "ERROR AL GRABAR REGISTRO. " << endl;
    }
}

///BUSCO NUMERO ID PARA VERIFICAR SI YA EXISTE.
int buscarNumeroDNI(char *dni)
{
    FILE *p;
    Choferes reg;
    int pos = 0;
    p = fopen("cargarChofer.dat", "rb");
    if (p == NULL)
        return -1;
    while (fread(&reg, sizeof(reg), 1, p) == 1)
    {
        if (strcmp(dni, reg.dni) == 0)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

int buscarNumeroCUIT(char *cuit)
{
    FILE *p;
    Choferes reg;
    int pos = 0;
    p = fopen("cargarChofer.dat", "rb");
    if (p == NULL)
        return -1;
    while (fread(&reg, sizeof(reg), 1, p) == 1)
    {
        if (strcmp(cuit, reg.cuit) == 0)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

///FUNCION PARA MOSTRAR TODOS LOS CAMPOS
void mostrarChofer(Choferes reg)
{
    if(reg.estado){
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "DNI: ";
        cout << reg.dni << endl;
        cout << "NOMBRE CHOFER   : ";
        cout << reg.nombre << endl;
        cout << "APELLIDO CHOFER : ";
        cout << reg.apellido << endl;
        cout << endl
            << "F. DE INGRESO: " << endl;
        cout << reg.fechaIngreso.dia << " / ";
        cout << reg.fechaIngreso.mes << " / ";
        cout << reg.fechaIngreso.anio << endl;
        cout << endl
            << "CUIT: ";
        cout << reg.cuit << endl;
        cout << "TIPO REGISTRO: ";
        cout << reg.tipoReg << endl;
        cout << endl
            << "FECHA VTO DEL REGISTRO: " << endl;
        cout << reg.vencimientoRegistro.dia << " / ";
        cout << reg.vencimientoRegistro.mes << " / ";
        cout << reg.vencimientoRegistro.anio << endl;
        cout << endl
            << "TELEFONO: ";
        cout << reg.telefono << endl;
        cout << "PROPIETARIO: ";
        if (reg.esPropietario == 1)
        {
            cout << "SI." << endl;
        }
        else
        {
            cout << "NO." << endl;
        }
        if (reg.estado == true)
        {
            //rlutil::setColor(rlutil::GREEN);
            cout << "ACTIVO" << endl;
        }
        else
        {
            if (reg.estado == false)
            {
                //rlutil::setColor(rlutil::RED);
                cout << "DADO DE BAJA" << endl;
            }
        }
        //rlutil::setColor(rlutil::WHITE);
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl
            << endl;
    }
}

///FUNCION PARA LEER EL ARCHIVO Y MOSTRAR USUARIOS.
void mostrarChoferes()
{
    FILE *p;
    Choferes reg;
    p = fopen("cargarChofer.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO.";
        return;
    }
    while (fread(&reg, sizeof(Choferes), 1, p) == 1)
    {
        mostrarChofer(reg);
    }
    fclose(p);
    system("pause");
}

void mostrar_por_dni()
{
    char nDNI[10];
    Choferes reg;
    cout << "INGRESE EL DNI: ";
    //cin.ignore();
    cin.getline(nDNI, 10);
    cout << "---------------------" << endl;
    FILE *p;
    p = fopen("cargarChofer.dat", "rb");
    if (p == NULL)
        return;
    while (fread(&reg, sizeof(reg), 1, p) == 1)
    {
        if (strcmp(nDNI, reg.dni) == 0)
        {
            cout << endl
                 << "Encontrado" << endl;
                 if(reg.estado){
                    mostrarChofer(reg);
                    system("pause");
                }else{
                    system("cls");
                    cout<<"CHOFER DADO DE BAJA"<<endl;
                    system("pause");
                }
        }
    }
    fclose(p);
}
///GRABA EN EL ARCHIVO EL REGISTRO QUE LE PASAMOS.
bool modificarRegistroChofer(Choferes reg, int pos)
{
    FILE *p;
    bool escribio;
    p = fopen("cargarChofer.dat", "rb+");
    if (p == NULL)
        return false;
    fseek(p, sizeof reg * pos, 0);
    escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

void modificarChofer()
{
    char dni[10];
    Choferes reg;
    int pos;
    ///PEDIR INGRESO MATERIA A ELIMINAR
    cout << "INGRESE EL DNI DEL CHOFER A MODIFICAR: ";
    //cin.ignore();
    cin.getline(dni, 10);
    ///VER SI EXISTE.
    pos = buscarNumeroDNI(dni);
    /// SI NO EXISTE INFORMAR Y TERMINAR
    if (pos == -1)
    {
        cout << "NO EXISTE EL CHOFER" << endl;
        return;
    }

    if (leerChofer(pos, &reg) == false)
    {
        cout << "NO SE PUDO LEER EL REGISTRO" << endl;
        return;
    }

    cout << "ingrese la nueva fecha de vencimiento: " << endl;

    reg.vencimientoRegistro = cargarFecha(false);

    /*cout << "ingrese el nuevo dia";
    cin >> reg.vencimientoRegistro.dia;
    cout << "ingrese el nuevo mes";
    cin >> reg.vencimientoRegistro.mes;
    cout << "ingrese el nuevo anio";
    cin >> reg.vencimientoRegistro.anio;*/

    if (modificarRegistroChofer(reg, pos) == true)
    {
        cout << "MODIFICACION REALIZADA" << endl;
    }
    else
        cout << "NO SE PUDO HACER LA MODIFICACION" << endl;
}

void bajaChofer()
{
    char dni[10];
    Choferes reg;
    int asd;
    int pos;
    ///PEDIR INGRESO MATERIA A ELIMINAR
    cout << "INGRESE EL DNI DEL CHOFER QUE DESEA DAR DE BAJA: ";
    //cin.ignore();
    cin.getline(dni, 10);
    ///VER SI EXISTE.
    pos = buscarNumeroDNI(dni);
    /// SI NO EXISTE INFORMAR Y TERMINAR
    if (pos == -1)
    {
        cout << "NO EXISTE EL CHOFER" << endl;
        return;
    }

    if (leerChofer(pos, &reg) == false)
    {
        cout << "NO SE PUDO LEER EL REGISTRO" << endl;
        return;
    }
    cout << "Esta seguro de que desea dar de baja el chofer? " << endl;
    cout<<"S >> SI"<<endl;
    cout<<"N >> NO"<< endl;
    asd=getch();
    while(!(asd == 115 || asd == 83 || asd == 110 || asd == 78)){
        cout<<"ELIJA ENTRE S para si, o N para no"<<endl;
        asd=getch();
    }
    if(asd=='s' || asd=='S'){
        reg.estado = false;
        if (modificarRegistroChofer(reg, pos) == true)
        {
            cout << "DADO DE BAJA EXITOSAMENTE" << endl;
        }
        else
            cout << "NO SE PUDO DAR DE BAJA" << endl;
    }else{
        cout<<"NO SE DIO DE BAJA"<<endl;

    }
    system("pause");
}

/*void bajaTotal(){
    Choferes reg;
    if(bajaChofer(reg)==true){
        cout<<"SE DIO LA BAJA CORRECTAMENTE.";
    }else{
        cout<<"EL ID INGRESADO NO EXISTE.";
    }

}*/

/*Funcion para verificar que la cadena no este vacia.(strlen indica la cantidad de caracteres en la cadena)*/

void cargarCadena(char *cadena, int tam, bool pv)
{
    if (pv)
    {
        //cout<<"ingrese la cadena";
        cin.getline(cadena, tam);
        cargarCadena(cadena, tam, false);
    }
    else
    {
        if (!strlen(cadena))
        {
            cout << "El dato no puede estar vacio" << endl;
            cout << "Vuelva a ingresar el dato" << endl;
            cin.getline(cadena, tam);
            cargarCadena(cadena, tam, false);
        }
    }
}

Fecha cargarFecha(bool registro)
{
    int horas = 0;
    int horasIngresadas = 0;
    Fecha fecha;
    time_t tiempo;
    char cad[80];
    tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    int dia = tmPtr->tm_mday;
    horas += dia * 24;
    int mes = tmPtr->tm_mon + 1;
    horas += mes * 730;
    int anio = 1900 + tmPtr->tm_year;
    horas += anio * 8760;

    cout << "FECHA: " << endl;
    cout << "DIA: ";
    cin >> fecha.dia;
    cout << "MES: ";
    cin >> fecha.mes;
    cout << "ANIO: ";
    cin >> fecha.anio;

    //Array que almacenara los dias que tiene cada mes (si el ano es bisiesto, sumaremos +1 al febrero)
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //Comprobar si el ano es bisiesto y anadir dia en febrero en caso afirmativo
    if ((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0)
        dias_mes[1]++;

    //Comprobar que el mes sea valido
    if (fecha.mes < 1 || fecha.mes > 12)
    {
        cout << "mes invalido" << endl;
        fecha = cargarFecha(registro);
    }
    if (fecha.dia <= 0 || fecha.dia > dias_mes[fecha.mes])
    {
        cout << "dia invalido" << endl;
        fecha = cargarFecha(registro);
    }

    //Si ha pasado todas estas condiciones, la fecha es valida

    horasIngresadas += fecha.anio * 8760;
    horasIngresadas += fecha.mes * 730;
    horasIngresadas += fecha.dia * 24;

    if (registro)
    {
        if (horasIngresadas <= horas)
        {
            cout << "fecha registro valida" << endl;
            return fecha;
        }
        else
        {
            cout << "Fecha registro incorrecta, intente nuevamente" << endl;
            fecha = cargarFecha(registro);
        }
    }
    else
    {
        if (horasIngresadas > horas)
        {
            cout << "fecha vencimiento valida"<<endl;
            return fecha;
        }
        else
        {
            cout << "Fecha vto incorrecta, intente nuevamente" << endl;
            fecha = cargarFecha(registro);
        }
    }
    return fecha;
}

void crearBackUp(){
    FILE *p;
    FILE *pb;
    Choferes reg;
    p = fopen("cargarChofer.dat", "rb");
    pb = fopen("cargarChofer.bkp", "wb+");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO";
        return;
    }
    while (fread(&reg, sizeof(Choferes), 1, p) == 1)
    {
        fwrite(&reg, sizeof(reg), 1, pb);
    }
    fclose(p);
    fclose(pb);
}


void restaurarBackUp(){
    FILE *p;
    FILE *pb;
    Choferes reg;
    p = fopen("cargarChofer.bkp", "rb");
    pb = fopen("cargarChofer.dat", "wb+");
    if (p == NULL)
    {
        cout << "ERROR DE ARCHIVO";
        return;
    }
    while (fread(&reg, sizeof(Choferes), 1, p) == 1)
    {
        fwrite(&reg, sizeof(reg), 1, pb);
    }
    fclose(p);
    fclose(pb);
}


