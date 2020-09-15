#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "funciones.h"



Choferes nuevoChofer(){
    Choferes reg;
    int opc;
    system("cls");
    cout<<"DNI: ";
    //cin.ignore();
    cargarCadena(reg.dni,10);
    cout<<"NOMBRE CHOFE   : ";
    //cin.ignore();
    cargarCadena(reg.nombre,50);
    cout<<"APELLIDO CHOFER : ";
    //cin.ignore();
    cargarCadena(reg.apellido,50);
    cout<<"F. DE INGRESO: "<<endl;
    cout<<"DIA: ";
    cin>>reg.fechaIngreso.dia;
    cout<<"MES: ";
    cin>>reg.fechaIngreso.mes;
    cout<<"ANIO: ";
    cin>>reg.fechaIngreso.anio;
    cout<<"CUIT: ";
    cin.ignore();
    cargarCadena(reg.cuit,20);
    cout<<"TIPO REGISTRO: ";
    cin>>reg.tipoReg;
    cout<<"FECHA VTO DEL REGISTRO: "<<endl;
    cout<<"DIA: ";
    cin>>reg.vencimientoRegistro.dia;
    cout<<"MES: ";
    cin>>reg.vencimientoRegistro.mes;
    cout<<"ANIO: ";
    cin>>reg.vencimientoRegistro.anio;
    cout<<"TELEFONO: ";
    cin.ignore();
    cargarCadena(reg.telefono,15);
    cout<<"PROPIETARIO: "<<endl;
    cout<<"1) SI.";
    cout<<"2) NO.";
    cout<<endl;

    opc=getch();
    switch(opc){
        case 1: reg.esPropietario=true;
        break;
        case 2: reg.esPropietario=false;
        break;
    }
    reg.estado=true;
    return reg;
}


