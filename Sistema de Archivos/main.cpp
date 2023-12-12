#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
   using namespace std;
int limpiarArchivo(const char *n);
#include "CLASS_FECHA.h"
#include "CargarCadena.h"
#include "CLASS_DEPORTES.h"
#include "CLASS_ARCHIVO_DEPORTES.h"
#include "CLASS_JUGADOR.h"
#include "CLASS_ARCHIVO_JUGADORES.h"
#include "FUNCIONES_CONFIGURACION.h"
#include "Reportes.h"
#include "DatosInicio.h"
#include "MenuDeportes.h"
#include "Menu_Jugadores.h"
#include "MenuConfiguracion.h"
#include "menuReportes.h"
#include "Dynamic.h"
int limpiarArchivo(const char *n)
{
    FILE *archi;
    archi=fopen(n,"wb");
    if(n==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return -1;
    }
    fclose(archi);
    return 1;
}
///COPIA TODO LO QUE ESTA EN EL ARCHIVO ORIGINAL
///AL BJF
///HAGO UNA LIMPIEZA DEL ARCHIVO ORIGINAL
///Y COPIA TODO LO QUE TENIA AL ARCHIVO .BJF A ARCHIVO ORIGINAL .DAT


int main(){

    while(true)
        {
            system("cls");
            int opc;
        cout << "--------------------------" << endl;
        cout << "MENU PRINCIPAL" << endl;
        cout << "1-MENU JUGADORES" << endl;
        cout << "2-MENU DEPORTES" << endl;
        cout << "3-REPORTES" << endl;
        cout << "4-CONFIGURACION" << endl;
        cout << "0-SALIR DEL PROGRAMA" << endl;
        cout << "--------------------------" << endl;
        cout << "SELECIONE UNA OPCION: ";
        cin  >> opc;

        switch(opc){

   case 1:
       menuJugadores();
    break;
   case 2:
       menuDeportes();
    break;
    case 3:
      menuReportes();
    break;
   case 4:
       menuConfiguracion();
    break;
   /*case 5:
       {
           Jugador *regJug;
           ArchivoJugadores listJUG;
           int tam=listJUG.contadorRegistros();
           regJug=new Jugador[tam];
           CargarDynamicJug(regJug,tam,listJUG);
           OrdenarDynamicJug(regJug,tam);
           MostrarDynamicJug(regJug,tam);
       }
    //VectorDynamicJug();
        break;*/
   case 0:

    return 0;

       default:;
    cout << "LA OPCION NO ES VALIDA" << endl;

    system("pause");
        }

}
}


