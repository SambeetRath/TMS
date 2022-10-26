#include <menu.h>
#include <task.h>

void create_task(int n)
{
	task *t;
    	t=(task*)calloc(n, sizeof(task));
    	FILE* fp = fopen("task.csv", "a+");
 	int j;
    	if (!fp)
        printf("Can't open file\n");
 
    	else
    	
    	{
    		for(j=0;j<n;j++)
    		{        
			printf("\n");
			printf("\nEnter TASK ID\n");
		    	scanf("%d", &t[j].task_id);
		    	printf("\nEnter TASK Name\n");
		    	scanf("%s", t[j].task_name);
		    
			printf("\nEnter TASK DESCRIPTION\n");
		    	scanf("%s",t[j].description);
		    
		    	printf("\nEnter TASK DEADLINE\n");
		    	scanf("%s", t[j].deadline);
		 
		    	/* Saving data in file */
		    	int i,dt=1;
		    	
			for(i=0;i<10;i++)
			{
				if(i!=2 && i!=5)
				{
					if(isdigit(t[j].deadline[i])==0)
					dt=0;
						
				}
			}    	
		    	
		    	if(t[j].task_id<10000 && t[j].task_id>999 && dt==1)
		    	{
		    		fprintf(fp, "%d,%s,%s,%s\n", t[j].task_id, t[j].task_name, t[j].description, t[j].deadline);
		    		printf("\nNew TASK added to record");
		    	}
		    	else
		    	printf("Task invalid");
	    	}
	    	/* Close the file */
		fclose(fp);
    	}
    	printf("\nTASK TABLE SUCCESSFULLY CREATED\n");
    	
}

void read_task()
{

	FILE* fp = fopen("task.csv", "r");
 	char buffer[1024];
 
    	if (!fp) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}
    	else
    	{	    
 		printf("\tTASK ID\tTASK NAME\tDESCRIPTION\tDEADLINE\n");
		while (fgets(buffer,1024, fp)) 
		{
		    	char* value = strtok(buffer, ",");
		    	while (value) 
		    	{
		        	printf("\t%s", value);
		        	value = strtok(NULL, ",");
		    	}
		}
    	}
    	fclose(fp);
}

void search_task(int tid)
{
	int i,find=-1;
	task ta[100];
	int r=0;
    	int rec=0;
	FILE* fp = fopen("task.csv", "r");
 	
    	if (!fp) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}
    	     
	do
	{
	 	r=fscanf(fp,"%d,%[^,],%[^,],%s\n",&ta[rec].task_id, ta[rec].task_name,ta[rec].description,ta[rec].deadline);
		if(r == 4)
		{
			rec++;
		} 
		/*printf("%d",r);*/	
		if(r != 4 && !feof(fp))
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
    	
    	
    	for(i=0;i<rec;i++)
    	{
    		if(ta[i].task_id==tid)
    		{
    			printf("\nMatch found at position %d",(i+1));
    			printf("\n\tTASK ID\tTASK NAME\tDESCRIPTION\tDEADLINE\n");
    			printf("\n\t%d\t%s\t%s\t%s\n", ta[i].task_id, ta[i].task_name,ta[i].description,ta[i].deadline);
    			printf("\n");
    			find++;
    		}
    	}
    	if(find==-1)
    	{
    		printf("\nINVALID TASK ID\n");
    	}
}

void update_task(int tid)
{
	task ta[100];
    	int r=0;
    	int rec=0;     
	int find=-1;
	
	int i,ttid;
    	char ttname[50];
	char tdes[20];
	char tdeadl[14];
	
	FILE* fp = fopen("task.csv", "r");
 	FILE* fpt = fopen("temptask.csv", "a+");
 	
 	char fname[20]="task.csv";
	char tfname[20]="temptask.csv";
 	
    	if (!fp || !fpt) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}
    	
	do
	{
		 r=fscanf(fp,"%d,%[^,],%[^,],%s\n",&ta[rec].task_id, ta[rec].task_name,ta[rec].description,ta[rec].deadline);
		if(r == 4)
		{
				rec++;
		} 
		/*printf("\nr=%d",r);*/
			
		if(r != 4 && !feof(fp))
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
    		if(ta[i].task_id==tid)
    		{
    			find=i;
    			printf("\nRECORD Found At Position %d\n",(find+1));
    			break;
    		}
    	}
    	
    	if(find!=(-1))
    	{
		for(i=0;i<rec;i++)
		{
			
		    	if(i!=find)
		    	{
		    		fprintf(fpt, "%d,%s,%s,%10s\n", ta[i].task_id, ta[i].task_name,ta[i].description,ta[i].deadline);
		    	}
		    	if(i==find)
		    	{
		    		printf("\nEnter TASK ID\n");
			    	scanf("%d", &ttid);
			    
			    	printf("\nEnter TASK Name\n");
			    	scanf("%s", ttname);
			    
				printf("\nEnter TASK Description\n");
			    	scanf("%s", tdes);
			    	
			    	printf("\nEnter TASK DEADLINE\n");
			    	scanf("%s", tdeadl);
			    	
			    	fprintf(fpt, "%d,%s,%s,%10s\n", ttid, ttname, tdes, tdeadl);
		    	}
		}
	}
    	
    	fclose(fp);
    	fclose(fpt);
    	if(find!=(-1))
    	{
    		remove(fname);
    		rename(tfname,fname);
    	}
    	
    	remove(tfname);
    	if(find!=-1)
    	{
    		printf("\nRECORD UPDATED SUCCESSFULLY\n");
    	}
    	else
    	{
    		printf("\nINVALID INPUT\n");
    	}
}


void delete_task(int tid)
{
	int i;
    	task ta[100];
    	int r=0;
    	int rec=0;     
	int find=-1;
	
	FILE* fp = fopen("task.csv", "r");
 	FILE* fpt = fopen("temptask.csv", "a+");
 	
 	char filename[20]="task.csv";
	char temp_filename[20]="temptask.csv";
 	
    	if (!fp || !fpt) 
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(0);
    	}
    		
	do
	{
		 r=fscanf(fp,"%d,%[^,],%[^,],%s\n",&ta[rec].task_id, ta[rec].task_name,ta[rec].description,ta[rec].deadline);
		if(r == 4)
		{
			rec++;
		} 
		/*printf("\nr=%d",r);*/	
		if(r != 4 && !feof(fp))
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
    		if(ta[i].task_id==tid)
    		{
    			find=i;
    			printf("\nRECORD Found At Position %d\n",(find+1));
    			break;
    		}
    	}
    	
    	if(find!=(-1))
    	{
	    	for(i=0;i<rec;i++)
	    	{
	    		if(i!=find)
	    		{
	    			fprintf(fpt, "%d,%s,%s,%9s\n", ta[i].task_id, ta[i].task_name,ta[i].description,ta[i].deadline);
	    		}
	    	}
	}
	
    	fclose(fp);
    	fclose(fpt);
    	if(find!=(-1))
    	{
	    	remove(filename);
	    	rename(temp_filename,filename);
	}
	else
	{
		remove(temp_filename);
	}
	
	if(find!=-1)
    	{
    		printf("\nRECORD DELETED SUCCESSFULLY\n");
    	}
    	else
    	{
    		printf("\nINVALID INPUT\n");
    	}
}

