#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <Arbusq.h>
#include <Lista.h>
#include <string>

class Diccionario
{
    private:
        string * Arr;
        unsigned int Long;
        int Medio(unsigned int Final, unsigned int Principio) const;
        bool Busq_Bin(const string & Palabra,unsigned int izq, unsigned int der) const;
    public:
        Diccionario(string Nombre);
        ~Diccionario();
        bool Existe(const string & Palabra,unsigned int izq, unsigned int der) const;
        void Listar(Lista<string> & l) const;
        void Mostrar() const;
};
/// HACER MERGE SORT, BUSQ_BIN, CANTELEMENTOS, CARGAR///

///CONSTRUCTOR
cONTANDO LAS PALABRAS QUE TIENE EL ARCHIVO, ESA SERIA LA LONG O NO?

Diccionario::Diccionario(string Nombre)
{
    unsigned int Long = Cantidad_Palabras(Nombre);
    Arr = new string[Long];
    this->Long = Long;
    Cargar(Nombre);
}


///DESTRUCTOR


Diccionario::~Diccionario()
{
    delete [] Arr;
}


///METODO PUBLICO EXISTE


bool Diccionario::Existe(const string & Palabra,unsigned int izq, unsigned int der) const
{
   return Busq_Bin(Palabra,izq, der);
}


///METODO PUBLICO LISTAR


void Diccionario::Listar(Lista<string> & l) const
{
    Arb.Listar_Arbol(l);
}


///METODO PUBLICO MOSTRAR


void Diccionario::Mostrar() const
{
    Arb.Mostrar();
}


///METODO PRIVADO MEDIO


int Diccionario::Medio(unsigned int Final, unsigned int Principio) const
{
    return ((Final + Principio)/2);
}


///METODO PRIVADO BUSQ_BIN


bool Diccionario::Busq_Bin(const string & Palabra,unsigned int izq, unsigned int der) const
{
    int mitad;
    mitad = Medio(izq, der);
    if (Long == izq)
    {
        if (Arr[Long] == Palabra)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (Arr[mitad] == Palabra)
        {
            return true;
        }
        else{
            if (Palabra < Arr[mitad])
            {
                return Busq_Bin(Palabra, izq, mitad);
            } else
            {
                return Busq_Bin(Palabra, mitad + 1, der);
            }

        }
    }
}
i no seria long?

///METODO PRIVADO CARGAR ///adapta esto para que funcione con diccionario  SISI


bool Diccionario::Cargar(string & Nombre)
{
    ifstream archivo;
    unsigned int i = 1;
    archivo.open(Nombre,ios::out|ios::in);
    if(!archivo.is_open())
    {
        return false;
    }
    while(!archivo.eof())
    {
        archivo >> Arr[i];
        i++;
    }
    archivo.close();
    return true;
}

int Diccionario::Cant_palabras
#endif // DICCIONARIO_H
