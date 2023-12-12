#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

void menuConfiguracion(){
system("cls");
bool confi=true;
int opcion;
while(confi==true){
    cout<<"--------------------------" << endl;
    cout<<"MENU DE CONFIGURACION"<<endl;
    cout<<"1-COPIA DE SEGURIDAD DEL ARCHIVO JUGADORES"<<endl;
    cout<<"2-COPIA DE SEGURIDAD DEL ARCHIVO DEPORTES"<<endl;
    cout<<"3-RESTAURAR EL ARCHIVO JUGADORES"<<endl;
    cout<<"4-RESTAURAR EL ARCHIVO DEPORTES"<<endl;
    cout<<"5-ESTABLECER DATOS DE INICIO"<<endl;
    cout<<"0-VOLVER AL MENU PRINCIPAL"<<endl;
    cout<< "--------------------------" << endl;
    cout<< "SELECIONE UNA OPCION: ";
    cin>>opcion;

    switch(opcion){
    case 1:
        CopSegArchivoJugadores();
        break;
    case 2:
        CopSegArchivoDeportes();
        break;
    case 3:
        ResCopSegArchivoJugadores();
        break;
    case 4:
        ResCopSegArchivoDeportes();
        break;
    case 5:
        {
        EstablecerDatosDeportes();
        EstablecerDatosJugadores();
        system("pause");
        }
        break;
    case 0:
        confi=false;
        break;
    }
}
}
#endif // MENUCONFIGURACION_H_INCLUDED
