#include <menu.h>
#include <user.h>


void create_user(int n)
{
	user *u;
 	u=(user*)calloc(n, sizeof(user));
    	FILE* fp = fopen(UCSV, APPENDDAT);
 	int j;
    	if (fp==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
    	}
    	else 
    	{       
    		for(j=0;j<n;j++)
    		{
			printf("\n");
			printf("\n\tEnter USER ID\n");
		    	(void)scanf("%d", &u[j].user_id);
		    
		    	printf("\n\tEnter USER Name\n");
		    	(void)scanf("%s", u[j].user_name);
		    
			printf("\n\tEnter USER DESIGNATION\n");
		    	(void)scanf("%s", u[j].designation);
		    
		 
		    	/* Saving data in file */
		    	int un=1;
		    	
		    	
				if(isupper(u[j].user_name[0])==0 && isupper(u[j].user_name[sizeof(u[j].user_name)])==0)
				{
					un=0;
				}
				    
		    	if(u[j].user_id<10000 && u[j].user_id>999 && un==1)
		    	{
		    		fprintf(fp, "%d,%s,%s\n", u[j].user_id, u[j].user_name,u[j].designation );
		    		printf("\n\tNew USER added to record");
		    	}
		    	else
		    	printf("\tUser info invalid\n");
		    }	
		    	/* Close the file */
		(void)fclose(fp);
		
    	}
    	printf("\n\tUSER TABLE SUCCESSFULLY CREATED\n");
    	free(u);
}

void read_user()
{

	FILE* fp = fopen(UCSV, READDAT);
 
    	if (fp==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
	user us[100];
    	int r=0;
    	int rec=0;
	FILE* fp = fopen(UCSV, READDAT);
    	if (fp==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
			printf("\n\tError in Format\n");
			break;
		}
		if(ferror(fp))
		{
			printf("\n\tError in Reading\n");
			break;
		}
	}while(!feof(fp));
    	
    	(void)fclose(fp);
    	
    	printf("\n\tRecords Read. %d\n",rec);
    	
    	for(i=0;i<rec;i++)
    	{
    		if(us[i].user_id==uid)
    		{
    			printf("\n\tMatch found at position %d",(i+1));
    			printf("\n\tUSER ID\tUSER NAME\tDESIGNATION\n");
    			printf("\n\t\%d\t%s\t%s\n", us[i].user_id,us[i].user_name,us[i].designation);
    			printf("\n");
    			find++;
    		}
    	}
    	if(find==-1)
    	{
    		printf("\n\tINVALID USER ID\n");
    	}
}

void delete_user(int uid)
{
	user us[100];
    	int r=0;
    	int rec=0;     
	int find=-1;
	int i;
	
	FILE* fp = fopen(UCSV, READDAT);
 	FILE* fpt = fopen("../data/tempuser.csv", APPENDDAT);
 	
 	char filename[25]=UCSV;
	char temp_filename[25]="../data/tempuser.csv";
 	
    	if (fp==NULL || fpt==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
			printf("\n\tError in Format\n");
			break;
		}
		if(ferror(fp))
		{
			printf("\n\tError in Reading\n");
			break;
		}
	}while(!feof(fp));
    	
    	printf("\n\tRecords Read. %d\n",rec);
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
    	
    	(void)fclose(fp);
    	(void)fclose(fpt);
    	
    	(void)remove(filename);
    	(void)rename(temp_filename,filename);
    	
    	if(find!=-1)
    	{
    		printf("\n\tRECORD DELETED SUCCESSFULLY\n");
    	}
    	else
    	{
    		printf("\n\tINVALID INPUT\n");
    	}
}

void update_user(int uid)
{
	user us[100];
    	int r=0;
    	int rec=0;     
	int find=-1;
	int i,tuid;
    	char tuname[50];
	char tdes[20];
	
	FILE* fp = fopen(UCSV, READDAT);
 	FILE* fpt = fopen("../data/tempuser.csv", APPENDDAT);
 	
 	char filename[25]=UCSV;
	char temp_filename[25]="../data/tempuser.csv";
 	
    	if (fp==NULL || fpt==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
			printf("\n\tError in Format\n");
			break;
		}
		if(ferror(fp))
		{
			printf("\n\tError in Reading\n");
			break;
		}
	}while(!feof(fp));
    	
    	printf("\n\tRecords Read. %d\n",rec);
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
    			printf("\n\tEnter USER ID\n");
		    	(void)scanf("%d", &tuid);
		    
		    	printf("\n\tEnter USER Name\n");
		    	(void)scanf("%s", tuname);
		    
			printf("\n\tEnter USER DESIGNATION\n");
		    	(void)scanf("%s", tdes);
		    	
		    	fprintf(fpt, "%d,%s,%s\n", tuid, tuname, tdes);
    		}
    	}
    	(void)fclose(fp);
    	(void)fclose(fpt);
    	
    	(void)remove(filename);
    	(void)rename(temp_filename,filename);
    	
    	if(find!=-1)
    	{
    		printf("\n\tRECORD UPDATED SUCCESSFULLY\n");
    	}
    	else
    	{
    		printf("\n\tINVALID INPUT\n");
    	}
}

