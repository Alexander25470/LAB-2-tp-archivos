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

void menuChoferes(string textoChoferes[],int opciones){


switch(menu(textoChoferes,opciones)){
case '1':
    system("cls");
    cout<<"elegiste nuevo chofer";
    break;
case '2':
    system("cls");
    cout<<"elegiste modificar chofer";
    break;
case '3':
    system("cls");
    cout<<"elegir listar chofer";
    break;
case '4':
    system("cls");
    cout<<"LISTAR TODOS LOS CHOFERES";
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
