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

**The program uses following structures:**

1. user_details: This structure contains first name, last name, gender, age, contact number, location, user name and password of the users.

2. booking: This structure contains PNR, Train Number, Source, Destination ,Time & Date of the train booked , passenger details structure , NoOfPassengers ( which will contain no of passengers under that booking PNR No. ) ,contact and fare of the booking .

3. passDetails: This structure contains id, name, gender and age of passenger

4. routes: This structure contains origin, destination and two pointers next and previous routes.

5. train_details: This structure contains train name, train number, origin, destination, train class, fare of the train and numbers of seats available for booking in that train.


**The program has following functions:**

1. view_Details: This function views all the details of train

2. add_train: This function helps admin to add the train

3. payment: This function calculates the total amount to be paid by the user 

4. makePayment: This function allows the user to either pay or deny the payment

5. bookingTrain: This function helps the user to do the reservation.

6. show_booking: This function shows all the reservation by PNR NO. or all bookings. 

7. cancelBooking: This function allows the user to cancel the reservation on the basis of PNR No.

8. modifyBooking: This function will allow the user to modify the reservation and will give the option to add passenger, remove passenger or edit existing passenger details.

9. admin_passwd_valid: This function validates the admin login

10. user_menu: This function shows the user all the functionalities that he can perform

11. admin_menu: This function shows the admin all the functionalities that he can perform.

12. login_main: This function lets the user or admin enter their login creadentials and login.

13. user_main: This function lets the user register as new user, or sign in if they are existing user.

14. user_reg: This function lets the user register as a new user.

15. routes_menu: This function lets the admin choose to create, display and modify train routes.

16. display_route: This function lets the admin create a train route.

17. modify_route: This function lets the admin modify an existing train route.

18. user_validt: This function validates the user login.

19. search_route: This function lets the user search the train route.

20. seatAllocation: This function allocates the seat to the user.
