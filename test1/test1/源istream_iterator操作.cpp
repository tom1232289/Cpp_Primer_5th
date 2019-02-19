#include<iostream>
#include<iterator>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
	istream_iterator<int> int_it(cin);
	istream_iterator<int> int_eof;
	ifstream in("alife");
	istream_iterator<string> str_it(in);

	//vector<int> ivec;
	//istream_iterator<int> in_iter(cin);
	//istream_iterator<int> eof;
	//while (in_iter != eof) 
	//	ivec.push_back(*in_iter++);
	
	istream_iterator<int> in_iter, eof;
	vector<int> vec(in_iter, eof);
}