#include <iostream>
#include <iomanip>
#include <climits>
#include <sstream>
#include <cstring>

#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree()
{
  root = NULL;
}

AVLTree::~AVLTree()
{
  clear();
}

void AVLTree::clear()
{
  clear(root);
  root = NULL;
}

void AVLTree::clear(TreePointer &t)
{
  if (t != NULL)
  {
    clear(t->leftNode);
    clear(t->rightNode);
    delete t;
  }
}

int AVLTree::leaves()
{
  return leaves(root);
}

int AVLTree::leaves(TreePointer &t)
{
  if (t == NULL)
    return 0;
  else if (t->leftNode == NULL && t->rightNode == NULL)
    return 1;
  else
    return leaves(t->leftNode) + leaves(t->rightNode);
}

int AVLTree::height()
{
  return height(root);
}

int AVLTree::height(TreePointer &t)
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

void AVLTree::searchInsert(TreeEntry x)
{
  bool h = false;
  searchInsert(x, root, h);
}

void AVLTree::searchInsert(TreeEntry x, TreePointer &pA, bool &h)
{
  TreePointer pB, pC;

  if (pA == NULL)
  { // inserir
    pA = new TreeNode;
    h = true;
    pA->entry = x;
    pA->count = 1;
    pA->leftNode = pA->rightNode = NULL;
    pA->bal = 0;
  }
  else
  {
    compSearchtInsert++;
    if (x < pA->entry)
    {
      searchInsert(x, pA->leftNode, h);

      if (h)
      {
        switch (pA->bal)
        {
        case -1:
          pA->bal = 0;
          h = false;
          break;
        case 0:
          pA->bal = +1;
          break;
        case +1:
          pB = pA->leftNode;
          if (pB->bal == +1)
          {
            countRotation++;

            pA->leftNode = pB->rightNode;
            pB->rightNode = pA;
            pA->bal = 0;
            pA = pB;
          }
          else
          {
            countRotation++;

            pC = pB->rightNode;
            pB->rightNode = pC->leftNode;
            pC->leftNode = pB;
            pA->leftNode = pC->rightNode;
            pC->rightNode = pA;

            if (pC->bal == +1)
              pA->bal = -1;
            else
              pA->bal = 0;

            if (pC->bal == -1)
              pB->bal = +1;
            else
              pB->bal = 0;

            pA = pC;
          }

          pA->bal = 0;
          h = false;
        }
      }
    }
    else
    {
      compSearchtInsert++;
      if (x > pA->entry)
      {
        searchInsert(x, pA->rightNode, h);

        if (h)
        {
          switch (pA->bal)
          {
          case +1:
            pA->bal = 0;
            h = false;
            break;
          case 0:
            pA->bal = -1;
            break;
          case -1:
            pB = pA->rightNode;
            if (pB->bal == -1)
            {
              countRotation++;

              pA->rightNode = pB->leftNode;
              pB->leftNode = pA;
              pA->bal = 0;
              pA = pB;
            }
            else
            {
              countRotation++;

              pC = pB->leftNode;
              pB->leftNode = pC->rightNode;
              pC->rightNode = pB;
              pA->rightNode = pC->leftNode;
              pC->leftNode = pA;

              if (pC->bal == -1)
                pA->bal = +1;
              else
                pA->bal = 0;

              if (pC->bal == +1)
                pB->bal = -1;
              else
                pB->bal = 0;

              pA = pC;
            }
            pA->bal = 0;
            h = false;
          }
        }
      }

      else
        pA->count++;
    }
  }
}

void AVLTree::write()
{

  cout << "\tAltura AVL: " << height() << endl;
  cout << "\tNumero de folhas AVL: " << leaves() << endl;
  cout << "\tNumero de comparacoes AVL: " << compSearchtInsert << endl;
  cout << "\tNumero de rotacoes AVL: " << countRotation << endl;
}
