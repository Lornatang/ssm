//
// Created by mac on 2018/8/28.
//

#include "user.h"
#include "file.h"
#include "util.h"
#include <unistd.h>
using namespace std;

int errCount = 0;

int main(int argc, char const *argv[]) {
  User user;

  // load data from file
  system("clear");
  cout << ("Loading data...!\n\n");

  if (argc < 2) {
    cerr << ("Please input '-h' or '--help' get help") << endl;
  } else if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    cout << ("Usage:\n");
    cout << ("-h or --help    \t --get exec help.             \n");
    cout << ("-v or --version \t --get app version.           \n");
    cout << ("-c or --create  \t --create account.            \n");
    cout << ("-s or --show    \t --print account information. \n");

  } else if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
    cout << ("Book store version 0.0.1\n"
             "Thread model: posix\n"
             "InstalledDir: /Library/Developer/CommandLineTools/usr/bin\n");
  } else if ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--create") == 0)) {
    if (user.Create())
      cout << ("Account create complete.\n");

    else {
      while (errCount < 2) {
        cerr << ("\nWait 3s to pass...\n");
        sleep(3);
        user.Create();
        errCount += 1;
      }
      cerr << ("\nError count have 3. exit create account. If you create account, please restart app.\n");
    }
  } else if ((strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "--show") == 0)){
    user.show();
  } else {
    cerr << ("Please use '-h' or '--help' get help\n") << endl;
  }

  return 0;
}