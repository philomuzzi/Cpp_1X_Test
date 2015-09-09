#include <vector>
using namespace std;

class Animal {
protected:
	int legs = 4;

public:
	explicit Animal(int legs)
		: legs(legs) {
	}

	virtual int walk(int steps) {
		return steps * 20;
	}

	virtual ~Animal() {}
};

class Human : public Animal {
public:
	Human() : Animal(2) {}

	int walk(int steps) override {
		return steps * 10;
	}

	Human(const Human& other) = delete;

	Human(Human&& other) = delete;

	Human& operator=(const Human& other) = delete;

	Human& operator=(Human&& other) = delete;

	~Human() override {}
};

int main() {
	Human h;
	Human h2 = h;

	getchar();

	return 0;
}