//todo.h
#include <stdio.h>

typedef struct {
    char title[100]; //ex) OSS Lab11
    char deadline[20]; //ex) 2023-05-08
    char day[10]; // ex) Mon
    int hrs; //ex) 4(예상 소요 시간)
    int check; // ex) 0, 1(한 일 입력받아서 √표시)
} ToDo;