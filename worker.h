/**
 * 职工抽象类，用于定义关于职工的操作抽象函数
 */
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker{
public:
    // 显示员工信息,纯虚函数，用于实现多态
    virtual void printInfo() = 0;
    // 显示员工职位
    virtual string getDeptName() = 0;
    int id;
    string name;
    int DeptId;

};
