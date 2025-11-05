/*
设计算法讲一个带头节点的单链表A分解为两个具有相同结构的链表B,C。B为值小于0的节点，C为值大于0的节点。
（链表A的元素为非零整数，要求B，C表利用A的结点）
*/


#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}LNode,*LinkList;

void initLink(LinkList &L){
    L = new Node;
    L->next = NULL;
}

void createLink(LinkList &L){
    int n;
    LNode *q = L;
    cout << "请输入链表元素个数" << endl;
    cin >> n;
    cout << "请输入链表元素" << endl;
    for (int i = 0; i < n; i++){
        LNode *p = new Node;
        cin >> p->data;
        q->next = p;
        q = q->next;
    }
    q->next = NULL;
}

// 拆分链表
void splitLink(LinkList &L1, LinkList &L2, LinkList &L3){
    LNode *p1 = L1->next;
    LNode *q2 = L2;
    LNode *q3 = L3;

    while (p1 != NULL){ 
        if (p1->data < 0){
            q2->next = p1;
            q2 = q2->next;
            p1 = p1->next; 
        }else if(p1->data > 0){
            q3->next = p1;
            q3 = q3->next;
            p1 = p1->next;
        }else{
            p1 = p1->next;
        }

    }
    q2->next = NULL;
    q3->next = NULL;
}

void display(LinkList L){
    LNode *p = L->next;
    if (p == NULL){
        cout << "链表为空" << endl;
        return;
    }

    while (p->next != NULL){
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << p->data << endl;
}

int main(){
    LinkList L1;
    LinkList L2;
    LinkList L3;
    initLink(L1);
    initLink(L2);
    initLink(L3);
    createLink(L1);
    splitLink(L1,L2,L3);
    display(L2);
    display(L3);
}
