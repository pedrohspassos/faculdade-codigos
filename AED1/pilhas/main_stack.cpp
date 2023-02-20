#include <iostream>
#include "stack.h"

using namespace std;

int main(){
     Stack pilha1;
    Tipo_item item;
    int opcao;

    cout << "##### Stack #####" << endl;

    do{
         cout << "Digite 0 para sair do programa" << endl;
         cout << "Digite 1 para  inserir elemto" << endl;
         cout << "Digite 2 para  remover elemento" << endl;
         cout << "Digite 3 para imprimir pilha" << endl;
         cout << "Digite 4 para tamanho da pilha" << endl;

         cin >> opcao;

        if(opcao == 1){
            cout << "Digite o elemento a ser inserido: \n";
            cin >> item;
            pilha1.push(item);
        }else if(opcao == 2){
            item = pilha1.pop();
            cout << "Elemento removido: " << item << endl;
        }else if(opcao == 3){
            pilha1.imprimir();
        } else if(opcao == 4){
            item = pilha1.size();  
            cout << " Pilha tem tamanho: " << item << endl;
        }
         
    } while(opcao != 0);
       

    

    return 0;
}

   
