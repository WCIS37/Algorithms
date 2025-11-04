/*
已知两个链表A和B分别表示两个集合，其元素递增排列。设法求出两个集合A和B的差集（仅在A中出现而不在B中出现的元素所构成的集合），
并将结果以同样形式存储，同时返回该集合的元素个数
*/


#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}LNode,*LinkList;

void initList(LinkList &L){
    L = new Node;
    L->next = NULL;
}

void create(LinkList &L){
    int n;
    LNode *q = L;
    cout << "输入链表元素个数" << endl;
    cin >> n;
    cout << "输入链表元素" << endl;
    for (int i = 0; i < n; i++){
        Node *p = new Node;
        cin >> p->data;
        q->next = p;
        q = p;
    }
    q->next = NULL;
}

// 求差集
int linkException(LinkList &L1,LinkList &L2){
    int count = 0;
    LNode *p1 = L1->next;
    LNode *q1 = L1;
    LNode *p2 = L2->next;

    if (L1->next == NULL || L2->next == NULL){
        cout << "有链表为空";
        return;
    }

    L1->next = NULL;
    while (p1 != NULL && p2 != NULL){
        if (p1->data < p2->data){
            q1->next = p1;
            q1 = q1->next;
            p1 = p1->next;
            q1->next = NULL;
            ++count;
        }else if(p1->data == p2->data){
            p1 = p1->next;
            p2 = p2->next;
        }else{
            p2 = p2->next;
        }
    }
    return count;
}

void display(LinkList L){
    LNode *p = L->next;
    if (p == NULL){
        return;
    }
    while (p->next != NULL){
        cout << p->data << "->";
        p = p->next;
    }
    cout << p->data << endl;
}

int main(){
    LinkList L1;
    LinkList L2;
    initList(L1);
    create(L1);
    initList(L2);
    create(L2);
    int count = linkException(L1,L2);
    display(L1);
    cout << "元素个数为：" << count;
}