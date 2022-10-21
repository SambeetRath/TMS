
#include <string.c>

typedef struct user
{
	char user_name[50];
	char designation[20];
    	int user_id;
}user;

user u;

void create_user()
{
    
    FILE* fp = fopen("user.csv", "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
        
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
                    printf("user_id :");
                }
 
                /* Column 2 */
                if (column == 1) 
                {
                    printf("\tuser_name :");
                }
 
                /* Column 3 */
                if (column == 2) 
                {
                    printf("\tuser_designation :");
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
    printf("\nUSER TABLE SUCCESSFULLY CREATED\n");
    return 0;
}

void read_user()
{
	
    	FILE* fp = fopen("user.csv", "a+");
 
    	if (!fp) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	return 0;
    	}
 
    	/* Asking user info */
    
    	printf("\nEnter USER ID\n");
    	scanf("%d", &u.user_id);
    
    	printf("\nEnter USER Name\n");
    	scanf("%[^\n]s", &u.user_name);
    
    	printf("\nEnter USER DESIGNATION\n");
    	scanf("%s", &u.designation);
 
    	/* Saving data in file */
    	fprintf(fp, "%d, %s, %s\n", u.user_id, u.user_name, u.designation);
 
    	printf("\nNew USER added to record");
 
    	fclose(fp);
    	return 0;
}
void update_user(int u.user_id)
{
	
}
