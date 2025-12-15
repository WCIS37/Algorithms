#include <iostream>
using namespace std;

typedef struct BiTNode{
    char data;
    struct BiTNode *left, *right;
}BiTNode, *BiTree;

void createBiTree(BiTree &T){
    char ch;
    cin >> ch;
    if (ch == '#'){
        T = NULL;
        return;
    }
    else {
        T = new BiTNode;
        T->data = ch;
        createBiTree(T->left);
        createBiTree(T->right);
    }
}

bool isEmpty(BiTree T){
    if (T == NULL)
        return 1;
    else
        return 0;
}

// 先序
void preorderTraversal(BiTree T){
    if (isEmpty(T)){
        return;
    }
    else {
        cout << T->data << " ";
        preorderTraversal(T->left);
        preorderTraversal(T->right);
    }
}

// 中序
void inorderTraversal(BiTree T){
    if (isEmpty(T)){
        return;
    }
    else {
        inorderTraversal(T->left);
        cout << T->data << " ";
        inorderTraversal(T->right);
    }
}

// 后序
void postorderTraversal(BiTree T){
    if (isEmpty(T)){
        return;
    }
    else {
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        cout << T->data << " ";
    }
}


// 求结点总数
int NodeCount(BiTree T){
    if (isEmpty(T)){
        return 0;
    }
    else {
        return NodeCount(T->left) + NodeCount(T->right) + 1;
    }
}

// 求叶子节点总数
int LeafCount(BiTree T){
    if (isEmpty(T)){
        return 0;
    }
    else if (T->left == NULL && T->right == NULL){
        return 1;
    }
    else{
        return LeafCount(T->left) + LeafCount(T->right);
    }
    
}

// 求二叉树深度(从最底层比较自己的左子树和右子树的深度，并将较大值加1并传给自己的父节点)
int Depth(BiTree T){
    int m,n;
    if (isEmpty(T))
    return 0;
    else{
        m = Depth(T->left);
        n = Depth(T->right);
        if (m>n)
        return(m+1);
        else
        return(n+1);
    }
    
}

// 链队的创建
typedef struct QNode {
    BiTree data;
    struct QNode *next;
} QNode;

typedef struct
{
    struct QNode *front;
    struct QNode *rear;
}Queue;


// 初始化队列
void initQueue(Queue &Q){
    Q.front = Q.rear = NULL;
}

// 判空
bool isEmptyQueue(Queue Q){
    return Q.front == NULL;
}

// 进队
void inQueue(Queue &Q, BiTree node){
    QNode *newNode = new QNode; 
    newNode->data = node;
    newNode->next = NULL;
    if (isEmptyQueue(Q)){
        Q.front = Q.rear = newNode;
    }
    else{
        Q.rear->next = newNode;
        Q.rear = newNode;
    }    
}

// 出队
BiTree outQueue(Queue &Q){
    if (isEmptyQueue(Q))
        return NULL;
    QNode *temp = Q.front;
    BiTree node = Q.front->data;
    Q.front = Q.front->next;
    if (Q.front == NULL){
        Q.rear = NULL;
    }
    delete temp;
    return node;
}

//层次遍历
void levelorderTraversal(BiTree T){
    if (T == NULL)
        return;
    Queue Q;
    initQueue(Q);
    inQueue(Q,T);
    while (!isEmptyQueue(Q)){
        BiTree node;
        node = outQueue(Q);
        cout << node->data << " ";
        if (node->left != NULL){
            inQueue(Q,node->left);
        }
        if (node->right != NULL){
            inQueue(Q,node->right);
        }
    }   
}

int main(){
    BiTree T;
    cout << "请按先序顺序依次输入节点" << endl;
    createBiTree(T);
    cout << "先序遍历：";
    preorderTraversal(T);
    cout << endl;
    cout << "中序遍历：";
    inorderTraversal(T);
    cout << endl;
    cout << "后序遍历：";
    postorderTraversal(T);
    cout << endl;
    cout << "层次遍历：";
    levelorderTraversal(T);
    cout << endl;

    cout << "总结点个数：";
    cout << NodeCount(T) << endl;
    cout << "叶子结点个数：";
    cout << LeafCount(T) << endl;
    cout << "二叉树深度：";
    cout << Depth(T) << endl;
    delete T;
}


