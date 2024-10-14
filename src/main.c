#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include "tokenizer.c"

#include "history.c"



#define MAX 50



int main(void) {

  // Simple UI for the tokenizer

  char userInput[MAX];

  List* history = init_history();  // Initialize history list

  char** tokens;



  printf("Welcome to my Tokenizer! \nEnter a phrase after '$'.\n");

  printf("Enter 'e' to exit or '!' to see your phrases so far.\n");



  // Loop until the user enters 'e' for exit

  while (1) {

    printf("$ ");

    fgets(userInput, MAX, stdin);  // Get user input

    userInput[strcspn(userInput, "\n")] = '\0';  // Remove newline character



    // Check if the user wants to exit

    if (strcmp(userInput, "e") == 0) {

      break;

    }



    // Show history if the user enters '!'

    if (strcmp(userInput, "!") == 0) {

      printf("Your phrases so far:\n");

      print_history(history);

    }


    // Otherwise, tokenize and store the input
    else {
      printf("The string you entered: %s\n", userInput);  // Echo the input

      tokens = tokenize(userInput);  // Tokenize the input string
      printf("The string you entered tokenized is:\n");
      print_tokens(tokens);  // Print the tokens

      add_history(history, userInput);  // Add the input to history
      free_tokens(tokens);  // Free the tokens after use
    }
  }

  // Free the history list
  free_history(history);

  printf("Thank you for using my Tokenizer!\n");
  return 0;
}
