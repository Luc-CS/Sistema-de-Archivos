#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
void menuReportes()
{
    bool salir=true;

    while(salir==true)
    {
        system("cls");
        int opc;
        cout << "--------------------------" << endl;
        cout << "MENU REPORTES" << endl;
        cout << "1-MOSTRAR JUGADORES EN UN DEPORTE" << endl;
        cout << "2-PUNOTO B" << endl;
        cout << "3-PUNOTO C" << endl;
        cout << "4-PUNOTO 1 (PARCIAL)" << endl;
        cout << "5-PUNOTO 2 (PARCIAL)" << endl;
        cout << "0-ATRAS" << endl;
        cout << "--------------------------" << endl;
        cout << "SELECIONE UNA OPCION: ";
        cin  >> opc;

        switch(opc)
        {

        case 1:
            PUNTO_A();
        break;
        case 2:
            PUNTOB();
            break;
        case 3:
            puntoC();
            break;
        case 4:
            ListarCantJugadoresInscriptos();
            break;
        case 5:
            ArchivoDeporteMas50Inscriptos();
            break;
        case 0:
        {
            salir=false;
        }


        break;

        default:
            cout << "LA OPCION NO ES VALIDA" << endl;


        }
    }
}



#endif // MENUREPORTES_H_INCLUDED
