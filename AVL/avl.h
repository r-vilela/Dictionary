#ifndef AVL_TREE_H
#define AVL_TREE_H

/**
 * @struct DataType
 * @brief Struct que sera usado para armazenar o dado definido pelo usuario
 * @warning Struct vital para a biblioteca, deve ser ultilizado para seu
 * funcionamento
 */
typedef struct data_type DataType;

/**
 * @brief Funcao para saber se os elementos sao iguais, ou o data1 esta a
 * direita, ou a esquerda
 * @param Ponteiro para um DataType e outro DataType
 * @return deve retornar -1 se o data1 se encontra a esquerda, 0 se os datas sao iguais e 1 se o data esta a direta
 */
int compData(DataType *data1, DataType *data2);

void showData(DataType *data);

typedef struct node Node;

typedef struct avl AVL;

// AVL operations
void right_rot(Node **root);

void left_rot(Node **root);

void left_righ_rot(Node **root);

void righ_left_rot(Node **root);

int rmvNode(Node **root, DataType *data, int *decreased);

int insertNode(Node **root, DataType *data, int *increased);

void showNode(Node *root, int lvl);

DataType *searchNode(Node *node, DataType *data);

void destroyNode(Node *node);

void findMin(Node **node);

// Commom operations
AVL *create();

int rmv(AVL *tree, DataType *data);

int insert(AVL *tree, DataType *data);

DataType *search(AVL *tree, DataType *data);

void show(AVL *tree);

void destroy(AVL *tree);

#endif
