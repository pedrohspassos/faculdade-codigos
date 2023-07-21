
// Pedro Henrique Da Silva Passos  Numero USP - 12683096
// Funcionamento - apenas compilar (g++ main.cpp BinarySearchTree.cpp AVLTree.cpp -o executavel.exe) e rodar o executavel

#include <iostream>
#include <fstream>
#include <iomanip>

#include "BinarySearchTree.h"
#include "AVLTree.h"

using namespace std;

int main()
{

  string filesName[3] = {"mam-na-np-lo.txt", "exame_10000-na-np-lo.txt", "biblia-na-np-lo.txt"};

  BinarySearchTree bst[3];
  AVLTree avl[3];
  for (int i = 0; i < 3; i++)
  {
    string word;
    ifstream theInput(filesName[i]);

    // ler cada palavra do arquivo e inserir
    while (theInput >> word)
    {
      bst[i].searchInsert(word);
      avl[i].searchInsert(word);
    }
    theInput.close();
    cout << endl;
    cout << filesName[i] << ":" << endl;
    bst[i].write();
    avl[i].write();

    //////////////////////////////////////////////////////////////////////////////////////////////

    // Medias ABB e AVL

    int qtdWord = bst[i].qtdWords;                    // qtd de palavras
    int qtdDifferentWords = bst[i].qtdDifferentWords; // qtd de palavras distintas
    int compSearchABB = bst[i].compSearchtInsert;     // qtd comparações ABB
    int compSearchAVL = avl[i].compSearchtInsert;     // qtd comparaçoes AVL
    int countRotation = avl[i].countRotation;         // qtd de rotacoes

    // Calculando media comparaçoes ABB

    float averageCompABB = 0.0;  // armazena media comparacoes ABB
    float averageCompAVL = 0.0;  // armazena media comparacoes AVL
    float averageRotation = 0.0; // armazena a media das rotacoes AVL

    averageCompABB = float(compSearchABB) / qtdWord;
    averageCompAVL = float(compSearchAVL) / qtdWord;
    averageRotation = float(countRotation) / qtdDifferentWords;

    // calculando media comparacoes e rotacoes AVL

    cout << endl;
    cout << "\tMedia de comparacoes ABB: " << setprecision(4) << averageCompABB << endl;
    cout << "\tMedia de comparacoes AVL: " << setprecision(4) << averageCompAVL << endl;
    cout << "\tMedia de rotacoes AVL: " << setprecision(2) << averageRotation << endl
         << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Achando as palavras com mais frequencia

    TreeNode *vetor = new TreeNode[qtdDifferentWords];

    int index = 0;
    bst[i].postOrder(vetor, index);

    for (int i = 0; i < qtdDifferentWords - 1; i++)
    {
      for (int j = 0; j < qtdDifferentWords - i - 1; j++)
      {
        if (vetor[j].count < vetor[j + 1].count)
        {
          TreeNode temp = vetor[j];
          vetor[j] = vetor[j + 1];
          vetor[j + 1] = temp;
        }
      }
    }

    cout << "*** Frequencia ****" << endl;
    for (int i = 0; i < 10; i++)
    {

      cout << "Posicao " << i << ": " << endl;
      cout << "Palavra: " << vetor[i].entry << " = "
           << "Frequencia: " << vetor[i].count << endl
           << endl;
    }

    delete[] vetor;
  }

  system("pause");
  return 0;
}