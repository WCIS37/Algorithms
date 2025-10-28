//24.2班崔栋翔
//求最大公因数
#include <iostream>
using namespace std;

//暴破
void burteForce(int m, int n) {
	int x = min(m, n);
	for (int i = x; i >= 1; i--) {
		if (m % i == 0 && n % i == 0) {
			cout << i << endl;
			break;
		}
	}
}

//短除法
void shortDivision(int m, int n) {
	int z = 1;
	int x = min(m, n);
	for (int i = 2; i <= x; ) {
		x = min(m, n);
		if (m % i == 0 && n % i == 0) {
			m /= i;
			n /= i;
			z *= i;
		} else {
			i++;
		}
	}
	cout << z << endl;
}

//辗转相除法
void  euclideanAlgorithm(int m, int n) {
	int temp; 
	while (n != 0) {
		temp = m % n;
		m = n;
		n = temp;
	}
	cout << m << endl;
}

int main() {
	int m, n;
	cin >> m >> n;
	if (m == 0 || n == 0) {
		cout << "0没有公因数" << endl;
		return 0;
	}
	cout << "暴破法求最大公因数为：";
	burteForce(m, n);
	cout << "短除法求最大公因数为：";
	shortDivision(m, n);
	cout << "辗转相除法求最大公因数为：";
	euclideanAlgorithm(m, n);
}
