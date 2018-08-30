//
// Created by mac on 2018/8/28.
// Some of the User's feature extensions.
//

/**
 * Class: User
 *            1.bool Create()
 *            2.bool Verify()
 * */

#ifndef LORNABK_UTIL_USER_H
#define LORNABK_UTIL_USER_H

#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;


bool systemEnder() {
  bool flag = false;

  system("clear");

  cout.flags(ios::adjustfield);
  cout << setw(45) << ("|______________|") << endl;
  cout << setw(45) << ("|Create account|") << endl;
  cout << setw(45) << ("|______________|") << endl;
  // system name and passwd
  string adminName = "xcrj";
  int adminPasswd = 8888;

  string name;
  int passwd = 0;

  int errCount = 3;

  while (true) {
    cout << "Name:";
    cin >> name;
    cout << "Passwd:";
    cin >> passwd;
    // name and passwd correct to run
    if (name != adminName || passwd != adminPasswd) {
      errCount -= 1;
      if (errCount > 0) {
        cerr << "User/Passwd valida error. And you can verify it " << errCount << " times\n";
        cerr << "Waiting 3s...\n";
        sleep(3);
      }
      else {
        cerr << "If the number of validation is exceeded, the system returns state -1.\n";
        cerr << "If you need to re-login, please re-run this App!\n";
        flag = false;
        return flag;
      }

    } else {
      cout << "Account verification is correct!\n";
      flag = true;
      return flag;
    }
  }
}

void userMenu()
{
  cout.flags(ios::adjustfield);
  cout << setw(60) << ("|----------------+++++++++++++++++++++--------------------|\n");
  cout << setw(60) << ("|                |Super Smart Manager|                    |\n");
  cout << setw(60) << ("|----------------+++++++++++++++++++++--------------------|\n");
  cout << setw(60) << ("|1.Initialize the number of users     6.Sort user info    |\n");
  cout << setw(60) << ("|2.Create user info                   7.Classify user info|\n");
  cout << setw(60) << ("|3.Delete user info                   8.Display user info |\n");
  cout << setw(60) << ("|4.Search user info                   9.Save user info    |\n");
  cout << setw(60) << ("|5.Modify user info                   10.Load user info   |\n");
  cout << setw(60) << ("|                    0.Exit system                        |\n");
  cout << setw(60) << ("|---------------------------------------------------------|\n");
}


#endif //
