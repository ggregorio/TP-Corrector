#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <Lista.h>
#include <fstream>

class Archivo
{
    friend std::ostream & operator<<(std::ostream & salida, Archivo & Arch);
    private:
        Lista<string> Lista_Archivo;
    public:
        Archivo();
        ~Archivo();
        bool Cargar(const string & Nombre);
        bool Guardar(const string & Nombre);
        void Agregar_Dato(const string & Dato);
        void Mostrar() const;
        const string & Iterador();
        void Iterador_Reset();
        bool Iterador_Fin();
};

Archivo::Archivo() ///consulta: esta bien que no haga nada el constructor
{

}


Archivo::~Archivo() ///consulta: hay que hacer algo aca o como la lista ya tiene su destructor no es necesario
{

}


///METODO PUBLICO GARGAR


bool Archivo::Cargar(const string & Nombre)
{
    ifstream archivo;
    string aux;
    archivo.open(Nombre,ios::out|ios::in);
    if(!archivo.is_open())
    {
        return false;
    }
    while(!archivo.eof())
    {
        archivo >> aux;
        Lista_Archivo.Agregar_Final(aux);
    }
    archivo.close();
    return true;
}


///METODO PUBLICO GUARDAR


bool Archivo::Guardar(const string & Nombre)
{
    ofstream archivo;
    archivo.open(Nombre,ios::out);
    if(archivo.is_open())
    {
        Lista_Archivo.Iterador_Reset();
        while(!Lista_Archivo.Iterador_Fin())
        {
            archivo << Lista_Archivo.Iterador() << endl;
        }
        archivo.close();
        return true;
    }else{
        return false;
    }
}


///METODO PUBLICO AGREGAR_DATO


void Archivo::Agregar_Dato(const string & Dato)
{
    Lista_Archivo.Agregar_Principio(Dato);
}


///METODO PUBLICO MOSTRAR


void Archivo::Mostrar() const
{
    Lista_Archivo.Mostrar();
}


///METODO PUBLICO ITERADOR


const string & Archivo::Iterador()

{
    return Lista_Archivo.Iterador();
}


///METODO PUBLICO ITERADOR_RESET


void Archivo::Iterador_Reset()
{
    Lista_Archivo.Iterador_Reset();
}


///METODO PUBLICO ITERADOR_FIN


bool Archivo::Iterador_Fin()
{
    return Lista_Archivo.Iterador_Fin();
}


std::ostream & operator<<(std::ostream & salida, Archivo & Arch)
{
    salida << Arch.Lista_Archivo;
    return salida;
}
#endif // ARCHIVO_H
