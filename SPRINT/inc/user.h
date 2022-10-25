#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct user
{
    	int user_id;
	char user_name[50];
	char designation[20];
}user;

user *u;

void create_user(int);
void read_user();
void search_user(int);
void update_user(int);
void delete_user(int);

#endif
