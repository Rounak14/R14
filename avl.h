#ifndef AVL_H
#define AVL_H

#include "node.h"

using namespace std;

class avl
{
    public:
        avl();
        int insertNode(node* newNode, node* headNode);
        bool treeInsertNode(node* newNode);
        node* deleteNode(node* victimNode);
        node* searchKey(int, node*);
        node* treeSearchKey(int);
        void inorderTraversal(node* headNode);
        void treeInorderTraversal();
        void rebalance(node* n);
        int updateHeights(node *n);
        node* rotateRight(node* n);
        node* rotateLeft(node* n);
        node* rotateRightThenLeft(node* n);
        node* rotateLeftThenRight(node* n);

        virtual ~avl();
    protected:
    private:
        node* head;

};

#endif // AVL_H

