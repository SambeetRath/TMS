
#include <menu.h>


int menu1()
{
      int choice=0;
      char menu[100] = "\n\tPlease enter your choice,\n\t1. CREATE/APPEND USER Table\t2. CREATE/APPEND TASK Table\n\t3. READ USER Table \n\t4. READ TASK Table \n\t5. UPDATE records from USER Table \n\t6. UPDATE records from TASK Table \n\t7. DELETE records from USER Table \n\t8. DELETE records from TASK Table \n\t9. SEARCH records from USER Table \n\t10. SEARCH records from TASK Table \n\t11. To Assign Task to User \n\t12. Display assigned User of a Task \n\t0. EXIT\n\t Choice: ";
      printf("%s",menu);
      scanf("%d",&choice);

      return choice;
}

void execMenu()
{
	while(1)
	{
		switch(menu1())
	    	{
		case 1:
			int n;
			printf("\nEnter the number of records you want to enter : ");
			scanf("%d",&n);
			create_user(n);
		        printf("");
		        break;
		case 2:
			int m;
			printf("\nEnter the number of records you want to enter : ");
			scanf("%d",&m);
			create_task(m);
		        break;       
		case 3:
			read_user();
		        break;
		case 4:
			read_task();
		        break;
		case 5:
			int uid;
			printf("\nEnter the USER Id to update record : ");
			scanf("%d",&uid);
			update_user();
		        
		        break;
		case 6:
			int tid;
			printf("\nEnter the TASK Id to update record : ");
			scanf("%d",&tid);
			update_user();
		        break;
		case 7:
			int uid;
			printf("\nEnter the USER Id to DELETE record : ");
			scanf("%d",&uid);
			delete_user();
			break;
		case 8:
			int tid;
			printf("\nEnter the TASK Id to DELETE record : ");
			scanf("%d",&uid);
			delete_user();
			break;
		case 9:
			int uid;
			printf("\nEnter the USER Id to DELETE record : ");
			scanf("%d",&uid);
			search_user();
			break;
		case 10:
			int tid;
			printf("\nEnter the TASK Id to DELETE record : ");
			scanf("%d",&uid);
			search_user();
			break;
		case 11:
			assignment();
			break;
		case 12:
			int taskid;
			printf("\nEnter the TASK Id to update record : ");
			scanf("%d",&taskid);
			display_usertask(taskid);
			break;
		case 0:
			exit(1);

		default:
		        printf("\nEnter the correct choice");
    		}
    	}
}
