//
// Created by mac on 2018/8/28.
// Basic User class
//

/**
 * Class User base*/

#ifndef LORNABK_USER_H
#define LORNABK_USER_H

// file save to "../data/*"
#ifndef USER_DATA_FILE
#define userDataFile "/usr/local/ssm/data/account.ssm"
#endif

// temp file use delete txt.
#ifndef ACCOUNT_TEMP_FILE
#define userDataTempFile "/usr/local/ssm/data/tmp.ssm"
#endif

// define max numbers
#ifndef DATA_MAX_NUM
#define MAX_NUM 10
#endif

// set flag status
bool flag = false;

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
using namespace std;

class User {
 private:
  int id;
  string passwd;
  string name;
  string address;
  int tel;
 public:
  User();
  ~User();
  int getId() const {
    return id;
  }
  void setId(int id) {
    User::id = id;
  }
  const string &getPasswd() const {
    return passwd;
  }
  void setPasswd(const string &passwd) {
    User::passwd = passwd;
  }
  const string &getName() const {
    return name;
  }
  void setName(const string &name) {
    User::name = name;
  }
  const string &getAddress() const {
    return address;
  }
  void setAddress(const string &address) {
    User::address = address;
  }
  int getTel() const {
    return tel;
  }
  void setTel(int tel) {
    User::tel = tel;
  }

  User *next;
  User *head;

  void userCreate();  // create user info
  void userInsert(int uid, const string &upasswd, const string &uname, const string &address, int utel);  // insert user info to file
  void userDelete(int uid);    // delete user info
  User *userFind(int uid);   // find user info by user id
  void userModify(int uid, const string &upasswd, const string &uname, const string &address, int utel));   // modify user info
  void userCopy(User *ptemp, User *p);  // copy user info
  void userSort(char ch);
  void userClassfy();
  bool userRead();        //read data from file
  bool userSave();        //save data to file
  int isRead();
  void quit();
  void disUserInfo();     // display all user info
};

#endif //LORNABK_USER_H
