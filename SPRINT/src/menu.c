
#include <menu.h>


int menu1()
{
      int choice=0;
      char menu[100] = "\n\tPress,\n\t1. Add\n\t2. Sub\n\t3. Exit\n\tChoice: ";
      printf("%s",menu);
      scanf("%d",&choice);

      return choice;
}

void execMenu()
{
	switch(menu1())
    {
        case 1:
                printf("Case 1 is executed");
                break;
        case 2:
                printf("Case 2 is executed");
                break;
        case 3:
                printf("Case 3 is executed");
                exit(EXIT_SUCCESS);
                break;

        default:
                printf("\nEnter the correct choice");

    }   
}