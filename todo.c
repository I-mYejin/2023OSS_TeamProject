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

