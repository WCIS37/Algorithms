#include <iostream>
using namespace std;

int main(){
    int apple[11], height, count = 0;
    for (int i = 0; i < 10; i++){
        cin >> apple[i];
    }
    cin >> height;
    for (int i = 0; i < 10; i++){
        if (height+30 >= apple[i]){
            ++count;
        }
        else {
            continue;
        }
    }
    cout << count;
}