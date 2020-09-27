#ifndef PRINTER_H_
#define PRINTER_H_

#include <iostream>
#include "Queue.h"
#include "Order.h"
#include <string>
using namespace std;

 //The Queue can only hold 50 documents at a time
// https://www.geeksforgeeks.org/queue-linked-list-implementation/ we should use this
class Printer {
  private:
    int allocation;
    int maxDocs;
//    Queue queueList = Queue(maxDocs);
    Queue queueList;

  public:
      Printer(){
        allocation = 500;
        maxDocs = 50;
        queueList = Queue(maxDocs);
      }


    void acceptOrder(Order &o) {
      if(allocation == 0){
        cout << "THE PRINTER IS EMPTY. PLEASE CONTACT AN ADMIN TO FIX THIS." << endl;
      }
      else if(queueList.getSize()>=50){
        cout << "THERE ARE TOO MANY DOCS ON THE QUEUE. WAIT A FEW MINS" << endl;
      }
      else{
        queueList.push(o);
        allocation -= o.getPages();
        cout << o.getName() << "'s order is successful" << endl;
        cout << "Printer has " << allocation << " pages left." << endl;
      }

    }

    int getPagesRemaining(){
      return allocation;
    }

    int getNumOfCurrentOrders(){
      return queueList.getSize();
    }
    void refillPages(){
      allocation = 500;
    }

    Order* cancelOrderById(int id){
      Order* discarded;
      discarded = queueList.getRidOfOrder(id);
      if(discarded != NULL){
        allocation += discarded->getPages();
        cout << "Cancellation successful" << endl;
        return discarded;
      }
      else{
        return NULL;
      }
    }

    void showQueuedStuff(){
      if(queueList.isEmpty()){
        cout << "Nuthin to see here " << endl;
      }
      else{
        queueList.printTheQueue();
      }
    }

    bool orderExists(int id){
      return queueList.isOrderInQueue(id);
    }


    Order* findTheOrderForMe(int id){
      return queueList.getOrderByID(id);
     }

     void print(){
       if(!queueList.isEmpty()) {
        Order* hi = queueList.pop();
        cout << "Printer order id " << hi->getID() << " has been printed." << endl;
        }
        else{
          cout << "There aren't any orders here bro " << endl;
        }
     }

};
#endif /* PRINTER_H_ */
