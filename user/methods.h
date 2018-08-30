//
// Created by mac on 2018/8/29.
//

#ifndef SSM_USER_METHODS_H
#define SSM_USER_METHODS_H

#include "user.h"
#include "base.h"

// Init user numbers
void User::userInit() {
  // users
  int n;
  userNode *p, *u;
  p = head;
  u = new userNode;
  cout << "Please input numbers: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u->id >> u->passwd >> u->name >> u->address >> u->tel;
    u->next = p->next;
    p->next = u;
    p = p->next;
  }
  if (p == nullptr)   //判断学生信息表是否创建成功
  {
    cerr << ("Init error. Please re-operate.\n");
    cerr << ("Return status -1.\n");
    userInit();
  }
}

// Print user info
void User::disUserInfo() {
  userNode *p;
  cout.flags(ios::left);
  cout << setw(20) << ("id") << setw(20) << ("password") << setw(20) << ("name") << setw(20) << ("address") << setw(20)
       << ("telephone\n");
  for (p = head->next; p != nullptr; p = p->next) {
    cout.flags(ios::left);
    cout << setw(20) << p->id << setw(20) << p->passwd << setw(20) << p->name << setw(20) << p->address << setw(20)
         << p->tel << endl;
  }
}

// insert student information (head interpolation)
void User::userInsert(int uid, const string &upasswd, const string &uname, const string &uaddress, int utel) {
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
  while (p->next && p->id != uid)
    p = p->next;
  if (p->id == uid)
    return p;
  else {
    cerr << ("Can't find id [") << uid << ("] information!\n");
    cerr << ("Return status -1.\n");
    return nullptr;
  }
}

// Modify student information (copy p information to tmp)
void User::userModify(int uid, const string &upasswd, const string &uname, const string &uaddress, int utel) {
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
void User::userCopy(userNode *p, userNode *tmp) {
  if (p == nullptr) {
    cerr << ("Copy information cannot be empty.\n") << endl;
    cerr << ("Return status -1.\n");
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
    cerr << ("Return status -1.\n");
  }
}

// Classify by user address
void User::userClassfy() {
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
  cout << setw(20) << ("1601") << setw(20) << ("1602") << setw(20) << ("1603\n");
  for (int i : address) {
    cout.flags(ios::left);
    cout << setw(20) << i;
  }
  cout << endl;
}

#endif //SSM_METHODS_H
