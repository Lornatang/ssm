//
// Created by mac on 2018/8/27.
//

#include "../include/user.h"
/*
 * Load data from file
 * */
bool loadData(map<int, User> &u, const string &pathName) {
  bool flag = true;
  User user;

  // init map
  u.clear();

  fstream ifs(pathName, ios::in);
  if (ifs) {
    string word;
    stringstream ss;
    while (getline(ifs, word)) {
      ss << word;
      ss >> user;
      ss.clear();

      u.insert(make_pair(user.getId(), user));
    }
    ifs.close();
  } else {
    flag = false;
    ifs.close();
  }
  return flag;
}

/*
 * read from file.
 * */
bool saveData(const map<int, User> &u, const string &pathName) {
  bool flag = true;
  User user;

  fstream ofs(pathName, ios::out);
  if (ofs) {
    stringstream word;
    for (const auto &p : u) {
      user = p.second;
      word << user << endl;
    }
    ofs << word.str();
    ofs.close();
  } else {
  }

  return flag;
}
