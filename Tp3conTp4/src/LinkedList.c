#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    this->pFirstNode = NULL;
    this->size = 0;

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int len = -1;
    if(this != NULL)
    {
    	len = this->size;
    }
    return len;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* auxiliarNodo = NULL;
    int indice;
    if(this != NULL && nodeIndex >=0 && nodeIndex < ll_len(this))
    {
    	auxiliarNodo = (Node*)this->pFirstNode;
    	indice = 0;
    	do
    	{
    		if(indice == nodeIndex)
    		{
    			break;
    		}
    		else
    		{
    			auxiliarNodo = (Node*)auxiliarNodo->pNextNode;
    			indice++;
    		}
    	}while(auxiliarNodo != NULL);

    }
    return auxiliarNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    Node* auxiliarNodo = NULL;
    Node* auxiliarNodoAnterior;
    int retorno = -1;

    if(this != NULL && nodeIndex <= ll_len(this))
    {
    	auxiliarNodo = (Node*)malloc(sizeof(Node*));
    	auxiliarNodo->pElement = pElement;
    	retorno = 0;

    	if(nodeIndex == 0)
    	{
    		auxiliarNodo->pNextNode = this->pFirstNode;
    		this->pFirstNode = auxiliarNodo;
    		this->size++;
    	    retorno = 0;
    	}
    	else if(nodeIndex == this->size)
    	{
    		auxiliarNodo->pNextNode = NULL;
    		auxiliarNodoAnterior = getNode(this,nodeIndex-1);
    		auxiliarNodoAnterior->pNextNode = auxiliarNodo;
    		this->size++;
    		retorno = 0;
    	}
    	else
    	{
    		auxiliarNodoAnterior = getNode(this,nodeIndex);
    		auxiliarNodo->pNextNode = auxiliarNodoAnterior->pNextNode;
    		auxiliarNodoAnterior->pNextNode = auxiliarNodo;
    		this->size++;
    		retorno = 0;
    	}


    }

    return retorno;
}




