#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

int index1 =0;
int pre_data[20];
int pre_counter = 0;
int comp_data[20];
int comp_counter = 0;
int comp_data1[20];
int comp_counter1 = 0;
Node * newNode(Data data,Node *parent)
{
    Node *node = malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->data = data;
    return node;
}



Data * searchNode(Node *n,Data d)
{
    if (n->data.value == d.value)
    {
        return &(n->data);
    }
    else if (n->data.value < d.value)
    {
        if(n->right == NULL)
        {
             NULL;
        }
        else
        {
             searchNode(n->right,d);
        }
    }
    else if (n->data.value > d.value)
    {
        if(n->left == NULL)
        {
            NULL;
        }
        else
        {
             searchNode(n->left,d);
        }
    }
}

Data * insertNode(Node *n,Data d)
{
    if (n->data.value < d.value)
    {
        if(n->right == NULL)
        {
            n->right = malloc(sizeof(Node));
            n->right->left = n->right->right = NULL;
            n->right->parent = n;
            n->right->data = d;
        }
        else
        {
            insertNode(n->right,d);
        }
    }
    else if (n->data.value > d.value)
    {
        if(n->left == NULL)
        {
            n->left = malloc(sizeof(Node));
            n->left->left = n->left->right = NULL;
            n->left->parent = n;
            n->left->data = d;
        }
        else
        {
            insertNode(n->left,d);
        }
    }
    else if (n->data.value == d.value)
    {
      return NULL;
    }

}

Data * search(Tree* bst,Data d)
{
    if (bst->root == NULL)
    {
        return NULL;
    }
   // else if (bst->root->data.value == d.value)
   // {
   //     return &(d);
   // }
    else
        {
          searchNode(bst->root,d);
        }

}

Data * insertTree(Tree* bst,Data d)
{
    if (bst->root == NULL)
    {
        bst->root = malloc(sizeof(Tree));
        bst->root->data=d;
        bst->root->left = NULL;
        bst->root->right = NULL;
        bst->root->parent = NULL;
    }
    else
        {
         insertNode(bst->root,d);
        }

}

Data * cloneTree(Node* n)
{
   if (n != NULL)
    {
       // pre_counter = 0;
       pre_data[pre_counter] = n->data.value;
       pre_counter = pre_counter + 1 ;
    }
    if (n != NULL)
    {
    cloneTree(n->left);
    cloneTree(n->right);}
}
Tree * clone(Tree* bst)
{
    cloneTree(bst->root);
    int i;
    Tree *copy_bst = newTree();
   // copy_bst->root = NULL;
    for (i = 0; i < pre_counter; i++){

		insertTree(copy_bst, (Data){pre_data[i]});
	}
	//free(copy_bst);
	return copy_bst;
}
Data * compareTree1(Node* n)
{
   if (n != NULL)
    {
        // comp_counter = 0;
       comp_data[comp_counter] = n->data.value;
       comp_counter = comp_counter + 1 ;
    }
    if (n != NULL)
    {
    compareTree1(n->left);
    compareTree1(n->right);}
}
Data * compareTree2(Node* n)
{
   if (n != NULL)
    {
        // comp_counter = 0;
       comp_data1[comp_counter1] = n->data.value;
       comp_counter1 = comp_counter1 + 1 ;
    }
    if (n != NULL)
    {
    compareTree2(n->left);
    compareTree2(n->right);}
}
int compare(Tree *t, Tree * copy)
{
    if (t == NULL || copy == NULL)
    {
        return 0;
    }
     comp_counter1 = 0;

     comp_counter = 0;
    compareTree1(t->root);
    compareTree2(copy->root);
    int i;
    for (i = 0; i < comp_counter; i++)
    {
        if (comp_data1[i] != comp_data[i])
        {
            return 0;
        }
	}
	return 1;
}

void traverse (Tree* bst,Node * n,Data *array)
{
    if (n != NULL)
    {
        traverse(bst,n->left,array);
        array[index1] = n->data;
        index1 = index1 + 1;
        traverse(bst,n->right,array);
    }
}
void sort(Tree* bst,Data *d)
{
    traverse(bst,bst->root,d);
}
void deleteLeaf(Node* leaf,Tree* bst)
{
    if (leaf == bst->root && leaf->data.value == bst->root->data.value)
            {
                free(bst->root);
                bst->root = NULL;
                return;
            }
    if (leaf->data.value < leaf->parent->data.value)
    {
        leaf->parent->left = NULL;
    }
    else
    {
        leaf->parent->right = NULL;
    }
    free(leaf);
}
Node * readNode(Node *n,Data d)
{

    if (n->data.value == d.value)
    {
        return n;
    }
    else if (n->data.value < d.value)
    {
        if(n->right == NULL)
        {
            return NULL;
        }
        else
        {
            return readNode(n->right,d);
        }
    }
    else if (n->data.value > d.value)
    {
        if(n->left == NULL)
        {
           return NULL;
        }
        else
        {
            return readNode(n->left,d);
        }
    }
}
void shortCircuit(Node* n)
{

    if (n==n->parent->left)
    {
        if (n->left != NULL)
        {
            n->parent->left = n->left;
            n->left->parent=n->parent;
        }
        else
        {
            n->parent->left = n->right;
            n->right->parent=n->parent;
        }
    }
    else
    {
        if(n->left != NULL)
        {
            n->parent->right = n->left;
            n->left->parent=n->parent;
        }
        else
        {
            n->parent->right=n->right;
            n->right->parent=n->parent;
        }
    }
    free(n);
}
Node* SearchRightMin(Node* n)
{
    n = n->right;
    while (n->left != NULL)
        n = n->left;
    return n;
}
void promote(Node* n,Tree* bst)
{
    Node* to_promote = SearchRightMin(n);
    n->data = to_promote->data;

    if (to_promote->left == NULL && to_promote->right == NULL)
    {
        deleteLeaf(to_promote,bst);
    }
    else
    {
        shortCircuit(to_promote);
    }
    //free(to_promote);
}
void removeData(Tree* bst,Data d)
{
    Node* to_delete = readNode(bst->root,d);

    if (to_delete != NULL)
    {
        if(to_delete->left == NULL && to_delete->right == NULL)
        {
            deleteLeaf(to_delete,bst);

        }
        else if(/*to_delete->data.value != bst->root->data.value &&*/ to_delete->left == NULL || to_delete->right == NULL)
        {
           if (to_delete->data.value == bst->root->data.value)
            {
                if (to_delete->left != NULL)
                {

                    bst->root = to_delete->left;
                    free(to_delete);
                }
                else
                {

                    bst->root = to_delete->right;
                     free(to_delete);
                }
            }
            else
            {
              shortCircuit(to_delete);
            }
        }
        else
        {
            promote(to_delete,bst);
        }
    }
   //free(to_delete);
}
void deletePost(Tree *bst, Node*n)
{
    if(n != NULL)
    {

        deletePost(bst, n->left);
        deletePost(bst,n->right);
        if(n->parent != NULL)
        {
            deleteLeaf(n,bst);
           // free(bst->root);
        }
        else
        {
           // deleteLeaf(n, bst);
            free(bst->root);
        }

    }
}
void deleteTree (Tree * bst)
{
    deletePost(bst,bst->root);
    free(bst);
}
Tree * newTree()
{
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    tree->insert = insertTree;
    tree->sort = sort;
    tree->search = search;
    tree->clone = clone;
    tree->compare = compare;
    tree->removeData = removeData;
    tree->delete = deleteTree;
    return tree;
}
