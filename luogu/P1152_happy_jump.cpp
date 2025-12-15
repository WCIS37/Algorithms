#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, flag = 1;
    cin >> n;
    int *arr = new int[n+5];
    int *num = new int[n+5]{0};
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++){
        num[i] = abs(arr[i] - arr[i+1]);
    }
    sort(num+1, num+n);
    for (int i = 1; i < n; i++){
        if (num[i] != i){
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    
}
