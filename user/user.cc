//
// Created by mac on 2018/8/28.
// Handler interface
//

#include "user.h"
#include "file.h"
#include "../util/user.h"
using namespace std;

int errCount = 0;

int main(int argc, char const *argv[]) {
  User user;

  system("clear");

  if (argc < 2) {
    cerr << ("Please use '-h' or '--help' get help") << endl;
  } else if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    cout << ("Usage:\n");
    cout << ("-h or --help    \t --get exec help.             \n");
    cout << ("-v or --version \t --get app version.           \n");
    cout << ("-c or --create  \t --create user.               \n");
    cout << ("-s or --show    \t --print user information.    \n");
    return 0;

  } else if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
    cout << ("Book store version 0.0.4-beta.1\n"
             "Thread model: posix\n"
             "InstalledDir: /Library/Developer/CommandLineTools/usr/bin\n");
    return 0;
  } else if ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--create") == 0)) {

  } else if ((strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "--show") == 0)) {
  } else {
    cerr << argv[1] << (" is unknown command!\n");
    cerr << ("Please use '-h' or '--help' get help\n");
    cerr << ("Return status -1\n");
  }

  return 0;
}