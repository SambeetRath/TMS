#ifndef MENU_H
#define MENU_H

#define APPENDDAT "a+"
#define READDAT "r+"
#define WRITEDAT "w+"

#define LOGINDAT "../data/user.dat"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int menu1();
void execMenu();
int userlogin(void);


void create_task(int );
void read_task();
void search_task(int);
void update_task(int);
void delete_task(int);

void create_user(int);
void read_user();
void search_user(int);
void update_user(int);
void delete_user(int);

void assignment();
void display_usertask(int);
void display_taskOfuser(int);

#endif
