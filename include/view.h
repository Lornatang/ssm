//
// Created by mac on 2018/8/27.
//

#ifndef LORNABK_VIEW_H
#define LORNABK_VIEW_H

#include "../include/user.h"

class View {
 public:
  View();
  ~View();

  /* 欢迎 */
  void welcome();

  /* 显示菜单 */
  void showMenu();

  /* View 显示所有学生 */
  void showAllStuAtView(const map<int, User> &stu_m1);

  /* View层 添加一个学生 */
  void addStuAtView(map<int, User> &stu_m1);

  /* View 查找一个学生 */
  void findStuAtView(const map<int, User> &m1);

  /* View层删除一个学生 */
  void deleteByIdAtView(map<int, User> &v1);

  /* View层 更新一个学生 */
  void updateByIdAtView(map<int, User> &m1);

  /* view层 把map保存进文件 */
  void saveToFileAtView(const map<int, User> &m1, string pathName);

  /* View层 把文件中的东西导入 map */
  void readFromFileAtView(map<int, User> &m, string pathName);
};

#endif //LORNABK_VIEW_H
