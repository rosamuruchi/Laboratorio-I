#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);
int resizeDown(ArrayList* this);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    void** aux;//pElement es un doble puntero a void
    int flag = 0;

    //Esto se pasa a funcion resizeUP
    if(this!=NULL && pElement!=NULL)
    {
        if(this->size == this->reservedSize)//si esta agotada la capacidad de la memoria, hago el realloc para que no se pise
        {
            aux = (void**) realloc(this->pElements, sizeof(void*)* (this->reservedSize + AL_INCREMENT));//necesito espacio en memoria para espacio a void
            //verfico que el auxiliar no sea nulo
            if(aux!=NULL)
            {
                this->pElements = aux;//que doble puntero apunte a donde apunta el auxiliar
                //tengo que modificar el reserved size
                this->reservedSize = this->reservedSize + AL_INCREMENT;//lo que habia mas lo quiero sumar
            }
            else
            {
                flag=1;//es nulo, no se cumple
            }
        }

        if(flag==0)//para no repetir el agregado
        {
            this->pElements[this->size]=pElement;//guardo en la dirección de memoria 0. Uso size, que siempre apunta al siguiente elemento
            this->size++;
            //tengo que pedir memoria

            returnAux=0;

        }


    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this->pElements); //limpio pElements
        free(this); // limpio la lista
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Delete arrayList //devuelve el tamaño del size
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    int tamano;

    if(this!=NULL)
    {
        tamano=this->size; //tamaño del size
        returnAux=tamano;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<this->len(this))
    {
        returnAux=*(this->pElements+index); // retorna el puntero al elemento que se encuentra en el index
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int longitud;

    if(this!=NULL && pElement!=NULL)
    {
        returnAux=0;
        longitud= this->len(this); //mido el tamaño de la lista
        for(i=0; i<longitud; i++)
        {
            if(*(this->pElements+i)==pElement)// si pElement es igual a elemento de la lista
            {
                returnAux=1;
                break;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position (inserta)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;
    int longitud;

    if(this!=NULL && pElement!=NULL)
    {
        longitud= this->len(this); //mido el tamaño de la lista

        if(index<=longitud && index>=0) // compruebo de que el indice este entre 0 y el tamaño de la lista
        {
            if(index==longitud) //si llega al tope
            {
                this->size++; //agrando el size
                this->add(this,pElement); // agrega pElement al final de la lista
            }
            else
            {
                *(this->pElements+index)=pElement; //inserta pElement en el arraylist con el indice especificado

            }
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief  Remove an element by index //elimina
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int longitud;

    if(this!=NULL)
    {
        longitud= this->len(this); //tamaño de el arraylist

        if(index<=longitud && index>=0)
        {
            if(!(contract(this,index))) //si esto es verdadero entra.
            {
                returnAux=0;
            }
        }
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list (borra)
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;
    void** aux; //creo un axiliar

    if(this!=NULL)
    {
        free(this->pElements); //elimino todos los elementos
        aux= (void**)malloc(sizeof(void*)*AL_INITIAL_VALUE);
        this->size=0;
        this->pElements=aux;
        this->reservedSize=AL_INITIAL_VALUE;
        free(aux); //borrar el auxilioar que cree y no volverlo a usar sino a punta  ala direccion de memoria
        returnAux=0;
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    ArrayList* aux; //creo un auxiliar
    int i;

    if(this!=NULL)
    {
        aux =al_newArrayList();

        if(this->reservedSize>aux->reservedSize)// si la lista es mayor a la auxiliar
        {
            aux->pElements=(void**) realloc(aux->pElements,sizeof(void*)*this->reservedSize);//agrandar el espacio de la lista auxiliar igual a la lista this
        }

        for(i=0; i<this->size; i++)
        {
            *(aux->pElements+i)=*(this->pElements+i);//copia los elementos del array ala nueva array
        }
        aux->size=this->size; //copia el cantidad de elementos
        aux->reservedSize=this->reservedSize;//copia el tamaño reservado

        returnAux=aux;
    }
    return returnAux;
}




/** \brief Inserts the element at the specified position (desplaza los elementos e inserta en la posicion del index)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    int longitud;

    if(this!=NULL && pElement!=NULL)
    {
        longitud= this->len(this); //longitud del tamaño de el arraylist

        if(index<=longitud && index>=0) //si index es mayor o igual a cero y menor e igual a la longitud del arraylist
        {
            if(expand(this,index)==0) //si se pudo agrandar el tamaño del arraylist (realloc)
            {
                //*(this->pElements+index)=pElement;
                //returnAux=0;
                if(this->set(this,index,pElement)==0) //si se pudo insertar el index en la lista
                {
                    returnAux=0;
                }
            }
        }
    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int longitud,i;

    if(this!=NULL && pElement!=NULL)
    {
        returnAux=0;
        longitud= this->len(this);// la longitud del arraylist
        for(i=0; i<longitud; i++)
        {
            if(*(this->pElements+i)==pElement) // si encuentra el elemento en la lista
            {
                returnAux=i; //devuelve la posicion
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this) //es vacio
{
    int returnAux = -1;
    int longitud;

    if(this!=NULL)
    {
        longitud=this->len(this); //tamaño del size del arraylist
        if(longitud==0) //si el tamaño del size es cero
        {
            returnAux=1; //es vacio
        }
        else
        {
            returnAux=0; //si no es vacio
        }
    }
    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it. (retorna un puntero que se encuentra en el index y luego lo elimina de la lista)
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    void* auxElement;
    int longitud;

    if(this!=NULL)
    {
        longitud= this->len(this); //tamaño del size del arraylist
        if(index<=longitud && index>=0)
        {
            auxElement=this->get(this,index); //devuelve el puntero por el index
            if(auxElement!=NULL)
            {
                //if(contract(this,index)==0)
                    if(this->remove(this,index)==0) //si elimina el elemnto en el index especificado del arraylist
                    {
                        returnAux=auxElement;
                    }
            }
        }
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    ArrayList* listaDos;
    int i;

    listaDos= al_newArrayList();

    if(this!=NULL && listaDos!=NULL)
    {
        if(from>=0 && from<to) //desde >0 y desde< hasta
        {
            for(i=from; i<=to ; i++)
            {
                listaDos->add(listaDos,*(this->pElements+i)); //agregando al arraylist
            }
            returnAux=listaDos;
        }
    }
    return returnAux ;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int i;
    int contenido;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for(i=0; i<this->size; i++)
        {
            contenido=this->contains(this,*(this2->pElements+i)); //comprueba elementos son contenidos
            if(contenido==0) //si contenido es vacio
            {
                returnAux=0; //no contiene todos los elementos
                break;
            }

        }
    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i,j;
    int limite;
    void* aux;

    if(this!=NULL && pFunc!=NULL)
    {
        if(order==0 || order==1) //si order es uno o el otro , entra
        {
            returnAux=0;
            limite=this->size;
            for(i=0; i<limite-1 ; i++)
            {
                for(j=i+1; j<limite; j++)
                {
                    if(order==1)
                    {
                        if(pFunc((this->get(this,i)),this->get(this,j))>0) //ordena de mayor
                        {
                            aux=*(this->pElements+i);
                            *(this->pElements+i)=*(this->pElements+j);
                            *(this->pElements+j)=aux; //puntero al elemnto que se encuentra en el indice j
                        }
                    }
                    if (order==0)
                    {
                        if((pFunc((this->get(this,i)),this->get(this,j))<0))//ordena de menor
                        {
                            aux=*(this->pElements+i);
                            *(this->pElements+i)=*(this->pElements+j);
                            *(this->pElements+j)=aux;
                        }
                    }
                }
            }
        }
    }




    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this) //agranda el tamaño del array
{
    int returnAux = -1;

    void** aux;

    if(this!=NULL)
    {
        if(this->size == this->reservedSize) //si llega al tope
        {
            aux = (void**) realloc(this->pElements, sizeof(void*)* (this->reservedSize + AL_INCREMENT)); // agrando espacio
            if(aux!=NULL)
            {
                this->pElements = aux;

                this->reservedSize = this->reservedSize + AL_INCREMENT;
                returnAux=0;
            }
        }
    }

    return returnAux;

}

int resizeDown(ArrayList* this)//achicar el tamaño del array // lo contrario del resizeUp
{
    int returnAux = -1;

    void** aux;

    if(this!=NULL)
    {
        if( this->reservedSize-(this->size)>AL_INCREMENT) //
        {
            aux = (void**) realloc(this->pElements, sizeof(void*)* (this->reservedSize - AL_INCREMENT)); //agrando espacio
            if(aux!=NULL)
            {
                this->pElements = aux;
                this->reservedSize = this->reservedSize - AL_INCREMENT;
                returnAux=0;
            }
        }
    }

    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i,j;

    if(this!=NULL)
    {
        resizeUp(this); //agranda el tamaño del array
        for(i=this->size-1 ; i>=index ; i--)
        {
            resizeUp(this);
            j=i+1;
            *(this->pElements+j)=*(this->pElements+i);
        }
        this->size++; //incremento el size
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i,j;

    if(this!=NULL )
    {
        if(index>=0 && index< this->size)
        {
            for(i=index; i<this->size; i++)
            {
                j=i+1; // uno mas adelante del index
                *(this->pElements+i)=*(this->pElements+j);//pisa
            }
            this->size--; //
            resizeDown(this); //achico el tamaño del array
            returnAux=0;
        }

        /*
        this->size--;

        aux = (void**) realloc(this->pElements, sizeof(void*)* (this->reservedSize - AL_INCREMENT));

        this->pElements = aux;
        this->reservedSize = this->reservedSize - AL_INCREMENT;

        returnAux=0;*/


    }

    return returnAux;

}
