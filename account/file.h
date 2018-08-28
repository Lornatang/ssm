//
// Created by mac on 2018/8/28.
//

#ifndef LORNABK_FILE_H
#define LORNABK_FILE_H

#include "user.h"

bool loadAccountData() {
  // buffer size
  char buffer[128];
  // file status
  bool flag = true;

  // open file filePath see "user.h"
  ifstream file(filePath);
  if (!file.is_open())
    flag = false;
  else {
    cout.flags(ios::left);
    cout << setw(20) << ("id") << setw(20) << ("passwd") << setw(20) << ("name") << setw(20) << ("tel") << endl;
    cout << ("---------------------------------------------------------------------------") << endl;
    while (!file.eof()) {
      file.getline(buffer, 100);
      cout << buffer;
    }
  }
  cout << endl;
  cout << ("---------------------------------------------------------------------------");
  return flag;
}


#endif //LORNABK_FILE_H
