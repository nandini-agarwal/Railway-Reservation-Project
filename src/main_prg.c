/*  Team 6 
        Aditi , Nandini, Vasundhra, Yukta, Nikhil
*/
 //  ************   Railway Reservation Project    ************

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 
#include <time.h>
#include <conio.h>

void view_Details();
void add_train();

char choice;

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
    int trainNo;
    char From[30];
    char Destination[30];
    int date;
    int month;
    int year;
    int hh;
    int mm;
    struct passDetails
    {
        int pid;
        char pname[40];
        char Gender;
        short age;

    } pt[10];
    int NoOfPassengers;
    char contact[10];
    int amount;
} book[50];

int input = 0;
struct routes
{
    char origin[15];
    struct routes* next;
    struct routes* previous;    
}*head, *last;

double totalcost = 0;
struct train_details
{
    char train_name[50];
    char train_number[5];
    char origin[15];
    char train_class[10][5];    //10 classes max. Classes can be stored in abbreviations of 5 char long
    char destination[15];
    int fare;
    int seats;
}obj;

int makePayment(int totalFare);
int payment(int age, int amount,int userinput);
int bookingTrain();
void show_booking();
void cancelBooking();
int admin_passwd_valid(char uname[10], char pwd[12]);
void user_menu();
void admin_menu();
void login_main(int n);
void user_main();
void user_reg();
// void login();
void routes_menu();
// void create_route(int n);
void display_route();
void modify_route();
// void insert_route(int n,char d[15]);
// void delete_route(int n);
void user_validt(char uname[],char pwd[]);
void search_route(char city1[],char city2[]);
int seatAllocation(int capacity,int tno,int choice);
int route_found = 0;

void search_route(char city1[],char city2[])
{
    int f = 0;
    struct routes *temp;
    if(head == NULL)
    {
        printf("No route found");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            if((strcmp(city1,temp->origin)==0) || (strcmp(city2,temp->origin)==0))
            {
                f = f+1;
                temp = temp->next;
            }
            else
                temp = temp->next;
        }
        if (f==2){
            printf("\nMatched --- Route found");
            route_found = 1;
        }
        else{
            printf("\nNo Route found");
            route_found = 0;
        }
    }
}
void user_main();

int seatAllocation(int capacity,int tno,int choice){
     FILE *fptr;
     struct train_details t;
     fptr = fopen("TrainDetails.txt", "a+");
     if (fptr == NULL)
     {
         printf("ERROR! File could not open");
         exit(1);
    }
switch (choice)
{
case 1:
    {
 while (fread(&t, sizeof(struct train_details), 1, fptr)) //loop to iterate over file
    {
        if (!strcmpi(t.train_number, tno))
        {  

            if(t.seats>capacity){
                t.seats = t.seats - capacity;
            }
            else{
                printf("\n Only %d Seats Left ",t.seats);
            }

            fclose(fptr);
            return 1;
        }
    }

    }
    break;

    case 2:{
while (fread(&t, sizeof(struct train_details), 1, fptr)) //loop to iterate over file
    {
        if (!strcmpi(t.train_number, tno))
        {  
                t.seats = t.seats + capacity;

            fclose(fptr);
            return 1;
        }
    }
    }
    break;

    default: fclose(fptr);
        break;
}
}

