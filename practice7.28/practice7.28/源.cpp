#include "Screen.h"

using namespace std;

// 函数的返回值如果是引用，则表明函数返回的是对象本身；
// 函数的返回值如果不是引用，则表明函数返回的是对象的副本。

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);	// 这些函数各自只返回对象的临时副本，不会改变myScreen的值
	cout << "\n";
	myScreen.display(cout);	// myScreen的值没有改变，所以全是‘X’
	cout << "\n";
	system("pause");
	return 0;
}

