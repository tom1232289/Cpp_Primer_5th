#include "Screen.h"

using namespace std;

// �����ķ���ֵ��������ã�������������ص��Ƕ�����
// �����ķ���ֵ����������ã�������������ص��Ƕ���ĸ�����

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);	// ��Щ��������ֻ���ض������ʱ����������ı�myScreen��ֵ
	cout << "\n";
	myScreen.display(cout);	// myScreen��ֵû�иı䣬����ȫ�ǡ�X��
	cout << "\n";
	system("pause");
	return 0;
}

