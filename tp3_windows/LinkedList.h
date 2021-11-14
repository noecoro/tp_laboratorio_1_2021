/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//todas las func reciveb cm 1er argumento listaEmpleados LinkedList con la q estoy trabajando
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);//devuelve el tamaño dinamico p saber cuantos hay adentro  cuantos agregue le paso la linklidts y me devuelv la cant de elem q tiene
//printf("cant d eemp ", ll_len(listaemp); devueleve los indices 0 1 2 etc
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//deja agregar un elemento al final es igual a empleados[0] = pE; etc [1] [2]
void* ll_get(LinkedList* this, int index);//leer el elemento de una posicion recibe la lista y la posicion q quiero leer pe= ll_get(listaemp,i) lo q antes era pe=empleado[i];
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);//le pasamos la listemp ll_remove(listemp,1); para la baja
int ll_clear(LinkedList* this);//borra la lista completa la pasa a cero vacia pero existe
int ll_deleteLinkedList(LinkedList* this);//elimina tod la lista
//es el free libero lista dinamica solo usar si cree una linked la use y sali de la fun y perdi la referencia  de ella o sea si ya perdi acceso la  libero no se puede usar mas
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
