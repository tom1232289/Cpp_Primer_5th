#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

for (const auto &entry : people) {
	ostringstream formatted, badNums;
	for (const auto &nums : entry.phones) {
		if (!valid(nums)) {
			badNums << " " << nums;
		}
		else {
			formatted << " " << format(nums);
		}
		if (badNums.str().empty()) {
			os<<entry.name<<" "
		}
	}
}