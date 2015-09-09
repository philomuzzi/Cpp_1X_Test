#include <vector>
#include <map>
#include <iostream>
using namespace std;

auto i = 1;
auto f = 123.f;
auto s = L"Hello";
auto a = { 1,2,3 };

auto meaning_of_life() {
	return 42;
}

template<typename T, typename U>
auto add(T t, U u) {
	return t + u;
}

int main() {
	map<string, vector<string, string>> sssmap;
	auto it = sssmap.begin();

	cout << meaning_of_life() << endl;

	cout << add(2.5, 4) << endl;
//	cout << add(string("hello "), "world") << endl;

	typedef decltype(sssmap.begin()) ssi;

	typedef decltype(42) myint;

	myint x = 123;
	cout << x << endl;

	typedef decltype(add(2.5, 4)) qtype;

	getchar();
	return 0;
}