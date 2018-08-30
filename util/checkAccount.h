//
// Created by mac on 2018/8/30.
//

#ifndef SSM_UTIL_CHECKACCOUNT_H
#define SSM_UTIL_CHECKACCOUNT_H

#include "../user/user.h"
using namespace std;

bool checkAccount(const string &id) {
  bool flag = true;
  ifstream ifs(userDataFile, ios::in);
  if (!ifs)
    cerr << "File open error." << endl;
  else {
    string word = string();
    while (ifs >> word) {
      if (word == id) {
        flag = false;
        return flag;
      }
    }
  }
  return flag;
}

#endif //SSM_UTIL_CHECKACCOUNT_H
