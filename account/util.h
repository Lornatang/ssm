//
// Created by mac on 2018/8/28.
//

/**
 * Class: User
 *            1.bool Create()
 *            2.bool Verify()
 * */

#ifndef LORNABK_UTIL_H
#define LORNABK_UTIL_H

#include "user.h"
using namespace std;

bool checkAccount(const string &id) {
  bool flag = true;
  ifstream ifs(filePath, ios::in);
  if (!ifs)
    cerr << "File open error." << endl;
  else {
    string word;
    while (ifs >> word) {
      if (word == id) {
        flag = false;
        return flag;
      }
    }
  }
  return flag;
}

bool User::Create() {
  User user;
  // set flag status
  bool flag = true;

  system("clear");

  cout.flags(ios::adjustfield);
  cout << setw(45) << ("|______________|") << endl;
  cout << setw(45) << ("|Create account|") << endl;
  cout << setw(45) << ("|______________|") << endl;

  cout << ("Id:");
  cin >> user.id;
  // if id exist. exit app;
  if (!checkAccount(user.id)) {
    flag = false;
  }
  else {
    cout << ("Password:");
    cin >> user.passwd;
    cout << ("Name:");
    cin >> user.name;
    cout << ("Telephone:");
    cin >> user.tel;
  }

  // if id don't exist run!
  if (flag) {
    ofstream ofs(filePath, ios::app);
    if (!ofs) {
      flag = false;
      cerr << "File open error." << endl;
    }
    else {
      ofs.flags(ios::left);
      ofs << setw(20) << user.id << setw(20) << user.passwd << setw(20) << user.name << setw(20) << user.tel << endl;
    }
    ofs.close();
  }
  return flag;
}

bool User::Verify() {
  // set return
  User user;
  bool flag = true;

  system("clear");

  cout << "Please input your account information." << endl;
  cout << ("Id:");
  cin >> user.id;

  if (checkAccount(user.id))
    flag = false;

  return flag;
}

#endif //
