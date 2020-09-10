#include "menu.h"
#include "structs.h"
int main()
{
    system("mode con: cols=121 lines=31");

    string menuPpal[8];
    menuPpal[0]="MENU PRINCIPAL";
    menuPpal[1]="---------------------------------------------------------------------------------------------------------------------";
    menuPpal[2]="1) Choferes";
    menuPpal[3]="2) Viajes";
    menuPpal[4]="3) Reportes";
    menuPpal[5]="4) Configuracion";
    menuPpal[6]="---------------------------------------------------------------------------------------------------------------------";
    menuPpal[7]="0) Salir del del Programa";

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



switch(menu(menuPpal,8)){
case '1':
    menuChoferes(textoChoferes,9);
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
return 0;
}
