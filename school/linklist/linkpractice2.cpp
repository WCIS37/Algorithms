/*
将两个非递减的有序链表合并为一个非递增的有序链表。结果链表仍使用原来两表的存储空间，表中允许有重复数据。
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

// 头插法使非递减输入变成非递增链表
void createList(LinkList &L){
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

void sortList(LinkList &L1, LinkList &L2) {
    LNode *p1 = L1->next;
    LNode *q1 = L1;
    LNode *p2 = L2->next;
    LNode *temp;
    if (L1->next == NULL || L2->next == NULL){
        cout << "有链表为空";
        return;
    }

    do {
        if (p1->data <= p2->data){
            temp = p2->next;
            p2->next = p1;
            q1->next = p2;
            p2 = temp;
            q1 = q1->next;
        }else{
            q1 = p1;
            p1 = p1->next;
        }
    }while (p1 != NULL && p2 != NULL);
    if (p2 != NULL){
        q1->next = p2;
    }
}

void display(LinkList L){
    LNode *p = L->next;
    if (p == NULL){;
        return;
    }
    while (p->next != NULL){
        cout << p->data << "->";
        p = p->next;
    }
    cout << p->data << endl;
}


int main(){
    LinkList L1,L2;
    initList(L1);
    initList(L2);
    createList(L1);
    createList(L2);
    sortList(L1,L2);
    display(L1);
    return 0;
}