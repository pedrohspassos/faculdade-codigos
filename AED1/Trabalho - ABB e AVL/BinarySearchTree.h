#include <string>

using namespace std;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef string TreeEntry;

// definicao de estruturas
struct TreeNode;

typedef TreeNode *TreePointer;

struct TreeNode
{
  TreeEntry entry;
  TreePointer leftNode, rightNode;
  int count;
};

class BinarySearchTree
{

public:
  BinarySearchTree();
  ~BinarySearchTree();
  void clear();
  int nodes();
  int leaves();
  int height();
  int minHeight();
  void searchInsert(TreeEntry x);
  void write();
  int totalNumberOfWords();
  void postOrder(TreeNode *vetor, int &index);

  int compSearchtInsert = 0;
  int qtdWords = 0;          // armazena qtd palavras
  int qtdDifferentWords = 0; // armazena qtd palavras distintas

private:
  // campos
  TreePointer root;

  // metodos
  void clear(TreePointer &t);
  int nodes(TreePointer &t);
  int leaves(TreePointer &t);
  int height(TreePointer &t);
  void searchInsert(TreeEntry x, TreePointer &t);
  int totalNumberOfWords(TreePointer &t);
  void postOrder(TreePointer &t, TreeNode *vetor, int &index);
  void process(TreePointer &t, TreeNode *vetor, int &index);
};
#endif