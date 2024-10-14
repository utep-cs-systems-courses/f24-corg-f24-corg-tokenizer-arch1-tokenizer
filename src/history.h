#ifndef _HISTORY_H_

#define _HISTORY_H_



typedef struct HistoryList {

  char* phrase;

  struct HistoryList* next;

} HistoryList;



// Initialize the history list

HistoryList* init_history();



// Add a phrase to history

void add_history(HistoryList* list, char* str);



// Print the history list

void print_history(HistoryList* list);



// Free the memory used by the history list

void free_history(HistoryList* list);



#endif

