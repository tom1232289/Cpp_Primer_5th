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
		cout << "转换后为：" << str << endl;
	}
	else
		cout << "该string对象不含大写字母，无需转换。" << endl;
	system("pause");
	return 0;
}