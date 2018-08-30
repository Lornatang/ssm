//
// Created by mac on 2018/8/29.
//

#ifndef SSM_USER_METHODS_H
#define SSM_USER_METHODS_H

#include "user.h"
#include "base.h"
#include "../util/checkAccount.h"
// Init user numbers
void User::userInit() {
  // users
  int n;
  userNode *p, *u;
  p = head;

  cout << "Please input numbers: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    u = new userNode;
    cout.flags(ios::adjustfield);
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << setw(32) << i << ("\n");
    cout << setw(45) << ("|-+-+-+-+-+-+-+-+-+-+-+-|\n");
    cout << ("id: ");
    cin >> u->id;
    if (!checkAccount(to_string(u->id))) {
      cerr << ("Account id is exist!\n");
      return;
    }
    cout << ("password: ");
    cin >> u->passwd;
    cout << ("name: ");
    cin >> u->name;
    cout << ("address: ");
    cin >> u->address;
    cout << ("tel: ");
    cin >> u->tel;

    u->next = p->next;
    p->next = u;
    p = p->next;
  }
  if (p == nullptr) {
    cerr << ("Init error. Please re-operate.\n");
    userInit();
  }
}

// Print user info
void User::disUserInfo() {
  userNode *p;
  cout.flags(ios::left);
  cout << ("id passwd name address telephone\n");
  for (p = head->next; p != nullptr; p = p->next) {
    cout.flags(ios::left);
    cout << p->id << (" ") << p->passwd << (" ") << p->name << (" ") << p->address << (" ") << p->tel << ("\n");
  }
}

// insert student information (head interpolation)
void User::userInsert(int uid, const string &upasswd, const string &uname, const string &uaddress, const string &utel) {
  userNode *p, *u;
  u = new userNode;
  u->id = uid;
  u->passwd = upasswd;
  u->name = uname;
  u->address = uaddress;
  u->tel = utel;

  p = head;
  u->next = p->next;
  p->next = u;
}

// Delete user info
void User::userDelete(int uid) {
  userNode *p, *tmp;
  p = head;
  tmp = p;
  /*cycle termination condition is p->next is not empty
   *and does not find the corresponding student number
   */
  while (p->next && p->id != uid) {
    tmp = p;
    p = p->next;
  }
  if (p->id == uid) {
    tmp->next = p->next;
    delete p;
  } else {
    cerr << ("Can't find id [") << uid << ("] information!\n");
    cerr << ("Return status -1.\n");
  }
}

// Find user info by id
userNode *User::userFind(int uid) {
  userNode *p;
  p = head->next;
  /*the termination condition is p->next is not empty
   * and the corresponding student number is not found
   */
  while (p->next && p->id != uid) {
    p = p->next;
  }
  if (p->id == uid) {
    return p;
  } else {
    cerr << ("Can't find id [") << uid << ("] information!\n");
    return nullptr;
  }
}

// Modify student information (copy p information to tmp)
void User::userModify(int uid, const string &upasswd, const string &uname, const string &uaddress, const string &utel) {
  // Call the find function.
  userNode *userItem = userFind(uid);
  if (userItem != nullptr) {
    userItem->id = uid;
    userItem->passwd = upasswd;
    userItem->name = uname;
    userItem->address = uaddress;
    userItem->tel = utel;
  }
}

// Copy student information (copy the information of p into tmp)
void User::userCopy(userNode *tmp, userNode *p) {
  if (p == nullptr) {
    cerr << ("Copy information cannot be empty.\n") << endl;
    return;
  } else {
    tmp->id = p->id;
    tmp->passwd = p->passwd;
    tmp->name = p->name;
    tmp->address = p->address;
    tmp->tel = p->tel;
  }
}

// Sort by user id
void User::userSort(char ch) {
  if (ch == '>') {
    for (userNode *p = head->next; p != nullptr; p = p->next) {
      for (userNode *q = head->next; q != nullptr; q = q->next) {
        if (p->id > q->id) {
          auto *tmp = new userNode;
          userCopy(tmp, p);
          userCopy(p, q);
          userCopy(q, tmp);
        }
      }
    }
  } else if (ch == '<') {
    for (userNode *p = head->next; p != nullptr; p = p->next) {
      for (userNode *q = head->next; q != nullptr; q = q->next) {
        if (p->id < q->id) {
          auto *tmp = new userNode;
          userCopy(tmp, p);
          userCopy(p, q);
          userCopy(q, tmp);
        }
      }
    }
  } else {
    cerr << ("Operator error!\n");
    return;
  }
}

// Classify by user address
void User::userClassify() {
  int address[3] = {0};
  userNode *p = head->next;
  while (p != nullptr) {
    if ("1601" == p->address) {
      address[0] += 1;
    } else if ("1602" == p->address) {
      address[1] += 1;
    } else if ("1603" == p->address) {
      address[2] += 1;
    }
    p = p->next;
  }
  cout.flags(ios::left);
  cout << ("1601 ") << ("1602 ") << ("1603\n");
  for (int i : address) {
    cout.flags(ios::left);
    cout << i << ("    ");
  }
  cout << endl;
}

#endif //SSM_METHODS_H
