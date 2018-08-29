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
void User::userRead() {
  User *p;
  p = head;
  ifstream in("StudentList.txt");
  if (!in) {
    cout << ("没有学生信息，请先录入学生信息!\n");
    return;
  }
  while (!in.eof()) {
    int num, math, eng, yuwen, sum;
    in >> num >> math >> eng >> yuwen >> sum;
    StuInsert(num, math, eng, yuwen);
  }
}

//保存学生信息
bool User::userSave() {
  User *p;
  p = head->next;
  ofstream out(userDataFile);
  if (!out) {
    cout << ("Can't open user data file!.\n");
    cerr << ("Return status -1.");
    flag = false;
    return flag;
  }
  while (p != nullptr) {
    out << setw(20) << p->id << setw(20) << p->name << setw(20) << p->passwd << setw(20) << p->address << setw(20)
        << p->tel << "\n";
    p = p->next;
    flag = true;
  }
  return flag;
}

#endif //LORNABK_FILE_H
