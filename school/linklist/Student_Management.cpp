// 使用单链表完成一个简单的学生管理系统
#include <iostream>
#include <cstring>
using namespace std;

// 定义学生信息
typedef struct {
    int no;
    char name[50];
    char sex;
    int age;
}Student;

// 创建链表
typedef struct Node{
    Student stu;
    struct Node *next;
}LNode, *LinkList;

// 初始化链表
void initList(LinkList &L){
    L = new LNode;
    L->next = NULL;
}

// 尾插法输入学生信息
void inputStudent(LinkList &L){
    int n;
    LNode *q = L;
    cout << "请输入添加的学生个数" << endl;
    cin >> n;
    cout << "请依次输入学生的学号，姓名，性别(w/m)，年龄（注意第二次选择输入功能会覆盖第一次的输入）" << endl;
    for (int i = 0; i < n; i++){
        LNode *p = new LNode;
        cin >> p->stu.no >> p->stu.name >> p->stu.sex >> p->stu.age;
        p->next = NULL;
        q->next = p;
        q = p;
    }
}

bool isEmpty(LinkList L){
    if (L->next == NULL){
        return 1;
    }
    return 0;
}

// 查找学生信息
void searchStudent(LinkList L, char name[]){
    LNode *q = L->next;
    while (q){
        if (strcmp(q->stu.name,name) == 0){
            cout << "学号：" << q->stu.no << endl;
            cout << "姓名：" << q->stu.name << endl;
            cout << "性别(w/m)：" << q->stu.sex << endl;
            cout << "年龄：" << q->stu.age << endl;
        }
        q = q->next;
    }
}

// 显示所有学生信息
void allStudent(LinkList L){
    LNode *q = L->next;
    while (q){
        cout << "学号：" << q->stu.no << endl;
        cout << "姓名：" << q->stu.name << endl;
        cout << "性别(w/m)：" << q->stu.sex << endl;
        cout << "年龄：" << q->stu.age << endl;
        cout << endl;
        q = q->next;
    }
}

// 显示记录的学生人数
void numberStudent(LinkList L){
    LNode *q = L->next;
    int count = 0;
    while (q){
        q = q->next;
        count += 1;
    }
    cout << count << endl;
}

// 添加学生信息
void addStudent(LinkList &L){
    LNode *q = L;
    LNode *p = new LNode;
    cout << "请依次输入添加学生的学号，姓名，性别(w/m)，年龄" << endl;
    cin >> p->stu.no >> p->stu.name >> p->stu.sex >> p->stu.age;
    while (q->next){
        q = q->next;
    }
    q->next = p;
    p->next = NULL;
}

// 删除指定学号学生信息
void deleteStudent(LinkList &L,int id){
    LNode *q = L;
    LNode *p = L->next;
    while (p->stu.no != id && p){
        q = p;
        p = p->next;
    }
    LNode *temp = p;
    p = p->next;
    q->next = p;
    temp->next = NULL;
    delete temp;
}

int main(){
    LinkList L;
    initList(L);
    int choice = -1;
    do{

        cout << "1. 输入学生信息" << endl;
        cout << "2. 根据姓名查找学生" << endl;
        cout << "3. 显示所有学生信息" << endl;
        cout << "4. 显示所有学生个数" << endl;
        cout << "5. 添加学生" << endl;
        cout << "6. 删除学生" << endl;
        cout << "0. 退出" << endl;
        cout << "输入选择: ";
        cin >> choice;

        switch (choice){
            case 1:
                inputStudent(L);
                break;
            case 2:
                if (isEmpty(L)){
                    cout << "没有学生信息" << endl;
                    break;
                }
                char name[50];
                cout << "请输入查找姓名";
                cin >> name;
                searchStudent(L,name);
                break;
            case 3:
                if (isEmpty(L)){
                    cout << "没有学生信息" << endl;
                    break;
                }
                allStudent(L);
                break;
            case 4:
                if (isEmpty(L)){
                    cout << "没有学生信息" << endl;
                    break;
                }
                numberStudent(L);
                break; 
            case 5:
                addStudent(L);
                break;
            case 6:
                if (isEmpty(L)){
                    cout << "没有学生信息" << endl;
                    break;
                }
                int did;
                cout << "请输入删除的学号";
                cin >> did;
                deleteStudent(L,did);
                break;
            case 0:
                break;
            default:
                break;
        }

        if (choice != 0) {
            cout << "按回车继续..." << endl;
            cin.ignore();
            cin.get();
        }
    } while (choice != 0);
}