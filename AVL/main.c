#include "avl.h"
#include <stdio.h>

typedef struct data_type{
    int value;
}Value;

int compData(Value *data1, Value *data2){
    if(data1->value == data2->value)
        return 0;
    if(data1->value > data2->value)
        return -1;
    else
        return 1;
}

void showData(Value *data){
    printf("%d\n", data->value);
}

int main()
{
    printf("Criou\n");
    AVL *tree = create();

    Value v1;
    v1.value = 1;

    Value v2;
    v2.value = 2;

    Value v3;
    v3.value = 3;

    Value v4;
    v4.value = 4;

    insert(tree, &v1);
    insert(tree, &v3);
    //insert(tree, &v4);
    insert(tree, &v2);

    if(search(tree, &v4))
        printf("Achou\n");
    else
        printf("Nao achou\n");


    show(tree);
}

