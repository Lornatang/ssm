//
// Created by mac on 2018/8/28.
//

#ifndef LORNABK_USER_H
#define LORNABK_USER_H

// file save to "../data/*"
#ifndef ACCOUNT_DATA_FILE
#define filePath "../data/account.dat"
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

class User {
 private:
  int id;
  string passwd;
  string name;
  string tel;
 public:
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
  const string &getTel() const {
    return tel;
  }
  void setTel(const string &tel) {
    User::tel = tel;
  }

  void create();
};

#endif //LORNABK_USER_H
