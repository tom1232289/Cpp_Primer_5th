#include<iostream>
#include<memory>

using namespace std;

struct destination{ };
struct connection{ };

connection connect(destination *pd) {
	cout << "开始连接" << endl;
	return connection();
}

void disconnect(connection c) {
	cout << "关闭连接" << endl;
}

void f1(destination &d) {
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); });
	cout << endl;
}

int main()
{
	destination d;
	f1(d);

	system("pause"); return 0;
}