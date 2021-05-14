#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login();
void registration();
// Structure for user
struct user_details
{
    char first_name[20];
    char last_name[30];
    char gender;                // M or F
    int age;
    char contact_number[12];
    char location[50];
    char user_name[10];         //Not more than 10 characters
    char password[12];          //Not more than 12 characters
};

void registration(void)
{
    char firstname[15];
    FILE *log;

    log=fopen("login.txt","w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    struct user_details l;                          //line 512

    printf("\nEnter details for registration.\n\n");
    printf("\nEnter First Name:\n");
    scanf(" %s",&l.first_name);
    printf("\nEnter Surname:\n");
    scanf(" %s",&l.last_name);
    printf("\nEnter Gender (M=male, F=female):\n");
    scanf(" %s",&l.gender);
    printf("\nEnter Your age:\n");
    scanf(" %d",&l.age);
    printf("\nEnter Your contact number:\n");
    scanf(" %s",&l.contact_number);
    printf("\nEnter Your location:\n");
    scanf(" %s",&l.location);
    printf("\n\nPlease choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.");
    printf("\nEnter Username:\n");
    scanf(" %s",&l.user_name);
    printf("\nEnter Password:\n");
    scanf(" %s",&l.password);

    printf("Thank you for registration.\nNow \n"); 

    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",firstname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    
    getchar();
    // system("CLS");
    login();
}


void login()
{
    char username[30],password[20];
    FILE *log;

    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    struct login l;

    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username:  ");
    fgets(username, 30, stdin);
    // scanf("%s",username);
    printf("\nPassword: ");
    printf("\n");
    fgets(password, 20, stdin);

    while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

            {   
                printf("\nSuccessful Login\n");
            }
        else 
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
            }
        }

    fclose(log);

    return;
}


//User Main panel
int main()
{
    int ch;
    // char us_name[10];
    // char pwd[12];
    printf("\n--------User Menu----------");
    printf("\n1. New User -- Register");
    printf("\n2. Existing User -- Sign In");
    printf("\n3. Return to main menu");
    printf("\n\n Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            registration();
            break;
        case 2:
            // login_main(0);
            // system("CLS");
            // printf("\nin logic Wrong Choice!! ");
            login();
            break;
        case 3:
            return;
        default:
            printf("\nWrong Choice!! ");
    }
    return 0;
}
