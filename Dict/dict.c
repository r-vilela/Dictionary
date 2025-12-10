#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVL Setting

int compData(Word *data1, Word *data2) {
  if (data1->id == data2->id)
    return 0;
  if (data1->id > data2->id)
    return -1;
  else
    return 1;
}

void showData(Word *data) {
  printf("%s \n\t\t%s - %s\n", data->word, data->description, data->translated);
}

// Dict Setting

typedef struct dict {
  AVL *dictPort;
  AVL *dictSpan;
} dict;

void loadDict(Dict *dict) {
  FILE *arqSpan = fopen("dadosSpan.txt", "r");
  if (arqSpan == NULL)
    return;
  Word word;
  while (!feof(arqSpan)) {
    fscanf(arqSpan, "%s %s %s\n", word.word, word.description, word.translated);
    insertWordSpan(dict, &word);
  }
  fclose(arqSpan);

  FILE *arqPort = fopen("dadosPort.txt", "r");
  if (arqPort != NULL) {
    while (!feof(arqPort)) {
      Word word;
      showData(&word);
      fscanf(arqPort, "%s %s %s\n", word.word, word.description,
             word.translated);
      insertWordPort(dict, &word);
    }
    fclose(arqPort);
  }
}

void saveDict(Dict *dict) {
  Word *word = getPosAVL(dict->dictSpan, 0);

  FILE *arqSpan = fopen("dadosSpan.txt", "wa");

  for (int i = 0; word != NULL; i++, word = getPosAVL(dict->dictSpan, i)) {
    fprintf(arqSpan, "%s %s %s\n", word->word, word->description,
            word->translated);
  }
  fprintf(arqSpan, "\n");
  fclose(arqSpan);

  word = getPosAVL(dict->dictPort, 0);

  FILE *arqPort = fopen("dadosPort.txt", "wa");

  for (int i = 0; word != NULL; i++, word = getPosAVL(dict->dictPort, i)) {
    fprintf(arqPort, "%s %s %s\n", word->word, word->description,
            word->translated);
  }
  fprintf(arqPort, "\n");
  fclose(arqPort);
}

Dict *createDict() {
  Dict *dict = (Dict *)malloc(sizeof(Dict));
  if (dict == NULL)
    return NULL;

  dict->dictSpan = createAVL();
  dict->dictPort = createAVL();

  return dict;
}

void destroyDict(Dict *dict) {
  destroyAVL(dict->dictSpan);
  destroyAVL(dict->dictPort);

  free(dict);
}

int removeWord(AVL *dict, Word *word) {
  word->id = createID(word->word);

  return rmvAVL(dict, word);
}

int insertWord(AVL *dict, Word *word) {
  Word *new = (Word *)malloc(sizeof(Word));
  if (new == NULL)
    return 0;
  strcpy(new->word, word->word);
  strcpy(new->description, word->description);
  strcpy(new->translated, word->translated);

  new->id = createID(new->word);

  return insertAVL(dict, new);
}

void showDict(AVL *dict) { showAVL(dict); }

void showDictIdx(AVL *dict, int start, int end) {
  Word *word = getPosAVL(dict, start);
  printf("imprimindo %d - %d\n", start, end);
  for (; word != NULL && start <= end; start++, word = getPosAVL(dict, start)) {
    printf("\t%d - ", start);
    showData(word);
  }
}

Word *searchWord(AVL *dict, Word *word) {
  word->id = createID(word->word);

  return searchAVL(dict, word);
}

int createID(char *word) {
  int total;
  for (int i = total = 0; word[i] != '\0'; i++, total = total + i * word[i])
    ;
  return total;
}

int removeWordSpan(Dict *dict, Word *word) {
  return removeWord(dict->dictSpan, word);
}

int removeWordPort(Dict *dict, Word *word) {
  return removeWord(dict->dictPort, word);
}

int insertWordSpan(Dict *dict, Word *word) {
  return insertWord(dict->dictSpan, word);
}

int insertWordPort(Dict *dict, Word *word) {
  return insertWord(dict->dictPort, word);
}

void showDictPort(Dict *dict) { showDict(dict->dictPort); }

void showDictSpan(Dict *dict) { showDict(dict->dictSpan); }

void showDictIdxPort(Dict *dict, int start, int end) {
  showDictIdx(dict->dictPort, start, end);
}

void showDictIdxSpan(Dict *dict, int start, int end) {
  showDictIdx(dict->dictSpan, start, end);
}

Word *searchWordPort(Dict *dict, Word *word) {
  return searchWord(dict->dictSpan, word);
}

Word *searchWordSpan(Dict *dict, Word *word) {
  return searchWord(dict->dictSpan, word);
}
