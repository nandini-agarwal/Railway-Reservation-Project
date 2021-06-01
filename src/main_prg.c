/*  Team 6 
        Aditi , Nandini, Vasundhra, Yukta, Nikhil
*/
 //  ************   Railway Reservation Project    ************

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 
#include <time.h>

struct user_details
{
    char first_name[20];
    char last_name[30];
    char gender;                
    int age;
    char contact_number[12];
    char location[50];
    char user_name[10];         
    char password[12];          
};

struct booking
{
    int PNR;
    char trainNo[10];
    char From[30];
    char Destination[30];
    struct Date
    {
        int date;
        int month;
        int year;
    } dt;
    struct passDetails
    {
        char pname[40];
        char Gender;
        short age;

    } pt[10];
    int NoOfPassengers;
    char contact[10];
    double amount;
} book[50];

int input = 0;
time_t t;
// srand((unsigned)time(&t));

double totalcost = 0;
struct train_details
{
    char train_name[50];
    char train_number[5];
    char origin[15];
    char train_class[10];
    char destination[15];
};

struct routes
{
    char origin_station[50];
    char *train_stops[50];
    char dest_station[50];
};

int makePayment(double totalFare);
double payment(int age, double amount);
int bookingTrain();
void show_booking();
void cancelBooking();
int admin_passwd_valid(char uname[10], char pwd[12]);
void user_menu();
void admin_menu();
void login_main(int n);
void user_main();

void user_main();


int makePayment(double totalFare)
{
    int ch = 0;
    // fetch fare;
    //generate bill 
    if (totalFare > 0.0)
    {
        printf("\n\nYour Fare For Tickets is   %lf ", totalFare);
        printf("\n\nPress 1 To Pay");
        printf("\nPress 0 To Cancel ");
        scanf("%d", &ch);
    }
    if (ch == 1)
    {
        return 1;
    }
    else
        return 0;
}



double payment(int age,double amount)
{
    totalcost = amount;
    //fare fetch.
    float fare = 100;
    if (age >= 0 && age <= 5)
    {
        totalcost = totalcost;
    }
    else if (age >= 5 && age <= 12)
    {
        totalcost = totalcost + (fare / 2); 
    }
    else if (age >= 60)
    {
        totalcost = totalcost + (0.4 * fare); 
    }
    else{
        totalcost = fare + totalcost;
    }
    printf("%lf ", totalcost);
    return totalcost;
}



