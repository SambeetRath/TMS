#include <menu.h>

struct login{
    	char username[10];
    	char password[10];
}*pUser;

int userlogin()
{
    	FILE *fp;
    	char uName[10], pwd[10];
    	int i;
    	int out=0;
    	char c;
	int u,p;
	int defined_pin=1234;
	int pin;
    	pUser=(struct login *)malloc(sizeof(struct login));
	
    	printf("\t1. Login Through An Existing Account\n\t2. Create New account\n\t3. To Exit\n");
    	printf("\n\t ENTER Choice : ");
    	(void)scanf("%d",&i);
    	
	switch(i)
	{
		case 1:
	    	    	u=0;
	    	    	p=0;
		    	if ( ( fp=fopen("../data/user.dat", "r+")) == NULL) 
		    	{
		        	if (( fp=fopen("../data/user.dat", "w+")) == NULL) 
		        	{
		            		printf ("Could not open file\n");
		            		exit (EXIT_FAILURE);
		        	}
		    	}
		    	
	    	    	printf("\n\tENTER Username and Password\n");
		    	printf("\tUsername: ");
		    	(void)scanf("%9s",uName);
		    	printf("\tPassword: ");
		    	(void)scanf("%9s",pwd);
		    	while ( fread (pUser, sizeof(struct login), 1, fp) == 1) 
		    	{
		        	if( strcmp ( pUser->username, uName) == 0) 
		        	{
		            		u=1;
		            		if( strcmp ( pUser->password, pwd) == 0) 
		            		{
		                		p=1;
		            		}
		        	}
		    	}
		    	if(u==1 && p==1)
		    	{
		    		printf("\n\tLOGIN SUCCESSFUL \n");
		    		out=1;;
		    	}
		    	else
		    	{
		    		printf("\tLOGIN UNSUCCESSFUL\n");
		    		out=0;
		    	}
		    	break;

		case 2:
			printf("\tENTER PIN TO CONTINUE : ");
		        (void)scanf("%d",&pin);
		        if(pin==defined_pin)
		        {
			    	do
			    	{
					if ( ( fp=fopen("../data/user.dat", "a+")) == NULL) 
					{
				    		if ( ( fp=fopen("../data/user.dat", "w+")) == NULL) 
				    		{
				        		printf ("Could not open file\n");
				        		exit (EXIT_FAILURE);
				    		}
					}
					printf("\tChoose A Username: ");
					(void)scanf("%9s",pUser->username);
					printf("\tChoose A Password: ");
					(void)scanf("%9s",pUser->password);
					fwrite (pUser, sizeof(struct login), 1, fp);
					printf("\tAdd another account? (Y/N): ");
					(void)scanf(" %c",&c);/*skip leading whitespace*/
			    	}while(c=='Y'||c=='y');
			    	printf("\tSIGNUP SUCCESSFUL\n\tPLEASE REOPEN THE APPLICATION\n");
		    	}
		    	else
		    	{
		    		printf("\n***INVALID PIN***\n");
		    	}
		    	break;
		    		
		    	/*case 3:
		    		exit(EXIT_SUCCESS);*/
		    	default:
		    		printf("Wrong input");
	    	}
	free (pUser);/*free allocated memory*/
	fclose(fp);
    	return out;
}   
   
int main()
{
    	int x=userlogin();
    	if(x==1)
    	{
    		execMenu();
    	}
    	return 0;
}
  
