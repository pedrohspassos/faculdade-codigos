#include <iostream>
#include <iomanip>
#include <climits>
#include <sstream>
#include <cstring>
#include <cmath>

#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
  root = NULL;
}
BinarySearchTree::~BinarySearchTree()
{
  clear();
}

void BinarySearchTree::clear()
{
  clear(root);
  root = NULL;
}

void BinarySearchTree::clear(TreePointer &t)
{
  if (t != NULL)
  {
    clear(t->leftNode);
    clear(t->rightNode);
    delete t;
  }
}

int BinarySearchTree::nodes()
{
  return nodes(root);
}

int BinarySearchTree::nodes(TreePointer &t)
{
  if (t == NULL)
    return 0;
  else
    return (1 + nodes(t->leftNode) + nodes(t->rightNode));
}

int BinarySearchTree::leaves()
{
  return leaves(root);
}

int BinarySearchTree::leaves(TreePointer &t)
{
  if (t == NULL)
    return 0;
  else if (t->leftNode == NULL && t->rightNode == NULL)
    return 1;
  else
    return leaves(t->leftNode) + leaves(t->rightNode);
}

int BinarySearchTree::height()
{
  return height(root);
}
//------------------------------------------------------------

int BinarySearchTree::height(TreePointer &t)
{
  if (t == NULL)
    return -1;
  else
  {
    int L, R;
    L = height(t->leftNode);
    R = height(t->rightNode);
    if (L > R)
      return L + 1;
    else
      return R + 1;
  }
}

int BinarySearchTree::minHeight()
{

  int qtd_node = nodes(root);

  return log2(qtd_node); // log2(n + 1) - 1 esta arredondando para baixo
}

void BinarySearchTree::searchInsert(TreeEntry x)
{
  searchInsert(x, root);
}

void BinarySearchTree::searchInsert(TreeEntry x, TreePointer &t)
{
  if (t == NULL)
  {
    t = new TreeNode;
    t->entry = x;
    t->count = 1;
    t->leftNode = t->rightNode = NULL;
  }

  else
  {
    compSearchtInsert++;
    if (x < t->entry)
      searchInsert(x, t->leftNode);

    else
    {
      compSearchtInsert++;
      if (x > t->entry)
        searchInsert(x, t->rightNode);
      else
        t->count++;
    }
  }
}

void BinarySearchTree::postOrder(TreeNode *vetor, int &index)
{

  postOrder(root, vetor, index);
}

void BinarySearchTree::process(TreePointer &t, TreeNode *vetor, int &index)
{

  vetor[index].entry = t->entry;
  vetor[index].count = t->count;
  index++;
}

void BinarySearchTree::postOrder(TreePointer &t, TreeNode *vetor, int &index)
{
  if (t != NULL)
  {
    postOrder(t->leftNode, vetor, index);
    postOrder(t->rightNode, vetor, index);
    process(t, vetor, index);
  }
}
void BinarySearchTree::write()
{

  qtdWords = totalNumberOfWords();
  qtdDifferentWords = nodes();

  cout << "\tNumero total de palavras distintas: " << qtdDifferentWords << endl;
  cout << "\tNumero total de palavras: " << qtdWords << endl;
  cout << "\tAltura da arvore minima: " << minHeight() << endl;
  cout << "\tAltura ABB: " << height() << endl;
  cout << "\tNumero de folhas ABB: " << leaves() << endl;
  cout << "\tNumero de comparacoes ABB: " << compSearchtInsert << endl;
}

int BinarySearchTree::totalNumberOfWords()
{
  return totalNumberOfWords(root);
}

int BinarySearchTree::totalNumberOfWords(TreePointer &t)
{
  if (t != NULL)
  {
    return t->count + totalNumberOfWords(t->leftNode) + totalNumberOfWords(t->rightNode);
  }

  return 0;
}
