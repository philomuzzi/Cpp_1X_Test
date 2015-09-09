#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <map>
using namespace std;

enum OldColor {
	Green,
	Red,
	Blue
};

enum class SomeState {
	Green,
	Blue,
	Yellow
};

enum class NewColor {
	Green,
	Red,
	Blue
};

int main() {
	OldColor oc = Green;
	NewColor nc = NewColor::Green;
	int xx = oc;
	auto yy = nc;

	vector<int> iv{1,3,5,6,5,3};
	for_each(iv.begin(), iv.end(), [](int n) -> float {
		         cout << n << endl;
		         return n;
	         });

	auto zero = 0;
	auto is_positive = [&](int n) {
		return n > zero;
	};
	cout << boolalpha << is_positive(-2) << endl;

	function<int(int)> fib = [&fib](int n) {
		return n < 2 ? 1 : fib(n - 1) + fib(n - 2);
	};
	cout << fib(25) << endl;

	for (auto& i: iv) {
		cout << i << endl;
	}

	for (auto& i: {12,22,34}) {
		cout << i << endl;
	}

	map<int, int> sm{ {12, 42}, {23, 14} };
	for (const auto& ksm : sm) {
		cout << ksm.first << " " << ksm.second << endl;
	}

	map<string, string> ssm{ {"hello", "world"}, {"holy", "shit"} };
	for (const auto& kssm: ssm) {
		cout << kssm.first.c_str() << " " << kssm.second.c_str() << endl;
	}

	getchar();
	return 0;
}