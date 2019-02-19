#include<iostream>
#include<iterator>
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	cout << accumulate(in, eof, 0) << endl;

	system("pause"); return 0;
}