//
// Created by mac on 2018/8/28.
//

#ifndef LORNABK_UTIL_H
#define LORNABK_UTIL_H

#include "user.h"

void User::Create() {
  int id;
  string passwd;
  string name;
  string tel;

  cout.flags(ios::adjustfield);
  cout << setw(45) << ("|______________|") << endl;
  cout << setw(45) << ("|Create account|") << endl;
  cout << setw(45) << ("|______________|") << endl;

  cout << ("id:");
  cin >> id;
  cout << ("passwd:");
  cin >> passwd;
  cout << ("name:");
  cin >> name;
  cout << ("tel:");
  cin >> tel;

  ofstream ofs(filePath, ios::app);
  if (!ofs) {
    cerr << "File open error" << endl;
  } else {
    ofs.flags(ios::left);
    ofs << setw(20) << id << setw(20) << passwd << setw(20) << name << setw(20) << tel << endl;
  }
  ofs.close();
}

#endif //
