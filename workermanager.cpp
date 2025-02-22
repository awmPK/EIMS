#include "workermanager.h"

// 构造函数初始化
workermanager::workermanager(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // 1.如果文件不存在，通过ifs.is_open()判断
    if(!ifs.is_open()){
        cout << "文件不存在！" << endl;
        this->empNum = 0;
        this->worker = NULL;
        this->FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 2.文件存在，且为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        // 文件为空
        cout << "文件为空！" << endl;
        this->empNum = 0;
        this->worker = NULL;
        this->FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 3.文件里面有内容
    this->empNum = this->getNumber();
    // 文件标记为非空
    this->FileIsEmpty = false;
    // cout << "职工人数为：" << this->empNum << endl;
    // 开辟列表空间
    this->worker = new Worker*[this->empNum];
    // 往列表空间中存入文件中的数据
    this->initEmp();

    // // 测试显示
    // for(int i=0;i<this->empNum;i++){
    //     cout << "员工编号：" << this->worker[i]->id << endl;
    //     cout << "员工姓名：" << this->worker[i]->name << endl;
    //     cout << "员工职位：" << this->worker[i]->getDeptName() << endl;
    // }
}

// 实现展示菜单
void workermanager::showMenu(){
    cout << "*************************************" << endl;
    cout << "**********欢迎使用职工管理系统*******" << endl;
    cout << "************0.退出管理系统***********" << endl;
    cout << "************1.增加职工信息**********" << endl;
    cout << "************2.显示职工信息**********" << endl;
    cout << "************3.删除职工信息**********" << endl;
    cout << "************4.修改职工信息**********" << endl;
    cout << "************5.查找职工信息**********" << endl;
    cout << "************6.按照编号排序**********" << endl;
    cout << "************7.清空所有信息**********" << endl;
    cout << "************************************" << endl;
    cout << endl;

}

// 退出功能实现
void workermanager::exitSystem(){
    cout << "欢迎下次使用~" << endl;
    exit(0);
}
// 确定员工是否存在
int workermanager::isExist(int id){
    for(int i=0;i<this->empNum;i++){
        if(this->worker[i]->id == id){
            return id;
        }
    }
    return -1;
}
// 删除员工
void workermanager::delEmp(){
    int id;
    cout << "请输入离职员工的编号：" << endl;
    cin >> id;
    int index = this->isExist(id);
    if(index==-1){
        cout << "没有该员工信息！" << endl; 
        return;
    }
    Worker* worker = this->worker[index];
    for(int i=index;i<this->empNum-1;i++){
        this->worker[i] = this->worker[i+1];
    }
    this->empNum--;
    this->save();
    cout << "删除编号为:" << id << " 姓名为：" << worker->name << endl;
}
// 添加职工信息
void workermanager::addEmp(){
    int num;
    cout << "请输入添加职工数量：" << endl;
    cin >> num;
    if(num<0){
        cout << "请输入合法数字！";
    }else{
        int newNum = this->empNum + num;
        Worker** w = new Worker*[newNum];
        if(this->empNum != 0){
            for(int i = 0; i < this->empNum; i++){
                // 将原始数据转移到新创建的数组里面
                w[i] = this->worker[i];
            }
        }
        // 使用循环将需要录入的信息录入
        for(int i = 0; i<num;i++){
            int id;
            string name;
            int deptNum;
            Worker* worker = NULL;
            cout << "请输入第" << i+1 << "个职工的信息" << endl;
            cout << "职工编号：";
            cin >> id;
            // 该循环用于确保所输入的id没有重复
            while (1)
            {
                int flag = 1;
                for(int j = 0; j<this->empNum;j++){
                    if(id == w[j]->id){
                        cout << "编号已存在，请重新输入！" << endl;
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0){
                    cin >> id;
                }else{
                    break;
                } 
            }
            cout << "请输入职工姓名：" << endl;
            cin >> name;
            cout << "请输入职工类型，以下有三种类型：" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板\n请输入职工类型" << endl;
            int select;
            cin >> select;
            switch (select)
            {
            case 1:
                worker = new Employee(id,name,select);
                break;
            case 2:
                worker = new Manager(id,name,select);
                break;
            case 3:
                worker = new Boss(id,name,select);
                break;
            default:
                cout << "请输入正确数字！" << endl;
                break;
            }
            // 
            w[empNum + i] = worker;
        }
    
        // 使用delete[]释放动态分配的空间
        delete[] this->worker;
        this->worker = w;
        this->empNum = newNum;
        this->save();
        cout << "成功添加" << num << "名员工！" << endl;
    }
    
}

 // 存储员工信息
 void workermanager::save(){
    ofstream ofs;
    // 存入信息的时候清空文件内容
    ofs.open(FILENAME, ios::out);
    for(int i=0;i<this->empNum;i++){
        ofs << this->worker[i]->id << "  "
        << this->worker[i]->name << "  "
        << this->worker[i]->DeptId << endl;
    }
    ofs.close();
 }
// 获取员工数量
 int workermanager::getNumber(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int DeptId;
    int num = 0;
    while(ifs>>id && ifs>>name && ifs>>DeptId){
        num++;
    }
    return num;
 }
// 初始化人员列表
void workermanager::initEmp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int DeptId;
    int index = 0;
    while(ifs>>id && ifs>>name && ifs>>DeptId){
        Worker* worker = NULL;
        switch (DeptId)
        {
        case 1://普通职工
            worker = new Employee(id,name,DeptId);
            break;
        case 2://经理
            worker = new Manager(id,name,DeptId);
            break;
        case 3://老板
            worker = new Boss(id,name,DeptId);
            break;
        }
        this->worker[index] = worker;
        index++;

    }
    ifs.close();
}

// 
void workermanager::showEmp(){
    if(this->FileIsEmpty){
        cout << "没有人员信息！" << endl;
    }else{
        for(int i=0;i<this->empNum;i++){
            // 利用多态打印人员信息
            this->worker[i]->printInfo();
        }
    }
}
 workermanager::~workermanager(){
    // 在析构函数中释放内存
    delete [] this->worker;
    this->worker = NULL;
}