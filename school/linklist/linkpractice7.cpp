/*
设计算法，将链表中所有节点的链接方向"原地"旋转，即要求仅利用原表的存储空间，换句话说，要求算法的空间复杂的为O(1)
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

// 逆转链表
void reverse(LinkList &L){
    if (L->next == NULL){
        cout << "链表为空" << endl;
        return;
    }

    LNode *p = L->next->next;
    LNode *q = L->next;
    
    L->next = NULL;
    do{
        q->next = L->next;
        L->next = q;
        q = p;
        if(p == NULL){}
        else{
            p = p->next;
        }
    } while (q != NULL);
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
    reverse(L);
    display(L);
}