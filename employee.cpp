#include "employee.h"

Employee::Employee(int id, string name, int DeptId){
    this->id = id;
    this->name = name;
    this->DeptId = DeptId;
}

void Employee::printInfo(){
    cout << "职工编号：" << id;
    cout << "\t\t职工姓名：" << name;
    cout << "\t\t职工岗位：" << getDeptName();
    cout << "\t\t岗位职责：完成经理交给的任务！" << endl;
}

string Employee::getDeptName(){
    return "员工";
}