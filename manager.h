#include "worker.h"

class Manager : public Worker{
    public:
        Manager(int id, string name, int DeptId);
        // 重写基类方法，显示员工信息
        void printInfo();
        // 重写基类方法，显示员工职位
        string getDeptName();
};