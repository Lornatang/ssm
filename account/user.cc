//
// Created by mac on 2018/8/28.
// Handler interface
//

#include "user.h"
#include "file.h"
#include "util.h"
using namespace std;

int errCount = 0;

int main(int argc, char const *argv[]) {
  User user;

  system("clear");

  if (argc < 2) {
    cerr << ("Please input '-h' or '--help' get help") << endl;
  } else if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    cout << ("Usage:\n");
    cout << ("-h or --help    \t --get exec help.             \n");
    cout << ("-v or --version \t --get app version.           \n");
    cout << ("-c or --create  \t --create account.            \n");
    cout << ("-s or --show    \t --print account information. \n");
    return 0;

  } else if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
    cout << ("Book store version 0.0.3\n"
             "Thread model: posix\n"
             "InstalledDir: /Library/Developer/CommandLineTools/usr/bin\n");
    return 0;
  } else if ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--create") == 0)) {
    if (user.Create()) {
      cout << ("Account create complete.\n");
      return 0;
    } else {
      while (errCount < 3) {
        cerr << ("Id is exist! Please input other number.\n");
        cerr << ("\nWait 3s to pass...\n");
        sleep(3);
        user.Create();
        errCount += 1;
      }
        cerr << ("Account create error.\n");
        cerr << ("\nError count have 3. exit create account. If you create account, please restart app.\n");
        return -1;
    }
  } else if ((strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "--show") == 0)) {
    // verify account
    if (user.Verify()) {
      cout << ("Account verify complete.\n");
      cout << ("Searching data...\n");
      sleep(1);
      user.show();
      return 0;
    } else {
      cerr << ("Account verify error.\n");
      cerr << ("Exit create account. If you create account, please restart app.\n");
      return -1;
    }
  } else {
    cerr << ("Please use '-h' or '--help' get help\n") << endl;
  }

  return 0;
}