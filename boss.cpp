#include "boss.h"

Boss::Boss(int id, string name, int DeptId){
    this->id = id;
    this->name = name;
    this->DeptId = DeptId;
}

void Boss::printInfo(){
    cout << "职工编号：" << id;
    cout << "\t\t职工姓名：" << name;
    cout << "\t\t职工岗位：" << getDeptName();
    cout << "\t\t岗位职责：给经理分发任务！" << endl;
}

string Boss::getDeptName(){
    return "老板";
}