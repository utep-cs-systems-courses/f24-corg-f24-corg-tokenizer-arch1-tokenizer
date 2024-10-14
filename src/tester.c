#include <string.h>

#include <stdio.h>

#include "tokenizer.h"

#include "history.h"



/* Tokenizer test cases */

void test_string_length() {

  if (string_length("happy") != 5)

    printf("FAILED: string_length('happy') == 5\n");

  else

    printf("PASSED: string_length('happy') == 5\n");

}



void test_is_valid_character() {

  if (is_valid_character(' ') != 0)

    printf("FAILED: is_valid_character(' ') == 0\n");

  else

    printf("PASSED: is_valid_character(' ') == 0\n");



  if (is_valid_character('h') != 1)

    printf("FAILED: is_valid_character('h') == 1\n");

  else

    printf("PASSED: is_valid_character('h') == 1\n");

}



void test_find_word_start() {

  char *str = "  happy";

  if (find_word_start(str) != &str[2])

    printf("FAILED: find_word_start('  happy') == &str[2]\n");

  else

    printf("PASSED: find_word_start('  happy') == &str[2]\n");

}


void test_find_word_terminator() {
  char *str = "happy joy";
  char *empty = "";
  if (find_word_terminator(str) != &str[5])
    printf("FAILED: find_word_terminator('happy joy') == &str[5]\n");
  else
    printf("PASSED: find_word_terminator('happy joy') == &str[5]\n");

  if (find_word_terminator(empty) != empty)
    printf("FAILED: find_word_terminator(empty) == empty\n");
  else
    printf("PASSED: find_word_terminator(empty) == empty\n");
}

void test_count_words() {
  char *str = "happy happy joy joy";
  if (count_words(str) != 4)
    printf("FAILED: count_words('happy happy joy joy') == 4\n");
  else
    printf("PASSED: count_words('happy happy joy joy') == 4\n");
}

void test_tokenize() {
  char *str = "happy happy joy joy";
  char **tokens = tokenize(str);
  if (strcmp(tokens[0], "happy") != 0 || strcmp(tokens[1], "happy") != 0 ||
      strcmp(tokens[2], "joy") != 0 || strcmp(tokens[3], "joy") != 0)
    printf("FAILED: tokenize('happy happy joy joy')\n");
  else
    printf("PASSED: tokenize('happy happy joy joy')\n");
  free_tokens(tokens);
}

/* History test cases */
void test_add_history() {
  List* list = init_history();
  add_history(list, "happy");
  if (strcmp(list->root->str, "happy") != 0)
    printf("FAILED: add_history(list, 'happy')\n");
  else
    printf("PASSED: add_history(list, 'happy')\n");

  add_history(list, "joy");
  if (strcmp(list->root->next->str, "joy") != 0)
    printf("FAILED: add_history(list, 'joy')\n");
  else
    printf("PASSED: add_history(list, 'joy')\n");
}

void test_get_history() {
  List* list = init_history();
  add_history(list, "happy");
  if (strcmp(get_history(list, 1), "happy") != 0)
    printf("FAILED: get_history(list, 1)\n");
  else
    printf("PASSED: get_history(list, 1)\n");
}

/* Main function to run the tests */
int main() {
  printf("Running tokenizer tests...\n");
  test_string_length();
  test_is_valid_character();
  test_find_word_start();
  test_find_word_terminator();
  test_count_words();
  test_tokenize();

  printf("\nRunning history tests...\n");
  test_add_history();
  test_get_history();

  return 0;
}
