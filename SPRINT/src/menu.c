
#include <menu.h>


int menu1()
{
      int choice=0;
      char menu[100] = "\n\tPlease enter your choice,\n\t1. CREATE USER and TASK Table\n\t2. READ\n\t3. UPDATE\n\t4.DELETE\n\t0.EXIT\n\tChoice: ";
      printf("%s",menu);
      scanf("%d",&choice);

      return choice;
}

void execMenu()
{
	switch(menu1())
    	{
        case 1:
        	create_user();
        	create_task();
                printf("");
                break;
                
        case 2:
        	read();
                printf("Case 2 is executed");
                break;
        case 3:
        	update();
                printf("Case 3 is executed");
                exit(EXIT_SUCCESS);
                break;
        case 4:
        	delete();

        default:
                printf("\nEnter the correct choice");

    }   
}
