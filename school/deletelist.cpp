//24.2崔栋翔
// 方法二和方法一的第二种实现，其方法调用在main函数中被注释掉了，可以自行切换调用

#include <iostream>
using namespace std;

typedef struct {
    int *data;
    int length;
}SQList;

// 初始化
void initList(SQList &L, int n){
    L.data = new int[n];
    L.length = 0;
    cout << "请输入顺序表的元素: ";
	for (int i = 0; i < n; i++){
	    cin >> L.data[i];
	    L.length++;
	}
}

// 打印顺序表 
void display(SQList L){
	for (int i = 0; i < L.length; i++){
	    cout << L.data[i] << " ";
	}
}

// 方法一第一种实现：索引计算：计算删除的元素的个数来计算顺序表移动的索引
void listDeleteOne(SQList &L, int x, int &count){
    for (int i = 0; i < L.length; i++){
        if(L.data[i] == x){
            L.data[i-count] = L.data[i+1];
            ++count;
        }else if(count != 0){
            L.data[i-(count-1)] = L.data[i+1];
        }
    }
    L.length -= count; 
}

// 方法一第二种实现：索引计算：判断到非删除的元素时前移 
void listDeleteThree(SQList &L, int x, int &count){
	for(int i = 0; i < L.length; i++){
		if(L.data[i] == x){
			++count;
		}else{
			L.data[i-count] = L.data[i];
		}
	}
	L.length -= count; 
} 

// 方法二：直接覆盖：碰到要删除的数x，直接在原顺序表上进行覆盖
void listDeleteTwo(SQList &L,int x, int &count){
    for (int i = 0; i < L.length; i++){
        if(L.data[i] == x){
            continue;
        }else{
            L.data[count] = L.data[i];
            ++count;
        }
    }
    L.length = count;
}

// 主函数 
int main(){
    int n;
    cout << "请输入顺序表的长度: ";
    cin >> n;
    SQList L;
    initList(L, n);
    int x;
    cout << "请输入一个你要删除的数: ";
    cin >> x;
    if(x < 0 || x > 100){
        cout << "输入错误" << endl;
        return 0;
    }


// //调用方法一(1)
//    int count = 0;
//    listDeleteOne(L, x, count);
//    if (count == 0){
//        cout << "没有找到删除的元素" << endl;
//        return 0;
//    }else{
//        cout << "使用方法一删除后的顺序表为: " << endl;
//        display(L);
//    }


// 调用方法一(2)
	int count = 0;
	listDeleteThree(L, x, count);
	if (count == 0){
	    cout << "\n没有找到删除的元素" << endl;
	    return 0;
	}else{
	    cout << "\n使用方法三删除后的顺序表为: " << endl;
	    display(L);
	}


// // 调用方法二
//     int count = 0;
//     listDeleteTwo(L, x, count);
//     if (count == n){
//         cout << "\n没有找到删除的元素" << endl;
//         return 0;
//     }else{
//         cout << "\n使用方法二删除后的顺序表为: " << endl;
//         display(L);
//     }
	

    delete[] L.data;
    L.length = 0;

}
