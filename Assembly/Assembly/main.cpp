#include <iostream>

using namespace std;

extern "C" int ASM();

int main()
{
	cout << ASM() << endl;

	return 0;
}