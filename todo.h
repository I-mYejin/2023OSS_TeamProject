//todo.h
#include <stdio.h>

typedef struct {
    char title[100]; //ex) OSS Lab11
    char deadline[20]; //ex) 2023-05-08
    char day[10]; // ex) Mon
    int hrs; //ex) 4(예상 소요 시간)
    int check=0; // ex) 0, 1(한 일 입력받아서 √표시)
} ToDo;

int deleteTodo(ToDo *s); //일정 삭제
void todoCheck(ToDo s); //일정 완료 체크 표시
void todoRead(ToDo s); //일정 리스트 출력

int addTodo(ToDo *t); //일정 추가