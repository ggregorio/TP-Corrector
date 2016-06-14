#ifndef LISTA_H
#define LISTA_H
#include <cassert>
#include <iostream>
using namespace std;

template <typename elem>
class Lista
{
private:
    ///Estructura implementada:

    struct nodo_l
    {
        elem Valor;
        nodo_l * Sig;
    };
    nodo_l * L;
    unsigned int Largo;
    nodo_l * Cursor;
    nodo_l * Ultimo;
    ///Metodos privados:

    void Nuevo_Nodo(nodo_l * & nodo, const elem & valor);
    void Agregar_Pos(nodo_l * & lista, const unsigned int pos, nodo_l * & nodo);
    void Eliminar(nodo_l * & lista);
    void imprimir(nodo_l * lista) const;
    nodo_l * Buscar(nodo_l * lista,const elem & valor);

public:
    ///Metodos publicos:

    Lista();
    Lista(const Lista<elem> & otraL);
    ~Lista();
    bool Agregar(const unsigned int pos, const elem & valor);
    void Agregar_Final(const elem & valor);
    void Agregar_Principio(const elem & valor);
    bool Vacia() const;
    unsigned int Longitud() const;
    void Mostrar() const;
    bool Eliminar(unsigned int pos);
    void Eliminar_Todo();
    bool Existe(const elem & valor);
    elem & Iterador();
    bool Iterador_Fin();
    void Iterador_Reset();
    Lista<elem> & operator=(const Lista<elem> &otraL);
    ///Lista<elem> & operator=(const Lista<elem> & otraL);
};


///CONSTRUCTOR


template <typename elem> Lista<elem>::Lista()
{
    L = NULL;
    Cursor = NULL;
    Largo = 0;
    Ultimo = NULL;
}


///METODO PRIVADO ELIMINAR


template <typename elem> void Lista<elem>::Eliminar(nodo_l * & lista)
{
    if(lista != NULL)
    {
        Eliminar(lista->Sig);
        delete lista;
        lista = NULL;
    }
}


///DESTRUCTOR


template <typename elem> Lista<elem>::~Lista()
{
    Eliminar(L);
    Cursor = NULL;
    Ultimo = NULL;
}


///METODO PUBLICO AGREGAR


template<typename elem> bool Lista<elem>::Agregar(const unsigned int pos, const elem & valor)
{
    if(pos >= 1 && pos <= Largo)
    {
        nodo_l * nodo;
        Nuevo_Nodo(nodo,valor);
        Agregar_Pos(L,pos,nodo);
        Largo++;
        return true;
    }
    else
    {
        if(pos == Largo+1)
        {
            Agregar_Final(valor);
            return true;
        }
        else
        {
            return false;
        }
    }
}


///METODO PRIVADO NUEVO_NODO


template <typename elem> void Lista<elem>::Nuevo_Nodo(nodo_l * & nodo, const elem & valor)
{
    nodo = new nodo_l;
    nodo->Sig = NULL;
    nodo->Valor = valor;
}


///METODO PRIVADO AGREGAR_POS


template <typename elem> void Lista<elem>::Agregar_Pos(nodo_l * & lista, const unsigned int pos, nodo_l * & nodo)
{
    if(pos == 1)
    {
        nodo->Sig = lista;
        lista = nodo;
    }else{
        Agregar_Pos(lista->Sig,pos-1,nodo);
    }
}


///METODO PUBLICO AGREGAR_FINAL


template <typename elem> void Lista<elem>::Agregar_Final(const elem & valor)
{
    nodo_l * nodo;
    Nuevo_Nodo(nodo,valor);
    if(Ultimo == NULL)
    {
        Ultimo = nodo;
        L = nodo;
    }
    else{
        Ultimo->Sig = nodo;
        Ultimo = nodo;
    }
    Largo++;
}


///METODO PUBLICO AGREGAR_PRINCIPIO


template <typename elem> void Lista<elem>::Agregar_Principio(const elem & valor)
{
    Agregar(1,valor);
}


///METODO PUBLICO VACIA


