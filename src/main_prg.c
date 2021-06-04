//Railway Reservation Project 
/*  Team 6 
        Aditi , Nandini, Vasundhra, Yukta, Nikhil
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h>
#include <string.h> //string operations

void view_Details();
void add_train();

char choice;


//Structure for user
struct user_details
{
    char first_name[20];
    char last_name[30];
    char gender;                // M or F
    int age;
    char contact_number[12];
    char location[50];
<<<<<<< Updated upstream
    char user_name[10];         //Not more than 10 characters
    char password[12];          //Not more than 12 characters
};

=======
    char user_name[10];         
    char password[12];          
} ud;

struct booking
{
    int PNR;
    char trainNo[10];
    char From[30];
    char Destination[30];
    int date;
    int month;
    int year;
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
>>>>>>> Stashed changes

//Structure for Trains
struct train_details
{
    char train_name[50];
    char train_number[5];
    char origin[15];
    char train_class[10];
    char destination[15];
}obj;

<<<<<<< Updated upstream
/*Structure for Routes --- Using this in case we need any files to store routes
can be done easily while reading files*/
struct routes
=======
/*struct routes
{
    char origin_station[15];
    char train_stops[5][15];
    char dest_station[15];
    char train_no[5];       //Train number should be the same in train_details
};*/

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
void user_reg();
void login();
void routes_menu();
void create_route(int n);
void display_route();
void modify_route();
void insert_route(int n,char d[15]);
void delete_route(int n);
void user_validt(char uname[],char pwd[]);
void search_route(char city1[],char city2[]);
void disp_users();
void disp_resv_chart();


//Search Route if the city exists in the given route or not
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
        if (f==2)
            printf("\nMatched --- Route found");
        else
            printf("\nNot found");
    }
}

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
>>>>>>> Stashed changes
{
    char origin_station[50];
    char *train_stops[50];
    char dest_station[50];
};

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

    printf("===================================Train Details===============================\n");
    printf("\n");
    printf("Train Number   Train Name      Train Origin    Train Destination   Train Class\n");
    while (fscanf(fptr, "%s\t%s\t%s\t%s\t\t%s\n", obj.train_number, obj.train_name, obj.origin, obj.destination, obj.train_class) != EOF)
    {
        printf("%s\t%s\t%s\t%s\t\t%s\n", obj.train_number, obj.train_name, obj.origin, obj.destination, obj.train_class);
    }

    fclose(fptr);
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
<<<<<<< Updated upstream
        printf("\n2. Modify a train");
        printf("\n3. Delete a train");
        printf("\n4. Log Out");
=======
        printf("\n2. Display train details");
		printf("\n3. Display list of all Users");
		printf("\n4. Display Rservation Chart");
        printf("\n5. Log Out");
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
            case 3:
                delete_train();
=======
			case 3:
				disp_users();
				break;
            case 4:
				disp_resv_chart();
				break;
			case 5:	
                printf("Succesfully logged out");
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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
=======
    case 1:
        user_reg();
        break;
    case 2:
        login();
        // login_main(0);
        break;
    case 3:
        main();
    default:
        printf("\nWrong Choice!! ");
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
        switch(choice)
=======
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            login_main(1);
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
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    return 0;
=======
}


//Display list of all users
void disp_users()
{
	FILE *fptr;
	fptr = fopen("login.txt", "r");
	if (fptr == NULL)
	{
       	printf("ERROR! File could not open");
       	exit(1);
   	}

   	printf("===================================User Details===============================\n");
   	printf("\n");
   	printf("First Name   Last Name      Gender    Age   Contact Number	Location	Username\n");
   	while (fread(&ud,sizeof(struct user_details),1,fptr))
   	{
   	    printf("%s\t%s\t%c\t%d\t%s\t%s\t%s\n", ud.first_name, ud.last_name, ud.age, ud.contact_number, ud.location, ud.user_name);
   	}
   	getch();
   	fclose(fptr);
}

void disp_resv_chart(){
	char train[10]; 
	int date, month, year;
	int i = 0;
    printf("\n Enter the Train No. ");
    gets(train);
	printf("\n Enter the Date of Journey");
	printf("\n Date-");
	scanf("%d",&date);
	printf("\n Month-");
	scanf("%d",&month);
	printf("\n Year-");
	scanf("%d",&year);

	system("@cls||clear");
	printf("===================================Reservation Chart===============================\n");
	printf("\n");
	printf("PNR No.     Departure      Arrival    Booking Name     Contact No.     No. of Passengers     Amount\n");
    for (i = 0; i <= input; i++)
    {
		printf("Inside Reservation chart");
        if (!(strcmpi(book[i].trainNo,train))&&(book[i].date == date)&&(book[i].month == month)&&(book[i].year == year))
        {
			printf("Inside Reservation chart2");
            printf("\n%d\t%s\t%s\t%s\t%s\t%d\t%lf", book[i].PNR, book[i].From, book[i].Destination, book[i].pt[1].pname, book[i].contact, book[i].NoOfPassengers, book[i].amount);
        }
    }
>>>>>>> Stashed changes
}