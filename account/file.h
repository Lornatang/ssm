//
// Created by mac on 2018/8/28.
//

/**
 * Class: User
 *            1.void show() show account data.
 * */

#ifndef LORNABK_FILE_H
#define LORNABK_FILE_H

#include "user.h"
using namespace std;


void User::show() {
  // buffer size
  char buffer[128];

  // open file filePath see "user.h"
  ifstream file(filePath);
  if (!file.is_open()) {
    cerr << "File open error!." << endl;
  }
  else {
    cout.flags(ios::left);
    cout << ("---------------------------------------------------------------------------\n");
    cout << setw(20) << ("id") << setw(20) << ("passwd") << setw(20) << ("name") << setw(20) << ("tel") << endl;
    cout << ("---------------------------------------------------------------------------\n");
    while (!file.eof()) {
      file.getline(buffer, 100);
      cout << buffer;
    }
  }
  cout << endl;
  cout << ("---------------------------------------------------------------------------\n");
}

#endif //LORNABK_FILE_H