template <typename elem> bool Lista<elem>::Vacia() const
{
    if(Largo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


///METODO PUBLICO LONGITUD


template <typename elem> unsigned int Lista<elem>::Longitud() const
{
    return Largo;
}


///METODO PUBLICO MOSTRAR


template <typename elem> void Lista<elem>::Mostrar() const
{
    imprimir(L);
    cout << endl;
}


///METODO PRIVADO IMPRIMIR


template <typename elem> void Lista<elem>::imprimir(nodo_l * lista) const
{
    if(lista!=NULL)
    {
        cout << lista->Valor << " ";
        imprimir(lista->Sig);
    }
}


///METODO PUBLICO ELIMINAR


template <typename elem> bool Lista<elem>::Eliminar(unsigned int pos)
{

    nodo_l * aborrar;
    if(pos == Largo)
    {
        nodo_l * aux = L;
        for(int i = 1; i<Largo-1; i++)
        {
            aux = aux->Sig;
        }
        aborrar = Ultimo;
        Ultimo = aux;
        Ultimo->Sig = NULL;
    }
    else
    {
        if(pos > 1)
        {
            nodo_l * aux = L;
            for(int i=1; i<pos-1; i++)
            {
                aux = aux->Sig;
            }
            aborrar = aux->Sig;
            aux->Sig = aux->Sig->Sig;
        }
        else
        {
            if(pos == 1)
            {
                aborrar = L;
                L = L->Sig;
            }
            else
            {
                return false;
            }
        }
    }
    if(aborrar == Cursor)
    {
        Cursor = aborrar->Sig;
        cout << "entro"<<endl;
    }
    delete aborrar;
    aborrar = NULL;
    Largo--;
    return true;
}


///METODO PUBLICO ELIMINAR_TODO


template <typename elem> void Lista<elem>::Eliminar_Todo()
{
    Eliminar(L);
    Cursor = NULL;
    Largo=0;
}


///METODO PUBLICO EXISTE


template <typename elem> bool Lista<elem>::Existe(const elem & valor)
{
    return Buscar(L,valor) != NULL;
}


///METODO PRIVADO BUSCAR


template <typename elem> typename Lista<elem>::nodo_l * Lista<elem>::Buscar(nodo_l * lista, const elem & valor)
{
    if(lista != NULL)
    {
        if(lista->Valor == valor)
        {
            return lista;
        }
        else
        {
            return Buscar(lista->Sig,valor);
        }
    }
    else
    {
        return NULL;
    }
}


///METODO PUBLICO ITERADOR


template <typename elem> elem & Lista<elem>::Iterador()
{
    assert(!Iterador_Fin());
    nodo_l * aux = Cursor;
    Cursor = Cursor->Sig;
    return aux->Valor;
}


///METODO PUBLICO ITERADOR_FIN


template <typename elem> bool Lista<elem>::Iterador_Fin()
{
    return Cursor == NULL;
}


///METODO PUBLICO ITERADOR_RESET


template <typename elem> void Lista<elem>::Iterador_Reset()
{
    Cursor = L;
}

///SOBRECARGA DE =


template <typename elem> Lista<elem> & Lista<elem>::operator=(const Lista<elem> &otraL)
{
    Eliminar_Todo(this->L);
    nodo_l * Aux;
    Aux = otraL.L;
    while(Aux != NULL)
    {
        this->Agregar_Final(Aux->Valor);
        Aux = Aux->Sig;
    }
    return this;
}

template<typename elem> Lista<elem>::Lista(const Lista<elem> & otraL)
{
    this->operator=(otraL);
}

template<typename elem> std::ostream & operator<<(std::ostream & salida, Lista<elem> & otraL)
{
    otraL.Iterador_Reset();
    if(!otraL.Iterador_Fin()){
        salida << "Lista(1,2,3,4,...,Long): \n";
        salida << "(";
        while(!otraL.Iterador_Fin())
        {
            salida << otraL.Iterador();
            if(!otraL.Iterador_Fin())
            {
                salida << ", ";
            }
        }
        salida << ")";
    }else{
        salida << "Lista vacia.";
    }
    return salida;
}
#endif // LISTA_H
