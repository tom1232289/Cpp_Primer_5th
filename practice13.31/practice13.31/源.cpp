#include "HasPtr.h"
#include <algorithm>

int main()
{
	vector<HasPtr> vecHP;
	for (int i = 33; i > 0; --i)
		vecHP.push_back(to_string(i));
	for (auto p : vecHP)
		cout << p.getString() << " ";
	cout << endl;
	sort(vecHP.begin(), vecHP.end());	// ��Ԫ�ؽ���ʱ����ò������򷨣��������swap����Ԫ�ؽ϶�ʱ����ÿ������򷨣������swap��������ֽ��Ϊ33��Ԫ�أ�
	for (auto p : vecHP)
		cout << p.getString() << " ";

	getchar();
	return 0;
}