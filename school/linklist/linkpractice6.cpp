/*
设计算法，通过一趟遍历确定长度为n的单链表中值最大的结点
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

int linkMaxValue(LinkList &L){
    LNode *p = L->next;

    if (p == NULL){
        return 0;
    }

    int maxlink = p->data;
    while (p->next != NULL){
        if (maxlink < p->next->data){
            maxlink = p->next->data;
            p = p->next;
        }else{
            p = p->next;
        }
    }
    if (maxlink < p->data){
        maxlink = p->data;
    }
    return maxlink;
}

int main(){
    LinkList L;
    int maxvalue;
    initLink(L);
    createLink(L);
    maxvalue = linkMaxValue(L);
    if (maxvalue == 0){
        cout << "链表为空";
    }else{
        cout << maxvalue;
    }
}