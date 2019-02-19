#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<char> cvec = { 'H','e','l','l','o',' ','W','o','r','l','d','!' };
	string str(cvec.data(),cvec.size());	// vector提供了data成员函数，返回其内存空间的首地址
	cout << str << endl;
	
	system("pause"); return 0;
}