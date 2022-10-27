#include <menu.h>
#include <user.h>
#include <task.h>
#include <assignment.h>


void assignment()
{
	
	FILE* fpu = fopen(ucsv, readdat);

    	if (!fpu)
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(EXIT_FAILURE);
    	}

    		user us[100];
    		int ru=0;
    		int recu=0;

		do
		{
		 	ru=fscanf(fpu,"%d,%[^,],%s\n",&us[recu].user_id, us[recu].user_name,us[recu].designation);
			if(ru == 3)
			{
				recu++;
			}
			/*printf("%d",r);*/
			if(ru != 3 && !feof(fpu))
			{
				printf("\nError in Format\n");
				break;
			}
			if(ferror(fpu))
			{
				printf("\nError in Reading\n");
				break;
			}
		}while(!feof(fpu));

    	(void)fclose(fpu);

    	FILE* fpt = fopen(tcsv, readdat);
    	if (!fpt)
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(EXIT_FAILURE);
    	}

    		task ta[100];
    		int rt=0;
    		int rect=0;

		do
		{
		 	rt=fscanf(fpt,"%d,%[^,],%[^,],%s\n",&ta[rect].task_id, ta[rect].task_name,ta[rect].description,ta[rect].deadline);
			if(rt == 4)
			{
				rect++;
			}
			/*printf("%d",r);*/
			if(rt != 4 && !feof(fpt))
			{
				printf("\nError in Format\n");
				break;
			}
			if(ferror(fpt))
			{
				printf("\nError in Reading\n");
				break;
			}
		}while(!feof(fpt));

    	(void)fclose(fpt);

    	FILE* fp = fopen(acsv, writedat);
    	if (!fp)
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(EXIT_FAILURE);
    	}
    	int i,j;

    	for(i=0;i<recu;i++)
    	{
    		fprintf(fp,"%d,%s,%s",us[i].user_id,us[i].user_name,us[i].designation);
	    	for(j=0;j<rect;j++)
    		{
	    		if(ta[j].task_name[0] == us[i].designation[0] && ta[j].task_name[1] == us[i].designation[1] && ta[j].task_name[2] == us[i].designation[2] && ta[j].task_name[3] == us[i].designation[3])
	    		{
	    			fprintf(fp,",%d,%s,%10s",ta[j].task_id,ta[j].task_name,ta[j].deadline);
	    			break;
	    		}
	    	}
	    	fprintf(fp,"\n");
    	}
    	(void)fclose(fp);
}

void display_usertask(int taskid)
{
	int i;
	assign a[100];
    	int r=0;
    	int rec=0;
    	
    	FILE* fp = fopen(acsv, readdat);
    	if (!fp)
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(EXIT_FAILURE);
    	}

	do
	{
		 r=fscanf(fp,"%d,%[^,],%[^,],%d,%[^,],%s\n", &a[rec].uid, a[rec].uname, a[rec].des, &a[rec].tid, a[rec].tname,a[rec].dline);
		if(r == 6)
		{
			rec++;
		}
		/*printf("%d",r);*/
		if(r != 6 && !feof(fp))
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
    		if(a[i].tid==taskid)
    		{
    			printf("For task %s with Task Id %d and deadline %10s \n",a[i].tname,a[i].tid,a[i].dline);
    			break;
    		}
    	}
	printf("\tUserId\tUserName\tDesignation\n");
    	for(i=0;i<rec;i++)
    	{
    		if(a[i].tid==taskid)
    		printf("\t%d\t%s\t\t%s\n",a[i].uid,a[i].uname,a[i].des);
    	}
    	(void)fclose(fp);
}

void display_taskOfuser(int userid)
{
	int i;
	assign a[100];
    	int r=0;
    	int rec=0;
    	
    	FILE* fp = fopen(acsv, readdat);
    	if (!fp)
    	{
        	/* Error in file opening */
        	printf("Can't open file\n");
        	exit(EXIT_FAILURE);
    	}
	
	do
	{
		r=fscanf(fp,"%d,%[^,],%[^,],%d,%[^,],%s\n", &a[rec].uid, a[rec].uname, a[rec].des, &a[rec].tid, a[rec].tname,a[rec].dline);
		if(r == 6)
		{
			rec++;
		}
		/*printf("%d",r);*/
		if(r != 6 && !feof(fp))
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
    		if(a[i].uid==userid)
    		{
    			printf("For USER %s with User Id %d and Designation %s \n",a[i].uname,a[i].uid,a[i].des);
    			printf("\tTaskId\tTaskName\tDeadline\n");
    			printf("\t%d\t%s\t\t%10s\n",a[i].tid,a[i].tname,a[i].dline);
    			break;
    		}
    	}
	
    	(void)fclose(fp);
}
