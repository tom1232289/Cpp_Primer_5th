#include <iostream>

using namespace std;

class numbered {
public:
	numbered() { mysn = seq++; }
	numbered(const numbered &n) { mysn = seq++; }
	int mysn;
private:
	static int seq;
};

int numbered::seq = 0;

void f(numbered s) {
	cout << s.mysn << endl;
}

int main(int argc, char *argv[])
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	system("pause");
	return 0;
}