#include<iostream>
#include<string>
#include<map>

using namespace std;

//int main()
//{
//	map<string, size_t> word_count;
//	string word;
//	while (cin >> word)
//		++word_count[word];
//	for (const auto &w : word_count)
//		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
//
//	system("pause"); return 0;
//}

int main()
{
	map<int, size_t> num_count;
	int val;
	while (cin >> val)
		++num_count[val];
	for (const auto &n : num_count)
		cout << n.first << " occurs " << n.second << ((n.second > 1) ? " times." : " time") << endl;

	system("pause"); return 0;
}