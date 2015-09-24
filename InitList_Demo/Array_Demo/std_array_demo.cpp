#include <vector>
#include <array>
#include <iostream>

using namespace std;

int main() {
	std::array<char, 6> str1 = {'1','2','3','4','5'};

	cout << str1.size() << " " << str1.max_size() << endl;

	std::copy(str1.begin() + 3, str1.end(), str1.begin());

	cout << str1.size() << " " << str1.max_size() << endl;

	for (auto& c : str1)
		cout << c << " ";
	cout << endl;

	const int length = 1024;

	char str2[length] = {'1','2','3','4','5','\0'};
	std::copy(str2 + 3, str2 + 5, str2);
//	for (auto c : str2)
//		cout << c << " ";
//	cout << endl;

	int msgid = 100 << 16;
	msgid = msgid & 0x7fff0000;
	int head = (100 << 16) & 0x7fff0000 | 24 & 0x0000ffff;
	cout << hex << head << endl;
	char *str3 = (char *)malloc(sizeof(int) + 1);
	memset(str3, 0, sizeof(int) + 1);
	memcpy(str3, &head, sizeof(head));

//	for (int i = 0; i != sizeof(int) + 1; ++i)
//		cout << hex << *(str3 + i) << endl;

	int head2 = *(int *)str3;
	int msgid2 = (head2 & 0x7fff0000) >> 16;
	int len = head2 & 0x0000ffff;
	cout << dec << head2 << " " << msgid2 << " " << len << endl;

	std::array<char, sizeof(int)> str4;
	memcpy(str4.data(), &head, sizeof(head));
	for (auto c : str4)
		cout << hex << c << endl;

	int head3 = *(int *)str4.data();
	int msgid3 = (head3 & 0x7fff0000) >> 16;
	int len2 = head3 & 0x0000ffff;
	cout << dec << head3 << " " << msgid3 << " " << len2 << endl;

	int head4 = *reinterpret_cast<int *>(str4.data());
	cout << head4 << endl;

	getchar();
	return 0;
}