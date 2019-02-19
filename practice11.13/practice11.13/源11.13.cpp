#include<iostream>
#include<utility>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<pair<string, int>> data;
	string str;
	int val;
	while (cin >> str && cin >> val) {
//		data.push_back(pair<string, int>(str, val));
//		data.push_back(make_pair(str, val));
		data.push_back({ str,val });
	}

	for (const auto &d : data)
		cout << d.first << " " << d.second << endl;

	system("pause"); return 0;
}