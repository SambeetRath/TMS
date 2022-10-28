#ifndef TASK_H
#define TASK_H

#define TCSV "../data/task.csv"

typedef struct task
{
	int task_id;
	char task_name[50];
	char description[20];
	char deadline[15];
}task;

#endif
