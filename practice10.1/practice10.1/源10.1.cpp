#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		system("pause"); return -1;
	}
	vector<int> ivec;
	int val;
	while (in >> val) 
		ivec.push_back(val);
	cout << "请输入要搜索的整数" << endl;
	cin >> val;
	cout << val << "出现了" << count(ivec.begin(), ivec.end(), val) << "次" << endl;
	
	system("pause"); return 0;
}