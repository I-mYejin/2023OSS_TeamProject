#include "todo.h"


//main
int main(void) {
  int count = 0;
  int index = count;
  ToDo *Todo = NULL;
  int menu;

  while(1){
    menu = selectMenu();
    if(menu == 0) {
      printf("Bye!\n");
      break;
    }



    }
    else if (menu == 8){ //猷 
      int index;
      completeTodoIndex(&Todo, &count, index);
      printf("猷 쇱 몃깆ㅻ� �ν몄: ");
      scanf("%d", &index);
      getchar();
      completeTodo(&Todo, &count, index);
    }
      

    }
  return 0;

    else if (menu == 7){ //요일별 일정 추가
      //addTodoByDay(t, &index, &count);
    }
    else if (menu == 8){ //완료 표시 기능
      int no = selectDataNo(t, index);
      int completeok;
      printf("완료하셨나요? (완료: 1, 취소: 0)");
      scanf("%d", &completeok);
      if(completeok == 1){
        completeTodo(&t[no-1]);
        printf("=> 일정 완료!\n");
      }
      else{
        printf("=> 취소됨! \n");
      }
      

    }

  }

}