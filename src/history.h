#ifndef HISTORY_H

#define HISTORY_H



// Structure for an individual history item in the linked list

typedef struct HistoryItem {

  int id;                // Unique ID of the history item

  char *str;             // String associated with the history item

  struct HistoryItem *next; // Pointer to the next item in the list

} HistoryItem;



// Structure representing the entire history list

typedef struct HistoryList {

  HistoryItem *head;     // Pointer to the first item in the history list

} HistoryList;



/* Initialize a new empty history list.

   Returns a pointer to the newly created history list. */

HistoryList* init_history();



/* Add a new history item to the end of the list.

   Parameters:

   - list: Pointer to the history list where the item will be added

   - str: The string to be stored in the new history item */

void add_history(HistoryList *list, char *str);


void add_history(HistoryList *list, char *str);

/* Retrieve the string stored in the history item with a matching ID.
   Parameters:
   - list: Pointer to the history list
   - id: The ID of the history item to be retrieved
   Returns a pointer to the string if found, or NULL if the ID does not exist. */
char *get_history(HistoryList *list, int id);

/* Print all the history items in the list.
   Parameters:
   - list: Pointer to the history list */
void print_history(HistoryList *list);

/* Free all memory allocated for the history list and its items.
   Parameters:
   - list: Pointer to the history list to be freed */
void free_history(HistoryList *list);

#endif // HISTORY_H
