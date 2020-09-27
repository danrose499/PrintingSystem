#ifndef ORDER_H_
#define ORDER_H_

#include <iostream>
#include <string>

using namespace std;

class Order{
  private:
    int pages;
    int id;
    string userPerson;
    Order* nextOrder;

  public:
    Order(int p, string u, int theID){
      pages = p;
      userPerson = u;
      id = theID;
      nextOrder = NULL;
    }

    Order(int p, string u){
      pages = p;
      userPerson = u;
      id = 0;
      nextOrder = NULL;
    }

    Order(){
      pages = 0;
      userPerson = "";
      id = 0;
      nextOrder = NULL;
    }
    const string getName(){
      return userPerson;
    }

    const int getID(){
      return id;
    }

    const int getPages(){
      return pages;
    }
    void setLink(Order* no){
      nextOrder = no;
    }

    Order* getLink(){
      return nextOrder;
    }

    const Order* getLink() const{
      return nextOrder;
    }

};

#endif
