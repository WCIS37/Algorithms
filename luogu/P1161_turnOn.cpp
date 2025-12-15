#include <bits/stdc++.h>
using namespace std;

int arr[2000001];
int main(){
    double a;
    int t, n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> t;
        for (int j = 1; j <= t; j++){
            int num = (int)(j * a);
            arr[num] ^= 1;  // 异或等于切换状态，(1变成0,0变成1)
        }
    }
    for (int i = 1;; i++){
        if (arr[i] == 1){
            cout << i;
            break;
        }
    }

}
