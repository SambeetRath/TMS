#include <menu.h>
#include <task.h>

void create_task(int n)
{
	task *t;
    	t=(task*)calloc(n, sizeof(task));
    	FILE* fp = fopen(tcsv, appenddat);
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
			printf("\n\tEnter TASK ID\n");
		    	(void)scanf("%d", &t[j].task_id);
		    	printf("\n\tEnter TASK Name\n");
		    	(void)scanf("%s", t[j].task_name);
		    
			printf("\n\tEnter TASK DESCRIPTION\n");
		    	(void)scanf("%s",t[j].description);
		    
		    	printf("\n\tEnter TASK DEADLINE\n");
		    	(void)scanf("%s", t[j].deadline);
		 
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
		    		printf("\n\tNew TASK added to record");
		    	}
		    	else
		    	printf("\tTask info invalid\n");
	    	}
	    	/* Close the file */
		(void)fclose(fp);
    	}
    	printf("\n\tTASK TABLE SUCCESSFULLY CREATED\n");
    	free(t);
}

void read_task()
{

	FILE* fp = fopen(tcsv, readdat);
 	char buffer[1024];
 
    	if (fp==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
    	(void)fclose(fp);
}

void search_task(int tid)
{
	int i,find=-1;
	task ta[100];
	int r=0;
    	int rec=0;
	FILE* fp = fopen(tcsv, readdat);
 	
    	if (fp==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
    		if(ta[i].task_id==tid)
    		{
    			printf("\n\tMatch found at position %d",(i+1));
    			printf("\n\tTASK ID\tTASK NAME\tDESCRIPTION\tDEADLINE\n");
    			printf("\n\t%d\t%s\t%s\t%s\n", ta[i].task_id, ta[i].task_name,ta[i].description,ta[i].deadline);
    			printf("\n");
    			find++;
    		}
    	}
    	if(find==-1)
    	{
    		printf("\n\tINVALID TASK ID\n");
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
	
	FILE* fp = fopen(tcsv, readdat);
 	FILE* fpt = fopen("../data/temptask.csv", appenddat);
 	
 	char fname[25]=tcsv;
	char tfname[25]="../data/temptask.csv";
 	
    	if (fp==NULL || fpt==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
			printf("\n\tError in Format\n");
			break;
		}
		if(ferror(fp))
		{
			printf("\n\tError in Reading\n");
			break;
		}
	}while(!feof(fp));
    	
    	printf("\nRecords Read. %d\n",rec);
    	for(i=0;i<rec;i++)
    	{
    		if(ta[i].task_id==tid)
    		{
    			find=i;
    			printf("\n\tRECORD Found At Position %d\n",(find+1));
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
		    		printf("\n\tEnter TASK ID\n");
			    	(void)scanf("%d", &ttid);
			    
			    	printf("\n\tEnter TASK Name\n");
			    	(void)scanf("%s", ttname);
			    
				printf("\n\tEnter TASK Description\n");
			    	(void)scanf("%s", tdes);
			    	
			    	printf("\n\tEnter TASK DEADLINE\n");
			    	(void)scanf("%s", tdeadl);
			    	
			    	fprintf(fpt, "%d,%s,%s,%10s\n", ttid, ttname, tdes, tdeadl);
		    	}
		}
	}
    	
    	(void)fclose(fp);
    	(void)fclose(fpt);
    	if(find!=(-1))
    	{
    		(void)remove(fname);
    		(void)rename(tfname,fname);
    	}
    	
    	(void)remove(tfname);
    	
    	if(find!=-1)
    	{
    		printf("\n\tRECORD UPDATED SUCCESSFULLY\n");
    	}
    	else
    	{
    		printf("\n\tINVALID INPUT\n");
    	}
}


void delete_task(int tid)
{
	int i;
    	task ta[100];
    	int r=0;
    	int rec=0;     
	int find=-1;
	
	FILE* fp = fopen(tcsv, readdat);
 	FILE* fpt = fopen("../data/temptask.csv", appenddat);
 	
 	char filename[25]=tcsv;
	char temp_filename[25]="../data/temptask.csv";
 	
    	if (fp==NULL || fpt==NULL) 
    	{
        	/* Error in file opening */
        	printf("\tCan't open file\n");
        	exit(EXIT_FAILURE);
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
    		if(ta[i].task_id==tid)
    		{
    			find=i;
    			printf("\n\tRECORD Found At Position %d\n",(find+1));
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
	
    	(void)fclose(fp);
    	(void)fclose(fpt);
    	if(find!=(-1))
    	{
	    	(void)remove(filename);
	    	(void)rename(temp_filename,filename);
	}
	else
	{
		(void)remove(temp_filename);
	}
	
	if(find!=-1)
    	{
    		printf("\n\tRECORD DELETED SUCCESSFULLY\n");
    	}
    	else
    	{
    		printf("\n\tINVALID INPUT\n");
    	}
}

