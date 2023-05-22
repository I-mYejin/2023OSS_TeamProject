#include "todo.h"
#include <string.h>

int selectMenu(){
    int menu;
    printf("\n\n *** 1Jung ***\n\n");
    printf("0. 종료\n\n");
    printf("1. 일정 조회(빨리 끝낼 수 있는 순서)\n");
    printf("2. 일정 조회(deadline별 검색)\n");
    printf("3. 일정 추가\n");
    printf("4. 일정 삭제\n");
    printf("5. 일정 수정\n");
    printf("6. 파일 저장\n");
    printf("7. 파일 불러오기\n");
    printf("8. 일정 완료 표시\n");
    printf("Select Menu: ");
    scanf("%d", &menu);
    getchar();
    return menu;   
}

// 비교 함수
int compare(const void *a, const void *b) {
  ToDo *scheduleA = (ToDo *)a;
  ToDo *scheduleB = (ToDo *)b;

  // 예상 소요 시간에 따라 오름차순으로 정렬
  return scheduleA->hrs - scheduleB->hrs;
}

//일정 추가 기능
void addTodo(ToDo **Todo, int *count){
 (*count)++;
  *Todo = (ToDo *)realloc(*Todo, *count * sizeof(ToDo));

  printf("Title: ");
  fgets((*Todo)[*count - 1].title, 100, stdin);
  (*Todo)[*count - 1].title[strcspn((*Todo)[*count - 1].title, "\n")] =
      '\0'; // 개행 문자 제거

  printf("Deadline (YYYY-MM-DD): ");
  fgets((*Todo)[*count - 1].deadline, 20, stdin);
  (*Todo)[*count - 1].deadline[strcspn((*Todo)[*count - 1].deadline, "\n")] ='\0'; // 개행 문자 제거

  printf("Estimated time to complete(hrs): ");
  scanf("%d", &(*Todo)[*count - 1].hrs);
  getchar(); // 개행 문자 제거
  printf("새로운 1Jung이 추가되었습니다!\n");
}
// 일정 리스트 출력 함수
void printTodoList(ToDo *Todo, int count) {
  if (count == 0) {
    printf("일정이 없습니다.\n");
  } else {
    // 정렬
    qsort(Todo, count, sizeof(ToDo), compare);

    // 결과 출력
    printf("\nDone  Title      Estimated_time(hrs)    Deadline\n");
    printf("=========================================================\n");
    for (int i = 0; i < count; i++) {
      if(Todo[i].check == 1) {
        printf("  √  ");
      } else {
        printf("     ");
      }
      printf("%-15s  %3d            %s\n", Todo[i].title, Todo[i].hrs, Todo[i].deadline);
    }
  }
}

//일정 완료 체크 함수
void completeTodo(ToDo **Todo, int *count, int index) {
  if (index >= 0 && index < *count) {
    (*Todo)[index].check = 1;
    printf("일정이 완료되었습니다.\n");
  } else {
    printf("유효하지 않은 인덱스입니다.\n");
  }
}

//일정 인덱스 리스트 함수
void completeTodoIndex(ToDo **Todo, int *count, int index) {
  printf("일정의 인덱스 리스트:\n");
    for (int i = 0; i < *count; i++) {
      printf("%d. %s\n", i, (*Todo)[i].title);
    }
}

  // 데드라인인 과제 리스트 출력 함수
