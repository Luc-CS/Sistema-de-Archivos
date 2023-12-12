#ifndef CLASS_FECHA_H_INCLUDED
#define CLASS_FECHA_H_INCLUDED
class Fecha
{
private:
    int dia, mes, anio;
public:
    void Cargar();
    void Mostrar();
    Fecha(int d=0, int m=0, int a=0)
    {
        this->dia=d;
        this->mes=m;
        this->anio=a;
    }
    ///sets()
    void setDia(int var)
    {
        if(var>0 && var<=31) {dia=var;}
        else{
                cout<<"DIA INGRESADO ES INVALIDO"<<endl;
        cout<<"INGRESA UN DIA DEL 1 AL 31"<<endl;
            while(var<=0||var>31){
                    cin>>var;
                dia=var;
        }
        }
    }
    void setMes(int var)
    {
        if(var>0 && var<=12) {mes=var;}
        else{
            cout<<"MES INGRESADO ES INVALIDO"<<endl;
        cout<<"INGRESA UN MES DEL 1 AL 12"<<endl;
            while(var<=0||var>12){
                    cin>>var;
            if(var>=1&&12<=var){
                mes=var;
            }
        }
        }
        }

    void setAnio(int var)
    {
        time_t tiempo;
        struct tm *tmPtr;

        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);
        if(var>0) anio=var;

        else{
            cout<<"ANIO INGRESADO ES INVALIDO"<<endl;
            cout<<"INGRESA UN ANIO DEL 1900 AL 2023"<<endl;
            while(var<=1900||var>(1900+tmPtr->tm_year)){
                    cin>>var;
            if(var>=1900&&(1900+tmPtr->tm_year)<=var){
                anio=var;
            }
        }
        }
        }

    ///gets()
    int getDia()
    {
        return dia;
    }
    int getMes()
    {
        return mes;
    }
    int getAnio()
    {
        return anio;
    }
};
void Fecha::Cargar()
{
    int d, m, a;
    cout<<"DIA ";
    cin>>d;
    setDia(d);
    cout<<"MES ";
    cin>>m;
    setMes(m);
    cout<<"ANIO ";
    cin>>a;
    setAnio(a);
}

void Fecha::Mostrar()
{
    cout<<"DIA ";
    cout<<dia<<endl;
    cout<<"MES ";
    cout<<mes<<endl;
    cout<<"ANIO ";
    cout<<anio<<endl;
}


#endif // CLASS_FECHA_H_INCLUDED
