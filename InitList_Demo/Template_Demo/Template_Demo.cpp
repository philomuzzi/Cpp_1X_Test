#include <iostream>
#include <tuple>
using namespace std;

template<typename T, size_t Size>
class Values {
	static_assert(Size > 1, "Use a scalar");
	T values[Size];
};

template<typename T, typename U>
auto add(T t, U u) {
	static_assert(is_integral<T>::value, "First parameter must be int");
	return t + u;
}

auto sum() {
	return 0;
}

template<typename H, typename... T>
auto sum(H head, T... t) {
	return head + sum(t...);
}

auto sum_producet(double a, double b) {
	return make_pair(a + b, a * b);
}

int main() {
	auto x{ "hello" };
	cout << x << endl;

	Values<int, 3> hints;
	Values<double, 2> annoys;

//	cout << add(2.5, 4) << endl;
//	cout << add(string("xxx"), " ccc").c_str() << endl;

	cout << sum(1, 2.5) << endl;

	auto values = sum_producet(3, 4);
	auto va = get<0>(values);

	float f1;
	tie(f1, ignore) = sum_producet(24, 3);

	cout << "sum is " << f1 << endl;

	getchar();
	return 0;
}