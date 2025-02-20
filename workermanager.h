/**
 * 管理系统类，用于定义管理系统管理相关的类
 */
// 防止该文件中被一个程序多次引用
#pragma once
#include <iostream>
#include <string>
#include <fstream>
// 定义宏，用于指定文件路径
#define FILENAME "empFile.txt"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
class workermanager
{
public:
    workermanager();
    // 展示菜单
    void showMenu();
    // 退出
    void exitSystem();
    // 增加员工
    void addEmp();
    // 存储员工信息
    void save();
    // 获取员工人数
    int getNumber();
    // 初始化人员列表
    void initEmp();
    // 显示职工
    void showEmp();
    // 删除员工
    void delEmp();
    // 确定员工是否存在，若存在则返回下标，若不存在则返回-1
    int isExist(int id);
    ~workermanager();

    // 文件是否为空
    bool FileIsEmpty;
    // 职工人员数量
    int empNum;
    // 存放职工人员基类指针的数组
    Worker** worker;
};

