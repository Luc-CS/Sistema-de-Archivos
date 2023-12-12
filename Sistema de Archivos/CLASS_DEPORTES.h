#ifndef CLASS_DEPORTES_H_INCLUDED
#define CLASS_DEPORTES_H_INCLUDED
class Deporte{
private:
    int _ID;///AUTONUMERICO
    char _Nombre[30];
    int _TipoDeporte;///del 1 al 21
    int _Anio;///año de origen entre 1800 y año actual
    bool _Estado;
public:
    void Cargar();
    void Mostrar();

    ///SETERS
    void setID(int id){
        _ID=id;
    }
    void setNombre(const char *nm){
        strcpy(_Nombre,nm);
    }
    void setTipoDeporte(int deport){
        if(deport>=1&&deport<=21){
            _TipoDeporte=deport;
        }
        else{
            cout<<"EL NUMERO QUE INGRESO NO ES VALIDO"<<endl;
            while(deport<1||deport>21){
                cout<<"INGRESA UN NUMERO DEL 1 AL 21"<<endl;
                cin>>deport;
            }
            _TipoDeporte=deport;
        }
    }
    void setAnioOrigen(int anio){
        if(anio>=1800&&anio<=2023){
            _Anio=anio;
        }
        else{
            cout<<"EL NUMERO QUE INGRESO NO ES VALIDO"<<endl;
            while(anio<1800||anio>2023){
                cout<<"INGRESA UN NUMERO DEL 1800 AL 2023"<<endl;
                cin>>anio;
            }
            _Anio=anio;
        }
    }
    void setEstado(bool es){_Estado=es;}
    ///GETERS
    int getID(){return _ID;}
    const char* getNombre(){return _Nombre;}
    int getTipoDeporte(){return _TipoDeporte;}
    int getAnioOrigen(){return _Anio;}
    bool getEstado(){return _Estado;}
};
void Deporte::Cargar(){
int deporte,anio;
char nom[30];
bool es;
cout<<"INGRESA NOMBRE:"<<endl;
cargarCadena(nom,29);
setNombre(nom);
cout<<"INGRESA TIPO DE DEPORTE:"<<endl;
cin>>deporte;
setTipoDeporte(deporte);
cout<<"INGRESA ANIO DE ORIGEN:"<<endl;
cin>>anio;
setAnioOrigen(anio);
es=true;
setEstado(es);
}
void Deporte::Mostrar(){
cout<<"ID: "<<_ID<<endl;
cout<<"NOMBRE: "<<_Nombre<<endl;
cout<<"TIPO DE DEPORTE: "<<_TipoDeporte<<endl;
cout<<"AÑO DE ORIGEN: "<<_Anio<<endl;
}
#endif // CLASS_DEPORTES_H_INCLUDED
