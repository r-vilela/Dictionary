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
    v1.value = 23;
    Value v2;
    v2.value = 15;
    Value v3;
    v3.value = 12;
    Value v4;
    v4.value = 19;
    Value v5;
    v5.value = 29;
    Value v6;
    v6.value = 25;
    Value v7;
    v7.value = 20;

    insert(tree, &v1);
    insert(tree, &v2);
    insert(tree, &v6);
    insert(tree, &v3);
    insert(tree, &v4);
    insert(tree, &v5);
    insert(tree, &v7);

    show(tree);

    //if(search(tree, &v4))
    //    printf("Achou\n");
    //else
    //    printf("Nao achou\n");

    rmv(tree, &v1);

    printf("\n");
    show(tree);

    destroy(tree);

}

