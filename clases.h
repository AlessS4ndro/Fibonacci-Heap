#include<iostream>
#include"../Lista-Enlazada/clases.h"
#include"../Lista-Enlazada/listlink.h"

using namespace std;

template<class T>
struct FNode
{
  T data;
  char color;
  int grado;
  FNode<T> *father;
  ListLink<FNode<T> *> hijos;
  
  FNode(T data){this->data=data;color='b';grado=0;}
};
template<class T>
class FibonacciHeap
{
  ListLink<FNode<T>*> roots;
  FNode<T>* dataMin;
  FNode<T>* *tabla;
  int size;
 public:
  FibonacciHeap(){size=0;dataMin=NULL;}
  void add(T );
  void merge();
  void unir(FNode<T> *,FNode<T> *);
  void decrease_key(FNode<T> *);
  void swap(FNode<T> *,FNode<T> *);
  void delete_(FNode<T> *);
  void delete_min();
  void find_min();
  void print();
  void view_min(){cout<<"min es "<<dataMin->data<<endl;}
};

template<class T>
void FibonacciHeap<T>::add(T data)
{
  
  FNode<T> *nuevo=new FNode<T>(data);
  if(!dataMin)dataMin=nuevo;
  if(data<dataMin->data)dataMin=nuevo;
  roots.push_front(nuevo);
  size++;
}
template<class T>
void FibonacciHeap<T>::merge()
{
  NodeSimple<FNode<T> *> *head=roots.get_root();
  while(head && head->left){ //// si existen porlos menos dos nodos
    if(head->value->grado==head->left->value->grado){//si los grados de dos adyacentes son iguales
      unir(head->value,head->left->value);
    }
  }
}
template<class T>
void FibonacciHeap<T>::unir(FNode<T> *p,FNode<T> *q)
{
  if(p->data<q->data){
    p->hijos.push_front(q);
    p->grado++;
    roots.delete_(q);
  }
  else{
    q->hijos.push_front(p);
    q->grado++;
    roots.delete_(p);
  }
}
template<class T>
void FibonacciHeap<T>::decrease_key(FNode<T> *p)
{
  if(!p)return;
  if(!(p->father))return;
  if(p->father->data<p->data)return;
  swap(p,p->father);
  decrease_key(p->father);
}
template<class T>
void FibonacciHeap<T>::swap(FNode<T> *p,FNode<T> *q)
{
  T temp=p->data;
  p->data=q->data;
  q->data=temp;
}
/*
template<class T>
void FibonacciHeap<T>::delete(FNode<T> *)
{
  
}
*/
template<class T>
void FibonacciHeap<T>::delete_min()
{
  int i;
  tabla=new FNode<T>*[size]; ///////// creamos la tabla para almacenar punteros
  NodeSimple<FNode<T> *> *head; ////////
  FNode<T> *transicion;
  
  do{ ///// recorremos la lista roots en el bucle
    head=roots.get_root();
    i=head->value->grado; ////////// almacenamos el grado en i;
    if(tabla[i]==NULL){ ////////// preguntamos si no existe puntero en la posicion   
      transicion=roots.pop_front(); ////////// almacenamos
      tabla[i]=transicion; ///// almacenamos el puntero
    }
    else{        //////// si existe un elemento en la posicion
      roots.push_front(tabla[i]); //// pusheamos el puntero a roots
      merge();
    }
 }while(head);
}


template<class T>
void FibonacciHeap<T>::print()
{
  NodeSimple<FNode<T> *> *head=roots.get_root();
  while(head!=NULL){
    cout<<"->"<<head->value->data<<"_"<<head->value->grado;
    head=head->left;
  }
  cout<<"->NULL"<<endl;
}
template<class T>
void FibonacciHeap<T>::find_min()
{
  NodeSimple<FNode<T> *> *head=roots.get_root();
 
  if(head)dataMin=head->value;
  while(head){
    if(head->value->data < dataMin->data)
      dataMin=head->value;
    head=head->left;
  } 
}

