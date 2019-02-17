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
	vector<string> text;
	string word;
	while (getline(cin,word)) {
		text.push_back(word);
	}
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
		for (auto it2 = it->begin(); it2 != it->end(); ++it2)
			*it2 = toupper(*it2);
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}