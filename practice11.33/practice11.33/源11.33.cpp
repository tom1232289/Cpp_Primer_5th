#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

map<string, string> bulidMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const string &transform(string &word, map<string,string> &trans_map) {
	auto map_it = trans_map.find(word);
	if (map_it != trans_map.cend())
		return map_it->second;
	else
		return word;
}

void transform_word(ifstream &map_file, ifstream &input_file) {
	auto trans_map = bulidMap(map_file);
	string line;
	while(getline(input_file, line)) {
		istringstream stream(line);
		string word;
		while (stream >> word) {
			cout << transform(word, trans_map) << " ";
		}
		cout << endl;
	}
}

int main(int argc,char* argv[])
{
	ifstream map_file(argv[1]);
	if (!map_file) {
		cerr << "无法打开规则文件" << endl;
		return -1;
	}
	ifstream input_file(argv[2]);
	if (!input_file) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
	transform_word(map_file, input_file);

	system("pause"); return 0;
}