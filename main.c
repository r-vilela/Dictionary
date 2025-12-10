#define _XOPEN_SOURCE_EXTENDED 1
#include <dict.h>
#include <string.h>
#include <stdio.h>

int main()
{
    Dict *dict = createDict();

    loadDict(dict);

    showDictSpan(dict);
    printf("\n");

    Word word;
    /*

    strcpy(word.word, "Abatir");
    strcpy(word.description, "verbo");
    strcpy(word.translated, "Abater");
    insertWordSpan(dict, &word);

    strcpy(word.word, "Abducacion");
    strcpy(word.description, "Substantivo Feminino");
    strcpy(word.translated, "Abducao");
    insertWordSpan(dict, &word);

    strcpy(word.word, "Abierto");
    strcpy(word.description, "Adjetivo");
    strcpy(word.translated, "Aberto");
    insertWordSpan(dict, &word);

    strcpy(word.word, "Ablandar");
    strcpy(word.description, "Verbo");
    strcpy(word.translated, "Amolecer");
    insertWordSpan(dict, &word);

    showDictSpan(dict);
    /*

    printf("\n");

    strcpy(word.word, "Abierto");

    printf("REMOVENDO\n");
    removeWordSpan(dict, &word);

    showDictSpan(dict);

    printf("\n");

    strcpy(word.word, "Abatir");

    printf("erro?\n");
    removeWordSpan(dict, &word);

    showDictSpan(dict);

    strcpy(word.word, "Ablandar");

    removeWordSpan(dict, &word);
    printf("\n");

    showDictSpan(dict);

    strcpy(word.word, "Abducacion");

    removeWordSpan(dict, &word);
    printf("VAZIO\n");

    showDictSpan(dict);

    strcpy(word.word, "Ablandar");
    strcpy(word.description, "Verbo");
    strcpy(word.translated, "Amolecer");
    insertWordSpan(dict, &word);

    printf("\n");

    showDictSpan(dict);

    Word *search = searchWordSpan(dict, &word);

    if (search!=NULL)
        printf("ACHOU!!\n");
    else
        printf("Nao achou T-T\n");


    printf("SALVANDO\n\n");
    */
    saveDict(dict);

    destroyDict(dict);

}

