#include "todo.h"

//main
int main(void) {
  ToDo *t[100];
  int index = 0;
  int count = 0;
  int menu;

  while(1){
    menu = selectMenu();
    if(menu == 0) break;
    
    if (menu == 1) {
      if(count > 0) {
        listTodo(t, index);
      }
    }
    
    else if(menu == 2){
      count += 1;
      addTodo(&t[index++]);

    }
    else if (menu == 3){
      updateTodo(t);

    }
    else if (menu == 4){

    }
    else if (menu == 5){

    }
    else if(menu == 6){
        
    }

  }
}
