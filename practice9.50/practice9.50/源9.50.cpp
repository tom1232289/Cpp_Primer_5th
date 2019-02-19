#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> svec = { "a12.3","-4.56","-7.8e-2" };
	float sum = 0;
	for (auto c : svec)
		sum += stof(c);
	cout << sum << endl;

	system("pause"); return 0;
}