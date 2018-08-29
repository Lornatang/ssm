//
// Created by mac on 2018/8/29.
//

#ifndef SSM_METHODS_H
#define SSM_METHODS_H

#include "user.h"
#include "file.h"

// Init user numbers
void User::userInit() {
  // users
  int n;
  User *p, *u;
  u = new User;
  p = head;
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
    cout << "Init error. Please re-operate.\n";
    userInit();
  }
}

// Print user info
void User::disUserInfo() {
  User *p;
  cout.flags(ios::left);
  cout << setw(20) << ("id") << setw(20) << ("password") << setw(20) << ("name") << setw(20) << ("address") << setw(20) << ("telephone\n");
  for (p = head->next; p != nullptr; p = p->next) {
    cout.flags(ios::left);
    cout << setw(20) << p->id << setw(20) << p->passwd << setw(20) << p->name << setw(20) << p->address << setw(20) << p->tel << endl;
  }
}

// insert student information (head interpolation)
void User::userInsert(int uid, const string &upasswd, const string &uname, const string &uaddress, int utel) {
  User *p, *u;
  u = new User;
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
  User *p, *tmp;
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
  } else
    cerr << "Can't find this user info.\n";
}

User *User::userFind(int uid) {
  User *p;
  p = head->next;
  /*the termination condition is p->next is not empty
   * and the corresponding student number is not found
   */
  while (p->next && p->id != uid)
    p = p->next;
  if (p->id == uid)
    return p;
  else {
    cout << "未找到该学生信息！" << endl;
    return NULL;
  }
}

void User::StuModify(int snum, int smath, int seng, int syuwen) {
  User *ItemStu = StuFind(snum);   //直接调用查找函数
  if (ItemStu != NULL) {
    ItemStu->math = smath;
    ItemStu->num = snum;
    ItemStu->math = smath;
    ItemStu->eng = seng;
    ItemStu->yuwen = syuwen;
    ItemStu->sum = ItemStu->math + ItemStu->eng + ItemStu->yuwen;
  }
}

void User::StuCopy(User *tmp, User *p)  //拷贝学生信息(将p的信息拷贝到ptemp中)
{
  if (p == NULL) {
    cout << "拷贝目标为空！" << endl;
  } else {
    tmp->num = p->num;
    tmp->math = p->math;
    tmp->eng = p->eng;
    tmp->yuwen = p->yuwen;
    tmp->sum = p->sum;
    //tmp->next = p->next;   //只是信息拷贝,next不能拷贝否则信息丢失
  }
}

void User::StuSort(char ch)   //根据 总分排序
{
  if (ch == '>') {
    for (User *p = head->next; p != NULL; p = p->next) {
      for (User *q = head->next; q != NULL; q = q->next) {
        if (p->sum > q->sum) {
          User *tmp = new User;
          StuCopy(tmp, p);
          StuCopy(p, q);
          StuCopy(q, tmp);
        }
      }
    }
  } else if (ch == '<') {
    for (User *p = head->next; p != NULL; p = p->next) {
      for (User *q = head->next; q != NULL; q = q->next) {
        if (p->sum < q->sum) {
          User *tmp = new User;
          StuCopy(tmp, p);
          StuCopy(p, q);
          StuCopy(q, tmp);
        }
      }
    }
  } else if (ch == 'o') {
    for (User *p = head->next; p != NULL; p = p->next) {
      for (User *q = head->next; q != NULL; q = q->next) {
        if (p->num < q->num) {
          User *tmp = new User;
          StuCopy(tmp, p);
          StuCopy(p, q);
          StuCopy(q, tmp);
        }
      }
    }
  } else {
    cout << "排序条件出错！" << endl;
  }
}

void User::StuClassfy()  //根据学生总分分类
{
  int grade[5] = {0};
  User *p = head->next;
  while (p != NULL) {
    if (89 < p->math) {
      grade[0]++;
    } else if (79 < p->math && p->math < 90) {
      grade[1]++;
    } else if (69 < p->math && p->math < 80) {
      grade[2]++;
    } else if (59 < p->math && p->math < 70) {
      grade[3]++;
    } else {
      grade[4]++;
    }
    p = p->next;
  }
  cout << "A" << '\t' << "B" << '\t' << "C" << '\t' << "D" << '\t' << "E" << endl;
  for (int i = 0; i < 5; i++) {
    cout << grade[i] << '\t';
  }
  cout << endl;
}

#endif //SSM_METHODS_H
