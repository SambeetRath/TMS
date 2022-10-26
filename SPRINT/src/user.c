#include <menu.h>
#include <user.h>


void create_user(int n)
{
	user *u;
 	u=(user*)calloc(n, sizeof(user));
    	FILE* fp = fopen("user.csv", "a+");
 	int j;
    	if (!fp)
        printf("Can't open file\n");
    	else 
    	{       
    		for(j=0;j<n;j++)
    		{
			printf("\n");
			printf("\nEnter USER ID\n");
		    	scanf("%d", &u[j].user_id);
		    
		    	printf("\nEnter USER Name\n");
		    	scanf("%s", u[j].user_name);
		    
			printf("\nEnter USER DESIGNATION\n");
		    	scanf("%s", u[j].designation);
		    
		 
		    	/* Saving data in file */
		    	int un=1;
		    	
		    	
				if(isupper(u[j].user_name[0])==0 && isupper(u[j].user_name[sizeof(u[j].user_name)])==0)
				{
					un=0;
				}
				    
		    	if(u[j].user_id<10000 && u[j].user_id>999 && un==1)
		    	{
		    		fprintf(fp, "%d,%s,%s\n", u[j].user_id, u[j].user_name,u[j].designation );
		    		printf("\nNew USER added to record");
		    	}
		    	else
		    	printf("User info invalid");
		    }	
		    	/* Close the file */
		fclose(fp);
		
    	}
    	printf("\nUSER TABLE SUCCESSFULLY CREATED\n");
}

void read_user()
{

	FILE* fp = fopen("user.csv", "r");
 
    	if (!fp) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}
    	else
    	{        
		char buffer[1024];
 		printf("\tUSER ID\t\tUSER NAME\tDESIGNATION\n\t");
		while (fgets(buffer,1024, fp)) 
		{
		    	char* value = strtok(buffer, ",");
	 		
		    	while (value) 
		    	{
		        	printf("%-18s", value);
		        	value = strtok(NULL, ",");
		    	}
		}
    	}
    	fclose(fp);
}

void search_user(int uid)
{
	int i,find=-1;
	FILE* fp = fopen("user.csv", "r");
    	if (!fp) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}
    		user us[100];
    		int r=0;
    		int rec=0;     
	do
	{
	 	r=fscanf(fp,"%d,%[^,],%s\n",&us[rec].user_id, us[rec].user_name,us[rec].designation);
		if(r == 3)
		{
			rec++;
		} 
		/*printf("%d",r);*/	
		if(r != 3 && !feof(fp))
		{
			printf("\nError in Format\n");
			break;
		}
		if(ferror(fp))
		{
			printf("\nError in Reading\n");
			break;
		}
	}while(!feof(fp));
    	
    	fclose(fp);
    	
    	printf("\nRecords Read. %d\n",rec);
    	
    	if(find!=-1)
    	{
    		printf("\nRECORD FOUND SUCCESSFULLY\n");
    	}
    	
    	for(i=0;i<rec;i++)
    	{
    		if(us[i].user_id==uid)
    		{
    			printf("\nMatch found at position %d",(i+1));
    			printf("\n\tUSER ID\tUSER NAME\tDESIGNATION\n");
    			printf("\n\t\%d\t%s\t%s\n", us[i].user_id,us[i].user_name,us[i].designation);
    			printf("\n");
    			find++;
    		}
    	}
    	if(find==-1)
    	{
    		printf("\nINVALID USER ID\n");
    	}
}

void delete_user(int uid)
{
	user us[100];
    	int r=0;
    	int rec=0;     
	int find=-1;
	int i;
	
	FILE* fp = fopen("user.csv", "r");
 	FILE* fpt = fopen("tempuser.csv", "a+");
 	
 	char filename[20]="user.csv";
	char temp_filename[20]="tempuser.csv";
 	
    	if (!fp || !fpt) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}

	do
	{
		r=fscanf(fp,"%d,%[^,],%s\n",&us[rec].user_id, us[rec].user_name,us[rec].designation);
		if(r == 3)
		{
			rec++;
		} 
		/*printf("%d",r);*/	
		if(r != 3 && !feof(fp))
		{
			printf("\nError in Format\n");
			break;
		}
		if(ferror(fp))
		{
			printf("\nError in Reading\n");
			break;
		}
	}while(!feof(fp));
    	
    	printf("\nRecords Read. %d\n",rec);
    	for(i=0;i<rec;i++)
    	{
    		if(us[i].user_id==uid)
    		{
    			find=i;
    			printf("%d",find);
    		}
    	}
    	
    	for(i=0;i<rec;i++)
    	{
    		if(i!=find)
    		{
    			fprintf(fpt, "%d,%s,%s\n", us[i].user_id, us[i].user_name,us[i].designation );
    		}
    	}
    	
    	fclose(fp);
    	fclose(fpt);
    	
    	remove(filename);
    	rename(temp_filename,filename);
    	
    	if(find!=-1)
    	{
    		printf("\nRECORD DELETED SUCCESSFULLY\n");
    	}
}

void update_user(int uid)
{
	FILE* fp = fopen("user.csv", "r");
 	FILE* fpt = fopen("tempuser.csv", "a+");
 	
 	char filename[20]="user.csv";
	char temp_filename[20]="tempuser.csv";
 	
    	if (!fp || !fpt) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}
    	
    	user us[100];
    	int r=0;
    	int rec=0;     
	int find=-1;	
	do
	{
		r=fscanf(fp,"%d,%[^,],%s\n",&us[rec].user_id, us[rec].user_name,us[rec].designation);
		if(r == 3)
		{
			rec++;
		} 
		/*printf("%d",r);*/	
		if(r != 3 && !feof(fp))
		{
			printf("\nError in Format\n");
			break;
		}
		if(ferror(fp))
		{
			printf("\nError in Reading\n");
			break;
		}
	}while(!feof(fp));
    	
    	int i,tuid;
    	char tuname[50];
	char tdes[20];
    	printf("\nRecords Read. %d\n",rec);
    	for(i=0;i<rec;i++)
    	{
    		if(us[i].user_id==uid)
    		{
    			find=i;
    			printf("%d",find);
    		}
    	}
    	for(i=0;i<rec;i++)
    	{
    		if(i!=find)
    		{
    			fprintf(fpt, "%d,%s,%s\n", us[i].user_id, us[i].user_name,us[i].designation );
    		}
    		if(i==find)
    		{
    			printf("\nEnter USER ID\n");
		    	scanf("%d", &tuid);
		    
		    	printf("\nEnter USER Name\n");
		    	scanf("%s", tuname);
		    
			printf("\nEnter USER DESIGNATION\n");
		    	scanf("%s", tdes);
		    	
		    	fprintf(fpt, "%d,%s,%s\n", tuid, tuname, tdes);
    		}
    	}
    	fclose(fp);
    	fclose(fpt);
    	
    	remove(filename);
    	rename(temp_filename,filename);
    	
    	if(find!=-1)
    	{
    		printf("\nRECORD UPDATED SUCCESSFULLY\n");
    	}
}

