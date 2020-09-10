#pragma once

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;



void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
void pintar_bordes() {
    for (int i = 1; i < 120; i++) {
        gotoxy(i, 1); printf("%c", 205);
        gotoxy(i, 30); printf("%c", 205);
    };
    for (int i = 1; i < 30; i++) {
        gotoxy(1, i); printf("%c", 186);
        gotoxy(119, i); printf("%c", 186);
    };
    gotoxy(1, 1); printf("%c", 201);
    gotoxy(1, 30); printf("%c", 200);
    gotoxy(119, 1); printf("%c", 187);
    gotoxy(119, 30); printf("%c", 188);
};
char menu(string cosito[], int opciones) {
    system("cls");
    int Y;
    pintar_bordes();
    for (int i = 0; i < opciones; i++)
    {
        Y = (i * 2) + 2;
        gotoxy(2, (i * 2) + 2); cout << cosito[i]; //escribe el menu
    }
            cout<<endl;
            char tecla = getch();//obtiene el valor de la tecla pulsada
            return tecla;
}

void menuChoferes(){

    string textoChoferes[9];
    textoChoferes[0]="MENU CHOFERES";
    textoChoferes[1]="---------------------------------------------------------------------------------------------------------------------";
    textoChoferes[2]="1) Nuevo chofer";
    textoChoferes[3]="2) Modificar chofer";
    textoChoferes[4]="3) Listar choferes por DNI";
    textoChoferes[5]="4) Listar todos los choferes";
    textoChoferes[6]="5) Eliminar chofer";
    textoChoferes[7]="---------------------------------------------------------------------------------------------------------------------";
    textoChoferes[8]="0) Salir del del Programa";

switch(menu(textoChoferes,9)){
    case '1':
        system("cls");
        cargarChofer();
        break;
    case '2':
        system("cls");
        cout<<"elegiste modificar chofer";
        break;
    case '3':
        system("cls");
        mostrar_por_dni();
        break;
    case '4':
        system("cls");
        mostrarChoferes();
        break;
    case '5':
        system("cls");
        cout<<"eleminar chofer";
        break;
    case '0':
        system("exit");
        break;
    }
}

void menuP(){
        string textoMenuPpal[8];
    textoMenuPpal[0]="MENU PRINCIPAL";
    textoMenuPpal[1]="---------------------------------------------------------------------------------------------------------------------";
    textoMenuPpal[2]="1) Choferes";
    textoMenuPpal[3]="2) Viajes";
    textoMenuPpal[4]="3) Reportes";
    textoMenuPpal[5]="4) Configuracion";
    textoMenuPpal[6]="---------------------------------------------------------------------------------------------------------------------";
    textoMenuPpal[7]="0) Salir del del Programa";


    switch(menu(textoMenuPpal,8)){
        case '1':
            menuChoferes();
            break;
        case '2':
            //algo
            break;
        case '3':
            //algo
            break;
        case '4':
            //algo
            break;
        case '0':
            system("exit");
            break;
    }
}
