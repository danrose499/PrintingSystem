#ifndef ADMIN_H_
#define ADMIN_H_

#include "User.h"
#include "Printer.h"
#include "Order.h"
//#include "Hash.h"
#include "Student.h"
#include <iostream>
using namespace std;
class Admin : public User{

	public:
		Admin(string u, string p): User(u, p){

		}

		Admin():User("",""){

		}
	// void createNewAdmin(string name, string password, AdminHash h){
	// 	Admin Admin1(name, password);
	// 	h.insert(Admin1);

	// }
	// void createNewStudent(string name, string password, StudentHash h){
	// 	Student Student1(name, password);
	// 	h.insert(Student1);
	// }


	void addPaper(Printer& p){
	/* DESCRIPTION:This adds paper to the printer
	 *
	 * PRECONDITION:A printer must exist and must be supplied as a parameter.
	 *
	 * POSTCONDITION:The printer gets the paper added.
	 */
	 p.refillPages();
	 cout << "Refill successful" << endl;
 }

	int checkPaper(Printer& p){
	/*   DESCRIPTION :We can check how much paper is left in the printer
	 *   PRECONDITION:A printer must exist
	 *   POSTCONDITION: We have the number of sheets remaining.
	 */
	 return p.getPagesRemaining();
 }
	void cancelOrder(Printer& p, int id){
		if(p.orderExists(id)){
			p.cancelOrderById(id);
		}
		else{
			cout << "Order does not exist" << endl;
		}
	}
};


#endif /* ADMIN_H_ */