/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int auxiliarIndice;

    if(this != NULL)
    {
    	auxiliarIndice = ll_len(this);
     if(addNode(this,auxiliarIndice,pElement) == 0)
     {
    	 retorno = 0;
     }

    }

    return retorno;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* auxiliarNodo = NULL;
    Node* auxiliarNodo2;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxiliarNodo2 = getNode(this,index);
    	if(auxiliarNodo2 != NULL)
    	{
    		auxiliarNodo = auxiliarNodo2->pElement;
    	}
    }


    return auxiliarNodo;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int retorno = -1;
    Node* auxiliarNodo;

    if(this != NULL && index >=0 && index <= ll_len(this))
    {
    	auxiliarNodo = getNode(this,index);
    	if(auxiliarNodo != NULL)
    	{
    		auxiliarNodo->pElement = pElement;
    		retorno = 0;

    	}
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int retorno = -1;
    Node* auxiliarNodo;
    Node* auxiliarNodo2;
    if(this != NULL && index > -1 && index < ll_len(this)){

        auxiliarNodo = getNode(this, index);

        if(auxiliarNodo != NULL)
        {
            if(index == 0)
            {
                this->pFirstNode = auxiliarNodo->pNextNode;
                this->size--;
                retorno = 0;
            }
            else
            {
                auxiliarNodo2 = getNode(this, index-1);
                auxiliarNodo2->pNextNode = auxiliarNodo->pNextNode;
                this->size--;
                retorno = 0;
            }

            free(auxiliarNodo);
        }
    }

    return retorno;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
	int retorno = -1;

	if(this != NULL)
	{
		while(ll_len(this) > 0)
		{
			ll_remove(this, 0);
		}

		retorno = 0;
	}

	    return retorno;
  /* int retorno = -1;
   int i;

   if(this != NULL)
   {
	   for(i=ll_len(this);i<=ll_len(this);i--)
	   {
		   ll_remove(this,i);
		   retorno = 0;
	   }

   }

    return retorno;*/
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int retorno = -1;

    if(this != NULL)
    {
    	if(ll_clear(this)== 0)
    	{
    		free(this);
    		retorno = 0;
    	}
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int retorno = -1;
    int i;
    Node* auxiliarNodo;


    if(this != NULL)
    {
    	for(i=0;i<ll_len(this);i++)
    	{
    		auxiliarNodo = getNode(this,i);
    		if(pElement == (Node*)auxiliarNodo->pElement)
    		{
    			retorno = i;
    			break;
    		}
    	}
    }



    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int retorno = -1;

    if(this != NULL)
    {
    	if(ll_len(this) > 0)
    	{
    		retorno = 0;
    	}
    	else
    	{
    		retorno = 1;
    	}
    }

    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int retorno = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	if(addNode(this,index,pElement)== 0)
    	{
    		retorno = 0;
    	}
    }

    return retorno;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* auxiliarNodo = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	auxiliarNodo = ll_get(this,index);
    	if(auxiliarNodo != NULL)
    	{
    		ll_remove(this,index);
    	}
    }

    return auxiliarNodo;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int retorno = -1;
    if(this != NULL)
    {
    	if(ll_indexOf(this,pElement) == -1)
    	{
    		retorno = 0;
    	}
    	else
    	{
    		retorno = 1;
    	}
    }

    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    int flag = 1;
    int i;
    void* auxiliarP;

    if(this != NULL && this2 != NULL)
    {
    	for(i=0;i<ll_len(this2);i++)
    	{
    		auxiliarP = (void*)ll_get(this2,i);
    		if(ll_contains(this,auxiliarP) != 1)
    		{
    			flag = 0;
    			break;
    		}
    	}
    	retorno = flag;
    }


    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElemento;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to <= ll_len(this) && to >= from)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(i=from;i<to;i++)
    		{
    			pElemento = (void*)ll_get(this,i);
    			{
    				if(pElemento != NULL)
    				{
    					ll_add(cloneArray,pElemento);
    				}
    			}
    		}
    	}
    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this,0,ll_len(this));

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno =-1;
    void* pElemento = NULL;
    void* pElemento2 = NULL;
    int i;
    int j;


    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
    	for(i=0;i<ll_len(this)-1;i++)
    	{
    		for(j=i+1;j<ll_len(this);j++)
    		{
    			pElemento = ll_get(this,i);
    			pElemento2 = ll_get(this,j);

    			if(pFunc(pElemento,pElemento2) == 1 && order)
    			{
    				ll_set(this,i,pElemento2);
    				ll_set(this,j,pElemento);
    			}
    			else if(pFunc(pElemento,pElemento2) == -1 && !order)
    			{
    				ll_set(this,i,pElemento2);
					ll_set(this,j,pElemento);
    			}

    		}

    	}
    	retorno = 0;
    }

    return retorno;

}
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;
	int i;
	void* pElemento;

	if(this != NULL && pFunc != NULL)
	{
		retorno = 0;
		for(i=0;i<ll_len(this);i++)
		{
			pElemento = ll_get(this,i);

			if(pFunc(pElemento) == -1)
			{
				printf("\nError en mapeo del elemento\n");
				retorno = -1;
			}

		}
	}

	return retorno;
}
LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
	LinkedList* listaFiltrada = NULL;
	void* pElemento = NULL;
	int i;

	if(this != NULL && pFunc != NULL)
	{
	   listaFiltrada = (LinkedList*)ll_newLinkedList();

		for(i=0;i<ll_len(this);i++)
		{
			pElemento = ll_get(this,i);

			if(pFunc(pElemento) == 1)
			{
				ll_add(listaFiltrada,pElemento);
			}
		}
	}
	return listaFiltrada;
}
int ll_count(LinkedList* this,int (*pFunc)(void*))
{
	int retorno = -1;
	int i;
	void* pElemento;
	int contador = 0;

	if(this != NULL && pFunc != NULL)
	{
		retorno = 0;
		for(i=0;i<ll_len(this);i++)
		{
			pElemento = ll_get(this,i);
			contador = contador + pFunc(pElemento);
		}

	} printf("\nSueldos totales a pagar: %d\n",contador);



	return retorno;
}
