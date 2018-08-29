//
// Created by mac on 2018/8/28.
// This is the file processing for the user user
//

/**
 * Class: User
 *            1.void show() show account data.
 * */

#ifndef LORNABK_FILE_H
#define LORNABK_FILE_H

#include "user.h"
using namespace std;

//从文件读入数据
bool User::userRead() {
  User user;
  ifstream in(userDataFile);
  if (!in) {
    cerr << ("Can't open user data file!.\n");
    cerr << ("Return status -1.\n");
    flag = false;
    return flag;
  }
  while (!in.eof()) {
    in >> user.id >> user.passwd >> user.name >> user.address >> user.tel;
    userInsert(user.id, user.passwd, user.name, user.address, user.tel);
    flag = true;
  }
  return flag;
}

//保存学生信息
bool User::userSave() {
  User *p;
  p = head->next;
  ofstream out(userDataFile);
  if (!out) {
    cerr << ("Can't open user data file!.\n");
    cerr << ("Return status -1.\n");
    flag = false;
    return flag;
  }
  while (p != nullptr) {
    out << setw(20) << p->id;
    out << setw(20) << p->name;
    out << setw(20) << p->passwd;
    out << setw(20) << p->address;
    out << setw(20) << p->tel << "\n";
    p = p->next;
    flag = true;
  }
  return flag;
}

#endif //LORNABK_FILE_H
