
#include <menu.h>

int menu1()
{
      int choice=0;
      printf("\n\t*************************************************************\t\n");
      printf("\n\t*****************************MENU****************************\t\n");
      printf( "\n\tPlease enter your choice,\n\t1. CREATE/APPEND USER Table\n\t2. CREATE/APPEND TASK Table\n\t3. READ USER Table \n\t4. READ TASK Table \n\t5. UPDATE records from USER Table \n\t6. UPDATE records from TASK Table \n\t7. DELETE records from USER Table \n\t8. DELETE records from TASK Table \n\t9. SEARCH records from USER Table \n\t10. SEARCH records from TASK Table \n\t11. To Assign Task to User \n\t12. Display assigned User of a Task \n\t13. Display Task of an User\n\t0. EXIT\n\t Choice: ");
      (void)scanf("%d",&choice);
      
      return choice;
}

void execMenu()
{
	int uid,tid;
	bool loop= true;
	while(loop)
	{
		switch(menu1())
	    	{
			case 1:
				int n;
				printf("\nEnter the number of records you want to enter : ");
				(void)scanf("%d",&n);
				create_user(n);
				break;
			case 2:
				int m;
				printf("\nEnter the number of records you want to enter : ");
				(void)scanf("%d",&m);
				create_task(m);
				break;       
			case 3:
				read_user();
				break;
			case 4:
				read_task();
				break;
			case 5:
				printf("\nEnter the USER Id to update record : ");
				(void)scanf("%d",&uid);
				update_user(uid);
				
				break;
			case 6:
				
				printf("\nEnter the TASK Id to update record : ");
				(void)scanf("%d",&tid);
				update_task(tid);
				break;
			case 7:
				printf("\nEnter the USER Id to DELETE record : ");
				(void)scanf("%d",&uid);
				delete_user(uid);
				break;
			case 8:
				printf("\nEnter the TASK Id to DELETE record : ");
				scanf("%d",&tid);
				delete_task(tid);
				break;
			case 9:
				printf("\nEnter the USER Id to SEARCH record : ");
				(void)scanf("%d",&uid);
				search_user(uid);
				break;
			case 10:
				printf("\nEnter the TASK Id to SEARCH record : ");
				scanf("%d",&tid);
				search_task(tid);
				break;
			case 11:
				assignment();
				break;
			case 12:
				int taskid;
				printf("\nEnter the TASK Id to View assigned users to the task : ");
				(void)scanf("%d",&taskid);
				display_usertask(taskid);
				break;
			case 13:
				int userid;
				printf("\nEnter the USER Id to View assigned task : ");
				(void)scanf("%d",&userid);
				display_taskOfuser(userid);
				break;
			case 0:
				printf("\n\t*************************************************************\t\n");
				loop=false;
				exit(EXIT_SUCCESS);

			default:
				printf("\nEnter the correct choice");
				loop=false;
    		}
    	}
}
