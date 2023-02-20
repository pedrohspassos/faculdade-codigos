#include <iostream>
#include "stack.h"

using namespace std;        




   
     Stack::Stack(){  // construtora
        top = 0;
        estrutura  = new Tipo_item[max_item];
     } 

     Stack::~Stack(){  // destrutora 
        delete[] estrutura;
     } 

     bool Stack::full(){ // verifica pilha cheia - true = cheia
        return (top == max_item);

     } 

     bool Stack::empty(){// verifica pilha vazia - true = vazia
        return(top == 0);
     } 

     void Stack::push(Tipo_item item){ // inseri elementos
        if(full()){
            cout << "A  pilha esta cheia" << endl;
        }else{
            estrutura[top] = item;
            top++;
        
        }

     } 

     Tipo_item Stack::pop(){ // retirar elementos
        if(empty()){
            cout << "A pilha esta vazia" << endl;
            return 0;
        } else{
            top--;
            return (estrutura[top]);

        }
     } 

     void Stack::imprimir(){
        cout<<" Stack: [ ";
        for(int i = 0; i < size(); i++){
            cout<< estrutura[i] << " ";
        }
        cout<<" ]"<<endl;
     } 

     int Stack::size(){
        return top;
     } // tamanoho pilha      

