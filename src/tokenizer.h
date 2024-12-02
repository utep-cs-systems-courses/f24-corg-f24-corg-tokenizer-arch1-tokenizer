#ifndef _TOKENIZER_

#define _TOKENIZER_



/* Check if the character is a space, tab, or newline */

int space_char(char c) {

  return (c == ' ' || c == '\t' || c == '\n');

}



/* Check if the character is not a space, tab, or newline */

int non_space_char(char c) {

  return !space_char(c);

}



/* Find the start of the next word (non-space character) */

char *word_start(char *str) {

  while (*str && space_char(*str)) {

    str++;

  }

  return (*str) ? str : 0;

}



/* Find the end of the current word (space or string terminator) */

char *word_end(char *str) {

  while (*str && non_space_char(*str)) {

    str++;

  }

  return str;

}



/* Count the number of words in the string */

int count_words(char *str) {

  int count = 0;

  while (*str) {

    str = word_start(str);

    if (str) {

      count++;

      str = word_end(str);

    }

  }

  return count;

}



/* Create a copy of the string, allocating memory */
char *copy_str(char *inStr, short len) {
  char *newStr = (char *)malloc(len + 1);
  strncpy(newStr, inStr, len);
  newStr[len] = '\0';
  return newStr;
}

/* Split the string into tokens (words) */
char **tokenize(char *str) {
  int num_words = count_words(str);
  char **tokens = (char **)malloc((num_words + 1) * sizeof(char *));
  int i = 0;

  while (*str && i < num_words) {
    char *start = word_start(str);
    if (!start) break;
    char *end = word_end(start);
    tokens[i++] = copy_str(start, end - start);
    str = end;
  }
  tokens[i] = 0; // End of tokens
  return tokens;
}

/* Print all tokens */
void print_tokens(char **tokens) {
  for (int i = 0; tokens[i]; i++) {
    printf("%s\n", tokens[i]);
  }
}

/* Get the token at a specific index */
char *get_token(char **tokens, int id) {
  return tokens[id];
}

/* Free the memory allocated for the tokens */
void free_tokens(char **tokens) {
  for (int i = 0; tokens[i]; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

#endif
