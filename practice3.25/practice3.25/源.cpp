#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade = 0;
	while (cin >> grade) {
		if (grade <= 100) {
			auto it = scores.begin();
			++*(it + grade / 10);
		}
	}
	for (auto it = scores.cbegin(); it != scores.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}