int bookingTrain()
{
    
    book[input].amount = 0;
    system("@cls||clear");
    printf("\n *********** Enter Booking Details *********** \n");
   
    int isValid = 1;
    while (1)
    {
        isValid = 1;
        fflush(stdin);
        printf("Source - ");
        gets(book[input].From);
        for (int i = 0; i < strlen(book[input].From); i++)
        {
            if ((book[input].From[i] >= 97 && book[input].From[i] <= 122) || (book[input].From[i] >= 65 && book[input].From[i] <= 90)) //check for characters only in name
            {
                isValid = 1;
                
            }
            else if (book[input].From[i]==32){
                isValid = 1;
            }
            else
            {
                isValid = 0;
                break;
            }
        }
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\n Source should not contain integer or special characters, enter again\n");
        }
    }

    isValid = 1;
    while (1)
    {
        fflush(stdin);
        printf("Destination - ");
        gets(book[input].Destination);
        for (int i = 0; i < strlen(book[input].Destination); i++)
        {
            if ((book[input].Destination[i] >= 97 && book[input].Destination[i] <= 122) || (book[input].Destination[i] >= 65 && book[input].Destination[i] <= 90)) //check for characters only in name
            {
                isValid = 1;
            }
            else if (book[input].Destination[i]==32){
                isValid = 1;
            }
            else
            {
                isValid = 0;
                break;
            }
        }
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\n Destination should not contain integer or special characters, enter again\n");
        }
    }

        // show trains under this path;
    isValid = 1;
    while (1)
    {
        fflush(stdin);
        printf("Train No. - ");
        gets(book[input].trainNo);         //check in list also else invalid
        for (int i = 0; i < strlen(book[input].trainNo); i++)
        {
            if ((book[input].trainNo[i] >= 48) || (book[input].trainNo[i] <=57)) //check for numbers only
            {
                isValid = 1;
                
            }
            else
            {
                isValid = 0;
                break;
            }
        }
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\n Train No should not contain character or special characters, enter again\n");
        }
    }
    
    isValid = 1;
    while (1)
    {
        fflush(stdin);
        printf("Enter Your Contact No. - ");
        gets(book[input].contact);
        if (!strcmpi(book[input].contact, "0000000000"))
        {
            isValid = 0;
        }

        for (int i = 0; i < 10; i++)
        {
            if ((book[input].contact[i] < 48) || (book[input].contact[i] > 57)) //check for numbers only
            {
                isValid = 0;
                break;
            }
            else
            {
                isValid = 1;
            }
        }
        if(strlen(book[input].contact)!=10){
            printf("\n Invalid Contact No. \n");
            continue;
        }
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\n Contact number should not contain characters, enter again\n");
        }
    }
    
    isValid = 0;
    while (1)
    {
        fflush(stdin);
        printf("No. of Passengers - ");
        scanf("%d", &book[input].NoOfPassengers);
        if (book[input].NoOfPassengers==0 || book[input].NoOfPassengers <0)
        {
            isValid = 0;
        }
        if (book[input].NoOfPassengers >=1 && book[input].NoOfPassengers <=6) //check for numbers only
        {
                isValid = 1;
                
            }
            else
            {
                printf("Only 6 Booking's can be done under one PNR No.");
                isValid = 0;
            }
        
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\n Passenger number should be only integer, enter again\n");
        }
    }

    book[input].PNR= 2345 + input;
    
    printf("\n******* Enter Passenger Details ******* ");
    for (int j = 0; j < book[input].NoOfPassengers;j++)
    {
        int rerun = 0;
        isValid = 1;
    while (1)
    {
        fflush(stdin);
        printf("\n\nPassenger's Name - ");
        scanf("%s",book[input].pt[j].pname);
        for (int i = 0; i < strlen(book[input].pt[j].pname); i++)
        {
            if ((book[input].pt[j].pname[i] >= 65) && (book[input].pt[j].pname[i] <= 112)) //check for characters only in name
            {
                isValid = 1;
                break;
            }
            else if (book[input].pt[j].pname[i]==32){
                isValid = 1;
            }
            else
            {
                isValid = 0;
            }
        }
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\n Name should not contain integer or special characters, enter again\n");
        }
    }
        
        while (1)
    {
        fflush(stdin);
        printf("Passengers age: ");
        scanf("%d", &book[input].pt[j].age);
        if ((book[input].pt[j].age >=0) && (book[input].pt[j].age < 105)) 
        {
            break;
        }
        else
        {
            printf("\n Invalid Age, enter again\n");
            continue;
        }
    }

    while (1)
    {
        fflush(stdin);
        printf("Passenger's Gender (M/F/O) -  ");
        scanf("%c", &book[input].pt[j].Gender);
        if (book[input].pt[j].Gender =='M' || book[input].pt[j].Gender=='m' || book[input].pt[j].Gender=='F'|| book[input].pt[j].Gender=='f' || book[input].pt[j].Gender=='O'|| book[input].pt[j].Gender=='o') 
        {
            break;
        }
        else
        {
            printf("\n Invalid Input, enter again\n");
            continue;
        }
    }
        book[input].amount=payment(book[input].pt[j].age,book[input].amount);
              
    }
    int ch = 0;
    if (makePayment(book[input].amount))
    {
        input=input +1;
        printf("\n!! Reservation Done successfully !!/n ");
        printf("\nYour PNR No. Is :  %d", book[input - 1].PNR);
        getchar();
    }
    else
    {
        printf("Your Reservation Cancelled !!");
        scanf("%d", &ch);
    }
    return 0;
}



