#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include "Printer.h"
#include "User.h"
using namespace std;

class Student : public User{
	public:
		Student(string u, string p): User(u,p){

		}

		Student():User("",""){

		}
	// int checkPosition(Printer p){
	//  return p.findTheOrderForMe(int id);
	// }
	/*DESCRIPTION: Tells the user their position in the printer
	* queue.
	*
	* PRECONDITION: User should be a valid user and it does not
	* matter if they have an order or not.
	*
	* POSTCONDITION: Returns the position and details of
	* the user's printing processes. If there is no order,
	* it returns -1 and says that there is no position.
	*
	* */



};



#endif /* STUDENT_H_ */
