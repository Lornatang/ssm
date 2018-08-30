//
// Created by mac on 2018/8/28.
// Handler interface
//

#include "../user/user.h"
#include "../util/user.h"
#include "../user/base.h"
#include "../user/file.h"
#include "../user/methods.h"
using namespace std;

int main(int argc, char const *argv[]) {
  User user;
  userNode *u;

  // set default user;
  int uid = 0;
  string upasswd;
  string uname;
  string uaddress;
  int utel = 0;

  char choice;

  system("clear");
  user.userRead();

  if (argc < 2) {
    cerr << ("Please use '-h' or '--help' get help.\n");
    return -1;
  } else if ((strcmp(argv[1], "-g") == 0) || (strcmp(argv[1], "--gui") == 0)) {
    userMenu();
    return 0;
  } else if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    cout << ("Usage:\n");
    cout << ("-g or --gui                  \t --Graphical display function.           \n");
    cout << ("-h or --help                 \t --get exec help.                        \n");
    cout << ("-v or --version              \t --get app version.                      \n");
    cout << ("-i or --init                 \t --Init user information.                \n");
    cout << ("-c or --create               \t --Create user information.              \n");
    cout << ("-d or --delete               \t --Delete user information.              \n");
    cout << ("-s or --show                 \t --Search user information.              \n");
    cout << ("-m or --modify               \t --Modify user information.              \n");
    cout << ("-e -s                        \t --extend function (sort by user id).    \n");
    cout << ("-e -c                        \t --extend function (classify by user id).\n");
    cout << ("-e -d                        \t --extend function (display by user id). \n");
    return 0;
  } else if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
    cout << ("Book store version 0.0.5-beta.1\n");
    cout << ("Thread model: posix\n");
    cout << ("InstalledDir: /Library/Developer/CommandLineTools/usr/bin\n");
    return 0;
  } else if ((strcmp(argv[1], "-i") == 0) || (strcmp(argv[1], "--init") == 0)) {
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Init   user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    if (flag) {
      cout << ("Init user info?(y/N)? ");
      cin >> choice;
      if (choice == 'y') {
        user.userInit();
        cout << ("Updating user info...\n");
        return 0;
      } else if (choice == 'N') {
        cerr << ("User operator cancel.\n");
        return -1;
      } else {
        user.userInit();
        cout << ("Updating user info...\n");
        return 0;
      }
    }
  } else if ((strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--create") == 0)) {
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Insert user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    cout << ("Password: ");
    cin >> upasswd;
    cout << ("Name: ");
    cin >> uname;
    cout << ("Address: ");
    cin >> uaddress;
    cout << ("Telephone: ");
    cin >> utel;
    cout << ("Do you want to add this information(y/N)? ");
    cin >> choice;
    if (choice == 'y') {
      user.userInsert(uid, upasswd, uname, uaddress, utel);
      cout << ("Insert user id [") << uid << ("] info complete!\n");
      user.userSave();
      cout << ("Updating user info...\n");
      return 0;
    } else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    } else {
      user.userModify(uid, upasswd, uname, uaddress, utel);
      cout << ("Insert user id [") << uid << ("] info complete!\n");
      user.userSave();
      cout << ("Updating user info...\n");
      return 0;
    }
  } else if ((strcmp(argv[1], "-d") == 0) || (strcmp(argv[1], "--delete") == 0)) {
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Delete user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    if (flag) {
      cout << ("Delete or delete after deletion(y/N)? ");
      cin >> choice;
      if (choice == 'y') {
        user.userDelete(uid);
        cout << ("Delete user id [") << uid << ("] info complete!\n");
        user.userSave();
        cout << ("Updating user info...\n");
        return 0;
      } else if (choice == 'N') {
        cerr << ("User operator cancel.\n");
        return -1;
      } else {
        user.userModify(uid, upasswd, uname, uaddress, utel);
        cout << ("Insert user id [") << uid << ("] info complete!\n");
        user.userSave();
        cout << ("Updating user info...\n");
        return 0;
      }
    }
  } else if ((strcmp(argv[1], "-s") == 0) || (strcmp(argv[1], "--show") == 0)) {
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Search user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    u = user.userFind(uid);
    cout.flags(ios::left);
    cout << setw(20) << ("id") << setw(20) << ("password") << setw(20) << ("name") << setw(20) << ("address")
         << setw(20) << ("telephone\n");
    cout << setw(20) << u->id << setw(20) << u->passwd << setw(20) << u->name << setw(20) << u->address << setw(20)
         << u->tel;
    return 0;
  } else if ((strcmp(argv[1], "-m") == 0) || (strcmp(argv[1], "--modify") == 0)) {
    if (!systemEnder()) {
      cerr << ("System ender error.\n");
      return -1;
    }
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(45) << ("|Modify user information|\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("Id: ");
    cin >> uid;
    cout << ("Password: ");
    cin >> upasswd;
    cout << ("Name: ");
    cin >> uname;
    cout << ("Address: ");
    cin >> uaddress;
    cout << ("Telephone: ");
    cin >> utel;
    // modify user info.
    if (flag) {
      cout << ("Do you want to add this information(y/N)? ");
      cin >> choice;
      if (choice == 'y') {
        user.userModify(uid, upasswd, uname, uaddress, utel);
        cout << ("Insert user id [") << uid << ("] info complete!\n");
        user.userSave();
        cout << ("Updating user info...\n");
        return 0;
      } else if (choice == 'N') {
        cerr << ("User operator cancel.\n");
        return -1;
      } else {
        user.userModify(uid, upasswd, uname, uaddress, utel);
        cout << ("Insert user id [") << uid << ("] info complete!\n");
        user.userSave();
        cout << ("Updating user info...\n");
        return 0;
      }
    }
    cout << ("Updating user info...\n");
    return 0;
  } else if ((strcmp(argv[1], "-e") == 0) || (strcmp(argv[2], "--s") == 0)) {
    cout << "Ascending Order or Descending Order (a/d/N): ";
    cin >> choice;
    if (choice == 'a')
      user.userSort('<');
    else if (choice == 'd')
      user.userSort('>');
    else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    } else
      user.userSort('>');
    return 0;
  } else if ((strcmp(argv[1], "-e") == 0) || (strcmp(argv[2], "--c") == 0)) {
    cout << "classification: (y/N): ";
    cin >> choice;
    if (choice == 'y')
      user.userClassfy();
    else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    } else
      user.userClassfy();
    return 0;
  } else if ((strcmp(argv[1], "-e") == 0) || (strcmp(argv[2], "--d") == 0)) {
    cout << "Display user info: (y/N): ";
    cin >> choice;
    if (choice == 'y')
      user.disUserInfo();
    else if (choice == 'N') {
      cerr << ("User operator cancel.\n");
      return -1;
    } else
      user.disUserInfo();
    return 0;
  } else {
    if (argc > 1) {
      cerr.flags(ios::adjustfield);
      cerr << setw(50) << ("Unknown command!\n");
    } else {
      cerr << ("Please use '-h' or '--help' get help\n");
      return -1;
    }
  }
}