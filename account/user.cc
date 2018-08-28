//
// Created by mac on 2018/8/28.
//

#include "user.h"
#include "file.h"
#include "util.h"
using namespace std;

int main(int argc, char const *argv[]) {
  User user;
  // load data from file
  system("clear");
  cout << ("Loading data...!\n\n");
  if(!loadAccountData())
    cerr << ("Loading data error...!");
  cout << endl;

  if (argc < 2) {
    cerr << ("Please input '-h' or '--help' get help") << endl;
  }
  else if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    cout << ("Usage:") << endl;
    cout << ("-h --help    \t --get exec help.  ") << endl;
    cout << ("-v --version \t --get app version.") << endl;
    cout << ("-c --create  \t --create account. ") << endl;
    cout << ("-d --delete  \t --delete account. ") << endl;
    cout << ("-s --search  \t --search account. ") << endl;
    cout << ("-m --modify  \t --modify account. ") << endl;
  }
  else if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
    cout << ("Book store version 0.0.1\n"
             "Thread model: posix\n"
             "InstalledDir: /Library/Developer/CommandLineTools/usr/bin") << endl;
  }
  else if ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--create") == 0)) {
    user.create();
  }
  else if ((strcmp(argv[1], "-d") == 0) || (strcmp(argv[1], "--delete") == 0)) {
    cout << ("hello!") << endl;
  }
  else if ((strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "--search") == 0)) {
    cout << ("hello!") << endl;
  }
  else if ((strcmp(argv[1], "-m") == 0) || (strcmp(argv[1], "--modify") == 0)) {
    cout << ("hello!") << endl;
  }
  else {
      cerr << ("Please input '-h' or '--help' get help") << endl;
  }

  return 0;
}