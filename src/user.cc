//
// Created by mac on 2018/8/27.
//

#include "../include/user.h"

User::User() {}

User::~User() {}

bool User::loadData(map<int, User> &u, const string &pathName) {
  bool flag = true;
  User user;

  // init map

  u.clear();

  fstream ifs(pathName, ios::in);
  if (ifs) {
    string word;
    stringstream ss;
    while (getline(ifs, word)) {
      ss << word;
      ss >> user;
      ss.clear();

      u.insert(make_pair(user.getId(), user));
    }
    ifs.close();
  } else {
    flag = false;
    ifs.close();
  }
  return flag;
}

/*
 * read from file.
 * */
bool User::saveData(const map<int, User> &u, const string &pathName) {
  bool flag = true;
  User user;

  fstream ofs(pathName, ios::out);
  if (ofs) {
    stringstream word;
    for (auto p: u) {

      user = p.second;
      word << user << endl;
    }
    ofs << word.str();
    ofs.close();
  } else {
  }

  return flag;
}

ostream &operator<<(ostream &os, User &user) {
  os << user.getId() << "     " << user.getName() << "     " << user.getPasswd();
  return os;
}

istream &operator>>(istream &is, User &user) {
  is >> user.id >> user.name >> user.passwd;
  return is;
}


// 增
User User::addAStu(map<int, User> &u, User &stu) {

  // 先假设id可以重复了
  u.insert(make_pair(stu.getId(), stu));
  return stu;
}

// 删
bool User::deleteStuById(map<int, User> &u, const int &id) {

  bool b = false;

  map<int, User>::iterator iter;
  iter = u.find(id);
  if (iter != u.end()) {
    u.erase(iter);
    b = true; // 删除成功
  }

  return b;
}

// 改
User User::updateStu(map<int, User> &u, const User &cStu) {

  // 迭代器是一个smart point！
  // 是可以通过迭代器去访问到 u里的东西，并且做出修改的！
  // 除非迭代器是const迭代器

  User stu = User();
  int id = cStu.getId();

  map<int, User>::iterator iter;
  iter = u.find(id);
  if (iter != u.end()) {
    // 修改
    iter->second = cStu;
    stu = cStu; // 把修改后的对象，赋值，再返回上层
  }

  return stu;
}

// 查 by id
User User::findById(const map<int, User> &u, const int &id) const {

  User stu = User();

  map<int, User>::const_iterator iter;
  iter = u.find(id);
  if (iter != u.end()) {
    stu = iter->second;
  }

  return stu;
}

// showAll
void User::showAll(const map<int, User> &u) const {

  for (auto p : u) {
    cout << p.second << endl;
  }
}

