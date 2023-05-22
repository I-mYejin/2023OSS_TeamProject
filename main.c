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
    else if (menu == 1) { 
     printTodoList(Todo, count);
    }
    
    else if(menu == 2){
      char today[20];
      printf("찾으려는 deadline 날짜를 입력하세요 (YYYY-MM-DD): ");
      fgets(today, 20, stdin);
      today[strcspn(today, "\n")] = '\0'; // 개행 문자 제거
      printDeadlineList(Todo, count, today);

    }
    else if (menu == 3){ 
      addTodo(&Todo, &count);

    }
    else if (menu == 4) { //일정 삭제
      int deleteok;
      printf("삭제하시겠습니까? (0:Yes / 1:No)");
      scanf("%d", &deleteok);
      if (deleteok == 0) {
        deleteTodo(&Todo, &count, index);
      } 
      else continue;
    }
    else if(menu == 5){
      updateTodo(&Todo, &count);
    }
    else if (menu == 6){ //파일 저장
      saveData(Todo, count);

    }
    else if(menu == 7){//파일 불러오기
    loadData(&Todo, &count);

    }
    else if (menu == 8){ //완료 표시
      int index;
      completeTodoIndex(&Todo, &count, index);
      printf("완료한 일정의 인덱스를 입력하세요: ");
      scanf("%d", &index);
      getchar();
      completeTodo(&Todo, &count, index);
    }
      

    }
  return 0;
}
