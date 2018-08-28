//
// Created by mac on 2018/8/28.
//

#ifndef LORNABK_UTIL_H
#define LORNABK_UTIL_H

#include "file.h"
#include "user.h"

void User::create() {
  int id;
  string passwd;
  string name;
  string tel;

  cout.flags(ios::adjustfield);
  cout << setw(45) << ("|______________|") << endl;
  cout << setw(45) << ("|Create account|") << endl;
  cout << setw(45) << ("|______________|") << endl;

  cout << ("id:");
  cin >> id;
  cout << ("passwd:");
  cin >> passwd;
  cout << ("name:");
  cin >> name;
  cout << ("tel:");
  cin >> tel;

  ofstream ofs(filePath, ios::app);
  if (!ofs) {
    cerr << "File open error" << endl;
  } else {
    ofs.flags(ios::left);
    ofs << setw(20) << id << setw(20) << passwd << setw(20) << name << setw(20) << tel << endl;
  }
}

void User::
delete() {

ifstream file("test.txt");
string line;
int n, count = 0;
ofstream outfile("test2.txt", ios::out | ios::trunc);
cout << "Please input the line number you want to del:" <<
endl;
cin >>
n;
while (!file.
eof()
) {
getline(file, line
);
if (count != n - 1)//如果要修改内容就在这修改line的内容,再存到文件中就行了
outfile << line <<
endl;
count++;
}
outfile.
close();
file.
close();
ofstream outfile1("test.txt", ios::out | ios::trunc);
fstream file1("test2.txt");
while (!file1.
eof()
) {
getline(file1, line
);
outfile1 << line <<
endl;
}
outfile1.
close();
file1.
close();
system("del test2.txt");//删除中间文件
return 0;
}

void User::search() {
  int id;
  string passwd;
  string name;
  string tel;

  cout.flags(ios::adjustfield);
  cout << setw(45) << ("|______________|") << endl;
  cout << setw(45) << ("|Create account|") << endl;
  cout << setw(45) << ("|______________|") << endl;

  cout << ("id:");
  cin >> id;
  cout << ("passwd:");
  cin >> passwd;
  cout << ("name:");
  cin >> name;
  cout << ("tel:");
  cin >> tel;

  ofstream ofs(filePath, ios::app);
  if (!ofs) {
    cerr << "File open error" << endl;
  } else {
    ofs.flags(ios::left);
    ofs << setw(20) << id << setw(20) << passwd << setw(20) << name << setw(20) << tel << endl;
  }
}

void User::modify() {
  int id;
  string passwd;
  string name;
  string tel;

  cout.flags(ios::adjustfield);
  cout << setw(45) << ("|______________|") << endl;
  cout << setw(45) << ("|Create account|") << endl;
  cout << setw(45) << ("|______________|") << endl;

  cout << ("id:");
  cin >> id;
  cout << ("passwd:");
  cin >> passwd;
  cout << ("name:");
  cin >> name;
  cout << ("tel:");
  cin >> tel;

  ofstream ofs(filePath, ios::app);
  if (!ofs) {
    cerr << "File open error" << endl;
  } else {
    ofs.flags(ios::left);
    ofs << setw(20) << id << setw(20) << passwd << setw(20) << name << setw(20) << tel << endl;
  }
}

#endif //LORNABK_UTIL_H
