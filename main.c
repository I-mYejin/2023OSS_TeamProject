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
    
    if (menu == 1) { //일정 조회
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
      int no = selectDataNo(t, index);
      int deleteok;
      printf("정말로 삭제하시겠습니까?(삭제:1)");
      scanf("%d", &deleteok);
      if (deleteok == 1){
        if (t[no -1] = NULL);
           count--;
      }
    }
            
    else if (menu == 5){ //파일 저장

    }
    else if(menu == 6){ //파일 불러오기
        
    }

  }
}
