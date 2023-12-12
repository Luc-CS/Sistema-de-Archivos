#ifndef CLASS_ARCHIVO_JUGADORES_H_INCLUDED
#define CLASS_ARCHIVO_JUGADORES_H_INCLUDED
int verificarID(int numID);
class ArchivoJugadores
{
private:
    char _nom[30];
public:
    ArchivoJugadores(const char *nombre="jugadores.dat")
    {
        strcpy(_nom,nombre);
    }
    ///BUSCA Y DEVUELVE LA POSICION, GUIANDOSE CON EL DNI DEL REGISTRO
    int buscaPorDNI(int dni)
    {
        Jugador regJ1;
        FILE *archi;
        archi=fopen(_nom,"rb");
        if(archi==NULL)
        {
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        int posRegistro=0;
        while(fread(&regJ1,sizeof(Jugador),1,archi)==1)
        {
            if(regJ1.getDNI()==dni)
            {
                fclose(archi);
                return posRegistro;
            }
            posRegistro++;
        }
        return -1;
    }
    int contadorRegistros(){
        int cont=0;
        FILE *archi;
        archi=fopen(_nom,"rb");
        Jugador reg;
        if(archi==NULL)
        {
            cout<<"UPS ALPARECER HUBO UN ERROR";
            system("pause");
            return -1;
        }
        while(fread(&reg,sizeof (Jugador),1,archi)==1){
                cont++;
        }
        fclose(archi);
        return cont;
        }
    ///AGREGA JUGADOR
    int AgregarJugador(Jugador regJ1)
    {
        FILE *archi;
        archi=fopen(_nom,"ab");
        if(archi==NULL)
        {
            cout<<"UPS ALPARECER HUBO UN ERROR";
            return -1;
        }
        int num=buscaPorDNI(regJ1.getDNI());
        if(num>=0){
            cout<<"EL DNI QUE QUIERE REGISTRAR YA ESTA REGISTRADO"<<endl;
            system("pause");
            return -1;
        }
        int vID=verificarID(regJ1.getDeporte());
        if(vID==-1){return -1;}
        int quepaso=fwrite(&regJ1,sizeof (Jugador),1,archi);
        fclose(archi);

        system("cls");
        return quepaso;
    }

    ///ESTA FUNCION DEVUELVE EL OBJETO JUGADOR
    Jugador leerRegistro(int pos)
    {
        Jugador regJ1;
        regJ1.setDNI(-1);
        FILE *archi;
        archi=fopen(_nom,"rb");
        if(archi==NULL)
        {
            cout<<"ERROR DE ARCHIVO"<<endl;
            return regJ1;
        }
        fseek(archi,sizeof regJ1*pos,0);
        int leyo=fread(&regJ1,sizeof(Jugador),1,archi);
        fclose(archi);

        if(leyo==0)
        {
            regJ1.setDNI(-1);
        }
        return regJ1;
    }
///MODIFICAR EL REGISTRO (MANDANDO LA POSICION Y OBJETO CARGADO)
    int modificarRegistro(Jugador regJ1, int pos)
    {
        FILE *archi;
        archi=fopen(_nom,"rb+");///+ le agrega al modo lo que no tiene
        if(archi==NULL)
        {
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return -1;
        }
        fseek(archi,sizeof regJ1*pos,0);
        /*bool quepaso=*/fwrite(&regJ1,sizeof(Jugador),1,archi);
        //cout<<"ESTO PASO: SI 1 Y NO 0"<<quepaso;
        fclose(archi);
        return 1;
    }
    int EliminarRegistroJugador()
    {

        Jugador regJ1;
        int dni;
        cout<<"INGRESE NUMERO DE DNI A BUSCAR"<<endl;
        cin>>dni;
        int pos=buscaPorDNI(dni);
        if(pos==-1)
        {
            cout<<"NO EXISTE EL DNI INGRESADO"<<endl;
            system("pause");
            return -1;
        }
        regJ1=leerRegistro(pos);
        regJ1.setEstado(false);
        modificarRegistro(regJ1,pos);
        cout << "REGISTRO ELIMINADO CON EXITO" << endl;
        system("pause");
        return 1;
    }

    int ModificarFecha(){
        int dni;
        int pos;
        //int dia,mes,anio;
        Jugador regJ1;
        Fecha t1;
        cout<<"Ingresa dni:"<<endl;
        cin>>dni;
        pos=buscaPorDNI(dni);
        if(pos==-1){
            cout<<"NO SE ENCONTRO NUMERO DNI"<<endl;
            return -1;
        }
        t1.Cargar();
        regJ1=leerRegistro(pos);
        regJ1.setFechaInscripcion(t1);
        modificarRegistro(regJ1,pos);
        return 1;
    }


    int ListarJugadores()
    {
        Jugador regJ1;
        FILE *archi;
        archi=fopen(_nom, "rb");
        if(archi==NULL)
        {
            cout<<"UPS ALPARECER HUBO UN ERROR";
            system("pause");
            return -1;
        }
        while(fread(&regJ1,sizeof (Jugador),1,archi)==1)
        {
            if(regJ1.getEstado()==true)
            {
                regJ1.Mostrar();
                cout<<endl;
            }
        }
        fclose(archi);
        system("pause");
        return 1;
    }

    int ListarxDNI()
    {
        int DNI,pos;
        Jugador regJ1;
        cout<<"INGRESAR DNI"<<endl;
        cin>>DNI;
        pos=buscaPorDNI(DNI);
        if(pos==-1){
            cout<<"EL DNI QUE INGRESO NO EXISTE"<<endl;
            system("pause");
            return -1;
        }
        regJ1=leerRegistro(pos);
        regJ1.Mostrar();
        cout<<endl;
        system("pause");
        return 1;
    }
};
///VERIFICA SI EL ID EXISTE EN EL ARCHIVO DEPORTE
int verificarID(int numID){
ArchivoDeportes listaDeport;
int pos=listaDeport.buscaPorID(numID);
if(pos==-1){
    cout<<"EL ID DEL DEPORTE NO EXISTE"<<endl;
    system("pause");
    return -1;
}
else{
    return 1;
}
}


#endif // CLASS_ARCHIVO_JUGADORES_H_INCLUDED