int makePayment(int totalFare)
{
    int ch = 0; 
    if (totalFare > 0.0)
    {
        printf("\n\nYour Fare For Tickets is   %lf ",totalFare);
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

int payment(int age,int amount,int userinput)
{
    switch (userinput)
    {
    case 1:{
        totalcost = amount;
    int fare = 100;
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
    return totalcost;
    }
        break;
    case 2:{
        totalcost = amount;
    //fare fetch.
    int fare = 100;
    if (age >= 0 && age <= 5)
    {
        totalcost = totalcost;
    }
    else if (age >= 5 && age <= 12)
    {
        totalcost = totalcost - (fare / 2); 
    }
    else if (age >= 60)
    {
        totalcost = totalcost - (0.4 * fare); 
    }
    else{
        totalcost = fare - totalcost;
    }
    return totalcost;
    }break;
    
}
}


int bookingTrain()
{
    int found = 0;
    book[input].amount = 0;
    system("@cls||clear");
    printf("\n *********** Enter Booking Details *********** \n");
   
    int isValid = 1;
    // while (1)
    // {
    //     isValid = 1;
        fflush(stdin);
        printf("Source - ");
        // gets(book[input].From);
        fgets(book[input].From, 30, stdin);
    //     for (int i = 0; i < strlen(book[input].From); i++)
    //     {
    //         if ((book[input].From[i] >= 97 && book[input].From[i] <= 122) || (book[input].From[i] >= 65 && book[input].From[i] <= 90)) //check for characters only in name
    //         {
    //             isValid = 1;
                
    //         }
    //         else if (book[input].From[i]==32){
    //             isValid = 1;
    //         }
    //         else
    //         {
    //             isValid = 0;
    //             break;
    //         }
    //     }
    //     if (isValid)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         printf("\n Source should not contain integer or special characters, enter again\n");
    //     }
    // }

    // isValid = 1;
    // while (1)
    // {      
        fflush(stdin);
        printf("Destination - ");
        // gets(book[input].Destination);
        fgets(book[input].Destination,30,stdin);
    //     for (int i = 0; i < strlen(book[input].Destination); i++)
    //     {
    //         if ((book[input].Destination[i] >= 97 && book[input].Destination[i] <= 122) || (book[input].Destination[i] >= 65 && book[input].Destination[i] <= 90)) //check for characters only in name
    //         {
    //             isValid = 1;
    //         }
    //         else if (book[input].Destination[i]==32){
    //             isValid = 1;
    //         }
    //         else
    //         {
    //             isValid = 0;
    //             break;
    //         }
    //     }
    //     if (isValid)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         printf("\n Destination should not contain integer or special characters, enter again\n");
    //     }
    // }
    isValid = 1;
    while (1)
    {
        fflush(stdin);
        printf("Enter Date in format(dd/mm/yy) :");
        scanf("%d/%d/%d", &book[input].date,&book[input].month,&book[input].year);
            if ((book[input].date >=1) && (book[input].date <=31) && (book[input].month >=1) && (book[input].month <=12)&&(book[input].year==21))//check for numbers only
            {
                isValid = 1;
                
            }
            else
            {
                isValid = 0;
                
            }
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\nInvalid Date Entered\n");
        }
    }

    isValid = 1;
    while (1)
    {
        fflush(stdin);
        printf("Enter Time in format(hh:mm) in 24-hour format :");
        scanf("%d:%d", &book[input].hh,&book[input].mm);
            if (((book[input].hh >=0) && (book[input].hh <=23)) && ((book[input].mm>=0) && (book[input].mm <=59)))//check for numbers only
            {
                isValid = 1;
                
            }
            else
            {
                isValid = 0;
                
            }
        if (isValid)
        {
            break;
        }
        else
        {
            printf("\nInvalid Time Entered\n");
        }
    }

    search_route(book[input].From, book[input].Destination);
    if(route_found==0)
    {
        printf("\nBooking Can't Be Done As No Such Route Exist");
        getch();
        user_menu();
    }

    // checkTrain(book[input].From, book[input].Destination);
    view_Details();
    // show trains under this path;
    // isValid = 1;
    // while (1)
    // {
        fflush(stdin);
        printf("\nTrain No. - ");
        scanf("%d",&book[input].trainNo);         //check in list also else invalid
    //     for (int i = 0; i < strlen(book[input].trainNo); i++)
    //     {
    //         if ((book[input].trainNo[i] >= 48) || (book[input].trainNo[i] <=57)) //check for numbers only
    //         {
    //             isValid = 1;
                
    //         }
    //         else
    //         {
    //             isValid = 0;
    //             break;
    //         }
    //     }
    //     if (isValid)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         printf("\n Train No should not contain character or special characters, enter again\n");
    //     }
    // }
    
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

        book[input].amount=payment(book[input].pt[j].age,book[input].amount,1);
        book[input].pt[j].pid = j + 1;
        printf("\nPassenger Id is %d",book[input].pt[j].pid);
    }
    int ch = 0;
    if (makePayment(book[input].amount))
    {
        input=input +1;
        seatAllocation(book[input].NoOfPassengers, book[input].trainNo, 1);
        printf("\nYour PNR No. Is :  %d", book[input - 1].PNR);
        printf("\n!! Reservation Done successfully !!\n ");
        getch();
    }
    else
    {
        input = input - 1;
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
     fflush(stdout);
    system("@cls||clear");
     printf("\n --------- Show Booking --------");
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
                 fflush(stdout);
                 system("@cls||clear");
                 printf("\n**************** Booking Details ****************\n");
                 printf("\nBooking PNR No. is:\t\t%d", book[i].PNR);
                 printf("\nSource:\t\t\t\t%s", book[i].From);
                 printf("\nDestination:\t\t\t%s", book[i].Destination);
                 printf("\nTrainNo:\t\t\t%d", book[i].trainNo);
                 printf("\nContact:\t\t\t%s", book[i].contact);
                 for (int j = 0; j < book[i].NoOfPassengers; j++)
                 {
                     if(book[i].pt[j].pid !=0)
                     {
                     printf("\n\nPassenger Id:\t\t\t%d", book[i].pt[j].pid);
                     printf("\nPassenger Name:\t\t\t%s", book[i].pt[j].pname);
                     printf("\nPassenger Age:\t\t\t%d", book[i].pt[j].age);
                     printf("\nPassenger Gender:\t\t%c", book[i].pt[j].Gender);
                 }
                 }
                 printf("\n\n Total Fare:\t\t\t%d", book[i].amount);
                 printf("\n\n************************************************\n\n");
                 getch();
             }
         }
         if (check == 0)
         {
             printf("\n!! No Booking Found with this PNR No. !!");
             show_booking();
         }
    }break;

    case 2:{
        int ch=1,found = 0;
        system("@cls||clear");
        for (int i = 0; i < input; i++)
        {
            if (book[i].PNR != 0)
            { 
                fflush(stdout);
                found = 1;
                if(ch==1){
                    printf("\n ************** Booking Details **************\n");
                    ch++;
                }
                printf("\nBooking PNR No. is:\t\t%d", book[i].PNR);
                printf("\nSource:\t\t\t\t%s", book[i].From);
                printf("\nDestination:\t\t\t%s", book[i].Destination);
                printf("\nTrainNo:\t\t\t%d", book[i].trainNo);
                printf("\nContact:\t\t\t%s", book[i].contact);
                // printf("\n-------------Passenger's Details--------------");
                for (int j = 0; j < book[i].NoOfPassengers; j++)
                {
                    if (book[i].pt[j].pid != 0)
                    {
                        printf("\n\nPassenger Id:\t\t\t%d", book[i].pt[j].pid);
                        printf("\nPassenger Name:\t\t\t%s", book[i].pt[j].pname);
                        printf("\nPassenger Age:\t\t\t%d", book[i].pt[j].age);
                        printf("\nPassenger Gender:\t\t%c", book[i].pt[j].Gender);
                    }
                }
                printf("\n\n Total Fare:\t\t\t%d", book[i].amount);
                printf("\n----------------------------------------------\n");
            }
    }
    if(found==1){
            printf("\n ********************************************************\n");
            getch();
    }
    else{
        printf("\n No Booking Record Found");
        getch();
    }
    show_booking();
    }
    break;
    case 3:{
        user_menu();
    }
    break;
     }
}

