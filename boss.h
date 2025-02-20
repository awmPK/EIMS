#pragma once
#include "worker.h"

class Boss : public Worker{
    public:
        Boss(int id, string name, int DeptId);
        // 重写基类方法，显示员工信息
        void printInfo();
        // 重写基类方法，显示员工职位
        string getDeptName();
};