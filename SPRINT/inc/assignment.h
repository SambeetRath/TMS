#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct assign
{
	int uid;
	char uname[50];
	char des[20];
	int tid;
	char tname[50];
	char dline[15];
}assign;

assign *a;

void assignment();
void display_usertask(int);
#endif
