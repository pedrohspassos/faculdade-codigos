#include <iostream>
#include "queue.h"

using namespace std;

  queue::queue(){
    first = 0; 
    last = 0;
    estrutura = new Tipo_Item(); //inicializando o vetor

  } 
  queue::~queue(){

    delete [] estrutura;
  } 
 
  bool queue::isempty(){

      return (first == last); // se true = lista vazia

  } 
 
  bool queue::isfull(){

      return ((last - first) == max_item); // se true = lista cheia
  } 
 
  void queue::enqueue(Tipo_Item item){ //semppre adiociona o elemnto no indice last
      if(isfull()){
        cout << "*** A fila esta cheia, retire um elemento primeiro ***\n";
      } else{

        estrutura[last % max_item] = item; // add o item a posicao livre da fila
        last++;          //                    

      }

  }  
  
  Tipo_Item queue::dequeue(){
      if(isempty()){
        cout << "*** A fila esta vazia, não existe elemetos para retirar ***\n";
        return 0;
     } else{
        first++;
        return estrutura[(first-1) % max_item];
      
     }
  }  
  
  void queue::print(){

    if(isempty()){
      cout<<"A fila esta vazia, nao a nada a mostrar!\n";
    }else{

    cout << "Queue: [ ";
    for(int i = first; i < last; i++){
      cout << estrutura[i % max_item] << " ";
    }
    
    cout << " ] \n";
    }

  } 