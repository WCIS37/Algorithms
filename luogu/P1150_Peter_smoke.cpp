#include <iostream>
using namespace std;

int smoke(int n, int k){
    if (n < k){
        return 0;
    }else{
        int o = n / k;
        return o+smoke(o+n%k,k);
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    int count = smoke(n,k);
    cout << n + count;
}