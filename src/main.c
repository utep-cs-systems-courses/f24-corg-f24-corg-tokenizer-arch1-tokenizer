#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "tokenizer.h"

#include "history.h"



#define MAX 50



int main(void) {

  // Simple UI

  char userInput[MAX];

  HistoryList* history = init_history();  // Initialize history list correctly

  char** tokens;



  printf("Welcome to my Tokenizer!\nEnter a phrase after '$'.\nEnter 'e' to exit or '!' to see your phrases so far\n");



  while (*userInput != 'e') {

    printf("$ ");

    fgets(userInput, MAX, stdin);

    printf("\n");



    if (*userInput != 'e' && *userInput != '!') {

      printf("The string you entered: %s", userInput);  // Test Echo

      tokens = tokenize(userInput);

      printf("The string you entered Tokenized is:\n");

      print_tokens(tokens);



      add_history(history, userInput);  // Add the input to history

    }


    if (*userInput == '!') {
      printf("Your Phrases so far:\n");
      print_history(history);  // Print history
    }
  }

  free_tokens(tokens);
  free_history(history);  // Free history
  printf("Thank you for using my Tokenizer! GOODBYE!\n");
  return 0;
}
