#ifndef MENU_JUGADORES_H_INCLUDED
#define MENU_JUGADORES_H_INCLUDED
void menuJugadores()
{
    bool salir=true;
    ArchivoJugadores listaJugadores;
    while(salir==true)
    {
        system("cls");
        int opc;
        cout << "--------------------------" << endl;
        cout << "MENU JUGADOR" << endl;
        cout << "1-AGREGAR JUGADOR" << endl;
        cout << "2-LISTAR JUGADOR POR DNI" << endl;
        cout << "3-LISTAR TODOS LOS JUGADORES" << endl;
        cout << "4-MODIFICAR FECHA DE INSCRIPCION" << endl;
        cout << "5-ELIMINAR REGISTRO DE JUGADOR" << endl;
        cout << "0-VOLVER AL MENU PRINCIPAL" << endl;
        cout << "--------------------------" << endl;
        cout << "SELECIONE UNA OPCION: ";
        cin  >> opc;

        switch(opc)
        {

        case 1:
        {
            Jugador jug;
            jug.Cargar();
            if(listaJugadores.AgregarJugador(jug)==1){
                cout<<"FUE REGISTRADO EXITOSAMENTE"<<endl;
                system("pause");
            }
        }
        break;
        case 2:
            listaJugadores.ListarxDNI();



            break;
        case 3:
            listaJugadores.ListarJugadores();
            break;
        case 4:
            listaJugadores.ModificarFecha();
            break;
        case 5:
            listaJugadores.EliminarRegistroJugador();
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


#endif // MENU_JUGADORES_H_INCLUDED
