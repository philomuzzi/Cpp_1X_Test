#include <vector>
#include <iostream>
#include <memory>
using namespace std;

class Address {
public:
	Address() {}
	Address(const Address&) { cout << "Address copied!" << endl; }
	int house_number;
	string city;
	int postcode;
};

Address make_address(int number, string city) {
	Address address{};
	address.city = city;
	address.house_number = number;

	return address;
}

unique_ptr<Address> make_address_pointer(int number, string city) {
	auto a = make_unique<Address>();
	a->city = city;
	a->house_number = number;

	return a;
}

class Company{
public:
	string name;
	int size;
};

class Person {
public:
	unique_ptr<Address> address;
	shared_ptr<Company> company;

	Person() {
		address = make_unique<Address>();
		company = make_unique<Company>();
	}
};

int main() {
	auto address = make_address(1234, "shenzhen");
	auto address2 = make_address_pointer(1234, "shenzhen");

	unique_ptr<Address> a;
	shared_ptr<Company> c;
	{
		Person p;
		p.address->house_number = 12345;
		p.company->name = "zqb";
//		a = p.address;
		c = p.company;
	}

	getchar();
	return 0;
}