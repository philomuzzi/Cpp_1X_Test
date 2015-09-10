#include <vector>
#include <iostream>
using namespace std;

class HasPtrMem {
public:
	HasPtrMem() : d(new int(0)) {
		cout << "Construct: " << ++n_cstr << endl;
	}

	HasPtrMem(const HasPtrMem & h) : d(new int(*h.d)) {
		cout << "Copy Construct: " << ++n_cptr << endl;
	}

	HasPtrMem(HasPtrMem && h) : d(h.d) {
		h.d = nullptr;
		cout << "Move construct: " << ++n_mvtr << endl;
	}

	~HasPtrMem() {
		cout << "Destruct: " << ++n_dstr << endl;
	}

	int * d;
	static int n_cstr;
	static int n_dstr;
	static int n_cptr;
	static int n_mvtr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;

HasPtrMem GetTemp() {
	HasPtrMem h;
	cout << h.d << endl;
	return h;
}

int main() {
	HasPtrMem a = GetTemp();
	cout << a.d << endl;

	HasPtrMem a2(a);
	HasPtrMem b(GetTemp());

	HasPtrMem c(move(a));

	getchar();
	return 0;
}