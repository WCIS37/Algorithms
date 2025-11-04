/*
设计算法，删除递增有序链表中值大于mink且小于maxk的所有元素(mink和maxk是给定的两个数，其值可以和表中元素相同，也可以不同)
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
    cout << "输入链表的元素个数" << endl;
    cin >> n;
    cout << "输入链表的元素" << endl;
    for (int i = 0; i < n; i++){
        LNode *p = new Node;
        cin >> p->data;
        q->next = p;
        q = q->next;
    }
    q->next = NULL;
}

// 删除链表特定值区间
void deleteLink(LinkList &L){
    int maxk, mink;
    cout << "请依次输入删除区间的 最小值 和 最大值" << endl;
    cin >> mink >> maxk;
    LNode *p = L->next;
    LNode *q = L;
    while (p != NULL){
        if (p->data > mink && p->data < maxk){
            q->next = p->next;
            delete p;
            p = q->next;
        }else{
            q = p;
            p = p->next;
        }
    }
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
    cout << p->data;
}

int main(){
    LinkList L;
    initLink(L);
    createLink(L);
    deleteLink(L);
    display(L);
}