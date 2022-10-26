
#include <menu.h>

struct login{
    	char username[10];
    	char password[10];
}*pUser;

	

int userlogin(void)
{
	
    	FILE *fp;
    	char uName[10], pwd[10];int i;char c;
	int u,p;
    	pUser=(struct login *)malloc(sizeof(struct login));
	
    	printf("\t1. Login Through An Existing Account\n\t2. Create New account\n\t3. To Exit\n");
    	printf("\n\t ENTER Choice : ");
    	scanf("%d",& i);
    	
    		
	    	switch(i)
	    	{
	    	    case 1:
	    	    
	    	    	u=0;
	    	    	p=0;
		    	if ( ( fp=fopen("user.dat", "r+")) == NULL) 
		    	{
		        	if (( fp=fopen("user.dat", "w+")) == NULL) 
		        	{
		            		printf ("Could not open file\n");
		            		exit (1);
		        	}
		    	}
		    	
	    	    	printf("\nENTER Username and Password\n");
		    	printf("Username: ");
		    	scanf("%9s",uName);
		    	printf("Password: ");
		    	scanf("%9s",pwd);
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
		    		printf("\n   LOGIN SUCCESSFUL \n");
		    		return 1;
		    	}
		    	else
		    	{
		    		printf("   LOGIN UNSUCCESSFUL\n");
		    		return 0;
		    	}
		    	break;

			case 2:
		    		do
		    		{
		        		if ( ( fp=fopen("user.dat", "a+")) == NULL) 
		        		{
		            			if ( ( fp=fopen("user.dat", "w+")) == NULL) 
		            			{
		                			printf ("Could not open file\n");
		                			exit (1);
		            			}
		        		}
		        		printf("Choose A Username: ");
		        		scanf("%9s",pUser->username);
		        		printf("Choose A Password: ");
		        		scanf("%9s",pUser->password);
		        		fwrite (pUser, sizeof(struct login), 1, fp);
		        		printf("Add another account? (Y/N): ");
		        		scanf(" %c",&c);/*skip leading whitespace*/
		    		}while(c=='Y'||c=='y');
		    		printf("SIGNUP SUCCESSFUL\nPLEASE REOPEN THE APPLICATION");
		    		break;
		    		
		    	case 3:
		    	exit(1);
		    	default:
		    		printf("Wrong input");
	    	}
    free (pUser);/*free allocated memory*/
    fclose(fp);
    return 0;
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
  
