#ifndef USER_H_
 #define USER_H_

#include <iostream>
#include "Printer.h"
using namespace std;

class User{
	private:
		friend class Hash; // To allow Hash to get username and password from User
		unsigned int allocation;
		/*Allocation is the maximum amount of pages while currentPagesLeft
		 * is the amount of pages a student has remaining.
		 * If the number of current pages is below 0, the student cannot
		 * print anymore. If the pages are reset, then the currentPagesLeft
		 * becomes equal to the allocation.*/

		 string userName;
		 string password;

		 /*userName holds the user's specific name, password holds the password*/
	public:
		User(string u, string pswd):allocation(1000), userName(u), password(pswd) {}
		User(){
			allocation = 1000;
			userName = "";
			password = "";
		}
		User(User& u){
			userName = u.getUserName();
			password = u.getPassword();
			allocation = u.getPagesLeft();


		}
		void print(int pages, int id, Printer &p) {
      if(p.getPagesRemaining()-pages >= 0){
			     if(allocation-pages >= 0) {
				         Order newOrder(pages,userName);
				         p.acceptOrder(newOrder);
                 allocation-=pages;

			}
			     else {
				         cout << "Error! You do not have enough pages left to print this document. Please speak to an administrator.";
			}
		}
    else{
      cout << "There is not enough paper to complete your order" << endl;
    }
  }

  void print(Order &o, Printer &p) {
    if(p.getPagesRemaining()-o.getPages() >= 0){
         if(allocation-o.getPages() >= 0) {
               p.acceptOrder(o);
               allocation-= o.getPages();

    }
         else {
               cout << "Error! You do not have enough pages left to print this document. Please speak to an administrator.";
    }
  }
  else{
    cout << "There is not enough paper to complete your order" << endl;
  }
}

		bool isPasswordCorrect(string guess){
			return guess == password;
		}

		 string getUserName(){
			 return userName;
		 }

		 string getPassword(){
			 return password;
		 }

     int getPagesLeft(){
       return allocation;
     }

};
#endif
