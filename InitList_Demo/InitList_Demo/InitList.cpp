#include <vector>
#include <map>
#include <iostream>
using namespace std;

template<typename T, typename U>
auto add(T t, U u) {
	return t + u;
}

template<typename T, typename... U>
auto add(T t, U... u) {
	return t + add(u...);
}

auto add() {
	return 0;
}

struct Address {
	int postcode;
	string city;
};

struct Person {
	int age;
	string name;
	Address address;

	explicit Person(const Address& address)
		: address(address) {
	}

	Person(int age, const string& name)
		: age(age),
		  name(name) {
	}
};

struct Exchange {
	int count;
	float rates[2];

	Exchange(initializer_list<float> flist) {
		if (flist.size() < 2) return;

		auto i = flist.begin();
		rates[0] = *i;
		i++;
		rates[1] = *i;
	}
};

int main() {
	auto t{ 1 };
	string s{ "hello" };
	vector<int> iv{ 1,2,3,4 };
	map<string, int> msi{ {"usa", 200000000}, {"china", 1300000000}, {"japan", 15000000} };
	map<int, string> postcode = { {010, "bejing"}, {021, "guangzhou" } };

	cout << add(t, 5) << endl;
	cout << add(t) << endl;
	cout << add(1, 2, 3, 4) << endl;

	Person p{ 30, "liguoxiong" };
	vector<Person> pv = {
		{30, "liguoxiong"},
		{20, "whowhowho"},
		{10, "???"}
	};

	Person person{Address()};

	for (auto i : iv)
		cout << i << endl;

	Exchange e1{ 1, 2, 3 };

	getchar();
	return 0;
}