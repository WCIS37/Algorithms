#include <iostream>
using namespace std;

int intPartition(int a, int k, int &flag){
    int sub1 = a / 100;
    int sub2 = (a / 10) % 1000;
    int sub3 = a % 1000;
    if ((sub1 % k == 0) && (sub2 % k == 0) && (sub3 % k == 0)){
        flag = 0;
        return a;
    }
    return 0;
}

int main(){
    int k, flag = 1;
    int count = 0;
    cin >> k;
    for (int i = 10000; i < 30001; i++){
        count = intPartition(i,k,flag);
        if (count){
            cout << count << endl;
        }
    }
    if (flag){
        cout << "No";
    }
    
    
}