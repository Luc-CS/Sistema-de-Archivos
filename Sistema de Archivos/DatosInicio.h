#ifndef DATOSINICIO_H_INCLUDED
#define DATOSINICIO_H_INCLUDED

void EstablecerDatosDeportes(){
ArchivoDeportes listDEP("deportes.dat");
ArchivoDeportes listINdep("DatosInicioDeportes.dat");
Deporte regDepor;
limpiarArchivo("deportes.dat");
int cantVuelt=listINdep.contadorRegistros();
for(int i=0;i<cantVuelt;i++){
    regDepor=listINdep.LeerRegistro(i);
    listDEP.AgregarDeporte(regDepor);
}
}

void EstablecerDatosJugadores(){
ArchivoJugadores listJUG("jugadores.dat");
ArchivoJugadores listINjug("DatosInicioJugadores.dat");
Jugador regJUG;
limpiarArchivo("jugadores.dat");
int cantVuelt=listINjug.contadorRegistros();
for(int i=0;i<cantVuelt;i++){
    regJUG=listINjug.leerRegistro(i);
    listJUG.AgregarJugador(regJUG);
}
}

#endif // DATOSINICIO_H_INCLUDED
