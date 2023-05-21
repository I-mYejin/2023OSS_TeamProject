#include "todo.h"
#include <string.h>

int selectMenu(){
    int menu;
    printf("\n\n *** 1Jung *** \n");
    printf("0. 종료\n\n");
    printf("1. 일정 조회\n"); //일정 리스트 출력 + 일정완료 체크표시
    printf("2. 일정 추가\n");
    printf("3. 일정 수정\n");
    printf("4. 일정 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 파일 불러오기\n");
    printf("7. 일정 추가(요일별)\n");
    printf("8. 일정 완료\n");
    printf("Select Menu: ");
    scanf("%d", &menu);
    return menu;   
}

//일정 완료 기능
int completeTodo(ToDo *t){
  t->check = 1;
  return 1;
}

//일정 추가 기능
int addTodo(ToDo *t){
  int repeat;
  char repeatDeadline[20];
  int repeatDays;
  printf("1. 단순 추가 2. 반복 추가 >> ");
  scanf("%d", &repeat);
  if(repeat == 2){
    printf("last date to add Todo(format: 20XX-XX-XX)>> "); //반복 일정을 추가할 마지막 날짜
    scanf("%s", repeatDeadline);

    printf("Title: ");
    scanf("%s", t->title);
    printf("Deadline(format: after * days): ");
    scanf("%d", &repeatDays);
    printf("Estimated time to complete(hrs): ");
    scanf("%d", &t->hrs);
    printf("=> 새로운 반복 일정이 추가되었습니다!");
    return 1;

  }
  else{
    printf("Title: ");
    getchar();
    scanf("%[^\ns]", t->title);
    getchar();
    printf("Deadline(format: 20XX-XX-XX): ");
    scanf("%s", t->deadline);
    printf("Day(Mon, Tues, Wed, Thurs, Fri, Sat, Sun): ");
    scanf("%s", t->day);
    printf("Estimated time to complete(hrs): ");
    scanf("%d", &t->hrs);
    printf("=> 새로운 일정이 추가되었습니다!");
    return 1;
  }
}
//미완성
void saveData(ToDo *t, int count){
    FILE *fp;
    char filename[20];
    printf("저장할 파일 이름: ");
    scanf("%s", filename);

    fp = fopen(filename, "wt");
    printf("\nNo Title Deadline Day Hours Finish\n");
    
    for(int i=0; i<count; i++){
        if(t[i].hrs == -1) continue;
        fprintf(fp, "%2d %s %s %s %d %d\n", i+1, t[i].title, t[i].deadline, t[i].day, t[i].hrs, t[i].check);
    }
    fclose(fp);
    printf("=> %s 파일에 저장됨! \n",filename);

}
//미완성
int loadData(ToDo *t){
    int i, count = 0;
    FILE *fp;
    char filename[20];
    printf("불러올 파일 이름: ");
    scanf("%s", filename);
    
    fp=fopen(filename, "rt");
    if(fp == NULL){
        printf("=> 파일 없음! \n");
        return 0;
    }
    for(i=0; i<100; i++){
        fscanf(fp, "%s", t[i].title);
        if(feof(fp)) break;
        fscanf(fp, "%s", t[i].deadline);
        fscanf(fp, "%s", t[i].day);
        fscanf(fp, "%d", &t[i].hrs);
    }
    fclose(fp);
    printf("=> %s 파일 로딩 성공!\n", filename);
    return i; //총 몇개의 데이탄지 리턴

}

int updateTodo(ToDo *t){
    return addTodo(t);
    }

int selectDataNo(ToDo *t, int count){
    int no;
    listTodo(t, count);
    printf("번호는?");
    scanf("%d", &no);
    return no;
}

// //일정 삭제 기능
// int deleteTodo(ToDo *t){
//     t->check = -1;
//     return 1;
// }


//일정 리스트 출력 기능
void todoRead(ToDo t){
    printf("%s  %s  %s  %d \n", t.title, t.deadline, t.day, t.hrs);
}

int listTodo(ToDo *t, int count){
    printf("\nNo    Title   Deadline    Day     Hours   Finish\n");
    printf("====================================================\n");
    for(int i=0; i<count; i++){
        if(t[i].check == -1) continue;
        printf("%2d    ", i+1);
        todoRead(t[i]);
        //일정완료 체크표시
        if(t[i].check == 1){ 
            printf("  √\n");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    return 1;
}

//일정 추가 기능 (요일별로)
// void addTodoByDay(ToDo *t[], int *index, int *count) {
//   int dayMenu;
//   printf("요일을 선택하세요:\n");
//   printf("1. 월요일\n");
//   printf("2. 화요일\n");
//   printf("3. 수요일\n");
//   printf("4. 목요일\n");
//   printf("5. 금요일\n");
//   printf("6. 토요일\n");
//   printf("7. 일요일\n");
//   printf("Select Day: ");
//   scanf("%d", &dayMenu);

//   if (dayMenu < 1 || dayMenu > 7) {
//     printf("잘못된 선택입니다.\n");
//     return;
//   }
//     char day[10];
//   switch (dayMenu) {
//     case 1:
//       strcpy(day, "Mon");
//       break;
//     case 2:
//       strcpy(day, "Tue");
//       break;
//     case 3:
//       strcpy(day, "Wed");
//       break;
//     case 4:
//       strcpy(day, "Thu");
//       break;
//     case 5:
//       strcpy(day, "Fri");
//       break;
//     case 6:
//       strcpy(day, "Sat");
//       break;
//     case 7:
//       strcpy(day, "Sun");
//       break;
//   }

//   printf("Title: ");
//   scanf("%s", t[*index]->title);
//   printf("Deadline (format: 20XX-XX-XX): ");
//   scanf("%s", t[*index]->deadline);
//   strcpy(t[*index]->day, day);
//   printf("Estimated time to complete (hrs): ");
//   scanf("%d", &t[*index]->hrs);
//   t[*index]->check = 0;

//   printf("=> 새로운 일정이 추가되었습니다!\n");
//   (*index)++;
//   (*count)++;
// }