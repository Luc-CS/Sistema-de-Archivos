#ifndef CLASS_JUGADOR_H_INCLUDED
#define CLASS_JUGADOR_H_INCLUDED



class Jugador{
private:
int _DNI;
int _Deporte; //número entre 1 y 10 //ID DEPORTE
int _Claustro; //1: docente; 2 alumno; 3 no docente; 4 graduado)
int _NumEquipo;
char _Nombre[30];
char _Apellido[30];
char _Email[30];
char _Telefono[30];
Fecha _FechaInscripcion;
float _Matricula;
bool _Estado;

public:
    Jugador(int DNI=-1,int Deporte=-1,int Claustro=-1,int NumEquipo=-1,const char *Nombre="sin nombre",const char *Apellido="sin apellido",const char *Email="default@gmail.com",const char *Telefono="sin numero",float Matricula=-1,bool Estado=true){
    _DNI=DNI;
    _Deporte=Deporte;
    _Claustro=Claustro;
    _NumEquipo=NumEquipo;
    strcpy(_Nombre,Nombre);
    strcpy(_Apellido,Apellido);
    strcpy(_Email,Email);
    strcpy(_Telefono,Telefono);
    _Matricula=Matricula;
    _Estado=Estado;

    }
    void Cargar();
    void Mostrar();


    ///setteres
    void setDNI(int dni)
    {
    _DNI=dni;
    }
    void setDeporte(int deporte)
    {
    if(deporte>=1&&deporte<=10){
            _Deporte=deporte;
        }
        else{
            cout<<"EL NUMERO QUE INGRESASTE NO ES VALIDO"<<endl;
            cout<<"INGRESE UN NUMERO DE 1 AL 10"<<endl;
            while(deporte<1||deporte>10){

                cin>>deporte;
            }
            _Deporte=deporte;
        }
    }
    void setClaustro(int claustro)
    {
        if(claustro>=1&&claustro<=4){
             _Claustro=claustro;
        }
        else{
                cout<<"EL NUMERO QUE INGRESASTE NO ES VALIDO"<<endl;
            cout<<"INGRESE UN NUMERO DE 1 AL 4"<<endl;
            while(claustro<1||claustro>4){
                cin>>claustro;
            }
            _Claustro=claustro;
        }
    }
    void setNumEquipo(int num)
    {
            _NumEquipo=num;
    }
    void setNombre(const char *nomb)
    {
     strcpy(_Nombre,nomb);
    }
    void setApellido(const char *ap)
    {
    strcpy(_Apellido,ap);
    }
    void setEmail(const char*mail)
    {
    strcpy(_Email,mail);
    }
    void setTelefono(const char *tel)
    {
     strcpy(_Telefono,tel);
    }
    void setMAtricula(float matricula)
    {
        if(matricula>=0){
            _Matricula=matricula;
        }
        else{
            cout<<"EL NUMERO QUE INGRESASTE NO ES VALIDO"<<endl;
            cout<<"INGRESE MAYOR O IGUAL A 0"<<endl;
            while(matricula<0){
                cin>>matricula;
            }
            _Matricula=matricula;
        }
    }
    void setEstado(bool estado)
    {
    _Estado=estado;
    }
    void setFechaInscripcion(Fecha fcha){
        _FechaInscripcion.setDia(fcha.getDia());
        _FechaInscripcion.setMes(fcha.getMes());
        _FechaInscripcion.setAnio(fcha.getAnio());
    }
    ///getters
    int getDNI(){return _DNI;}
    int getDeporte(){return _Deporte;}
    int getClaustro(){return _Claustro;}
        int getNumEquipo(){return _NumEquipo;}
    const char* getNombre(){return _Nombre;}
     const char* getApellido(){return _Apellido;}
      const char* getTelefono(){return _Telefono;}
      float getMAtricula(){return _Matricula;}
      bool getEstado(){return _Estado;}
      int getDia(){return _FechaInscripcion.getDia();}
      int getMes(){return _FechaInscripcion.getMes();}
      int getAnio(){return _FechaInscripcion.getAnio();}
};
void Jugador::Cargar(){
    int dni, deport, claustro, numEquipo;
    char nombre[30],apellido[30],email[30],telefono[30];
    float matricula;
    bool es;
    Fecha t1;
cout<<"COMPLETA DATOS DEL JUGADOR"<<endl;
cout<<"Ingresa DNI:"<<endl;
cin>>dni;
setDNI(dni);
cout<<"Ingresa nombre:"<<endl;
cargarCadena(nombre,29);
setNombre(nombre);
cout<<"Ingresa apellido:"<<endl;
cargarCadena(apellido,29);
setApellido(apellido);
cout<<"Ingresa Email:"<<endl;
cargarCadena(email,29);
setEmail(email);
cout<<"Ingresa Telefono:"<<endl;
cargarCadena(telefono,29);
setTelefono(telefono);
cout<<"Ingresa claustro:"<<endl;
cin>>claustro;
setClaustro(claustro);
cout<<"Ingresa ID deporte:"<<endl;
cin>>deport;
setDeporte(deport);
cout<<"Ingresa Numero de equipo:"<<endl;
cin>>numEquipo;
setNumEquipo(numEquipo);
cout<<"Ingresa fecha de inscripcion:"<<endl;
t1.Cargar();
setFechaInscripcion(t1);
cout<<"Ingresa matricula:"<<endl;
cin>>matricula;
setMAtricula(matricula);
es=true;
setEstado(es);
}
void Jugador::Mostrar(){
cout<<"DNI: "<<_DNI<<endl;
cout<<"Nombre: "<<_Nombre<<endl;
cout<<"Apellido: "<<_Apellido<<endl;
cout<<"Email: "<<_Email<<endl;
cout<<"Telefono: "<<_Telefono<<endl;
cout<<"Claustro: "<<_Claustro<<endl;
cout<<"ID Deporte: "<<_Deporte<<endl;
cout<<"Numero del equipo: "<<_NumEquipo<<endl;
cout<<"Fecha de inscripcion"<<endl;
_FechaInscripcion.Mostrar();
cout<<"Matricula: "<<_Matricula<<endl;

}
#endif // CLASS_JUGADOR_H_INCLUDED
