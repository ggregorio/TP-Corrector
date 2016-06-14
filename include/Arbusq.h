#ifndef ARBUSQ_H
#define ARBUSQ_H
#include <Lista.h>
#include <iostream>

using namespace std;

template <typename elem>

class Arbusq
{
    private:
        ///Estructura implementada:

        struct nodo_arb{
            nodo_arb * Mayores;
            nodo_arb * Menores;
            elem Valor;
        };
        nodo_arb * Raiz;
        unsigned int CantElem;
        ///Metodos privados:

        void Eliminar(nodo_arb * & Arbol);
        void Nuevo_Nodo(nodo_arb * & Nodo,const elem & valor);
        void Agregar_priv(nodo_arb * & Arbol, const elem & Valor);
        nodo_arb * Buscar(nodo_arb * Arbol, const elem & Valor) const;
        void Mostrar_p(nodo_arb * Arbol) const;
        void auxAltura(nodo_arb * nodo,const unsigned int a, unsigned int & altura) const;
        bool Es_Hoja(nodo_arb * nodo) const;
        void Inorder(Lista<elem> & L,nodo_arb * Arbol) const;
        void Frontera(Lista<elem> & L,nodo_arb * arbol) const;
    public:
        ///Metodoss Publicos:

        Arbusq();
        ~Arbusq();
        void Agregar(const elem & Valor);
        bool Vacio() const;
        unsigned int Cantidad_Elementos() const;
        bool Existe(const elem & Valor) const;
        void Mostrar() const;
        unsigned int Altura() const;
        ///Lista<elem> & Listar_Arbol() const
        ///Lista<elem> & Listar_Frontera() const
        void Listar_Arbol(Lista<elem> & L) const;
        void Listar_Frontera(Lista<elem> & L) const;
};


///CONSTRUCTOR


template <typename elem> Arbusq<elem>::Arbusq()
{
    Raiz = NULL;
    CantElem = 0;
}


///METODO PRIVADO ELIMINAR


template <typename elem> void Arbusq<elem>::Eliminar(nodo_arb * & Arbol)
{
    if(Arbol != NULL)
    {
        Eliminar(Arbol->Mayores);
        Eliminar(Arbol->Menores);
        delete Arbol;
        Arbol = NULL;
        CantElem = 0;
    }
}


///DESTRUCTOR


template <typename elem> Arbusq<elem>::~Arbusq()
{
    Eliminar(Raiz);
    Raiz = NULL;
}


///MEOTODO PUBLICO AGREGAR


template <typename elem> void Arbusq<elem>::Agregar(const elem & Valor)
{
    //nodo_arb * nodo;
    //Nuevo_Nodo(nodo,Valor);
    Agregar_priv(Raiz,Valor);
    CantElem++;
}


///METODO PRIVADO NUEVO_NODO


template <typename elem> void Arbusq<elem>::Nuevo_Nodo(nodo_arb * & Nodo, const elem & valor)
{
    Nodo = new nodo_arb;
    Nodo->Mayores = NULL;
    Nodo->Menores = NULL;
    Nodo->Valor = valor;
}


///METODO PRIVADO AGREGAR_PRIV


template <typename elem> void Arbusq<elem>::Agregar_priv(nodo_arb * & Arbol, const elem & Valor)
{
    if(Arbol == NULL)
    {
        Nuevo_Nodo(Arbol, Valor);
    }
    else
    {
        if(Arbol->Valor > Valor)
        {
            Agregar_priv(Arbol->Menores,Valor);
        }
        else
        {
            Agregar_priv(Arbol->Mayores,Valor);
        }
    }
}


///METODO PUBLICO CANTIDAD_ELEMENTOS


template <typename elem> unsigned int Arbusq<elem>::Cantidad_Elementos() const
{
    return CantElem;
}


///METODO PUBLICO VACIO


template <typename elem> bool Arbusq<elem>::Vacio() const
{
    return Raiz != NULL;
}


///METODO PUBLICO EXISTE


template <typename elem> bool Arbusq<elem>::Existe(const elem & Valor) const
{
    return Buscar(Raiz,Valor) != NULL;
}


///METODO PRIVADO BUSCAR


template <typename elem> typename Arbusq<elem>::nodo_arb * Arbusq<elem>::Buscar(nodo_arb * Arbol,const elem & Valor) const
{
    if(Arbol != NULL)
    {
        if(Arbol->Valor == Valor)
        {
            return Arbol;
        }
        else
        {
            if(Arbol->Valor > Valor)
            {
                return Buscar(Arbol->Menores,Valor);
            }
            else
            {
                return Buscar(Arbol->Mayores,Valor);
            }
        }
    }
    else
    {
        return Arbol;
    }
}


///METODO PUBLICO MOSTRAR


template <typename elem> void Arbusq<elem>::Mostrar() const
{
    Mostrar_p(Raiz);
    cout << endl;
}


///METODO PRIVADO MOSTRAR_P


template <typename elem> void Arbusq<elem>::Mostrar_p(nodo_arb * Arbol) const
{
    if(Arbol != NULL)
    {
        cout << Arbol->Valor << " ";
        Mostrar_p(Arbol->Menores);
        Mostrar_p(Arbol->Mayores);
    }
}


///METODO PUBLICO ALTURA


template <typename elem> unsigned int Arbusq<elem>::Altura() const
{
    unsigned int Altu;
    Altu=0;
    if (Raiz == NULL){
        return 0;
    }else{
        auxAltura(Raiz,0,Altu);
        return Altu+1;
    }
}


///METODO PRIVADO AUXALTURA


template <typename elem> void Arbusq<elem>::auxAltura(nodo_arb * nodo,const unsigned int alt_actual, unsigned int & altura) const
{
    if(nodo != NULL){
        auxAltura(nodo->Menores,alt_actual+1,altura);
        auxAltura(nodo->Mayores,alt_actual+1,altura);
        if(Es_Hoja(nodo) && (alt_actual > altura))
        {
            altura = alt_actual;
        }
    }
}


///METODO PRIVADO ES_HOJA


template <typename elem> bool Arbusq<elem>::Es_Hoja(nodo_arb * nodo) const
{
    if((nodo->Menores == NULL) && (nodo->Mayores == NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
}


///METODO PUBLICO LISTAR_ARBOL


template <typename elem> void Arbusq<elem>::Listar_Arbol(Lista<elem> & L) const
{
    Inorder(L,Raiz);
}


///MEOTODO PRIVADO INORDER


template <typename elem> void Arbusq<elem>::Inorder(Lista<elem> & L,nodo_arb * Arbol) const
{
    if(Arbol != NULL)
    {
        Inorder(L,Arbol->Mayores);
        L.Agregar_Principio(Arbol->Valor);
        Inorder(L,Arbol->Menores);
    }
}


///METODO PUBLICO LISTAR FRONTERA


template <typename elem> void Arbusq<elem>::Listar_Frontera(Lista<elem> & L) const
{
    Frontera(L,Raiz);
}


///METODO PRIVADO FRONTERA


template <typename elem> void Arbusq<elem>::Frontera(Lista<elem> & L,nodo_arb * arbol) const
{
    if(arbol != NULL)
    {
        if(Es_Hoja(arbol))
        {
            L.Agregar_Final(arbol->Valor);
        }
        else
        {
            Frontera(L,arbol->Menores);
            Frontera(L,arbol->Mayores);
        }
    }
}
#endif // ARBUSQ_H
