/*
已知两个链表A和B分别表示两个集合，其元素递增排列。请设计一个算法用于求出A和B的交集，并将结果放在A中
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
    Node *q = L;
    cout << "输入链表元素个数" << endl;
    cin >> n;
    cout << "输入链表元素" << endl;
    for (int i = 0; i < n; i++){
        Node* p = new Node;
        cin >> p->data;
        q->next = p;
        q = p;
    }
    q->next = NULL;
}

// 求交集
void Intersection(LinkList &L1, LinkList &L2){
    LNode *q1 = L1;
    LNode *p1 = L1->next;
    LNode *p2 = L2->next;
    bool flag = true;

    if (L1->next == NULL || L2->next == NULL){
        cout << "有链表为空";
        return;
    }

    L1->next = NULL;
    while (p1 != NULL && p2 != NULL){
        if (p1->data > p2->data){
            p2 = p2->next;
        }else if (p1->data < p2->data){
            p1 = p1->next;
        }
        else{
            q1->next = p1;
            q1 = q1->next;
            p1 = p1->next;  // 必须写在q1->next = NULL前面，不然L1链就会断
            p2 = p2->next;
            q1->next = NULL;
            flag = false;
        }
    }
    if (flag){
        cout << "链表没有交集" << endl;
        return;
    }
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
    cout << p->data;
}

int main(){
    LinkList L1;
    LinkList L2;
    initList(L1);
    create(L1);
    initList(L2);
    create(L2);
    Intersection(L1,L2);
    display(L1);
}