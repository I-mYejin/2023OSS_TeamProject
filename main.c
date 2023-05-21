#include "todo.h"

//main
int main(void) {
  ToDo t[100];
  int count = loadData(t);
  int index = count;
  int menu;

  while(1){
    menu = selectMenu();
    if(menu == 0) {
      printf("Bye!\n");
      break;
    }
    
    else if (menu == 1) { //일정 조회
      if(count > 0) {
        listTodo(t, index);
      }
    }
    
    else if(menu == 2){ //일정 추가
      count += 1;
      addTodo(&t[index++]);

    }
    else if (menu == 3){ //일정 수정
      updateTodo(t);

    }
    else if (menu == 4){ //일정 삭제
      //int no = selectDataNo(t, index);
      // int deleteok;
      // printf("정말로 삭제하시겠습니까?(삭제:1)");
      // scanf("%d", &deleteok);
      // if (deleteok == 1){
      //   if (&t[no -1] == NULL) count--;
      // }
    }
            
    else if (menu == 5){ //파일 저장
      saveData(t, index);

    }
    else if(menu == 6){ //파일 불러오기
      loadData(t);
        
    }

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