#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
///PROTOTIPOS
void cargarUser();
Choferes nuevoChofer(Choferes reg);
bool grabarUser(Choferes reg);
void cargarUser();
int buscarNumeroDNI(char *nDNI);
void mostrarChofer(Choferes reg);
void mostrarChoferes();

///FIN PROTOTIPOS

Choferes nuevoChofer(Choferes reg){
    int opc;
    system("cls");
    cout<<"DNI: ";
    cin>>reg.dni;
    cin.ignore();
    cout<<"NOMBRE CHOFE   : ";
    cin.getline(reg.nombre,50);
    cout<<"APELLIDO CHOFER : ";
    cin.getline(reg.apellido,50);
    cout<<"F. DE INGRESO: "<<endl;
    cout<<"DIA: ";
    cin>>reg.fechaIngreso.dia;
    cout<<"MES: ";
    cin>>reg.fechaIngreso.mes;
    cout<<"ANIO: ";
    cin>>reg.fechaIngreso.anio;
    cin.ignore();
    cout<<"CUIT: ";
    cin.getline(reg.cuit,20);
    cout<<"TIPO REGISTRO: ";
    cin>>reg.tipoReg;
    cout<<"FECHA VTO DEL REGISTRO: "<<endl;
    cout<<"DIA: ";
    cin>>reg.vencimientoRegistro.dia;
    cout<<"MES: ";
    cin>>reg.vencimientoRegistro.mes;
    cout<<"ANIO: ";
    cin>>reg.vencimientoRegistro.anio;
    cin.ignore();
    cout<<"TELEFONO: ";
    cin.getline(reg.telefono,15);
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
    reg=nuevoChofer(reg);
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

int buscarNumeroDNI(char *nDNI){
    FILE *p;
    Choferes reg;
    int pos=0;
    int iguales;
    p=fopen("cargarChofer.dat", "rb");
    if(p==NULL) return -1;
    while(fread(&reg, sizeof(reg), 1, p)==1){
            iguales=0;
            for(int d=0; d<10;d++){
                if(nDNI[d]==reg.dni[d])
                {
                    iguales++;
                }
            }
            if(iguales==10){
                fclose(p);
                return pos;
            }
            pos++;
        }
    fclose(p);
    return -1;
}

///BUSCO NUMERO ID PARA VERIFICAR SI YA EXISTE.
int buscarNumeroID(char *dni){
    FILE *p;
    Choferes reg;
    int pos=0;
    p=fopen("cargarUser.dat", "rb");
    if(p==NULL) return -1;
    while(fread(&reg, sizeof(reg), 1, p)==1){
            if(dni==reg.dni){
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
    cout<<"DNI: ";
    cout<<reg.dni<<endl;
    cout<<"NOMBRE CHOFER   : ";
    cout<<reg.nombre<<endl;
    cout<<"APELLIDO CHOFER : ";
    cout<<reg.apellido<<endl;
    cout<<"F. DE INGRESO: "<<endl;
    cout<<"DIA: ";
    cout<<reg.fechaIngreso.dia<<endl;
    cout<<"MES: ";
    cout<<reg.fechaIngreso.mes<<endl;
    cout<<"ANIO: ";
    cout<<reg.fechaIngreso.anio<<endl;
    cout<<"CUIT: ";
    cout<<reg.cuit<<endl;
    cout<<"TIPO REGISTRO: ";
    cout<<reg.tipoReg<<endl;
    cout<<"FECHA VTO DEL REGISTRO: "<<endl;
    cout<<"DIA: ";
    cout<<reg.vencimientoRegistro.dia<<endl;
    cout<<"MES: ";
    cout<<reg.vencimientoRegistro.mes<<endl;
    cout<<"ANIO: ";
    cout<<reg.vencimientoRegistro.anio<<endl;
    cout<<"TELEFONO: ";
    cout<<reg.telefono;
    cout<<"PROPIETARIO: "<<endl;
    if(reg.esPropietario==1){
        cout<<"ES PROPIETARIO."<<endl;
    }else{
        cout<<"NO ES PROPIETARIO."<<endl;
    }
    if(reg.estado==true){
        //rlutil::setColor(rlutil::GREEN);
        cout<<"ACTIVO"<<endl;
    }else
    {
        if(reg.estado==false){
            //rlutil::setColor(rlutil::RED);
            cout<<"INACTIVO"<<endl;
        }
    }
    //rlutil::setColor(rlutil::WHITE);
    cout<<"-----------------------"<<endl<<endl;
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
}

void mostrar_por_dni(){
    char nDNI[10];
    Choferes reg;
    int iguales;
    cout<<"INGRESE EL DNI: ";
    cin>>nDNI[10];
    cout<<"---------------------"<<endl;
    FILE *p;
    p=fopen("cargarChofer.dat", "rb");
    if(p==NULL) return;
    while(fread(&reg, sizeof(reg), 1, p)==1){
        iguales=0;
        for(int d=0; d<10;d++){
                if(nDNI[d]==reg.dni[d])
                {
                    iguales++;
                }
            }
            system("pause");
            if(iguales==10){
                mostrarChofer(reg);
            }
        }
    fclose(p);

}

/*Funcion para verificar que la cadena no este vacia.(strlen indica la cantidad de caracteres en la cadena)*/
/*char verificar_caracteres(char vec[],int tam){

    if(strlen(vec)>0) {
        return vec[tam];

            else
            {
              cout<<"Ingrese un dato correcto la concha de la hermana de Kloster";
              cin>>vec;
              verificar_caracteres(vec);
              return vec[tam];
            }




}*/
