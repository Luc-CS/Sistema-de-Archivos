#ifndef CLASS_ARCHIVO_DEPORTES_H_INCLUDED
#define CLASS_ARCHIVO_DEPORTES_H_INCLUDED

class ArchivoDeportes
{
private:
    char _Nombre[30];
public:
    ArchivoDeportes(const char *nom="deportes.dat")
    {
        strcpy(_Nombre,nom);
    }
    Deporte AutomatizacionID(Deporte regDeport){
        FILE *archi;
        archi=fopen(_Nombre,"rb");
        if(archi==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return regDeport;
        }
        int ContID=1;
        Deporte regTemp;
        while(fread(&regTemp,sizeof (Deporte),1,archi)==1)
        {
            ContID++;
        }
        regDeport.setID(ContID);
        fclose(archi);
        return regDeport;
    }

        int contadorRegistros(){
        int cont=0;
        FILE *archi;
        archi=fopen(_Nombre,"rb");
        Deporte reg;
        if(archi==NULL)
        {
            cout<<"UPS ALPARECER HUBO UN ERROR";
            system("pause");
            return -1;
        }
        while(fread(&reg,sizeof (Deporte),1,archi)==1){
                cont++;
        }
        fclose(archi);
        return cont;
        }
    int buscaPorID(int numID)
    {
        Deporte regDeport;
        FILE *archi;
        archi=fopen(_Nombre,"rb");
        if(archi==NULL)
        {
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        int posRegistro=0;
        while(fread(&regDeport,sizeof(Deporte),1,archi)==1)
        {
            if(regDeport.getID()==numID)
            {
                fclose(archi);
                return posRegistro;
            }
            posRegistro++;
        }
        return -1;
    }
    Deporte LeerRegistro(int pos)
    {
        Deporte regDeport;
        regDeport.setID(-1);
        FILE *archi;
        archi = fopen(_Nombre,"rb");
        if(archi==NULL)
        {
            cout<<"ERROR ARCHIVO"<<endl;
            return regDeport;
        }
        fseek(archi,sizeof regDeport*pos,0);
        int leyo=fread(&regDeport,sizeof (Deporte),1,archi);
        fclose(archi);
        if(leyo==0)
        {
            regDeport.setID(-1);
        }
        return regDeport;
    }
    int ModificarArchivo(int pos,Deporte regDeport){
        FILE *archi;
        archi=fopen(_Nombre,"rb+");
        if(archi==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            system("pause");
            return -1;
        }
        fseek(archi,sizeof regDeport*pos,0);
        int quepaso=fwrite(&regDeport,sizeof (Deporte),1,archi);
        fclose(archi);
        return quepaso;
    }

    int AgregarDeporte(Deporte regDeport)
    {
        FILE *archi;
        archi=fopen(_Nombre,"ab");
        if(archi==NULL)
        {
            cout<<"UPS ALPARECER HUBO UN ERROR";
            return -1;
        }
        regDeport=AutomatizacionID(regDeport);
        int quepaso=fwrite(&regDeport,sizeof (Deporte),1,archi);
        fclose(archi);
        system("cls");
        return quepaso;
    }

    int ListarTodo()
    {
        Deporte regDeport;
        FILE *archi;
        archi=fopen(_Nombre, "rb");
        if(archi==NULL)
        {
            cout<<"UPS ALPARECER HUBO UN ERROR";
            system("pause");
            return -1;
        }
        while(fread(&regDeport,sizeof (Deporte),1,archi)==1)
        {
            if(regDeport.getEstado()==true)
            {
                regDeport.Mostrar();
                cout<<endl;
            }
        }
        fclose(archi);
        system("pause");
        return 1;
    }
    int ListarID(){
        int numID;
        Deporte regDeport;
        cout<<"INGRESA ID:"<<endl;
        cin>>numID;
        int pos=buscaPorID(numID);
        if(pos==-1){
            cout<<"EL ID INGRESADO NO EXISTE"<<endl;
            system("pause");
            return -1;
        }
        regDeport=LeerRegistro(pos);
        regDeport.Mostrar();
        cout<<endl;
        system("pause");
        return 1;
    }
    int ModificarAnio(){
    int anio,numID;
    Deporte regDeport;
    cout<<"INGRESA ID:"<<endl;
    cin>>numID;
    int pos=buscaPorID(numID);
    if(pos==-1){
        cout<<"EL ID INGRESADO NO EXISTE"<<endl;
        system("pause");
        return -1;
    }
    cout<<"INGRESA ANIO:"<<endl;
    cin>>anio;
    regDeport=LeerRegistro(pos);
    regDeport.setAnioOrigen(anio);
    int quepaso=ModificarArchivo(pos,regDeport);
    if(quepaso==1){
        cout<<"Archivo modificado correctamente"<<endl;
        system("pause");
        return 1;
    }
    else{
        return -1;
    }
    }
    int EliminarRegistro(){
        int numID;
        Deporte regDeport;
        cout<<"INGRESA ID:"<<endl;
        cin>>numID;
        int pos=buscaPorID(numID);
        if(pos==-1){
            cout<<"EL DNI INGRESADO NO EXISTE"<<endl;
            system("pause");
            return -1;
        }
        regDeport=LeerRegistro(pos);
        regDeport.setEstado(false);
        int quepaso=ModificarArchivo(pos,regDeport);
        if(quepaso==1){
            cout<<"Registro eliminado correctamente"<<endl;
            system("pause");
            return 1;
        }
        else{
            return -1;
        }
    }
};


#endif // CLASS_ARCHIVO_DEPORTES_H_INCLUDED
