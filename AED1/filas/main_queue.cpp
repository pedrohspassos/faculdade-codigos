#include <iostream>
#include "queue.h"
using namespace std;

int main(){

  queue fila1;
  int opcao;
  Tipo_Item item; //variavel acrescimo e retirada

  cout << " ***** Programa gerador de Queues *****\n";

  do{
      cout << "Digite 0 para parar o programa!\n";
      cout << "Digite 1 para parar inserir um elemento!\n";
      cout << "Digite 2 para parar remover um elemento!\n";
      cout << "Digite 3 para parar imprimir a fila!\n";
      cin >> opcao;

      if(opcao == 1){
        cout << "Digite o elemento que deseja inserir na fila: \n";
        cin >> item;
        fila1.enqueue(item);
      }else if (opcao == 2){

        item = fila1.dequeue();
        cout << "O elemento removido eh: " << item << endl;
      }else if (opcao == 3){
        fila1.print();
      }

  } while (opcao != 0);
  



}