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
void User::userRead() {
  userNode *p;
  p = head;
  ifstream in(userDataFile);
  if (!in) {
    cout << "None user info!" << endl;
    return;
  }
  while (!in.eof()) {
    int id;
    string passwd;
    string name;
    string address;
    string tel;
    in >> id >> passwd >> name >> address >> tel;
    userInsert(id, passwd, name, address, tel);
  }
}

//保存学生信息
void User::userSave() {
  userNode *p;
  p = head->next;
  ofstream out(userDataFile);
  if (!out) {
    cerr << ("Can't open user data file!.\n");
    return;
  }
  while (p != nullptr) {
    out << p->id << ("\t");
    out << p->name << ("\t");
    out << p->passwd << ("\t");
    out << p->address << ("\t");
    out << p->tel << "\n";
    p = p->next;
  }
}

#endif //LORNABK_FILE_H
