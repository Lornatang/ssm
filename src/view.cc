//
// Created by mac on 2018/8/27.
//

#include "../include/view.h"

#include <utility>
#include <iostream>
#include <map>
#include <fstream>
#include <unistd.h>
using namespace std;

View::View() = default;

View::~View() = default;

/* 欢迎 */
void View::welcome() {
  system("clear");
  cout << "欢迎来到湖南涉外经济学院计算机应用1603班学生管理系统" << endl;
}

/* 显示菜单 */
void View::showMenu() {

  cout << "\n";
  cout << "操作步骤" << endl;

  cout << "1. 录入" << endl;
  cout << "2. 修改" << endl;
  cout << "3. 查找" << endl;
  cout << "4. 删除" << endl;
  cout << "5. 显示所有" << endl;
  cout << "6. 保存至文件" << endl;
  cout << "7. 从文件导入" << endl;
  cout << "0. 退出" << endl;
  cout << "\n";
  cout << "\n";
  cout << "请选择操作：";
}

/* View 显示所有学生 */
void View::showAllStuAtView(const map<int, User> &stu_m1) {

  system("clear");
  cout << "id    |" << "name  |" << "age" << endl;
  User cStuMg;
  cStuMg.showAll(stu_m1);

  getchar();
  system("clear");
  welcome();
  showMenu();
}

/* view层 添加一个学生 */
void View::addStuAtView(map<int, User> &stu_m1) {
  User cStuMg;

  int id = 0;
  string name;
  int age = 0;
  User cStu;

  system("clear");

  cout << "录入\n";
  cout << "id:";
  cin >> id;

  cout << "name:";
  cin >> name;

  cout << "age:";
  cin >> age;

  cStu.setId(id);
  cStu.setName(name);
  cStu.setPasswd(age);

  // 保存
  cStuMg.addAStu(stu_m1, cStu);

  system("cls");
  welcome();
  showMenu();
}

/* View 查找一个学生 */
void View::findStuAtView(const map<int, User> &m1) {

  system("clear");
  int id = 0;
  cout << "请输入要查找学生的id" << endl;
  cin >> id;

  User cStuMg;
  User cStu;
  cStu = cStuMg.findById(m1, id);

  if (cStu.getId() != -1) {
    cout << cStu << endl;
  } else {
    cout << "查无此人" << endl;
  }

  getchar();
  system("clear");
  welcome();
  showMenu();

}

/* view层删除一个学生 */
void View::deleteByIdAtView(map<int, User> &v1) {

  system("clear");
  int id = 0;
  cout << "请输入要删除的学生的id" << endl;
  cin >> id;

  User cStuMg;
  bool b = cStuMg.deleteStuById(v1, id);

  if (b) {
    cout << "删除成功" << endl;
  } else {
    cout << "查无此人" << endl;
  }

  getchar();
  system("clear");
  welcome();
  showMenu();

}

/* view层 更新一个学生 */
void View::updateByIdAtView(map<int, User> &m1) {

  system("cls");

  cout << "请输入要修改的学生的id" << endl;
  int id = 0;
  cin >> id;
  string name = " ";

  cout << "name:";
  cin >> name;

  int age = 0;
  cout << "age:";
  cin >> age;

  User cStu;
  cStu.setId(id);
  cStu.setName(name);
  cStu.setPasswd(age);

  User cStuMg;

  User cStu2 = cStuMg.updateStu(m1, cStu);

  if (cStu2.getId() != -1) {
    cout << cStu2 << endl;
    cout << "修改成功" << endl;
  } else {
    cout << "查无此人" << endl;
  }

  system("pause");
  system("cls");
  welcome();
  showMenu();

}

/* view层 把vec保存进文件 */
void View::saveToFileAtView(const map<int, User> &m1, string pathName) {

  if (m1.begin() == m1.end()) {
    system("cls");
    cout << "还没有任何学生信息，无法保存" << endl;
  } else {
    // 保存
    User cStuMg;
    bool b = cStuMg.saveData(m1, pathName);
    if (b) {
      system("clear");
      cout << "保存成功" << endl;
    } else {
      cout << "保存失败" << endl;
    }
  }

  getchar();
  system("clear");
  welcome();
  showMenu();

}

/* view层 把文件中的东西导入 vec */
void View::readFromFileAtView(map<int, User> &m, string pathName) {

  system("clear");

  User cStuMg;
  bool b = cStuMg.loadData(m, pathName);
  if (b) {
    cout << "读取成功" << endl;
  } else {
    cout << "读取失败" << endl;
  }
  getchar();
  system("clear");
  welcome();
  showMenu();
}
