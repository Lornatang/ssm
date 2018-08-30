//
// Created by mac on 2018/8/28.
// This is the file processing for the user user
//

/**
 * Class: User
 *            1.void show() show account data.
 * */

#ifndef SSM_USER_FILE_H
#define SSM_USER_FILE_H

#include "user.h"
#include "base.h"
using namespace std;

//从文件读入数据
bool User::userRead() {
  ifstream in(userDataFile);
  if (!in) {
    cout << "None user info!" << endl;
    return flag;
  }
  while (!in.eof()) {
    int id;
    string passwd;
    string name;
    string address;
    int tel;
    in >> id >> passwd >> name >> address >> tel;
    userInsert(id, passwd, name, address, tel);
    flag = true;
  }
  return flag;
}

//保存学生信息
void User::userSave() {
  userNode *p;
  p = head->next;
  ofstream out(userDataFile);
  if (!out) {
    cerr << ("Can't open user data file!.\n");
    return ;
  }
  while (p != nullptr) {
    out << setw(20) << p->id;
    out << setw(20) << p->name;
    out << setw(20) << p->passwd;
    out << setw(20) << p->address;
    out << setw(20) << p->tel << "\n";
    p = p->next;
  }
}

//bool User::quit() {
//  flag = userSave();
//  if (!flag) {
//    cerr << ("Data save is error.\n");
//    cerr << ("Return status -1\n");
//    return flag;
//  } else {
//    cout << ("Data saved! Exit system!\n");
//    cout << ("Return status 0.\n");
//    flag = true;
//    return flag;
//  }
//}

#endif //LORNABK_FILE_H
