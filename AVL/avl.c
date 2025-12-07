#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    DataType *info;
    int bf;
    struct node *left;
    struct node *right;
}Node;

typedef struct avl{
    Node *root;
}AVL;

AVL *create(){
    AVL *tree = (AVL *) malloc(sizeof(AVL));
    if(tree == NULL)
        return NULL;

    tree->root = NULL;

    return tree;
}

void right_rot(Node **root){
    Node *dad = (*root);
    Node *son = dad->left;
    dad->left = (*root)->right;
    son->right = dad;

    dad->bf = 0;
    son->bf = 0;

    (*root) = son;
}

void left_rot(Node **root){
    Node *dad = (*root);
    Node *son = dad->right;
    dad->right = (*root)->left;
    son->left = dad;

    dad->bf = 0;
    son->bf = 0;

    (*root) = son;
}

void left_right_rot(Node **root){
    Node *grandPa = (*root);
    Node *dad = grandPa->left;
    Node *son = dad->right;

    grandPa->left = son->right;
    dad->right = son->left;

    son->left = dad;
    son->right = grandPa;

    switch(son->bf){
        case -1:
            dad->bf = 1;
            grandPa->bf = 0;
            break;
        case 0:
            dad->bf = 0;
            grandPa->bf = 0;
            break;
        case 1:
            dad->bf = 0;
            grandPa->bf = -1;
            break;
    }
    son->bf = 0;
    (*root) = son;
}

void right_left_rot(Node **root){
    Node *grandPa = (*root);
    Node *dad = grandPa->right;
    Node *son = dad->left;

    grandPa->right = son->left;
    dad->left = son->right;

    son->right = dad;
    son->left = grandPa;

    switch(son->bf){
        case -1:
            dad->bf = 1;
            grandPa->bf = 0;
            break;
        case 0:
            dad->bf = 0;
            grandPa->bf = 0;
            break;
        case 1:
            dad->bf = 0;
            grandPa->bf = -1;
            break;
    }
    son->bf = 0;
    (*root) = son;
}

int removeNode(Node **root, DataType *data, int *decreased){
    if((*root) == NULL)
        return 0;

    if(compData((*root)->info, data) == 0){
        if((*root)->left == NULL && (*root)->left == NULL){
            free((*root));
            (*root) = NULL;
            (*decreased) = 1;
            return 1;
        }
    }else if(compData((*root)->info, data) == 1){
        if(removeNode(&((*root)->right), data, decreased)){
            if(*decreased){
                switch ((*root)->bf) {
                    case -1:
                        (*root)->bf = 0;
                        (*decreased) = 0;
                        break;
                    case 0:
                        (*root)->bf = 1;
                        (*decreased) = 0;
                        break;
                    case 1:
                        (*root)->bf = 1;
                        (*decreased) = 0;
                        break;
                }
            }
        }
    }
}

int remove(AVL *tree, DataType *data){
    int decreased=0;
    return removeNode(&(tree->root), data, &decreased);
}

int insertNode(Node **root, DataType *data, int *increased){
    if((*root)==NULL){
        (*root) = (Node *) malloc(sizeof(Node));
        if((*root) == NULL) return 0;

        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->bf = 0;
        (*root)->info = data;

        (*increased) = 1;

        return 1;
    }

    if(compData((*root)->info, data) == -1)
        if(insertNode(&(*root)->left, data, increased)){
            if(*increased){
                switch((*root)->bf){
                    case -1:
                        if(((*root)->left)->bf == -1)
                            right_rot(&(*root));
                        else
                            left_right_rot(&(*root));
                        *increased = 0;
                        break;
                    case 0:
                        (*root)->bf = -1;
                        *increased = 1;
                        break;
                    case 1:
                        (*root)->bf = 0;
                        *increased = 0;
                        break;
                }
            }
            return 1;
        } else return 0;
    else if(compData((*root)->info, data) == 1)
        if(insertNode(&(*root)->right, data, increased)){
            if(*increased){
                switch((*root)->bf){
                    case -1:
                        (*root)->bf = 0;
                        *increased = 0;
                        break;
                    case 0:
                        (*root)->bf = 1;
                        *increased = 1;
                        break;
                    case 1:
                        if(((*root)->right)->bf == 1)
                            left_rot(&(*root));
                        else
                            right_left_rot(&(*root));
                        *increased = 0;
                        break;
                }
            }
            return 1;
        }

    return 0;
}

int insert(AVL *tree, DataType *data){
    int increased = 0;
    return insertNode(&(tree->root), data, &increased);
}

void showNode(Node *root, int lvl){
    if(root == NULL) return;

    showNode(root->left, lvl+1);

    for(int i=0;i<lvl;i++)
        printf("..");
    printf("..");
    showData(root->info);

    showNode(root->right, lvl+1);

}

void show(AVL *tree){
    showNode(tree->root, 0);
}

DataType *searchNode(Node *node, DataType *data){
    if(node == NULL)return NULL;

    if(compData(node->info, data) == 0)
        return node->info;
    if(compData(node->info, data) == 1)
        return searchNode(node->right, data);

    return searchNode(node->left, data);
}

DataType *search(AVL *tree, DataType *data){
    return searchNode(tree->root, data);
}

void destroyNode(Node *node){
    if(node == NULL) return;
    destroyNode(node->left);
    destroyNode(node->right);

    free(node);
}

void destroy(AVL *tree){
    destroyNode(tree->root);

    free(tree);
}

