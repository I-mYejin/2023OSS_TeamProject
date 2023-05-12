#include "todo.h"

//미완성
int selectMenu(){
    int menu;
    printf("\n *** 1Jung *** \n");
    printf("0. 종료\n\n");
    printf("1. 일정 조회\n");
    printf("2. 일정 추가\n");
    printf("3. 일정 수정\n");
    printf("4. 알정 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 파일 불러오기\n");
    printf("Select Menu: ");
    scanf("%d", &menu);
    return menu;   
}


//일정 추가 기능
int addTodo(ToDo *t){
    printf("Title: ");
    scanf("%s", t->title);
    printf("Deadline(format: 20XX-XX-XX): ");
    scanf("%s", t->deadline);
    printf("Day(Mon, Tues, Wed, Thurs, Fri, Sat, Sun): ");
    scanf("%s", t->day);
    printf("Estimated time to complete(hrs): ");
    scanf("%d", t->hrs);
    printf("=> 새로운 일정이 추가되었습니다!");
    return 1;
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
        fprintf(fp, "%2d %s %s %s %d %s\n", i+1, t[i].title, t[i].deadline, t[i].day, t[i].hrs, t[i].check);
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
        fscanf(fp, "%d", t[i].hrs);
    }
    fclose(fp);
    printf("=> %s 파일 로딩 성공!\n", filename);
    return i; //총 몇개의 데이탄지 리턴

}

int updateTodo(ToDo *t){
    return addTodo(t);
    }

//일정 삭제 기능
int deleteTodo(ToDo *t){
    t->check = -1;
    return 1;
}


//일정 리스트 출력 기능
void todoRead(ToDo t){
    printf("%s  %s  %s  %d %s\n", t.title, t.deadline, t.day, t.hrs, t.check);
}

int listTodo(ToDo *t[], int count){
    printf("\nNo    Title   Deadline    Day     Hours   Finish\n");
    printf("====================================================\n");
    for(int i=0; i<count; i++){
        if(t[i] -> check == -1) continue;
        printf("%2d    ", i+1);
        todoRead(*t[i]);
        //일정완료 체크표시
        if(t[i]->check == 1){ 
            printf("  √\n");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}