bool leerChofer(int pos, Choferes *pReg){
    FILE *p;
    bool leyo;
    p=fopen("cargarChofer.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos*sizeof(Choferes),0);
    leyo=fread(pReg, sizeof(Choferes), 1, p);
    fclose(p);
    return leyo;
}

bool grabarChofer(Choferes reg){
    FILE *p;
    bool write;
    p=fopen("cargarChofer.dat", "ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO";
        return 0;
    }
    write=fwrite(&reg, sizeof(reg), 1, p);
    fclose(p);
    return write;
}

void cargarChofer(){
    Choferes reg;
    int pos;
    bool grabo;
    reg=nuevoChofer();
    pos=buscarNumeroDNI(reg.dni);
    if(pos!=-1){
        cout<<"YA EXISTE EL DNI"<<endl;
        system("pause");
        return;
    }
    grabo=grabarChofer(reg);
    if(grabo==true){
        cout<<"EL REGISTRO SE REALIZO CON EXITO."<<endl;
    }
    else{
        cout<<"ERROR AL GRABAR REGISTRO. "<<endl;
    }
}


///BUSCO NUMERO ID PARA VERIFICAR SI YA EXISTE.
int buscarNumeroDNI(char *dni){
    FILE *p;
    Choferes reg;
    int pos=0;
    p=fopen("cargarChofer.dat", "rb");
    if(p==NULL) return -1;
    while(fread(&reg, sizeof(reg), 1, p)==1){
            if(strcmp(dni,reg.dni)==0){
                fclose(p);
                return pos;
            }
            pos++;

        }
    fclose(p);
    return -1;
}
///FUNCION PARA MOSTRAR TODOS LOS CAMPOS
void mostrarChofer(Choferes reg){
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"DNI: ";
    cout<<reg.dni<<endl;
    cout<<"NOMBRE CHOFER   : ";
    cout<<reg.nombre<<endl;
    cout<<"APELLIDO CHOFER : ";
    cout<<reg.apellido<<endl;
    cout<<endl<<"F. DE INGRESO: "<<endl;
    cout<<"DIA: ";
    cout<<reg.fechaIngreso.dia<<endl;
    cout<<"MES: ";
    cout<<reg.fechaIngreso.mes<<endl;
    cout<<"ANIO: ";
    cout<<reg.fechaIngreso.anio<<endl;
    cout<<endl<<"CUIT: ";
    cout<<reg.cuit<<endl;
    cout<<"TIPO REGISTRO: ";
    cout<<reg.tipoReg<<endl;
    cout<<endl<<"FECHA VTO DEL REGISTRO: "<<endl;
    cout<<"DIA: ";
    cout<<reg.vencimientoRegistro.dia<<endl;
    cout<<"MES: ";
    cout<<reg.vencimientoRegistro.mes<<endl;
    cout<<"ANIO: ";
    cout<<reg.vencimientoRegistro.anio<<endl;
    cout<<endl<<"TELEFONO: ";
    cout<<reg.telefono<<endl;
    cout<<"PROPIETARIO: ";
    if(reg.esPropietario==1){
        cout<<"SI."<<endl;
    }else{
        cout<<"NO."<<endl;
    }
    if(reg.estado==true){
        //rlutil::setColor(rlutil::GREEN);
        cout<<"ACTIVO"<<endl;
    }else
    {
        if(reg.estado==false){
            //rlutil::setColor(rlutil::RED);
            cout<<"DADO DE BAJA"<<endl;
        }
    }
    //rlutil::setColor(rlutil::WHITE);
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
}

///FUNCION PARA LEER EL ARCHIVO Y MOSTRAR USUARIOS.
void mostrarChoferes(){
    FILE *p;
    Choferes reg;
    p=fopen("cargarChofer.dat", "rb");
    if(p==NULL) {
        cout<<"ERROR DE ARCHIVO.";
        return;
    }
    while(fread(&reg, sizeof(Choferes), 1, p)==1){
            mostrarChofer(reg);
        }
    fclose(p);
    system("pause");
}

void mostrar_por_dni(){
    char nDNI[10];
    Choferes reg;
    cout<<"INGRESE EL DNI: ";
    //cin.ignore();
    cin.getline(nDNI,10);
    cout<<"---------------------"<<endl;
    FILE *p;
    p=fopen("cargarChofer.dat", "rb");
    if(p==NULL) return;
    while(fread(&reg, sizeof(reg), 1, p)==1){
        if(strcmp(nDNI,reg.dni)==0){
                cout<<endl<<"Encontrado"<<endl;
                mostrarChofer(reg);
        }
        }
    fclose(p);

}
///GRABA EN EL ARCHIVO EL REGISTRO QUE LE PASAMOS.
bool modificarRegistroChofer(Choferes reg,int pos){
    FILE *p;
    bool escribio;
    p=fopen("cargarChofer.dat", "rb+");
    if(p==NULL) return false;
    fseek(p, sizeof reg*pos,0);
    escribio=fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;

}

void modificarChofer(){
    char dni[10];
    Choferes reg;
    int pos;
///PEDIR INGRESO MATERIA A ELIMINAR
    cout<<"INGRESE EL DNI DEL CHOFER A MODIFICAR: ";
    //cin.ignore();
    cin.getline(dni,10);
///VER SI EXISTE.
    pos=buscarNumeroDNI(dni);
/// SI NO EXISTE INFORMAR Y TERMINAR
    if(pos==-1){
        cout<<"NO EXISTE EL CHOFER"<<endl;
        return;
    }

    if(leerChofer(pos, &reg)==false){
        cout<<"NO SE PUDO LEER EL REGISTRO"<<endl;
        return;
    }

    cout<<"ingrese la nueva fecha de vencimiento: "<<endl;

    cout<<"ingrese el nuevo dia";
    cin>>reg.vencimientoRegistro.dia;
    cout<<"ingrese el nuevo mes";
    cin>>reg.vencimientoRegistro.mes;
    cout<<"ingrese el nuevo anio";
    cin>>reg.vencimientoRegistro.anio;

    if(modificarRegistroChofer(reg,pos)==true){
        cout<<"MODIFICACION REALIZADA"<<endl;
    }
    else cout<<"NO SE PUDO HACER LA MODIFICACION"<<endl;
}

void bajaChofer(){
    char dni[10];
    Choferes reg;
    char asd;
    int pos;
///PEDIR INGRESO MATERIA A ELIMINAR
    cout<<"INGRESE EL DNI DEL CHOFER QUE DESEA DAR DE BAJA: ";
    //cin.ignore();
    cin.getline(dni,10);
///VER SI EXISTE.
    pos=buscarNumeroDNI(dni);
/// SI NO EXISTE INFORMAR Y TERMINAR
    if(pos==-1){
        cout<<"NO EXISTE EL CHOFER"<<endl;
        return;
    }

    if(leerChofer(pos, &reg)==false){
        cout<<"NO SE PUDO LEER EL REGISTRO"<<endl;
        return;
    }

    cout<<"Est� seguro de que desea dar de baja el chofer? "<<endl;
    cin>>asd;
    cout<<"Bueno, se da de baja igual";
    system("pause");
    reg.estado=false;


    if(modificarRegistroChofer(reg,pos)==true){
        cout<<"DADO DE BAJA EXITOSAMENTE"<<endl;
    }
    else cout<<"NO SE PUDO DAR DE BAJA"<<endl;
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

void cargarCadena(char *cadena,int tam, bool pv){
    if(pv){
        //cout<<"ingrese la cadena";
        cin.getline(cadena,tam);
        cargarCadena(cadena,tam,false);
    }else{
        if(!strlen(cadena)){
            cout<<"El dato no puede estar vacio"<<endl;
            cout<<"Vuelva a ingresar el dato"<<endl;
            cin.getline(cadena,tam);
            cargarCadena(cadena,tam,false);
        }
    }
}
