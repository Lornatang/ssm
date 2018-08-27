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
  friend ostream &operator<<(ostream &os, User &user);
  friend istream &operator>>(istream &is, User &user);

  User();
  ~User();
  void setPasswd(int passwd) {
    User::passwd = passwd;
  }
  int getId() const {
    return id;
  }
  void setId(int id) {
    User::id = id;
  }
  const string &getName() const {
    return name;
  }
  void setName(const string &name) {
    User::name = name;
  }
  int getPasswd() const {
    return passwd;
  }

  bool loadData(map<int, User> &u, const string &pathName);
  bool saveData(const map<int, User> &u, const string &pathName);
  bool accountEnder(int id, int passwd);
  void accountCreate(int id, const string &name, int passwd);
  // 增
  User addAStu(std::map<int, User> &u, User &stu);

  // 删
  bool deleteStuById(std::map<int, User> &u, const int &id);

  // 改
  User updateStu(std::map<int, User> &u, const User &stu);

  // 查 by id
  User findById(const std::map<int, User> &u, const int &id) const;

  // showAll
  void showAll(const std::map<int, User> &u) const;
  
};

#endif //LORNABK_USER_H
