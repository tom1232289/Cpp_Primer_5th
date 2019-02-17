#include<iostream>
#include<vector>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main()
{	
	vector<string> text;
	string word;
	while (cin >> word) {
		text.push_back(word);
	}
	for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it)
		cout << *it << endl;
	system("pause");
	return 0;
}