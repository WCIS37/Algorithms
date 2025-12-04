#include <iostream>
#include <cctype>
using namespace std;

#define MAXSIZE 1000

typedef struct{
	char data[MAXSIZE];
	int top;
}SqStack;

typedef struct {
    int data[MAXSIZE];
    int top;
} NumStack;

void initStack(SqStack *s){
	s->top = -1;
}

void initNumStack(NumStack *s) {
    s->top = -1;
}

bool isEmpty(SqStack *s) {
    return s->top == -1;
}

bool isNumEmpty(NumStack *s) {
    return s->top == -1;
}


char getTop(SqStack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

void Push(SqStack *s,char value){
	if(s->top == MAXSIZE - 1){
		cout << "栈满了，吃不下了"; 
		return ;
	}
	s->top++;
	s->data[s->top] = value;
}

void pushNum(NumStack *s, int value) {
    if (s->top == MAXSIZE - 1) {
        cout << "栈满了，吃不下了";
        return;
    }
    s->top++;
    s->data[s->top] = value;
}

char Pop(SqStack *s){
	if(isEmpty(s)){
		cout << "栈空了，吐不出来了";
		return '\0';
	}
	char value = s->data[s->top];
	s->top--;
	return value;
}

int popNum(NumStack *s) {
    if (isNumEmpty(s)) {
        cout << "栈空了，吐不出来了";
        return 0;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

int compareOperator(char c){
	switch(c) {
        case '+':
        case '-': 
			return 1;
        case '*':
        case '/': 
			return 2;
        default: 
			return 0;
    }
}

void tranToExpression(SqStack *s, char * arr, char *toArr){
	
	int i = 0;
	int j = 0;
	while (arr[i] != '#' && arr[i] != '\0'){
		if (isdigit(arr[i])) {
            while (isdigit(arr[i])) {
                toArr[j++] = arr[i++];
            }
            toArr[j++] = ' ';
        }
		else{
		switch (arr[i]){
			case '+':
			case '-':
			case '*':
			case '/':
			{
				if (!isEmpty(s) && getTop(s) != '(' && (compareOperator(s->data[s->top]) >= compareOperator(arr[i]))){
					toArr[j++] = Pop(s);
					toArr[j++] = ' ';
				}
				Push(s,arr[i]);
				++i;
				break;
			}
			case '(':
				Push(s,'(');
				++i;
				break;
			case ')':
			{
				while (!isEmpty(s) && getTop(s) != '('){
					toArr[j++] = Pop(s);
					toArr[j++] = ' ';
				}
				if (!isEmpty(s) && getTop(s) == '('){
					Pop(s);
				}
				++i;
				break;
			}
		default:
			++i;
			break;
		}
	}
	}
	while (!isEmpty(s)) {
        toArr[j++] = Pop(s);
        toArr[j++] = ' ';
    }
	if (j > 0 && toArr[j-1] == ' ') {
		j--;
	}
	toArr[j] = '\0';
}

void calculate(NumStack *n, char *toArr){
	int i = 0;
	int num1,num2,all;
	if(n->top == MAXSIZE - 1){
		cout << "栈满了，吃不下了"; 
		return ;
	}
	
	while (toArr[i] != '\0')
	{
		if (isdigit(toArr[i])) {
			int num = 0;
			while (isdigit(toArr[i])) {
				num = num * 10 + (toArr[i] - '0');
				++i;
			}
			pushNum(n, num);
			continue;
		}

		switch (toArr[i]){
			case '+':
				num1 = popNum(n);
				num2 = popNum(n);
				all = num1 + num2;
				pushNum(n,all);
				++i;
				break;
			case '-':
				num1 = popNum(n);
				num2 = popNum(n);
				all = num2 - num1;
				pushNum(n,all);
				++i;
				break;
			case '*':
				num1 = popNum(n);
				num2 = popNum(n);
				all = num2 * num1;
				pushNum(n,all);
				++i;
				break;
			case '/':
				num1 = popNum(n);
				num2 = popNum(n);
				if (num1 != 0){
					all = num2 / num1;
				}else{
					cout << "除0犯规";
					return ;
				}
				pushNum(n,all);
				++i;
				break;
		default:
				++i;
				continue;

		}
		
	}
	if (!isNumEmpty(n)){
		int e = popNum(n);
		cout << e;
	}else{
		cout << "栈空了呀！";
	}
	
}

int main(){
	SqStack s;
	initStack(&s);
	NumStack n;
    initNumStack(&n);
	char arr[MAXSIZE]{'0'};
	char toArr[MAXSIZE]{'0'};

	int i = 0;
	cout << "请输入一个简单表达式，以#结尾" << endl;
    char ch;
    while (cin.get(ch) && ch != '#') {
        if (ch != '\n') {
            arr[i++] = ch;
        }
    }
    arr[i] = '\0';

	tranToExpression(&s,arr,toArr);
	calculate(&n,toArr);
	
	
}