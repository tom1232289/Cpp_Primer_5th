#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{
	Screen<5, 3> myScreen;
	// ������ƶ����ض�λ�ã�������������
	myScreen.move(4, 0).set('#');
	myScreen.display(cout);
	cout << endl;

	Screen<5, 5> nextScreen('X');
	nextScreen.move(4, 0).set('#').display(cout);
	cout << endl;
	nextScreen.display(cout);
	cout << endl;

	const Screen<5, 3> blank;
	myScreen.set('#').display(cout);
	cout << endl;
	blank.display(cout);
	cout << endl;

	myScreen.clear('2').display(cout);
	cout << endl;
	myScreen.move(4, 0);
	myScreen.set('#');
	myScreen.display(cout);
	cout << endl;
	myScreen.clear('Z').display(cout);
	cout << endl;

	// ����temp������Screen<5,3>����Screen<5,3> &
	Screen<5, 3> temp = myScreen.move(4, 0);	// �򷵻�ֵ������
	temp.set('#');								// �ı�temp�Ͳ���Ӱ��myScreen
	myScreen.display(cout);
	cout << endl;

	cin >> myScreen;
	cout << myScreen << endl << nextScreen << endl << temp << endl;

	return 0;
}