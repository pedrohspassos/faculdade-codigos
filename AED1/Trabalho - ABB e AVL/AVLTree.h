#include <string>

using namespace std;

#ifndef AVLTREE_H
#define AVLTREE_H

typedef string TreeEntry;

class AVLTree
{
public:
  AVLTree();
  ~AVLTree();
  void clear();
  int leaves();
  int height();
  void searchInsert(TreeEntry x);
  void write();

  int compSearchtInsert = 0; // qtd comparaçoes AVL
  int countRotation = 0;     // qtd rotacoes AVL

private:
  // definicao de estruturas
  struct TreeNode;

  typedef TreeNode *TreePointer;

  struct TreeNode
  {
    TreeEntry entry;
    TreePointer leftNode, rightNode;
    int count;
    int bal; // -1 0 +1
  };

  // campos
  TreePointer root;

  // metodos
  void clear(TreePointer &t);
  int leaves(TreePointer &t);
  int height(TreePointer &t);
  void searchInsert(TreeEntry x, TreePointer &pA, bool &h);
};
#endif