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
5. View List of All Users
6. Logout


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

4. routes: This structure contains origin, destination and two pointers next and previous routes.

5. train_details: This structure contains train name, train number, origin, destination, train class, fare of the train and numbers of seats available for booking in that train.


**The program has following functions:**

1. view_Details: This function views all the details of train

2. add_train: This function helps admin to add the train

3. payment: This function calculates the total amount to be paid by the user 

4. makePayment: This function allows the user to either pay or deny the payment

5. bookingTrain: This function helps the user to book a train.

6. show_booking: This function shows all the booking done by the user 

7. cancelBooking: This function allows the user to cancel the booking made by him

8. modifyBooking: This function allows the user to modify the booking made by him

9. admin_passwd_valid: This function validates the admin login

10. user_menu: This function shows the user all the functionalities that he can perform

11. admin_menu: This function shows the admin all the functionalities that he can perform.

12. login_main: This function lets the admin enter their login creadentials and login.

13. user_main: This function lets the user register as new user, or sign in if they are existing user.

14. user_reg: This function lets the user register as a new user.

15. login: This function lets the user to enter their login credentials and login.

16. routes_menu: This function lets the admin choose to create, display and modify train routes.

17. create_route: This function lets the admin to create the new route for the train. 

18. display_route: This function lets the admin create a train route.

19. modify_route: This function lets the admin insert or delete a route for the train

20. delete_route: This function lets the admin delete the route.

21. insert_route: This function lets the admin insert a route for the train.

22. user_validt: This function validates the user login.

23. search_route: This function lets the user search the train route.

24. seatAllocation: This function allocates the seat to the user.

25. disp_users: This function displays a list of all users.


**Steps to run the program:**
  
  Using **makefile**
1. navigate to the **src** folder
2. Run command "make"


  Using **gcc compiler.**
1. Navigate to **src** folder.
2. To compile the program: gcc -o main_prg main_prg.c
3. To run the program :     main_prg.exe


**Some future scope:**

Functionality for Admin: 

Display Reservation Chart

Functions:

disp_resv_chart: This function would take train number and date of journey as input to display a reservation chart of that train.