void show_booking()
{
    int choice = 1;
     int pnr;
     int check = 0;
     printf("\n 1 Show Particluar Booking");
     printf("\n 2 Show All Booking");
     printf("\n 3 Back To User Menu  ");
     scanf("%d", &choice);
     if (choice == 1 || choice == 2 || choice == 3)
     {
     switch (choice)
     {
     case 1:
     {
         printf("\n Enter Your Booking PNR No. ");
         scanf("%d", &pnr);
         for (int i = 0; i < input; i++)
         {
             if (book[i].PNR == pnr)
             {
                 check = 1;
                 system("@cls||clear");
                 printf("\n-------------------Booking Details-----------------------\n\n");
                 printf("\nBooking PNR No. is:\t\t%d", book[i].PNR);
                 printf("\nSource:\t\t\t\t%s", book[i].From);
                 printf("\nDestination:\t\t\t%s", book[i].Destination);
                 printf("\nTrainNo:\t\t\t%d", book[i].trainNo);
                 printf("\nContact:\t\t\t%s", book[i].contact);
                 for (int j = 0; j < book[i].NoOfPassengers; j++)
                 {
                     printf("\n\nPassenger Name:\t\t\t%s", book[i].pt[j].pname);
                     printf("\nPassenger Age:\t\t\t%d", book[i].pt[j].age);
                     printf("\nPassenger Gender:\t\t%c", book[i].pt[j].Gender);
                 }
                 printf("\n\nTotal Fare:\t\t\t%lf", book[i].amount);
                 printf("\n\n---------------------------------------------------------\n\n");
                 
             }
         }
         if (check == 0)
         {
             printf("\n!! No Booking Found with this PNR No. !!");
             show_booking();
         }
    }break;

    case 2:{
         system("@cls||clear");
          printf("\n-------------------Booking Details-----------------------\n\n");
    for (int i = 0; i < input;i++){
        if (book[i].PNR !=0)
        {
            printf("\n-------------------Passenger's Details-----------------------\n\n");
            printf("\nBooking PNR No. is:\t\t%d", book[i].PNR);
            printf("\nSource:\t\t\t\t%s", book[i].From);
            printf("\nDestination:\t\t\t%s", book[i].Destination);
            printf("\nTrainNo:\t\t\t%d", book[i].trainNo);
            printf("\nContact:\t\t\t%s", book[i].contact);
            for (int j = 0; j < book[i].NoOfPassengers; j++)
            {
                printf("\n\nPassenger Name:\t\t\t%s", book[i].pt[j].pname);
                printf("\nPassenger Age:\t\t\t%d", book[i].pt[j].age);
                printf("\nPassenger Gender:\t\t%c", book[i].pt[j].Gender);
            }
            printf("\n\nTotal Fare:\t\t\t%lf", book[i].amount);
            printf("\n\n---------------------------------------------------------\n\n");
           
    }
    }
   
    }
    break;
    case 3:{
        user_menu();
    }
    break;
     }
}

else{
          printf("Invalid Input");
           show_booking();
     }

}


void cancelBooking(){
     int pnr;
    int check = 0;
    printf("\n Enter Your Booking PNR No. ");
    scanf("%d",&pnr);
    for (int i = 0; i < input;i++){
        if (book[i].PNR == pnr)
        {
            check = 1;
            book[i].PNR = 0;
            printf("\n !! Your Booking Is Cancelled !!");
            printf("\n\n Note: Your amount will be refunded within 2 days of Cancel the Booking");
            getchar();
            break;
    }
    }
    if(check==0){
        printf("\nInvalid PNR Entered.\nPlease Try Again.");
        cancelBooking();
    }
    
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


void user_menu()
{
    int a;
    char c;
    printf("\n -------------- User Menu -------------");
    // validation;
    do
    {
         system("@cls||clear");
        printf("\n1. Make a Booking");
        printf("\n2. Modify the Booking");
        printf("\n3. Cancel the booking");
        printf("\n4. Show Reservation");
        printf("\n5. Return to Main Menu ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        system("@cls||clear");
            bookingTrain();
            break;
        case 2:
        system("@cls||clear");
            // modifyBooking();
            break;
        case 3:
        system("@cls||clear");
            cancelBooking();
            break;
        case 4:
        system("@cls||clear");
            show_booking();
            break;
        case 5:
        system("@cls||clear");
            user_main();
            break;
        default:
            printf("Wrong choice entered , Try again");
            a = 0;
            break;
        }
        printf("\n Return to User Menu ( Press Y or y) ");
        scanf("%c", &c);

    } while (a >= 5 || c == 'Y' || c == 'y');
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
                // add_train();
                break;
            case 2:
                // modify_train();
                break;
            case 3:
                // delete_train();
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
        // res = user_passwd_valid(us_name,pwd);
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
        // user_reg();
        break;
    case 2:
        user_menu();
        // login_main(0);
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
    user_menu();
    int choice;
    while (1)
    {
        system("@cls||clear");
        printf("\n----------------Welcome to BTRIRCTC---------\n");
        printf("\n1. Admin Login");
        printf("\n2. User Login");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // admin_main();
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