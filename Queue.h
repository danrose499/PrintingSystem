#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <string>
#include "Order.h"
using namespace std;
/*Proposal: We should store the orders in this queue object
*/
class Queue {
  private:
    int size;
    int capacity;
    Order* start;
    Order* end;

  public:

    Queue(int c){
      size = 0;
      capacity = c;
      start = NULL;
      end = NULL;
    }
    Queue(){
      size = 0;
      capacity = 0;
      start = NULL;
      end = NULL;
    }

    bool isEmpty(){
      return size <= 0;
    }

    bool isFull(){
      return size >= capacity;
    }

    int getSize(){
      return size;
    }

    void push(Order& printOrder){
      if(isEmpty()){

        start = &printOrder;
        end = &printOrder;
        size++;
      }
      else if(!isFull()){
        end -> setLink(&printOrder);
        end = &printOrder;
        size++;
      }
      else{
        cout << "TOO BUSY. PLEASE WAIT." << endl;
      }
   }

    Order* pop(){
      if(start == NULL){
        return NULL;
      }
      else{
        Order* printedStuff = start;
        start = start->getLink();
        size--;
        return printedStuff;
      }
    }


    int findOrderById(int id){
      Order* cursor;
      int counter = 0;
      for(cursor = start; cursor!=NULL; cursor = cursor->getLink()){
          if(cursor->getID() == id){
            return counter;
          }
          counter++;
      }
      return -1;
   }

   Order* getOrderByPosition(int pos){
     Order* cursor;
     int i = 0;
     for(cursor = start; cursor->getLink() != NULL; cursor = cursor->getLink()){
       if(pos == i){
         return cursor;
       }
     }
     return NULL;
   }

   Order* getOrderByID(int id){
     Order* cursor;
     for(cursor = start; cursor != NULL; cursor = cursor->getLink()){
       if(cursor->getID() == id){
         return cursor;
       }
     }
     return NULL;
   }

    bool isOrderInQueue(int id){
      Order* cursor;
      for(cursor = start; cursor!= NULL; cursor = cursor->getLink()){
        if(cursor->getID() == id){
          return true;
        }
      }
      return false;
    }

    Order* getRidOfOrder(int id){
      int position = findOrderById(id);
      if(position == 0){
        Order* toBeRemoved;
        toBeRemoved = pop();
        return toBeRemoved;
      }
      else{
        Order* orderBeforeTheOneRemoved = start;
        for(int j = 0; j < position-1;j++){
          orderBeforeTheOneRemoved = orderBeforeTheOneRemoved->getLink();
        }
        Order* toBeRemoved = orderBeforeTheOneRemoved->getLink();
        orderBeforeTheOneRemoved->setLink(toBeRemoved->getLink());
        if(position == size-1){
          end = orderBeforeTheOneRemoved;
        }
        size--;
        return toBeRemoved;
      }
      return NULL;


    }

    void printTheQueue(){
      Order* cursor;
      for(cursor = start; cursor!= NULL; cursor= cursor->getLink()){
        cout << "Id: " << cursor->getID() << " Username: " << cursor->getName() << " Number of pages: " << cursor->getPages() << endl;
      }
    }
  };

#endif /*QUEUE_H_*/
