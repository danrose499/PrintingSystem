//============================================================================
// Name        : final-project.cpp
// Author      : Sk Ayon, Daniel Lichter, Daniel Rosenthal
// Version     :
// Copyright   :
// Description : Final NAC Printing Project
//============================================================================

#include <iostream>
#include "Printer.h"
#include "Student.h"
#include "Admin.h"
#include "User.h"
#include "Hash.h"
#include "Queue.h"
#include "Order.h"
using namespace std;


int main() {
	bool isRunning = true;
	string yourUsername;
	string yourPassword;
	string adminOrStudentResponse;
	int counterID = 1;
	string UIresponse;
	string inputUserName;
	string inputPassword;
	string studentChoice;
	string newUserName;
	string newUserPassword;
	string newStudentOrAdmin;
	string inputIDForOrder;
	int convertedID;
	string sNumOfPagesInOrder;
	int numOfPagesInOrder;
	bool correctUsername = false;
	bool correctPassword = false;
	bool loggedIn = false;
	bool validStudentChoice = false;
	Admin* tempAdmin;
	Student* tempStudent;
	Admin newAdmin;
	Student newStudent;
	StudentHash studentTable;
	AdminHash adminTable;
	Admin DanielR("Daniel Rosenthal","qwertyuiop");
	adminTable.insert(DanielR);
	Student SkA("Sk Ayon","a");
	studentTable.insert(SkA);
	Printer blackAndWhite;
	Order everythingHere[20000];
	Order tempOrder;
	int indexForEverythingHere = 0;

	while(isRunning){
		cout << "--------------------------------------" << endl;
		cout << "Welcome to the NAC printing service." << endl;
		cout << "--------------------------------------" << endl;
		cout << "Please type 1 to login in as an admin or 2 to login as student or 3 to shut down the program: ";
		while(!validStudentChoice){
			getline(cin,studentChoice);
			if(studentChoice != "1" && studentChoice != "2" && studentChoice != "3"){
				cout << "--------------------------------------" << endl;
				cout << "INCORRECT OPTION. PLEASE TRY AGAIN!" << endl;
				cout << "--------------------------------------" << endl;
			}
			else if (studentChoice == "1" || studentChoice == "2"){
				validStudentChoice = true;
			}
			else{
				cout << "--------------------------------------" << endl;
				cout << "--------------------------------------" << endl;
				cout << "We shutting down bois " << endl;
				cout << "--------------------------------------" << endl;
				cout << "--------------------------------------" << endl;
				isRunning = false;
				validStudentChoice = true;
			}
		}
		if((studentChoice == "1") || (studentChoice == "2")){ //Login for Student and Admin
			while(!correctUsername){
				cout << "Please give me the username: ";
				getline(cin,inputUserName);
				if((!adminTable.existsInHashTable(inputUserName))  && (!studentTable.existsInHashTable(inputUserName))){
					cout << "--------------------------------------" << endl;
					cout << "Invalid username." << endl;
					cout << "--------------------------------------" << endl;
				}
				else{
					correctUsername = true;
				}
			}
			if(studentChoice == "1" ) {
				tempAdmin = adminTable.getAdmin(inputUserName);
			}
			else if(studentChoice=="2") {
				tempStudent = studentTable.getStudent(inputUserName);
			}
			while(!correctPassword){
				cout << "Please give me your password: ";
				getline(cin,inputPassword);
				if(studentChoice=="1"){
					if(inputPassword == tempAdmin->getPassword()){
						correctPassword = true;
						loggedIn = true;
					}
					else{
						cout << "--------------------------------------" << endl;
						cout << "Incorrect try again" << endl;
						cout << "--------------------------------------" << endl;
					}
				}
				else if(studentChoice== "2"){
					if(inputPassword == tempStudent->getPassword()){
						correctPassword = true;
						loggedIn = true;
					}
					else{
						cout << "--------------------------------------" << endl;
						cout << "Incorrect try again" << endl;
						cout << "--------------------------------------" << endl;
					}
				}
			}
			while(loggedIn){
				if(studentChoice == "1"){ //Admin Interface
					cout << "--------------------------------------" << endl;
					cout << "Welcome Admin " << tempAdmin->getUserName() << endl;
					cout << "--------------------------------------" << endl;
					cout << "Type 1 to refill the printer with paper, 2 to cancel a print order, 3 to make a new user, 4 to show all the print orders, 5 to print it, or any other key to log out: ";
					getline(cin, UIresponse);
					if(UIresponse == "1"){
						blackAndWhite.refillPages();
						cout << "Black and white printer successfully reloaded with paper." << endl;
					}
					else if(UIresponse == "2"){
						cout << "Give me the ID of the order to delete: ";
						getline(cin,inputIDForOrder);
						convertedID = stoi(inputIDForOrder);
						tempAdmin->cancelOrder(blackAndWhite,convertedID);


					}
					else if(UIresponse == "3"){
						cout << "Time to create a new user." << endl;
						cout << "Type in the new username: ";
						getline(cin,newUserName);
						cout << "Type in the new password: ";
						getline(cin,newUserPassword);
						cout << "Type 1 for Admin or 2 for Student: ";
						getline(cin,newStudentOrAdmin);
						if(newStudentOrAdmin == "1"){
							newAdmin = Admin(newUserName,newUserPassword);
							adminTable.insert(newAdmin);
							cout << "--------------------------------------" << endl;
							cout << "New Admin successful" << endl;
							cout << "--------------------------------------" << endl;
						}
						else if(newStudentOrAdmin == "2"){
							newStudent = Student(newUserName,newUserPassword);
							studentTable.insert(newStudent);
							cout << "--------------------------------------" << endl;
							cout << "New Student successful" << endl;
							cout << "--------------------------------------" << endl;
						}
						else{
							cout << "--------------------------------------" << endl;
							cout << "Failed to create new user. Next time specify the right type." << endl;
							cout << "--------------------------------------" << endl;
						}
					}
					else if(UIresponse == "4"){
            cout << "--------------------------------------" << endl;
            cout << "The queue is: " << endl;
            cout << "--------------------------------------" << endl;
						blackAndWhite.showQueuedStuff();
					}
          else if(UIresponse == "5"){
            cout << "--------------------------------------" << endl;
            blackAndWhite.print();
            cout << "--------------------------------------" << endl;
          }
					else{
						loggedIn = false;
						validStudentChoice = false;
						correctPassword = false;
						correctUsername = false;
						cout << "--------------------------------------" << endl;
						cout << "You've been logged out. Thanks for visiting." << endl;
						cout << "--------------------------------------" << endl;
					}
				}
				else if (studentChoice == "2"){
					cout << "Welcome Student " << tempStudent->getUserName() << endl;
					cout << "--------------------------------------" << endl;
					cout << "You have " << tempStudent->getPagesLeft() << " pages remaining." << endl;
					cout << "--------------------------------------" << endl;
					cout << "Type 1 to print an order, 2 to check an order through id, or any other key to log out: ";
					getline(cin,UIresponse);
					if(UIresponse == "1"){
						cout << "IT IS TIME TO PRINT BABYYYYYYY " << endl;
						cout << "How many pages do you want to print?" << endl;
						getline(cin,sNumOfPagesInOrder);
						numOfPagesInOrder = stoi(sNumOfPagesInOrder);
						Order newO(numOfPagesInOrder,tempStudent->getUserName(),counterID);
						tempOrder = newO;
						cout << "--------------------------------------" << endl;
						cout << "Your order ID is " << counterID << endl;
						cout << "--------------------------------------" << endl;
						everythingHere[indexForEverythingHere] = tempOrder;
						tempStudent->print(everythingHere[indexForEverythingHere],blackAndWhite);
						indexForEverythingHere++;
						counterID++;
					}
					else if(UIresponse == "2"){
						cout << "What do you want to check: ";
						getline(cin,inputIDForOrder);
						convertedID = stoi(inputIDForOrder);
						if(blackAndWhite.orderExists(convertedID)){
							tempOrder = *blackAndWhite.findTheOrderForMe(convertedID);
							cout << "--------------------------------------" << endl;
							cout << "Id: " << tempOrder.getID() << " Username: " << tempOrder.getName() << " Number of pages: " << tempOrder.getPages() << endl;
							cout << "--------------------------------------" << endl;
						}
						else{
							cout << "--------------------------------------" << endl;
							cout << "This order does not exist" << endl;
							cout << "--------------------------------------" << endl;
						}
					}
					else{
						loggedIn = false;
						validStudentChoice = false;
						correctPassword = false;
						correctUsername = false;
						cout << "--------------------------------------" << endl;
						cout << "You've been logged out. Thanks for visiting." << endl;
						cout << "--------------------------------------" << endl;
					}
				}
			}
		}
	}
	return 0;
}
