//Railway Reservation Project 
/*  Team 6 
        Aditi , Nandini, Vasundhra, Yukta, Nikhil
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h>
#include <string.h> //string operations

//Structure for user
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


//Structure for Trains
struct train_details
{
    char train_name[50];
    char train_number[5];
    char origin[15];
    char train_class[10][5];    //10 classes max. Classes can be stored in abbreviations of 5 char long
    char destination[15];
};

/*Structure for Routes --- Using this in case we need any files to store routes
can be done easily while reading files*/
struct routes
{
    char origin_station[15];
    char train_stops[5][15];
    char dest_station[15];
    char train_no[5];       //Train number should be the same in train_details
};

//Adding a route for the train
void add_route(char tno[], char org[], char dest[])
{
    FILE *infile;
    struct routes rt;
    int i,n;
    infile = fopen("routedets.txt","a+");
    if( infile == NULL)
    {
        fprintf(stderr,"\nError opening file\n");
        return;
    }
    strcpy(rt.train_no,tno);
    strcpy(rt.origin_station,org);
    strcpy(rt.origin_station,dest);
    printf("Enter the number of stops between %s and $s: ",org,dest);
    scanf("%d",&n);
    if ( (n >= 0) && (n <= 5))
    {
        for (i=0; i<n; i++)
        {
            printf("Enter the %d stop: ",i+1);
            scanf("%s",rt.train_stops[i]);
        }
    }
    fwrite(&rt, sizeof(struct routes), 1, infile);
    if(fwrite != 0)
        printf("Train Route Details succesfully stored.\n");
    else
        printf("Error writing the file!!\n");
    fclose(infile);
}

//User Password validation
int passwd_valid(char uname[10],char pwd[12])
{
    FILE *infile;
    struct user_details ud;
    infile = fopen("userdets.txt","a+");
    if( infile == NULL)
    {
        fprintf(stderr,"\nError opening file\n");
        return -1;
    }

    //read the contents from the file
    while (fread(&ud,sizeof(struct user_details),1,infile))
    {
        if (!strcmp(ud.user_name,uname))
        {
            if(!strcmp(ud.password,pwd))
            {
                printf("Login Successfull!!!");
                return 1;
            }
            else
            {
                printf("Password Incorrect. ");
            }
        }
    }
    printf("Invalid credentials. Please check again.");
    return 0;    
}

//Admin Password validation
int admin_passwd_valid(char uname[10],char pwd[12])
{
    /*Admin Details:-
        username - testad
        password - rail6 */
    if(!strcmp(uname,"testad"))
    {
        if(!strcmp(pwd,"rail6"))
        {
            return 1;
        }
        else
        {
            printf("The entered password for admin is incorrect.");
        }
    }
    else
    {
        printf("The username for admin is invalid. Please try again.");
    }
    return 0;
}

//Edit an existing train details
void edit_existing_train(char tno[])
{
    FILE *infile;
    struct train_details td;
    
}


//Add a Train
void add_train()
{
    struct train_details td;
    FILE *infile;
    char tname[5];
    int n,i;
    infile = fopen("traindets.txt","a+");
    if(infile == NULL)
    {
        fprintf(stderr,"\nError in opening the file");
        return;
    }
    printf("Enter the Train number: ");
    scanf("%s",tname);
    while(fread(&td, sizeof(struct train_details), 1, infile))
    {
        if(!strcmp(td.train_number,tname))
        {
            int ch;
            printf("\nTrain Number already exists");
            printf("\nDo you wish to edit the details of the train?\n 1.Yes\n 2.No\n");
            scanf("%d",&ch);
            if(ch == 1)
            {
                edit_existing_train(tname);
                return;
            }
            else if(ch == 2)
            {
                break;
            }
            else
                printf("Invalid choice\n");
        }
    }
    printf("\tEnter the Train name:\n");
    scanf("%s",td.train_name);
    strcpy(td.train_number,tname);
    printf("\tEnter the origin: ");
    scanf("%s",td.origin);
    printf("\tEnter the destination: ");
    scanf("%s",td.destination);
    printf("\tEnter the number of classes in the train: ");
    scanf("%d",n);
    for (i = 0; i<n ; i++)
    {
        printf("\nEnter the %d class of the train",i+1);
        scanf("%s",td.train_class[i]);
    }
    fwrite(&td, sizeof(struct train_details), 1, infile);
    if(fwrite != 0)
        printf("Train Details succesfully stored.\n");
    else
        printf("Error writing the file!!\n");
    
    //Add route for the train which we just entered 
    add_route(td.train_number,td.origin,td.destination);
    fclose(infile);
}


//Admin Main Menu Panel
void admin_menu()
{
    int ch;
    char c;
    do
    {
        printf("\n-------Admin Menu--------\n");
        printf("\n1. Add a train");
        printf("\n2. Modify a train");
        printf("\n3. Delete a train");
        printf("\n4. Log Out");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                add_train();
                break;
            case 2:
                modify_train();
                break;
            case 3:
                delete_train();
                break;
            case 4:
                printf("Succesfully logged out");
                return;
        }
        printf("Do you wish to continue?(Please enter Y or y to continue) ");
        scanf("%c",&c);
    }while (c == 'Y' || c == 'y');
}

//Main Login panel
void login_main(int n)          // 0 -- Normal User, 1 -- Admin 
{
    int res;
    char us_name[10];
    char pwd[12];
    printf("\nEnter the user name: ");
    scanf("%s",us_name);
    printf("\nEnter the password: ");
    scanf("%s",pwd);
    if (n == 1)
    {
        res = admin_passwd_valid(us_name,pwd);
    }
    else if(n == 0)
    {
        res = user_passwd_valid(us_name,pwd);
    }
    if(res == 1)
            admin_menu();
        else
            printf("Invalid Login. Check the credentials. Please Try again.");
}

//User Main panel
void user_main()
{
    int ch;
    char us_name[10];
    char pwd[12];
    printf("\n--------User Menu----------");
    printf("\n1. New User -- Register");
    printf("\n2. Existing User -- Sign In");
    printf("\n3. Return to main menu");
    printf("\n\n Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            user_reg();
            break;
        case 2:
            login_main(0);
            break;
        case 3:
            return;
        default:
            printf("\nWrong Choice!! ");
    }
}

//Main function
int main()
{
    int choice;
    while(1)
    {
        system("@cls||clear");
        printf("\n----------------Welcome to BTRIRCTC---------\n");
        printf("\n1. Admin Login");
        printf("\n2. User Login");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        switch(choice)
        {
            case 1:
                admin_main();
                break;
            case 2:
                user_main();
                break;
            case 3:
                printf("Thank you for visiting. Please visit us soon");
                exit(0);
        }
    }
    return 0;
}