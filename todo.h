//todo.h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char title[100]; // ex) OSSLab11
  int hrs;
  char deadline[20];
  int check;
} ToDo;

int selectMenu();
int compare(const void *a, const void *b);
void addTodo(ToDo **Todo, int *numTodo);
void printTodoList(ToDo *Todo, int numTodo);
void printDeadlineList(ToDo *Todo, int numTodo, char *today);
void saveData(ToDo *t, int count);
int loadData(ToDo **Todo, int *count);
void deleteTodo(ToDo **Todo, int *count, int index);
void updateTodo(ToDo **Todo, int *count);
void completeTodo(ToDo **Todo, int *count, int index);
void completeTodoIndex(ToDo **Todo, int *count, int index);