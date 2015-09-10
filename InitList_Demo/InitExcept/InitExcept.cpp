#include <vector>
#include <iostream>
using namespace std;

class Person {
public:
	Person(int a, string s)
		try : Person(s) {
		cout << "run body" << endl;
		age = a;
	}
	catch (...) {
		cout << "caught exception" << endl;
	}

private:
	Person(string s) : name(s) {
		cout << "target constructor" << endl;
		throw 0;
	}
	string name {"liguoxiong"};
	int age {30};
};

int main() {
	Person p{30, "guoxiong"};

	getchar();
	return 0;
}