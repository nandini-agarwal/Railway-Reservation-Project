# Railway-Reservation-Project
Railway Reservation Project for DSA Assignment

**This project allows us to perform the following functionalities:**

1. Add, Delete and Modify Users
2. Add, Delete and Modify Trains
3. View List of Trains
4. View List of Users
5. Reserve Train
6. Update and Cancel Reservation
7. Discount on Reservation for senior citizens
8. List of trains between two stations

**This project has two sections:**

1. Admin
2. User

**Admin can access following functionalities:**
1. Login
2. Add Train
3. Modify Train
4. View List of Trains
5. Logout

**User can access following functionalities:**
1. Add booking
2. Cancel booking
3. Show booking 
4. Modify booking 
5. Add passenger 
6. Remove passenger
7. Edit passenger
8. Edit booking

**The program uses following structures:**

1. user_details: This structure contains first name, last name, gender, age, contact number, location, user name and password of the users.

2. booking: This structure contains PNR, Train Number, Source, Destination of the train booked.

3. passDetails: This structure contains id, name, gender and age of passenger

4. NoOfPassengers: This structure contains contact number and total number of passengers.

5. routes: This structure contains origin, destination and two pointers next and previous routes.

6. train_details: This structure contains train name, train number, origin, destination, train class, fare of the train and numbers of seats available for booking in that train.


**The program has following functions:**

void view_Details();
void add_train();
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
