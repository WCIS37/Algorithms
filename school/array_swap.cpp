//24.2 崔栋翔
//逆置数组源码
#include <iostream>
using namespace std;

//置换函数 
void SWAP(int *start, int *end){
	while(start < end){
		int temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main(){
	int n, m;
	cout << "数组大小:";
	cin >> n;
	cout << "写入数组内容:"; 
	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> *(a+i);
	}
	
	cout << "请输入m，把前m个数和后n-m个数进行置换:";
	cin  >> m;
	
	int *start = a, *end = a+n-1;
	SWAP(start, end);
	
	start = a, end = (a+n-m-1);
	SWAP(start, end);
	
	start = a+n-m, end = a+n-1;
	SWAP(start, end);
	
	for(int i = 0; i < n; i++){
		cout << *(a+i);
	}
	
}
