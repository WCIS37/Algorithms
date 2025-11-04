/*
将两个递增有序链表合并为一个递增有序链表，结果链表仍使用原来两表的存储空间，表中不允许有重复数据。
*/

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

void InputList(LinkList &L){
    int n;
    LNode *q = L;
    cout << "请输入元素个数:" << endl;
    cin >> n;
    cout << "请输入链表元素" << endl;
    for (int i = 0; i < n; i++){
        LNode *p = new LNode;
        cin >> p->data;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    
}

void sortList(LinkList &L1, LinkList &L2) {
    LNode *p1 = L1;
    LNode *p2 = L2->next;
    LNode *temp;
    if (L1->next == NULL || L2->next == NULL){
        cout << "有链表为空";
        return;
    }

    while (p1->next != NULL && p2 != NULL) {
        if (p1->next->data < p2->data) {
            p1 = p1->next;
        }
        else if (p1->next->data == p2->data) {
            p2 = p2->next;
        }
        else {
            temp = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p2 = temp;
        }
    }

    if (p2 != NULL) {
        p1->next = p2;
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
    InputList(L1);
    InputList(L2);
    sortList(L1,L2);
    display(L1);
    return 0;
}
