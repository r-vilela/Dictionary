#include "Dict/dict.h"
#define _XOPEN_SOURCE_EXTENDED 1
#include <dict.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int main() {
  Dict *dict = createDict();
  Word *word, new;
  int opc;
  char opcChar;
  int isPort = 0;

  loadDict(dict);

  char buffer[128] = {0};
  int len = 0;

  do {
    clearScreen();

    if (isPort)
      printf(BOLD CYAN "\t===== PORTUGUESE DICTIONARY =====\n\n" RESET);
    else
      printf(BOLD CYAN "\t===== SPANISH DICTIONARY =====\n\n" RESET);

    printf(GREEN "1) Add word\n" RESET);
    printf(YELLOW "2) Search for Word\n" RESET);
    printf(YELLOW "3) List Words\n" RESET);
    printf(ORANGE "4) Change Dictionary\n" RESET);
    printf(ORANGE "5) Remove word\n" RESET);
    printf(RED "0) Quit\n" RESET);

    printf(BOLD CYAN "Enter option: " RESET);
    scanf("%d", &opc);

    switch (opc) {
    case 1:
      strcpy(new.word, "0");
      strcpy(new.description, "0");
      strcpy(new.translated, "0");
      opcChar = 'y';
      while (opcChar == 'y' || opcChar == 'Y') {
        clearScreen();

        if (isPort)
          printf(BOLD CYAN "\t=== ADD A NEW PORTUGUESE WORD ===\n" RESET);
        else
          printf(BOLD CYAN "\t=== ADD A NEW SPANISH WORD ===\n" RESET);

        printf(GREEN "\nAdd a new Word to the Dictionary\n" RESET);

        if (new.word[0] != '0') {
          printf(YELLOW "\tWord: ");
          printf(BOLD "%s\n" RESET, new.word);
          if (new.description[0] != '0') {
            printf(YELLOW "\tDescription: ");
            printf(BOLD "%s\n" RESET, new.description);
            if (new.translated[0] != '0') {
              printf(YELLOW "\tTranslated: ");
              printf(BOLD "%s\n" RESET, new.translated);
            } else
              printf(YELLOW "\tTranslated: " RESET);
          } else
            printf(YELLOW "\tDescription: " RESET);
        } else {
          printf(YELLOW "\tWord: " RESET);
        }

        if (opcChar == 'y' || opcChar == 'Y') {
          if (new.word[0] == '0')
            scanf(" %[^'\n']", new.word);
          else if (new.description[0] == '0')
            scanf(" %[^'\n']", new.description);
          else if (new.translated[0] == '0')
            scanf(" %[^'\n']", new.translated);
          else {
            if (isPort) {
              if (!insertWordPort(dict, &new)) {
                strcpy(new.word, "0");
                strcpy(new.description, "0");
                strcpy(new.translated, "0");
              }
            } else {
              if (!insertWordSpan(dict, &new)) {
                printf("added\n");
                strcpy(new.word, "0");
                strcpy(new.description, "0");
                strcpy(new.translated, "0");
              }
            }
            printf(YELLOW "\nWant to add another? (Y/y) (N/n) ");
            scanf(" %c", &opcChar);
          }
        }
      }
      break;
    case 2:
      strcpy(new.word, "0");
      word = NULL;
      opcChar = 'y';
      while (opcChar == 'y' || opcChar == 'Y') {
        clearScreen();
        if (isPort)
          printf(BOLD CYAN "\t=== SEARCH FOR A PORTUGUESE WORD ===\n\n" RESET);
        else
          printf(BOLD CYAN "\t=== SEARCH FOR A SPANISH WORD ===\n\n" RESET);

        if (new.word[0] == '0') {
          printf(GREEN "Search for a word: " RESET);
        } else {
          if (word == NULL) {
            printf(RED "Word not found ");
            printf(BOLD "%s\n" RESET, new.word);
            printf(YELLOW "Want to try again? (Y/y) (N/n) ");
            scanf(" %c", &opcChar);
          } else {
            printf(YELLOW "\tWord: ");
            printf(BOLD "%s\n" RESET, word->word);
            printf(YELLOW "\tDescription: ");
            printf(BOLD "%s\n" RESET, word->description);
            printf(YELLOW "\tTranslated: ");
            printf(BOLD "%s\n" RESET, word->translated);

            printf(GREEN "Search for a word: " RESET);
          }
        }

        if (opcChar == 'y' || opcChar == 'y') {
          scanf(" %[^'\n']", new.word);
          if (isPort)
            word = searchWordPort(dict, &new);
          else
            word = searchWordSpan(dict, &new);
        }
      }
      break;

    case 3:
      int start = 0;
      int end = 10;
      int page = 1;
      while (page) {
        clearScreen();
        if (isPort)
          printf(BOLD CYAN "\t=== LIST PORTUGUESE DICTIONARY ===\n\n" RESET);
        else
          printf(BOLD CYAN "\t=== LIST SPANISH DICTIONARY ===\n\n" RESET);

        printf(YELLOW "Page %d\n" RESET GREEN, page);
        if (isPort)
          showDictIdxPort(dict, start, end);
        else
          showDictIdxSpan(dict, start, end);
        printf(YELLOW "p - Previous page\t" RESET);
        printf(YELLOW "n - Next page\t\n" RESET);

        printf(RED "s - Return to menu\t\n" RESET);

        printf(CYAN "Enter option: " RESET);
        scanf("%s", &opcChar);

        if (opcChar == 'n' || opcChar == 'N') {
          start = start + 10;
          end = end + 10;
          page++;
        } else if ((opcChar == 'p' || opcChar == 'P') && page > 1) {
          start = start - 10;
          end = end - 10;
          page--;
        } else if (opcChar == 's' || opcChar == 'S') {
          page = 0;
        }
      }
      opc = 3;
      break;

    case 4:
      isPort = !isPort;
      break;

    case 5:
      strcpy(new.word, "0");
      int deleted = 0;
      opcChar = 'y';
      while (opcChar == 'y' || opcChar == 'Y') {
        clearScreen();
        if (isPort)
          printf(BOLD CYAN
                 "\t=== REMOVE WORD FROM PORTUGUESE WORD ===\n\n" RESET);
        else
          printf(BOLD CYAN "\t=== REMOVE WORD FROM SPANICH WORD ===\n\n" RESET);

        if (new.word[0] == '0') {
          printf(ORANGE "Enter the word to be removed: " RESET);
        } else {
          if (deleted) {
            printf(ORANGE "\tWord: ");
            printf(BOLD "%s\n" RESET, new.word);

            printf(RED "REMOVED\n" RESET);
          } else {
            printf(RED "Word not found ");
            printf(BOLD "%s\n" RESET, new.word);
          }
          printf(YELLOW "Want to try again? (Y/y) (N/n) ");
          scanf(" %c", &opcChar);
        }

        if (opcChar == 'y' || opcChar == 'y') {
          scanf(" %[^'\n']", new.word);
          if (isPort)
            deleted = removeWordPort(dict, &new);
          else
            deleted = removeWordSpan(dict, &new);
        }
      }
      break;
    case 0:
      clearScreen();
      printf(RED "SAVING . . .\n" RESET);
    }
  } while (opc != 0);

  /*
  showDictSpan(dict);

  strcpy(word.word, "Abatir");
  strcpy(word.description, "verbo");
  strcpy(word.translated, "Abater");
  // insertWordSpan(dict, &word);

  removeWordSpan(dict, &word);

  showDictSpan(dict);

  Word *search = searchWordSpan(dict, &word);

  if (search != NULL)
    printf("ACHOU!!\n");
  else
    printf("Nao achou T-T\n");
  */

  saveDict(dict);

  destroyDict(dict);
}
