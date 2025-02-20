#include "workermanager.h"

int main(){
    
    int select = 0;
    while (1){
        workermanager wm;
        wm.showMenu();
        cout << "请输入需要的功能" << endl;
        cin >> select;
        switch (select)
        {
        case 0:
            wm.exitSystem();
            break;
        case 1://增加信息
            wm.addEmp();
            break;
        case 2://显示信息
            wm.showEmp();
            break;
        case 3://删除职工信息
            wm.delEmp();
            break;
        case 4://修改职工信息
            cout << "功能待扩充！" << endl;
            break;
        case 5://查找职工信息
            cout << "功能待扩充！" << endl;
            break;
        case 6://按编号排序
            cout << "功能待扩充！" << endl;
            break;
        case 7://清空所有信息
            cout << "功能待扩充！" << endl;
            break;
        default:
            cout << "请输入0-7数字" << endl;
            break;
        }
    }
    return 0;
}