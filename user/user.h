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
#define userDataFile "/usr/local/ssm/data/user.ssm"
#endif

// temp file use delete txt.
#ifndef ACCOUNT_TEMP_FILE
#define userDataTempFile "/usr/local/ssm/data/userTmp.ssm"
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
  string tel;
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
                  const string &utel);  // insert user info to file
  void userDelete(int uid);    // delete user info
  userNode *userFind(int uid);   // find user info by user id
  void userModify(int uid,
                  const string &upasswd,
                  const string &uname,
                  const string &uaddress,
                  const string &utel);   // modify user info
  void userCopy(userNode *ptemp, userNode *p);  // copy user info
  void userSort(char ch);
  void userClassify();
  bool userRead();        //read data from file
  void userSave();        //save data to file
  void disUserInfo();     // display all user info
};

#endif //SSM_USER_USER_H