else{
          printf(" Invalid Input");
          getch();
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
             seatAllocation(book[i].NoOfPassengers, book[i].trainNo, 2);
            printf("\n !! Your Booking Is Cancelled !!");
            printf("\n\n Note: Your amount will be refunded within 2 days of Cancel the Booking");
            getch();
    }
    }
    if(check==0){
        printf("\nInvalid PNR Entered.\nPlease Try Again.");
        cancelBooking();
    }
    
}  //DATE INPUT

void modifyBooking()
{   
    int choice = 1,booking_found=0;
     int pnr;
     int check = 0;
      system("@cls||clear");
     printf("\n------- Booking Modify Menu -------");
     printf("\n 1 Modify Passenger's Details");
     printf("\n 2 Modify Other Details");
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
         for (int ch = 0; ch < input; ch++)
         {
             if (book[ch].PNR == pnr)
             {
                 int a = 1;
                 check = 1;
                 booking_found = 1;
                 system("@cls||clear");
                 printf("\n 1 Add New Passenger");
                 printf("\n 2 Remove Existing Passenger");
                 printf("\n 3 Edit Existing Passenger Details");
                 printf("\n 4 Back To User Menu ");
                 scanf("%d", &a);
                  system("@cls||clear");
                 if(a ==1 || a==2 || a==3 || a==4){
                     switch (a)
                     {
                     case 1: {
                         if(book[ch].NoOfPassengers>=6){
                             printf("\nNOTE : Only 6 Passenger's can be added under one PNR No.");
                         }
                    else {
                         int len = book[ch].NoOfPassengers;
                         book[ch].NoOfPassengers = book[ch].NoOfPassengers + 1;
                         printf("\n******* Enter Passenger Details ******* ");
                         for (int j = len; j < book[ch].NoOfPassengers; j++)
                         {
                             int rerun = 0;
                             int isValid = 1;
                             while (1)
                             {
                                 fflush(stdin);
                                 printf("\n\nPassenger's Name - ");
                                 scanf("%s", book[ch].pt[j].pname);
                                 for (int i = 0; i < strlen(book[ch].pt[j].pname); i++)
                                 {
                                     if ((book[ch].pt[j].pname[i] >= 65) && (book[ch].pt[j].pname[i] <= 112)) //check for characters only in name
                                     {
                                         isValid = 1;
                                         break;
                                     }
                                     else if (book[ch].pt[j].pname[i] == 32)
                                     {
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
                                 scanf("%d", &book[ch].pt[j].age);
                                 if ((book[ch].pt[j].age >= 0) && (book[ch].pt[j].age < 105))
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
                                 scanf("%c", &book[ch].pt[j].Gender);
                                 if (book[ch].pt[j].Gender == 'M' || book[ch].pt[j].Gender == 'm' || book[ch].pt[j].Gender == 'F' || book[ch].pt[j].Gender == 'f' || book[ch].pt[j].Gender == 'O' || book[ch].pt[j].Gender == 'o')
                                 {
                                     break;
                                 }
                                 else
                                 {
                                     printf("\n Invalid Input, enter again\n");
                                     continue;
                                 }
                             }
                             book[ch].pt[j].pid = j + 1;
                             seatAllocation(book[ch].NoOfPassengers, book[ch].trainNo, 1);
                             if(book[ch].pt[j].age >5 ){
                             book[ch].amount = payment(book[ch].pt[j].age, book[ch].amount,1);
                             printf("\n\nPassenger's Id is %d", book[ch].pt[j].pid);
                             printf("\nUpdated Amount is %d", book[ch].amount);
                             }
                             else{
                                 printf("\nAs the passenger's Age is less than 5, so no change in amount");
                                 printf("\n Total fare is %d", book[ch].amount);
                             }
                             printf("\n\n!! Details Updated Successfully !!\n");
                             input++;
                     }
                     }
                     getch();
                     modifyBooking();
                 }
                 break;

                 case 2 :{
                     int id,pos,value=0;
                     printf("\nEnter Passenger's Id");
                     scanf("%d", &id);
                     for (int i = 0; i < book[ch].NoOfPassengers;i++){  
                         if(book[ch].pt[i].pid==id) {
                             pos = i;
                         }
                         if(book[ch].pt[i].pid !=id && book[ch].pt[i].pid !=0)
                             {value++;}
                          }
                          book[ch].pt[pos].pid = 0;
                         if(value >=1) 
                         {
                             seatAllocation(book[ch].NoOfPassengers, book[ch].trainNo, 2);
                             book[ch].amount=payment(book[ch].pt[pos].age, book[ch].amount, 2);
                             printf("\nPassenger Removed Successfully !!");
                             printf("\nUpdated Fare is %d", book[ch].amount);
                             printf("\n\nNOTE: Your amount will be refunded within 2 days\n");
                         }
                         else{
                             printf("\nWe can't remove this passenger , as it is the only passenger left. \nPlease cancel the Booking \n");
                         }
                         getch();
                          system("@cls||clear");
                         modifyBooking();
                }
                 break;
                 case 3 :{
                     int id,isValid,rerun,age,found=0;
                    system("@cls||clear");
                     printf("\nEnter Passenger's Id");
                     scanf("%d", &id);       //validation
                     for (int j = 0; j < book[ch].NoOfPassengers;j++){
                         if(book[ch].pt[j].pid==id){
                             found = 1;
                             age = book[ch].pt[j].age;
                             book[ch].amount=payment(book[ch].pt[j].age, book[ch].amount, 2);
                            rerun = 0;
                             isValid = 1;
                             while (1)
    {
        fflush(stdin);
        printf("\n\nPassenger's Name - ");
        scanf("%s",book[ch].pt[j].pname);
        for (int i = 0; i < strlen(book[ch].pt[j].pname); i++)
        {
            if ((book[ch].pt[j].pname[i] >= 65) && (book[ch].pt[j].pname[i] <= 112)) //check for characters only in name
            {
                isValid = 1;
                break;
            }
            else if (book[ch].pt[j].pname[i]==32){
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
        scanf("%d", &book[ch].pt[j].age);
        if ((book[ch].pt[j].age >=0) && (book[ch].pt[j].age < 105)) 
        {
            break;
        }
        else
        {
            printf("\n Invalid Age, enter again\n");
            getch();
            continue;
        }
    }
    while (1)
    {
        fflush(stdin);
        printf("Passenger's Gender (M/F/O) -  ");
        scanf("%c", &book[ch].pt[j].Gender);
        if (book[ch].pt[j].Gender =='M' || book[ch].pt[j].Gender=='m' || book[ch].pt[j].Gender=='F'|| book[ch].pt[j].Gender=='f' || book[ch].pt[j].Gender=='O'|| book[ch].pt[j].Gender=='o') 
        {
            break;
        }
        else
        {
            printf("\n Invalid Input, enter again\n");
            continue;
        }
    }
            if(book[ch].pt[j].age !=age){
                book[ch].amount=payment(book[ch].pt[j].age,book[ch].amount,1);
                printf("Updated Amount Is %d", book[ch].amount);
                getch();
            }
            else{
                printf("\nNo Change In Fare.\nYour Fare is : lf", book[ch].amount);
                getch();
            }
            
    }
                    }  

                     if(found==0){
                         printf("\nPassenger Id didn't match");
                         getch();
                     } 
                     else{
                          system("@cls||clear");
                         modifyBooking();
                     }   
                 }break;

                 case 4 :{
                      system("@cls||clear");
                     modifyBooking();
                 }
                     break;
                     }
                 }
             }
         }
         if(booking_found==0){
             printf("\nInvalid PNR No. Entered.");
             getch();
         }
         }
     break;

     case 2:
     {
         system("@cls||clear");
         bookingTrain();
             }
             break;
             case 3:{ system("@cls||clear");
                 user_menu();
             }
             break;
             }
             if(check==0){
                 printf("\nNo Booking Found With This PNR No.");
                 modifyBooking();
             }
     }
     else{
         printf("\n!! Invalid Input !!");
         getchar();
          system("@cls||clear");
         modifyBooking();
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
        username - test
        password - rail */
    if(!strcmp(uname,"test"))
    {
        if(!strcmp(pwd,"rail"))
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
        printf("The username for admin is invalid.");
    }
    return 0;
}


void user_menu()
{
    int a,found;
    char c;
    char c1[15],c2[15];
    printf("\n -------------- User Menu -------------");
    // validation;
    do
    {
        system("@cls||clear");
        printf("\n------- Booking Menu -------\n");
        printf("\n1. Make a Booking");
        printf("\n2. Modify the Booking");
        printf("\n3. Cancel the booking");
        printf("\n4. Show Reservation");
        printf("\n5. Search for the routes");
        printf("\n6. Return to Main Menu ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
        system("@cls||clear");
            bookingTrain();
            break;
        case 2:
        system("@cls||clear");
            modifyBooking();
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
            fflush(stdin);
            printf("Enter the first city: ");
            fgets(c1,15,stdin);
            printf("Enter the second city: ");
            fgets(c2,15,stdin);
            search_route(c1,c2);
            break;
        case 6:
        system("@cls||clear");
            main();
            break;
        default:{
            printf("Wrong choice entered , Try again");
            a = 0;
        }
            break;
        }
        // printf("\n Return to User Menu ( Press Y or y) ");
        // scanf("%c", &c);
        c = 'Y';

    } while (a >= 6 || c == 'Y' || c == 'y');
}

//Add Train Method
void add_train()
{

    FILE *fptr;
    printf("\nEnter num: ");
    scanf(" %s", &obj.train_number);
    printf("\nEnter name: ");
    scanf(" %s", &obj.train_name);
    printf("\nEnter origin: ");
    scanf(" %s", &obj.origin);
    printf("\nEnter dest: ");
    scanf(" %s", &obj.destination);
    printf("\nEnter class: ");
    scanf(" %s", &obj.train_class);
    // printf("\nEnter Fare : ");
    // scanf("%d", &obj.fare);
    // printf("\nEnter Capacity : ");
    // scanf("%d", &obj.seats);

    fptr = fopen("TrainDetails.txt", "a+");

    if (fptr == NULL)
    {
        printf("Error!");
    }
    else
    {
        fputs("\n", fptr);
        fputs(obj.train_number, fptr);
        fputs("\t", fptr);
        fputs(obj.train_name, fptr);
        fputs("\t", fptr);
        fputs(obj.origin, fptr);
        fputs("\t", fptr);
        fputs(obj.destination, fptr);
        fputs("\t", fptr);
        fputs(obj.train_class, fptr);
        // fputs("\t", fptr);
        // fputs(obj.fare, fptr);
        // fputs("\t", fptr);
        // fputs(obj.seats, fptr);
        fclose(fptr);
    }
label:
    printf("Do you want to view details?\n");
    printf("Enter 'y' to view details or 'n' to go back to main menu ");
    scanf(" %c", &choice);
    switch (choice)
    {
    case 'Y':
    case 'y':
        view_Details();
        break;
    case 'N':
    case 'n':
        printf("No");
        break;
    default:
        printf("Wrong Choice!\n");
    }
}

//View Train Details Method
void view_Details()
{

    FILE *fptr;
    fptr = fopen("TrainDetails.txt", "r");
    if (fptr == NULL)
    {
        printf("ERROR! File could not open");
        exit(1);
    }

    printf("\n===================================Train Details===============================\n");
    printf("\n");
    printf("Train Number   Train Name      Train Origin    Train Destination   Train Class\n");
    while (fscanf(fptr, "%s\t%s\t%s\t%s\t\t%s\n", obj.train_number, obj.train_name, obj.origin, obj.destination, obj.train_class) != EOF)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n", obj.train_number, obj.train_name, obj.origin, obj.destination, obj.train_class);
    }
    getch();
    fclose(fptr);
}


//Admin Main Menu Panel
void admin_menu()
{
    int ch;
    char c;
    do
    {
        system("@cls||clear");
        printf("\n-------Admin Menu--------\n");
        printf("\n1. Add a train");
        printf("\n2. Display train details");
        //printf("\n3. Delete a train");
        printf("\n3. Log Out");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            system("@cls||clear");
                add_train();
                printf("\n\n\n\n");
                routes_menu();
                break;
            case 2:
            system("@cls||clear");
                view_Details();
                break;
            case 3:

                printf("Succesfully logged out");
                break;
        }
        fflush(stdin);
        printf("Do you wish to continue?(Please enter Y or y to continue) ");
        scanf("%c",&c);
    }while (c == 'Y' || c == 'y');
}
//User validation
void user_validt(char uname[],char pwd[])
{
    FILE *log;
    log = fopen("login.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    struct user_details l;
    while(fread(&l,sizeof(struct user_details),1,log))
    {
        if(strcmp(uname,l.user_name) ==0 && strcmp(pwd,l.password)==0)
        {   
            printf("\nSuccessful Login\n");
            getch();
            user_menu();
        }
        else 
        {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
        }
    }
    fclose(log);
}

//User Login
void login()
{
    char username[30],password[20];
    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username:");
    //fgets(username, 30, stdin);
    scanf("%s",username);
    printf("\nPassword:");
    scanf("%s",password);
    user_validt(username,password);
    getch();
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
    {
        printf("Invalid Login. Check the credentials. Please Try again.");
        getch();
        main();
    }
}

//User Registration
void user_reg()
{
    int isValid = 1;
    // char firstname[15];
    FILE *log;
    struct user_details l;    
    system("@cls||clear");
    printf("\n**********Enter details for registration.**********\n");
    while(1) //Firstname
    {
        printf("\nEnter First Name:\n");
        scanf("%s",&l.first_name);
        for (int i = 0; i < strlen(l.first_name); i++)
            {
                if ((l.first_name[i] >= 65) && (l.first_name[i] <= 112)) //check for characters only in name
                {
                    isValid = 1;
                    break;
                }
                else if (l.first_name[i] == 32){
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

    while(1) //Lastname
    {
        printf("\nEnter Surname:\n");
        scanf("%s",&l.last_name);
        for (int i = 0; i < strlen(l.last_name); i++)
            {
                if ((l.last_name[i] >= 65) && (l.last_name[i] <= 112)) //check for characters only in name
                {
                    isValid = 1;
                    break;
                }
                else if (l.last_name[i] == 32){
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
                printf("\n Last name should not contain integer or special characters, enter again\n");
            }

    }

    printf("\nEnter Gender (M=male, F=female, O=Other):\n");
    while(1){
        fflush(stdin);
        scanf("%c",&l.gender);
        if(l.gender =='M' || l.gender=='m' || l.gender=='F'|| l.gender=='f' || l.gender=='O'|| l.gender=='o')
        {
            break;
        }
        else
        {
            printf("\n Invalid gender, enter again\n");
            continue;
        }
    }
    
    printf("\nEnter Your age:\n");
    while(1)
    {
        fflush(stdin);
        scanf("%d", &l.age);
        if ((l.age >=18) && (l.age< 100)) 
        {
            break;
        }
        else
        {
            printf("\n Invalid Age, enter again\n");
            continue;
        }
    }

    while(1)
    {
        printf("\nEnter Your contact number:\n");
        scanf("%s",&l.contact_number);

        if (!strcmpi(l.contact_number, "0000000000"))
            {
                isValid = 0;
            }

        for (int i = 0; i < 10; i++)
        {
            if ((l.contact_number[i] < 48) || (l.contact_number[i] > 57)) //check for numbers only
            {
                isValid = 0;
                break;
            }
            else
            {
                isValid = 1;
            }
        }
        if(strlen(l.contact_number)!=10){
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

    printf("\n\nPlease choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.");
    printf("\nEnter Username:\n");
    scanf(" %s",&l.user_name);
    printf("\nEnter Password:\n");
    scanf(" %s",&l.password);
    printf("Thank you for registration.\nNow \n"); 
    log=fopen("login.txt","a+");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }
    fwrite(&l,sizeof(struct user_details),1,log);
    fclose(log);
    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",l.first_name);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    getch();
    system("@cls||clear");
    printf("***************User Login***************");
    login();
}

//User Main panel
void user_main()
{
    int ch;
    char us_name[10];
    char pwd[12];
    system("@cls||clear");
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
        // user_menu();
        login(0);
        break;
    case 3:
    login_main(1);
        return;
    default:
        printf("\nWrong Choice!! ");
    }
}

//Main function
int main()
{
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
            login_main(1);
            break;
        case 2:
            // login();
            user_main();
            break;
        case 3:
            printf("Thank you for visiting. Please visit us soon");
            exit(0);
        }
    }
    return 0;
}

//Routes Main menu
void routes_menu()
{
    int n,c = 1;
    while (c !=4 )
    {
        printf("--------------------------\n");
        printf("-----Routes Menu----------\n");
        printf("--------------------------\n");
        printf("1. Create a route\n");
        printf("2. Display a route\n");
        printf("3. Modify a route\n");
        printf("4. Return to Train's menu\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch(c)
        {
            case 1:
                head = NULL;
                last = NULL;
                printf("\nEnter the number of stops you would like to create: ");
                scanf("%d",&n);
                create_route(n);
                break;
            case 2:
                display_route();
                break;
            case 3:
                modify_route();
                break;
            case 4:
                admin_menu();
                break;    
            default:
                printf("Enter a valid choice.\nGiven choice is invalid.\n ");
        }
        printf("\n\n\n\n");       
    }
}

//Function to create a new route
void create_route(int n)
{
    int i;
    char data[15];
    struct routes *newNode;
    if(n >= 1)
    {
        head = (struct routes*)malloc(sizeof(struct routes));
        printf("Enter the origin: ");
        fflush(stdin);
        fgets(data,15,stdin);

        strcpy(head->origin,data);
        head->previous = NULL;
        head->next = NULL;

        last = head;
        //Adding the rest of the cities
        for(i=2; i<=n; i++)
        {
            newNode = (struct routes*)malloc(sizeof(struct routes));
            printf("Enter the next stop: ");
            fflush(stdin);
            fgets(data,15,stdin);
            
            strcpy(newNode->origin,data);
            newNode->previous = last;
            newNode->next = NULL;

            last->next = newNode;           //Link previous city to new one
            last = newNode;                 //New node is the last node
        }
        printf("\n\nRoute created successfully");
    }
}

//Display the route
void display_route()
{
    struct routes *temp;

    if(head == NULL)
    {
        printf("No route found");
    }
    else
    {
        temp = head;
        printf("\n\nThe route active is:\n\n");
        while(temp != NULL)
        {
            printf("%s\n", temp->origin);
            temp = temp->next;
        }
    }
}

//For Modification 
void modify_route()
{
    int n,c = 1;
    char city[15];
    while (c !=0 )
    {
        printf("---------------------------------------\n");
        printf("-----Routes Modification Menu----------\n");
        printf("---------------------------------------\n");
        printf("1. Insertion of a city\n");
        printf("2. Deletion of a city\n");
        printf("3. Go back\n");
        printf("---------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("\nEnter the city which you would like to add: ");
                fflush(stdin);
                fgets(city,15,stdin);
                printf("\nEnter the position where you would like to enter a new city: ");
                scanf("%d",&n);
                insert_route(n,city);
                break;
            case 2:
                printf("\nEnter the position from which you would like to delete: ");
                scanf("%d",&n);
                delete_route(n);
                break;
            case 3:
                routes_menu();
                break;
            default:
                printf("Invalid choice. Try again");
        }
    }
}

//For insertion of a city
void insert_route(int n,char d[])
{
    int i;
    struct routes *newNode, *temp;
    if(head == NULL)
    {
        printf("The route does not exist");
    }
    else
    {
        temp = head;
        i = 1;
        while(i<n-1 && temp!= NULL)
        {
            temp = temp->next;
            i++;
        }

        //If Origin needs to be modified
        if( n == 1)
        {
            newNode = (struct routes*)malloc(sizeof(struct routes));
            strcpy(newNode->origin,d);
            newNode->next = head;
            newNode->previous = NULL;

            head->previous = newNode;
            head = newNode;

            printf("\nRoute modified Successfully!!!");
        }
        else if(temp == last) //To modify destination
        {
            if(last == NULL)
            {
                printf("Nothing to enter here! As the list is empty.");
            }
            else
            {
                newNode = (struct routes*)malloc(sizeof(struct routes));
                strcpy(newNode->origin,d);
                newNode->next = NULL;
                newNode->previous = last;

                last->next = newNode;
                last = newNode;
                printf("\nRoute modified successfully!!!");
            }
        }
        else if(temp != NULL)
        {
            newNode = (struct routes*)malloc(sizeof(struct routes));
            strcpy(newNode->origin,d);
            newNode->next = temp->next;     //New->next to n+1
            newNode->previous = temp;       //new->prev to n-1
            if(temp->next!=NULL)
            {
                temp->next->previous = newNode;
            }
            temp->next = newNode;
            printf("\nRoute modified successfully!!!");
        }
        else
        {
            printf("Error!! Invalid position\n");
        }
    }
}

//To Delete of a city
void delete_route(int n)
{
    struct routes *current;
    int i;

    current = head;
    for(i=1; i<n && current!=NULL; i++)
    {
        current = current->next;
    }
    
    //If the origin needs to be deleted
    if(n == 1)
    {
        if(head == NULL)
        {
            printf("\nNothing to delete here!!!!");
        }
        else
        {
            head = head->next; //Since the origin needs to be needed
            if(head != NULL)
                head ->previous = NULL;
            
            free(current); //Delete the data from memory
            printf("Successfully modified the route");
        }
    }
    else if(current == last)    //Delete the last city
    {
        if(last == NULL)
        {
            printf("\nNothing to delete here!!!!");
        }
        else
        {
            last = last->previous;  //To make the second last city now the destination
            if(last != NULL)
                last->next = NULL;

            free(current);      //To free memory
            printf("Successfully modified the route");            
        }
    }
    else if(current != NULL)
    {
        current->previous->next = current->next;
        current->next->previous = current->previous;

        free(current);
        printf("Modified the route successfully");
    }
    else
    {
        printf("\nInvalid position\n");
    }
}