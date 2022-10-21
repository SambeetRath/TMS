
#include <string.c>


typedef struct task
{
	char task_name[50];
	char description[20];
	char deadline[10];
    	int task_id;
}task;

void create_task()
{
    
    	FILE* fp = fopen("task.csv", "r");
 
    	if (!fp)
        printf("Can't open file\n");
 
    	else 
    	{
        
		char buffer[1024];
	 
		int row = 0;
		int column = 0;
 
           while (fgets(buffer,1024, fp)) 
           {
            	column = 0;
            	row++;
 
            
            	if (row == 1)
                	continue;
 
            	/* Splitting the data*/
            	char* value = strtok(buffer, ", ");
 
            	while (value) 
            	{
                	/* Column 1 */
                	if (column == 0) 
                	{
                    		printf("task_id :");
                	}
 
                	/* Column 2 */
                	if (column == 1) 
                	{
                    		printf("\ttask_name :");
                	}
 
                	/* Column 3 */
                	if (column == 2) 
                	{
                    		printf("\ttask_description :");
                	}
                	/* Column 4 */
                	if (column == 3) 
                	{
                    		printf("\ttask_deadline :");
                	}
 
                	printf("%s", value);
                	value = strtok(NULL, ", ");
                	column++;
            	}
 
            	printf("\n");
        }
 
        /* Close the file */
        fclose(fp);
    	}
    	printf("\nTASK TABLE SUCCESSFULLY CREATED\n");
    	return 0;
}

void read_task()
{

    	FILE* fp = fopen("task.csv", "a+");
 
    	task t;
 
    	if (!fp) 
    	{
        /* Error in file opening */
        printf("Can't open file\n");
        return 0;
    	}
 
    	/* Asking user info */
    
    	printf("\nEnter TASK ID\n");
    	scanf("%d", &t.task_id);
    
    	printf("\nEnter TASK Name\n");
    	scanf("%[^\n]s", &t.task_name);
    
    	printf("\nEnter TASK DESCRIPTION\n");
    	scanf("%s", &t.description);
    
    	printf("\nEnter TASK DEADLINE\n");
    	scanf("%s", &t.deadline);
 
    	/* Saving data in file */
    	fprintf(fp, "%d, %s, %s, %s\n", t.test_id, t.test_name, t.destination, t.deadline);
 	
    	printf("\nNew TASK added to record");
    	
 
    	fclose(fp);
    	return 0;
}


