#include "todo.h"

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
    for(int i=0; i<count; i++){
        if(t[i].hrs == -1) continue;
        fprintf(fp, "%s %s %s %d \n", t[i].title, t[i].deadline, t[i].day, t[i].hrs);
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



