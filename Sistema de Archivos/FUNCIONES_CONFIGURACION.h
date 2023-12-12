#ifndef FUNCIONES_CONFIGURACION_H_INCLUDED
#define FUNCIONES_CONFIGURACION_H_INCLUDED

///COPIA DE SEGURIDAD DE JUGADORES

int CopSegArchivoJugadores(){
FILE *archi, *archi2;
archi=fopen("jugadores.dat","rb");
Jugador regJUG;
if(archi==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    return -1;
}
archi2=fopen("jugadores.bak","wb");
if(archi2==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    fclose(archi);
    return -1;
}
while(fread(&regJUG,sizeof (Jugador),1,archi)==1){
        fwrite(&regJUG,sizeof (Jugador),1,archi2);
}
fclose(archi);
fclose(archi2);
return 1;
}

///RESTAURAR COPIA DE SEGURIDAD DE JUGADORES

int ResCopSegArchivoJugadores(){
FILE *archi, *archi2;
archi=fopen("jugadores.dat","wb");
Jugador regJUG;
if(archi==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    return -1;
}
archi2=fopen("jugadores.bak","rb");

if(archi2==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    fclose(archi);
    return -1;
}
while(fread(&regJUG,sizeof (Jugador),1,archi2)==1){
        fwrite(&regJUG,sizeof (Jugador),1,archi);
}
fclose(archi);
fclose(archi2);
return 1;
}

///COPIA DE SEGURIDAD DE DEPORTES

int CopSegArchivoDeportes(){
FILE *archi, *archi2;
archi=fopen("deportes.dat","rb");
Deporte regDEPORT;
if(archi==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    return -1;
}
archi2=fopen("deportes.bak","wb");

if(archi2==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    fclose(archi);
    return -1;
}
while(fread(&regDEPORT,sizeof (Deporte),1,archi)==1){
        fwrite(&regDEPORT,sizeof (Deporte),1,archi2);
}
fclose(archi);
fclose(archi2);
return 1;
}

///RESTAURAR COPIA DE SEGURIDAD DE DEPORTES

int ResCopSegArchivoDeportes(){
FILE *archi, *archi2;
archi=fopen("deportes.dat","wb");
Deporte regDEPORT;
if(archi==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    return -1;
}
archi2=fopen("deportes.bak","rb");
if(archi2==NULL){
    cout<<"ERROR DE ARCHIVO"<<endl;
    system("PAUSE");
    fclose(archi);
    return -1;
}
while(fread(&regDEPORT,sizeof (Deporte),1,archi2)==1){
        fwrite(&regDEPORT,sizeof (Deporte),1,archi);
}
fclose(archi);
fclose(archi2);
return 1;
}
#endif // FUNCIONES_CONFIGURACION_H_INCLUDED
