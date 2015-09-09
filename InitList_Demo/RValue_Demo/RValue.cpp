#include <vector>
#include <iostream>
using namespace std;

string getName() {
	return "liguoxiong";
}

void printName(const string& name) {
	cout << "Ord Name: " << name.c_str() << endl;
}

void printName(string&& name) {
	cout << "RValue Name: " << name.c_str() << endl;
}

int main() {
	string name1 = getName();

	// 右值以前是不可更改的，所以必须要const
	const string& name2 = getName();
//	name2 = "dell";

	auto name3 = getName();

	string&& name4 = getName();
	name4 = "dell";
	cout << name4.c_str() << endl;

	string name5("john");
	printName(getName());
	printName(name5);

	getchar();
	return 0;
}