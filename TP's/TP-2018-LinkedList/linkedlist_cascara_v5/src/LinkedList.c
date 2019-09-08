#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
*
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
* \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                       ( 0) Si funciono correctamente
*
*/
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!= NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this!= NULL && nodeIndex>=0 && nodeIndex < ll_len(this))
    {
        pNode=this->pFirstNode; //lo coloco como primer elemento

        while(nodeIndex>0)
        {
            pNode=pNode->pNextNode;
            nodeIndex--;
        }
    }
    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* NuevoNodo;
    Node* NextNodo;
    Node* PreviuosNodo;

    if(this!= NULL )
    {
        if(nodeIndex>=0 && nodeIndex <= ll_len(this))
        {
            NuevoNodo= (Node*) malloc(sizeof(Node));
            if(NuevoNodo!=NULL)
            {
                NuevoNodo->pElement=pElement;
                NuevoNodo->pNextNode=NULL;
                if(nodeIndex==0)
                {
                    NuevoNodo->pNextNode=this->pFirstNode;
                    this->pFirstNode=NuevoNodo;
                }
                else
                {
                    PreviuosNodo=this->pFirstNode;
                    NextNodo=PreviuosNodo->pNextNode;

                    while(nodeIndex>1)
                    {
                        PreviuosNodo=NextNodo;
                        NextNodo=PreviuosNodo->pNextNode;
                        nodeIndex--;
                    }
                    PreviuosNodo->pNextNode=NuevoNodo;
                    NuevoNodo->pNextNode=NextNodo;
                }
                this->size++;
                returnAux=0;
            }
        }
    }
    return returnAux;
}
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tamanio;

    if(this!= NULL)
    {
        tamanio=ll_len(this);
        if(addNode(this,tamanio,pElement)==0) //agrega el nodo a la lista
        {
            returnAux=0;
        }

    }
    return returnAux;
}

void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* NodoAux;

    if(this!= NULL )
    {
        NodoAux=getNode(this,index);
        if(index>=0 && index < ll_len(this))
        {
            returnAux=NodoAux->pElement;
        }
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* NodoAux;

    if(this!= NULL)
    {
        NodoAux=getNode(this,index);
        if(NodoAux!=NULL && index>=0 &&(index <= ll_len(this)))
        {
            NodoAux->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* NodoAux;
    Node* NodoNext;
    int indice=0;

    if(this!= NULL )
    {
        if(index>=0 &&(index < ll_len(this)))
        {
            NodoAux=this->pFirstNode; //actual lo defino como primero
            NodoNext=NodoAux->pNextNode; //nodoSig lo defino como el siguiente
            if(index==0)
            {
                NodoAux=this->pFirstNode; //si el indice es Cero, el actual sera el primero entonces
            }
            else
            {
                while(indice< index-1) //si INDICE es menor que Index-1 (POSICION) Hasta que llega a la primerNodo
                {
                    NodoAux=NodoAux->pNextNode;
                    NodoNext=NodoAux->pNextNode;
                    indice++; //aumenta indice+1
                }
                NodoAux->pNextNode=NodoNext->pNextNode;
            }
            this->size--;
            returnAux=0;
        }
    }
    return returnAux;
}

int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int tam;
    int i;

    if(this!=NULL)
    {
        tam=ll_len(this);
        for(i=0; i<tam ; i++)
        {
            ll_remove(this,i);
        }
        returnAux=0;
        //free(this);
    }
    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    Node* NodoAux;
    int returnAux = -1;
    int longitud,i;

    if(this!=NULL)
    {
        longitud=ll_len(this);
        for(i=0; i<longitud; i++)
        {
            NodoAux=getNode(this,i);
            if(NodoAux!=NULL && NodoAux->pElement==pElement)
            {
                returnAux= i;
                break;
            }
        }
    }
    return returnAux;
}

int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
            returnAux=1; //esta vacia
        }
        else
        {
            if(ll_len(this)>0)
            {
                returnAux=0; //no esta vacia
            }
        }
    }
    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!= NULL)
    {
        if(addNode(this,index,pElement)==0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}

void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pElementAux;

    if(this!= NULL )
    {
        if(index>=0 &&(index <= ll_len(this)))
        {
            pElementAux=ll_get(this,index);
            if(pElementAux!=NULL)
            {
                if(ll_remove(this,index)==0)
                {
                    returnAux=pElementAux;
                }
            }
        }
    }
    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement)
{
    Node* NodoAux;
    int returnAux = -1;
    int longitud,i;

    if(this!=NULL)
    {
        returnAux=0;
        longitud=ll_len(this);
        for(i=0; i<longitud; i++)
        {
            NodoAux=getNode(this,i);
            if(NodoAux!=NULL && NodoAux->pElement==pElement)
            {
                returnAux= 1;
                break;
            }
        }
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    void* pElementAux;
    int returnAux = -1;
    int contenido,i;

    if(this!= NULL && this2!= NULL)
    {
        returnAux=1;

        for(i=0; i<ll_len(this2); i++)
        {
            pElementAux=ll_get(this2,i);
            contenido=ll_contains(this,pElementAux);
            if(contenido==0) //si contenido es vacio
            {
                returnAux=0; //no contiene todos los elementos

            }
            else
            {
                if(contenido==1)
                {
                    returnAux=1;
                }
            }
        }
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementAux;
    int longitud,i;

    if(this != NULL)
    {
        longitud=ll_len(this);
        if(to<=longitud && longitud>from && from>=0 && from<to) //desde >0 y desde< hasta
        {
            cloneArray=ll_newLinkedList();
            for(i=from; i<=to ; i++)
            {
                pElementAux=ll_get(this,i);
                if(pElementAux!=NULL)
                {
                    if(ll_add(cloneArray,pElementAux)==0) //agregando al arraylist
                    {
                        continue;
                    }
                }
            }
        }
    }
    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int i;

    if(this != NULL)
    {
        for(i=0;i<ll_len(this); i++)
        {
            cloneArray=ll_subList(this,0,ll_len(this));
        }
    }
    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    void* pElementI=NULL;
    void* pElementJ=NULL;
    void* auxiliar=NULL;
    int returnAux =-1;
    int limite;
    int i,j;

    if(this != NULL && pFunc!= NULL)
    {
        if(order==0 || order==1)
        {
            returnAux=0;
            limite=ll_len(this);

            for(i=0; i<limite-1 ; i++)
            {

                for(j=i+1; j<limite; j++)
                {
                    pElementI=ll_get(this,i);
                    pElementJ=ll_get(this,j);
                    if(order==1)
                    {
                        if(pFunc(pElementI,pElementJ)>0) //ordena de mayor
                        {
                            auxiliar=pElementI;
                            pElementI=pElementJ;
                            pElementJ=auxiliar; //puntero al elemnto que se encuentra en el indice j
                        }
                    }
                    else if (order==0)
                    {
                        if(pFunc(pElementI,pElementJ)<0)//ordena de menor
                        {
                            auxiliar=pElementI;
                            pElementI=pElementJ;
                            pElementJ=auxiliar;
                        }
                    }
                    ll_set(this,i,pElementI);
                    ll_set(this,j,pElementJ);
                }
            }
        }
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* this2=NULL;
    void* pElement=NULL;
    int i;

    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        this2= ll_newLinkedList();
        for(i=0; i<ll_len(this); i++)
        {
            pElement=ll_get(this,i);
            if(pFunc(pElement))
            {
                ll_add(this2,pElement);
            }
        }
    }
    return this2;
}
