#include "../defs.h"

using Calculator::calculate;

int main() {
	cout << "Enter an expression ";
	string expr;
	while (cin >> expr) {
		cout << calculate(expr) << endl;
		cout << "Enter an expression ";
	}
	return 0;
}
