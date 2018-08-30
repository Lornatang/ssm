//
// Created by mac on 2018/8/28.
// Basic User class
//

/**
 * Class User base*/

#ifndef SSM_USER_USER_H
#define SSM_USER_USER_H

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


struct userNode {
  int id;
  string passwd;
  string name;
  string address;
  int tel;
  userNode *next;
};
class User {
  userNode *head;

 public:
  User();
  ~User();
  void userInit();  // create user info
  void userInsert(int uid,
                  const string &upasswd,
                  const string &uname,
                  const string &uaddress,
                  int utel);  // insert user info to file
  void userDelete(int uid);    // delete user info
  userNode *userFind(int uid);   // find user info by user id
  void userModify(int uid,
                  const string &upasswd,
                  const string &uname,
                  const string &uaddress,
                  int utel);   // modify user info
  void userCopy(userNode *ptemp, userNode *p);  // copy user info
  void userSort(char ch);
  void userClassfy();
  bool userRead();        //read data from file
  bool userSave();        //save data to file
  bool quit();
  void disUserInfo();     // display all user info
};

#endif //SSM_USER_USER_H
