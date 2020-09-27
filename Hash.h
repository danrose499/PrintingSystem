#ifndef HASH_H_
#define HASH_H_

#include "User.h"
#include "Admin.h"
#include "Student.h"
#include <iostream>
using namespace std;

class AdminHash{
  private:
        unsigned int index;
        Admin* arr[26000];
  public:
        AdminHash() : index(26000) {} //Constructor for 16000 Students Enrolled with extra indexes included

        int hashFunction(string username) { //Hash function takes sum of ASCII for username mod index
                int sum = 0;
                for(int i=0;i<username.length();i++) {
                      sum+=username[i];
                }
                return sum%index;
        }

    void insert (Admin& newAdmin) {

        int spot = hashFunction(newAdmin.getUserName()); //**//

          while(arr[spot] != NULL)
             spot++;
             arr[spot]=&newAdmin;
      }


  Admin* getAdmin(string username) {
    int spot = hashFunction(username);

    Admin* temp = arr[spot];
    while(temp->getUserName() != username){
      temp = arr[++spot];
    }
    return temp;
  }

  bool existsInHashTable(string username){
    return (arr[hashFunction(username)] != NULL) && (arr[hashFunction(username)]->getUserName() == username);
  }

};


class StudentHash{
  private:
        unsigned int index;
        Student* arr[26000];
  public:
        StudentHash() : index(26000) {} //Constructor for 16000 Students Enrolled with extra indexes included

        int hashFunction(string username) { //Hash function takes sum of ASCII for username mod index
                int sum = 0;
                for(int i=0;i<username.length();i++) {
                      sum+=username[i];
                }
                return sum%index;
        }

    void insert (Student& newStudent) {

        int spot = hashFunction(newStudent.getUserName());

          while(arr[spot] != NULL)
             spot++;
             arr[spot]=&newStudent;
      }


  Student* getStudent(string username) {
    int spot = hashFunction(username);

    Student* temp = arr[spot];
    while(temp->getUserName() != username){
      temp = arr[++spot];
    }
    return temp;
  }

  bool existsInHashTable(string username){
    return ((arr[hashFunction(username)] != NULL) && (arr[hashFunction(username)]->getUserName() == username));
  }

};


#endif /* HASH_H_ */
