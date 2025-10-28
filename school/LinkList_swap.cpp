#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}LNode,*LinkList;
 
void initList(LinkList &L){
    L = new LNode;
    L->next = NULL;
    
}

// 前插法
void createListUp(LinkList &L){
    int n;
    cout << "请输入元素个数:" << endl;
    cin >> n;
    cout << "请输入链表元素" << endl;
    for (int i = 0; i < n; i++){
        LNode *p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

//后插法
void createListDown(LinkList &L){
    int n;
    LNode *q = L;
    cout << "请输入元素个数:" << endl;
    cin >> n;
    cout << "请输入链表元素" << endl;
    for (int i = 0; i < n; i++){
        LNode *p = new LNode;
        cin >> p->data;
        if (L->next == NULL){
            L->next = p;
        }
        q->next = p;
        q = p;
    }
    q->next = NULL;
}

// 逆置数组
void reverse(LinkList &L){
    LNode *q = L->next;
    L->next = NULL;
    LNode *p;
    while(q){
        p = q->next;
        q->next = L->next;
        L->next = q;
        q = p;
    }
}

void display(LinkList L){
    LNode* p = L->next;
    while(p->next){
        cout << p->data << "->";
        p = p->next;
    }
    cout << p->data << endl;
}

int main(){
    LinkList L;
    initList(L);

    cout << "选择你想要的链表插入方法" << endl;
    cout << "1.前插法" << endl;
    cout << "2.后插法" << endl;
    char c;
    cin >> c;
    switch (c){
    case '1':
        createListUp(L);    //前插法
        break;
    case '2':
        createListDown(L);  //后插法
        break;
    default:
        cout << "请输入正确编号" << endl;
        return 0;
    }

    cout << "逆置前的链表: ";
    display(L);
    reverse(L);
    cout << "逆置后的链表: ";
    display(L);
    return 0;

}

