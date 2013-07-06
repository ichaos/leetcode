#include <iostream> 

using namespace std;

bool isOverflow(int a, int b) {
	cout << a << " * " << b << " = " << a * b << endl;

	return false;
}

int main() {
	isOverflow(2147483641, 2);
}