#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷��������ļ�" << endl;
		system("pause"); return -1;
	}
	vector<int> ivec;
	int val;
	while (in >> val) 
		ivec.push_back(val);
	cout << "������Ҫ����������" << endl;
	cin >> val;
	cout << val << "������" << count(ivec.begin(), ivec.end(), val) << "��" << endl;
	
	system("pause"); return 0;
}