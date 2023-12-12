#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

///EJERCICIOS PARCIAL

//FUNCIONES DE PARCIAL
//PUNTO 1
void ListarCantJugadoresInscriptos(){
int cantJug[12]={};
ArchivoJugadores listJUG;
Jugador regJUG;

int cantVUEL=listJUG.contadorRegistros();
for(int i=0;i<cantVUEL;i++){
        regJUG=listJUG.leerRegistro(i);
        if(regJUG.getAnio()==2023&&regJUG.getEstado()==true){
            cantJug[regJUG.getMes()-1]++;
        }
}
for(int i=0;i<12;i++){
    cout<<"EN EL MES "<<i+1<<" SE INSCRIBIERON: "<<cantJug[i]<<endl;
}
system("pause");
}
//PUNTO 2
class punto2{
    private:
    int _ID;
    char _Nombre[30];
    int _Anio;
    int _inscriptos;//en realidad es incriptos no alumnos, segun el profe tomo lo primero (maxi)
    bool _Estado;

    public:
        punto2(int id=0 ,const char *n="sin deporte" ,int anio=2023 ,int inscri=0){
            _ID=id;
            strcpy(_Nombre,n);
            _Anio=anio;
            _inscriptos=inscri;
        }
        void setID(int id){_ID=id;}
        void setNombre(const char *nm){strcpy(_Nombre,nm);}
        void setAnioOrigen(int anio){_Anio=anio;}
        void setEstado(bool es){_Estado=es;}
        void setInscriptos(int a){_inscriptos=a;}

        void Mostrar(){
            cout<<"ID: "<<_ID<<endl;
            cout<<"NOMBRE: "<<_Nombre<<endl;
            cout<<"AÑO DE ORIGEN: "<<_Anio<<endl;
            cout<<"INSCRIPTOS: "<<_inscriptos<<endl;
        }
};
void ArchivoDeporteMas50Inscriptos(){
ArchivoDeportes listDEPORT;
ArchivoJugadores listJUG;
FILE *archi;
archi=fopen("nuevoDeportes.dat","wb");
Deporte regDEPORT;
Jugador regJUG;
punto2 regNUEVO;

int cantJ=listJUG.contadorRegistros();
int cantD=listDEPORT.contadorRegistros();

for(int i=0;i<cantD;i++){
        regDEPORT=listDEPORT.LeerRegistro(i);
        int cantInscriptos=0;
        if(regDEPORT.getTipoDeporte()==5){
            for(int x=0;x<cantJ;x++){
                regJUG=listJUG.leerRegistro(x);
                if(regDEPORT.getID()==regJUG.getDeporte()){
                    cantInscriptos++;
                }
            }
            if(cantInscriptos>50){
            regNUEVO.setID(regDEPORT.getID());
            regNUEVO.setNombre(regDEPORT.getNombre());
            regNUEVO.setAnioOrigen(regDEPORT.getAnioOrigen());
            regNUEVO.setInscriptos(cantInscriptos);
            regNUEVO.setEstado(true);
            fwrite(&regNUEVO,sizeof (punto2),1,archi);
            }
        }
}
fclose(archi);
}

//FUNCIONES DE PRACTICA PARCIAL
void PUNTO_A(){
ArchivoJugadores regJUG;
Jugador JUG;
int cantVuelt;
int num_deporte;
int cantJugadores=0;
cout << "INGRESA NUMERO DE DEPORTE"<<endl;
cin >> num_deporte;
cantVuelt=regJUG.contadorRegistros();
for(int i=0;i<cantVuelt;i++){
    JUG=regJUG.leerRegistro(i);
    if(JUG.getDeporte()==num_deporte){
            cantJugadores++;
    }
}
cout<<"LA CANTIDAD DE JUGADORES QUE LO PRACTICAN"<<endl;
cout<<cantJugadores << endl;
system("pause");
}

void PUNTOB(){

 ArchivoJugadores regJUG;
int claustro[4]={};//vector para contar jugadores de cada claustro
int cantVuelt;
Jugador JUG;
cantVuelt=regJUG.contadorRegistros();
for(int i=0;i<cantVuelt;i++)
    {
    JUG=regJUG.leerRegistro(i);
    claustro[JUG.getClaustro()-1]++;
    }
int maxJUG=0,maxClau=0;
for(int i=0;i<4;i++){
    if(i==0){
        maxClau=i+1;
        maxJUG=claustro[i];
    }
    else if(claustro[i]>=maxJUG){
            maxClau=i+1;
        maxJUG=claustro[i];
    }
}
cout<<"EL CLAUSTRO CON MAS JUGADORES ES:"<<endl;
cout<<maxClau << endl ;
system("pause");
}

bool esDelTipo(int idDeporte, int tipo){
    ArchivoDeportes archi;
    Deporte reg;
    int cantReg=archi.contadorRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archi.LeerRegistro(i);
        if(reg.getID()==idDeporte){
            if(reg.getTipoDeporte()==tipo)return true;
            else return false;
        }
    }
    return false;
 }
 void puntoC(){
    ArchivoJugadores archi;
    Jugador reg;
    cout<<"INGRESE UN TIPO DE DEPORTE ";
    int tipo, cantAlu=0;
    cin>>tipo;
    int cantReg=archi.contadorRegistros();
    for(int i=0;i<cantReg;i++){
        reg=archi.leerRegistro(i);
        if(reg.getClaustro()==2){
            if(esDelTipo(reg.getDeporte(), tipo)) cantAlu++;
        }
    }

    cout<<"CANTIDAD DE JUGADORES ALUMNOS"<<cantAlu<<endl;
    system("pause");
}
#endif // REPORTES_H_INCLUDED
