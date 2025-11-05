/* 
已知长度为n的线性表A采用顺序存储结构。请设计一个时间复杂度为O(n)，空间复杂度为O(1)的算法，
可删除线性表中所有值为item的值
*/

#include <iostream>
using namespace std;

#define MAXSIZE 1000

typedef struct {
	int data[MAXSIZE];
	int length;
}SeqList;

void initArr(SeqList* &arr){
	arr = new SeqList;
	arr->length = 0;
}

void inputArr(SeqList* &arr){
	int n;
	cout << "请输入线性表的长度" << endl;
	cin >> n;
	cout << "请依次输入线性表元素" << endl;
	for (int i = 0; i < n; i++){
		cin >> arr->data[i];
	}
	arr->length = n;
}

void deleteArr(SeqList* &arr){
	int item, count = 0;
	cout << "请输入要删除的元素" << endl;
	cin >> item;
	for (int i = 0, j = 0; i < arr->length; i++){
		if (arr->data[i] != item){
			arr->data[j] = arr->data[i];
			++j;
		}else{
			++count;
		}
	}
	if (count == 0){
		cout << "线性表中没有该元素" << endl;
		return;
	}else{
		arr->length -= count;
	}
}

void display(SeqList *arr){
	if (arr->length == 0){
		cout << "线性表为空";
		return;
	}
	cout << "[";
	int i = 0;
	while (i != arr->length-1){
		cout << arr->data[i]  << ",";
		i++;
	}
	cout << arr->data[i] << "]" << endl;
}

int main(){
	SeqList *arr;
	initArr(arr);
	inputArr(arr);
	deleteArr(arr);
	display(arr);
}
