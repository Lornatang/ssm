//
// Created by mac on 2018/8/27.
//

#ifndef LORNABK_USER_H
#define LORNABK_USER_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

class User {
 private:
  int id;
  string name;
  int passwd;
 public:
  friend ostream &operator<<(ostream &os, User &stu);
  friend istream &operator>>(istream &is, User &stu);

  User();
  ~User();
  int getId() const;
  string getName() const;
  int getPasswd() const;

  void setId(int id);
  void setName(string name);
  void setpasswd(int passwd);

  bool loadData(const map<int, User> &u1, const string &pathName);
  bool saveData(const map<int, User> &u1, const string &pathName);
  bool accountEnder(int id, int passwd);
  void accountCreate(int id, const string &name, int passwd);

};

#endif //LORNABK_USER_H
