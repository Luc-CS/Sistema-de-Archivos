#ifndef DYNAMIC_H_INCLUDED
#define DYNAMIC_H_INCLUDED

/// EJERCICIOS DE PRACTICA

int CargarDynamicJug(Jugador *regJug,int tam,ArchivoJugadores listJUG){
    if(regJug==nullptr){
                cout<<"ERROR"<<endl;
           return -1;
    }
for(int i=0;i<tam;i++){
        regJug[i]=listJUG.leerRegistro(i);
}
return 1;
}

void OrdenarDynamicJug(Jugador *regJug,int tam){
Jugador aux;
for(int i=0;i<tam;i++){
        for(int x=0;x<tam;x++){//PUEDE SER: for(int x=i+1;i<tam;i++
            if(strcmp(regJug[i].getApellido(),regJug[x].getApellido())<0){
                aux=regJug[i];
                regJug[i]=regJug[x];
                regJug[x]=aux;
            }
        }
    }
}

void MostrarDynamicJug(Jugador *regJug,int tam){
for(int i=0;i<tam;i++){
    regJug[i].Mostrar();
    cout<<endl;
}
system("pause");
delete[] regJug;
}



int VectorDynamicJug(){
ArchivoJugadores listJUG;
int tam=listJUG.contadorRegistros();
Jugador *regJug;
regJug=new Jugador[tam];
if(regJug==nullptr){
    cout<<"ERROR"<<endl;
    return -1;
}
for(int i=0;i<tam;i++){
        regJug[i]=listJUG.leerRegistro(i);
}
for(int i=0;i<tam;i++){
    regJug[i].Mostrar();
    cout<<endl;
}
system("pause");
delete[] regJug;
return 1;
}

#endif // DYNAMIC_H_INCLUDED
