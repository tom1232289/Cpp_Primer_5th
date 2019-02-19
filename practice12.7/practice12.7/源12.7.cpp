#include<iostream>
#include<memory>
#include<vector>

using namespace std;

shared_ptr<vector<int>> new_vector() {
	return make_shared<vector<int>>();
}

void read_int(shared_ptr<vector<int>> spv) {
	int ival;
	while (cin >> ival)
		spv->push_back(ival);
}

void print_int(shared_ptr<vector<int>> spv) {
	for (const auto v : *spv)
		cout << v << " ";
	cout << endl;
}

int main()
{
	auto spv = new_vector();
	read_int(spv);
	print_int(spv);

	system("pause"); return 0;
}