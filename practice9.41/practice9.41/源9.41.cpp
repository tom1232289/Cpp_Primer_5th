#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<char> cvec = { 'H','e','l','l','o',' ','W','o','r','l','d','!' };
	string str(cvec.data(),cvec.size());	// vector�ṩ��data��Ա�������������ڴ�ռ���׵�ַ
	cout << str << endl;
	
	system("pause"); return 0;
}