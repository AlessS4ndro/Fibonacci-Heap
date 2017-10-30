#include<iostream>
#include"clases.h"

using namespace std;

int main()
{
  FibonacciHeap<int> heap;
  int n;
  
  do{
    cin>>n;
    heap.add(n);
    heap.print();
  }while(n!=999);

  //heap.find_min();
  heap.view_min();
  heap.delete_min();
  heap.print();
  heap.find_min();
  heap.view_min();

  return 0;
}
