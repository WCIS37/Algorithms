#include<iostream>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR 0

typedef int Status; 
typedef int ElemType;

#define MAXSIZE 100			

typedef struct {
	ElemType *elem;
	int length;
} SqList;

Status InitList_Sq(SqList &L) { 
	L.elem = new ElemType[MAXSIZE];
	L.length = 0;
	return OK;
}

Status GetElem(SqList L, int i, ElemType &e) {
	if (i <= 0 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int LocateElem_Sq(SqList L, int e) { 
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == e)
			return i+1;
	}
	return ERROR;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) { 
	if (i < 1 || i > (L.length+1) || L.length >= MAXSIZE)
		return ERROR;
	for (int j = L.length; j >= i; j--){
		L.elem[j] = L.elem[j-1];
	}
	L.elem[i-1] = e;
	++L.length;
	return OK;

}

Status ListDelete_Sq(SqList &L, int i) { 
	if (i < 1 || i > L.length)
		return ERROR;
	for(int j = i; j < L.length; j++){
		L.elem[j-1] = L.elem[j];
	}
	L.length -= 1; 
	return OK;
}

int main() {
	SqList L;
	int i = 0, temp, a, c, choose;
	ElemType e;
	
	cout << "1. 初始化\n";
	cout << "2. 输入\n";
	cout << "3. 取值\n";
	cout << "4. 查找\n";
	cout << "5. 插入\n";
	cout << "6. 删除\n";
	cout << "7. 输出\n";
	cout << "0. 退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1:
			if (InitList_Sq(L))
				cout << "成功初始化顺序表"<<endl;
			else
				cout << "顺序表初始化失败"<<endl;
			break;
		case 2: 
			int n,i;
			cout<<"请输入元素个数:"<<endl;
			cin>>n;
			cout<<"请输入"<<n<<"个元素"<<endl;
			for(i=0;i<=n-1;i++)
			{
				cin>>L.elem[i];
				L.length++;
			}
		
			break;
		case 3:
			cout << "请输入一个位置用来取值：\n";
			cin >> i;
			temp = GetElem(L, i, e);
			if (temp != 0) {
				cout << "取值成功，值为："<<endl;
				cout << e << endl;
			} else
				cout << "查找失败！位置超出范围"<<endl;
			break;
		case 4: 
			cout << "请输入所要查找的元素值:";
			cin >> e;
			temp = LocateElem_Sq(L, e);
			if (temp != 0) {
				cout << "查找成功\n";
				cout << temp<<endl;
			}
			else
				cout << "查找失败！\n";
			break;
		case 5: 
			cout << "请输入插入位置";
			cin >> a;
			cout << "请输入要插入的元素";
			cin >> e;
			if (ListInsert_Sq(L, a, e))
				cout << "插入成功.\n\n";
			else
				cout << "插入失败.\n\n";
			break;
		case 6: 
			cout << "请输入所要删除的元素的位置:";
			cin >> c;
			if (ListDelete_Sq(L, c))
				cout << "删除成功.\n\n";
			else
				cout << "删除失败.\n\n";
			break;
		case 7: 
			cout << "当前的线性表为：";
			for (i = 0; i < L.length; i++)
				cout<<setw(5)<<L.elem[i];
			cout<<endl;
		
			break;
		}
	}
	return 0;
}