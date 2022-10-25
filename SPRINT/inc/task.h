#ifndef TASK_H
#define TASK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct task
{
	int task_id;
	char task_name[50];
	char description[20];
	char deadline[15];
}task;

task *t;

void create_task(int );
void read_task();
void search_task(int);
void update_task(int);
void delete_task(int);

#endif
