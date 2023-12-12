#ifndef MENUDEPORTES_H_INCLUDED
#define MENUDEPORTES_H_INCLUDED

 void menuDeportes(){
     bool salir=true;
     ArchivoDeportes ListaDeportes;
 while(salir==true)
        {
            system("cls");
            int opc;
        cout << "--------------------------" << endl;
        cout << "MENU DEPORTES" << endl;
        cout << "1-AGREGAR DEPORTE" << endl;
        cout << "2-LISTAR POR ID" << endl;
        cout << "3-LISTAR TODO" << endl;
        cout << "4-MODIFICAR ANIO DE ORIGEN" << endl;
        cout << "5-ELIMINAR REGISTRO" << endl;
        cout << "0-VOLVER AL MENU PRINCIPAL" << endl;
        cout << "--------------------------" << endl;
        cout << "SELECIONE UNA OPCION: ";
        cin  >> opc;

        switch(opc){

   case 1:
       {
           Deporte pre;
           pre.Cargar();
           if(ListaDeportes.AgregarDeporte(pre)==1){
                cout<<"FUE REGISTRADO EXITOSAMENTE"<<endl;
           system("pause");
           }
       }
    break;
   case 2:
       ListaDeportes.ListarID();
    break;
    case 3:
        ListaDeportes.ListarTodo();
    break;
   case 4:
       ListaDeportes.ModificarAnio();
    break;
   case 5:
       ListaDeportes.EliminarRegistro();
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
#endif // MENUDEPORTES_H_INCLUDED