void printDeadlineList(ToDo *Todo, int count, char *today){
  if (count == 0) {
    printf("일정이 없습니다.\n");
  } 
  else {
    printf("[1Jung due %s]", Todo->deadline);
    printf("\nTitle  Estimated_time(hrs)\n");
    printf("==================================\n");
    for (int i = 0; i < count; i++) {
      if (strcmp(today, Todo[i].deadline) == 0) {
        printf("%10s  %3d\n", Todo[i].title, Todo[i].hrs);
      }
    }
  }
}
//파일 저장
void saveData(ToDo *t, int count){
    FILE *fp;
    char filename[20];
    printf("저장할 파일 이름: ");
    scanf("%s", filename);

    fp = fopen(filename, "wt");
    qsort(t, count, sizeof(t), compare);

    // 결과 출력
    fprintf(fp,"\nTitle  Estimated_time(hrs)  Deadline\n");
    fprintf(fp,"============================================\n");
    for (int i = 0; i < count; i++) {
        if(t[i].check != 1) fprintf(fp,"%3s  %7d         %s\n", t[i].title, t[i].hrs, t[i].deadline);
    }
    fclose(fp);
    printf("=> %s 파일에 저장됨! \n",filename);

}
//파일 불러오기
int loadData(ToDo **Todo, int *count){
    int i;
    FILE *fp;
    char filename[20];
    char str[100]; //trash can
    printf("불러올 파일 이름: ");
    scanf("%s", filename);
    
    fp=fopen(filename, "rt");
    if(fp == NULL){
        printf("=> 파일 없음! \n");
        return 0;
    }
    fgets(str, 100, fp); //필요없는 버리기
    fgets(str, 100, fp);
    fgets(str, 100, fp);
    for(int i=0; i<100; i++){
        (*count) ++;
        *Todo = (ToDo *)realloc(*Todo, *count * sizeof(ToDo));
        fscanf(fp, "%[^\t]s",(*Todo)[*count-1].title);
        (*Todo)[*count - 1].title[strcspn((*Todo)[*count - 1].title, "\n")] ='\0';
        if(feof(fp)) break;
        fscanf(fp, "%d", &(*Todo)[*count - 1].hrs);
        fscanf(fp, "%[^\n]s", (*Todo)[*count - 1].deadline);
        (*Todo)[*count - 1].deadline[strcspn((*Todo)[*count - 1].deadline, "\n")] ='\0';
        fgets(str, 100, fp);
        fgets(str, 100, fp);
        fgets(str, 100, fp);
    
    }
    fclose(fp);
    printf("=> %s 파일 로딩 성공!\n", filename);
    return *count; //총 몇개의 데이탄지 리턴
}

void updateTodo(ToDo **Todo, int *count){
    int index;
    printf("<수정할 일정의 인덱스 리스트>\n");
   for (int i = 0; i < *count; i++) {
     printf("%d. %3s  %7d         %s\n", i, (*Todo)[i].title, (*Todo)[i].hrs, (*Todo)[i].deadline);
   }
    printf("수정할 일정의 인덱스를 입력하세요: ");
   scanf("%d", &index);
   getchar(); // 개행 문자 제거
    int update;
    printf("수정할 부분(1. 제목 2. 시간 3. deadline): ");
    scanf("%d", &update);
    getchar();
    char updatesT[100];
    int updatesH;
    char updatesD[10];
    if(update == 1){
        printf("수정 사항: ");
        fgets(updatesT, 100, stdin);
        updatesT[strcspn(updatesT, "\n")] ='\0';
        strcpy((*Todo)[index].title, updatesT);
    }
    else if(update == 2){
        printf("수정 사항: ");
        scanf("%d", &updatesH);
        (*Todo)[index].hrs= updatesH;

    }
    else if(update == 3){
        printf("수정 사항: ");
        fgets(updatesD, 100, stdin);
        updatesD[strcspn(updatesD, "\n")] ='\0';
        strcpy((*Todo)[index].deadline, updatesD);

    }
  printf("1Jung이 수정되었습니다!\n");
}

void deleteTodo(ToDo **Todo, int *count, int index) {
  if (index >= 0 && index < *count) {
    printf("<삭제할 일정의 인덱스 리스트>\n");
    for (int i = 0; i < *count; i++) {
      printf("%d. %s\n", i, (*Todo)[i].title);
    }

    printf("삭제할 일정의 인덱스를 입력하세요: ");
    scanf("%d", &index);
    getchar(); // 개행 문자 제거

    if (index >= 0 && index < *count) {
      for (int i = index; i < *count - 1; i++) {
        strcpy((*Todo)[i].title, (*Todo)[i + 1].title);
        (*Todo)[i].hrs = (*Todo)[i + 1].hrs;
        strcpy((*Todo)[i].deadline, (*Todo)[i + 1].deadline);
      }
      (*count)--;
      *Todo = (ToDo *)realloc(*Todo, *count * sizeof(ToDo));
      printf("일정이 삭제되었습니다.\n");
    } else {
      printf("유효하지 않은 인덱스입니다.\n");
    }
  } else {
    printf("유효하지 않은 인덱스입니다.\n");
  }
}