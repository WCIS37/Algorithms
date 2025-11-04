#include <iostream>
#include <ctime>
using namespace std;

void printN1(int N){
    if (N){
        printN1(N - 1);
        printf("%d\n",N);
    }
    return;
}

void printN2(int N){
    for (int i = 1; i <= N; i++){
        printf("%d\n", i);
    }
    return;
}

int main(){
    int n;
    double duration;
    clock_t start, stop;
    const int number = 10;  //多重复几次是为了使时间更明显

    cin >> n;
    start = clock();
    for (int i = 0; i < number; i++){
        printN2(n);     //当printN2运行100000时就会爆掉，因为栈溢出，所以效率跟空间有关。
    }
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;

    printf("%f\n", duration);      //很明显二者并没有太大差别
}