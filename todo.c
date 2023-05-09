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

void saveData(ToDo *t, int count){
    FILE *fp;
    char filename[20];
    fp = fopen(filename, "wt");
    for(int i=0; i<count; i++){
        if(t[i].hrs == -1) continue;
        fprintf(fp, "%s %s %s %d \n", t[i].title, t[i].deadline, t[i].day, t[i].hrs);
    }
    fclose(fp);
    printf("=> 파일에 저장됨! \n");

}

