#ifndef DICTIONARY_H
#define DICTIONAY_H
#include <avl.h>

typedef struct dict Dict;

typedef struct data_type {
  int id;
  char word[40];
  char description[40];
  char translated[40];
} Word;


// Dicionary operations
int removeWordSpan(Dict *dict, Word* word);

int removeWordPort(Dict *dict, Word* word);

int insertWordSpan(Dict *dict, Word* word);

int insertWordPort(Dict *dict, Word* word);

void showDictPort(Dict *dict);

void showDictSpan(Dict *dict);

Word *searchWordPort(Dict *dict, Word* word);

Word *searchWordSpan(Dict *dict, Word* word);

// Main Operations
Dict *createDict();

void loadDict(Dict *dict);

void saveDict(Dict *dict);

void destroyDict(Dict *dict);

int removeWord(AVL *dict, Word *word);

int insertWord(AVL *dict, Word *word);

void showDict(AVL *dict);

Word *searchWord(AVL *dict, Word* word);

int createID(char *word);

#endif
