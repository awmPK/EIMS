#include "manager.h"

Manager::Manager(int id, string name, int DeptId){
    this->id = id;
    this->name = name;
    this->DeptId = DeptId;
}

void Manager::printInfo(){
    cout << "职工编号：" << id;
    cout << "\t\t职工姓名：" << name;
    cout << "\t\t职工岗位：" << getDeptName();
    cout << "\t\t岗位职责：完成老板交给的任务，同时给员工下发任务！" << endl;
}

string Manager::getDeptName(){
    return "经理";
}