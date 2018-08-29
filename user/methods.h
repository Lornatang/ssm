//
// Created by mac on 2018/8/29.
//

#ifndef SSM_METHODS_H
#define SSM_METHODS_H

#include "user.h"
#include "file.h"

void SInfo::CreatSinfo()     //创建学生信息表
{
  int n;
  StuNode *p, *s;
  p = StuListHead;
  cout << "请输入学生人数：";
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    s = new StuNode;
    cin >> s->num >> s->math>>s->eng>>s->yuwen;
    s->sum = s->math + s->eng + s->yuwen;
    s->nextstu = p->nextstu;
    p->nextstu = s;
    p = p->nextstu;
  }
  if (p == NULL)   //判断学生信息表是否创建成功
  {
    cout << "创建失败请重新创建！" << endl;
    CreatSinfo();
  }
}

void SInfo::ShowInfo()      //遍历输出
{
  StuNode *p;
  cout << "学号" << '\t' << "数学" << '\t' << "英语" << '\t' << "语文" << '\t' << "总分" << endl;
  for (p = StuListHead->nextstu; p != NULL; p = p->nextstu)
  {
    cout << p->num << '\t' << p->math << '\t' << p->eng << '\t' << p->yuwen << '\t' << p->sum << endl;
  }
}

void SInfo::StuInsert(int snum, int smath,int seng,int syuwen)     //插入学生信息（头插法）
{
  StuNode *s,*p;
  s = new StuNode;
  s->num = snum;
  s->math = smath;
  s->eng = seng;
  s->yuwen = syuwen;
  s->sum = s->math + s->eng + s->yuwen;
  p = StuListHead;
  s->nextstu = p->nextstu;
  p->nextstu = s;
}

void SInfo::StuDelete(int snum)
{
  StuNode *p, *ptemp;
  p = StuListHead;
  ptemp = p;
  while (p->nextstu && p->num!=snum)   //循环终止条件为p->nextstu不为空 而且没有找到相应学号的学生
  {
    ptemp = p;
    p = p->nextstu;
  }
  if (p->num == snum)
  {
    ptemp->nextstu = p->nextstu;
    delete p;
  }
  else
  {
    cout << "未找到该学生信息！" << endl;
  }
}

StuNode *SInfo::StuFind(int snum)
{
  StuNode *p;
  p = StuListHead->nextstu;
  while (p->nextstu && p->num != snum)   //循环终止条件为p->nextstu不为空 而且没有找到相应学号的学生
  {
    p = p->nextstu;
  }
  if (p->num == snum)
  {
    return p;
  }
  else
  {
    cout << "未找到该学生信息！" << endl;
    return NULL;
  }
}

void SInfo::StuModify(int snum, int smath, int seng, int syuwen)
{
  StuNode *ItemStu = StuFind(snum);   //直接调用查找函数
  if (ItemStu != NULL)
  {
    ItemStu->math = smath;
    ItemStu->num = snum;
    ItemStu->math = smath;
    ItemStu->eng = seng;
    ItemStu->yuwen = syuwen;
    ItemStu->sum = ItemStu->math + ItemStu->eng + ItemStu->yuwen;
  }
}

void SInfo::StuCopy(StuNode *ptemp, StuNode *p)  //拷贝学生信息(将p的信息拷贝到ptemp中)
{
  if (p == NULL)
  {
    cout << "拷贝目标为空！" << endl;
  }
  else
  {
    ptemp->num = p->num;
    ptemp->math = p->math;
    ptemp->eng = p->eng;
    ptemp->yuwen = p->yuwen;
    ptemp->sum = p->sum;
    //ptemp->nextstu = p->nextstu;   //只是信息拷贝,next不能拷贝否则信息丢失
  }
}

void SInfo::StuSort(char ch)   //根据 总分排序
{
  if (ch == '>')
  {
    for (StuNode *p = StuListHead->nextstu; p != NULL; p = p->nextstu)
    {
      for (StuNode *q = StuListHead->nextstu; q != NULL; q = q->nextstu)
      {
        if (p->sum > q->sum)
        {
          StuNode *ptemp = new StuNode;
          StuCopy(ptemp, p);
          StuCopy(p, q);
          StuCopy(q, ptemp);
        }
      }
    }
  }
  else if (ch == '<')
  {
    for (StuNode *p = StuListHead->nextstu; p != NULL; p = p->nextstu)
    {
      for (StuNode *q = StuListHead->nextstu; q != NULL; q = q->nextstu)
      {
        if (p->sum < q->sum)
        {
          StuNode *ptemp = new StuNode;
          StuCopy(ptemp, p);
          StuCopy(p, q);
          StuCopy(q, ptemp);
        }
      }
    }
  }
  else if (ch == 'o')
  {
    for (StuNode *p = StuListHead->nextstu; p != NULL; p = p->nextstu)
    {
      for (StuNode *q = StuListHead->nextstu; q != NULL; q = q->nextstu)
      {
        if (p->num < q->num)
        {
          StuNode *ptemp = new StuNode;
          StuCopy(ptemp, p);
          StuCopy(p, q);
          StuCopy(q, ptemp);
        }
      }
    }
  }
  else
  {
    cout << "排序条件出错！" << endl;
  }
}

void SInfo::StuClassfy()  //根据学生总分分类
{
  int grade[5] = {0};
  StuNode *p = StuListHead->nextstu;
  while (p != NULL)
  {
    if (89 < p->math)
    {
      grade[0]++;
    }
    else if (79 < p->math && p->math < 90)
    {
      grade[1]++;
    }
    else if (69 < p->math && p->math < 80)
    {
      grade[2]++;
    }
    else if (59 < p->math && p->math < 70)
    {
      grade[3]++;
    }
    else
    {
      grade[4]++;
    }
    p = p->nextstu;
  }
  cout << "A" << '\t' << "B" << '\t' << "C" << '\t' << "D" << '\t' << "E" << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << grade[i] << '\t';
  }
  cout << endl;
}




#endif //SSM_METHODS_H
