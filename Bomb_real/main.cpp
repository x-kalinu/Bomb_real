#include <iostream>
#include <random>
#include<windows.h>
#include<fstream>
#include <sstream>
#include <iomanip>


using namespace std;



int ran(int mi, int ma) {
	random_device rd;
	ranlux48 engine(rd());
	uniform_int_distribution<int> distrib(mi, ma);
	int r = distrib(engine);
	return r;
}
void bomb() {
	int n = ran(0, 280);
	int mi = 0;
	int ma = 280;
	int d;
	cout << mi << "~" << ma << endl;
	do {
		cin >> d;
		cout << endl;
		if (d > mi && d < ma) {
			if (d < n) {
				cout << d << "~" << ma << endl;
				cout << endl;
				mi = d;
			}
			else if (d > n) {
				cout << mi << "~" << d << endl;
				cout << endl;
				ma = d;
			}
			else {
				cout << "BOMB! ! !" << endl;
				cout << endl;
			}
		}
		else {
			cout << "����������һ��" << mi << "~" << ma << "֮�������" << endl;
			cout << endl;
		}
	} while (d != n);
	return;
}
string real() {
	string li;

	ifstream fi("real.txt");
	string lin[200];
	int n = 0;
	while (std::getline(fi, li)) {
		lin[n] = li;
		n++;
	}
	fi.close();
	int m = ran(0, n - 1);
	string e = lin[m];
	return e;
}
int main() {


	while (1) {
		cout << "1. ����ը��" << endl;
		cout << "2. ���Ļ�" << endl;
		cout << "����������˳�" << endl;
		int x;
		cin >> x;
		cout << endl;
		if (x == 1) {
			bomb();
		}
		else if (x == 2) {
			cout << real() << endl;
			cout << endl;
		}
		else {
			break;
		}
	}
}