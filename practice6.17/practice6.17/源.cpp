#include<iostream>
#include<string>	
using namespace std;

bool Has_Upper(const string &s) {
	for (auto c : s) {
		if (isupper(c))
			return true;
	}
	return false;
}

void ChangeToLower(string &s) {
	for (auto &c : s) {
		c=tolower(c);
	}
}

int main()
{
	string str{ "value" };
	if (Has_Upper(str)) {
		ChangeToLower(str);
		cout << "ת����Ϊ��" << str << endl;
	}
	else
		cout << "��string���󲻺���д��ĸ������ת����" << endl;
	system("pause");
	return 0;
}