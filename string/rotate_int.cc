#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int reverse(int x) {
	long result = 0;
	bool flag = false;
	string str;
	stringstream stream;
	if(x < 0) {
		flag = true;
		x *= -1;
	}
	
	stream << x;
	stream >> str;
	for(int i = 0; i < str.length() / 2; i++) {
		swap(str[i], str[str.length() - 1 -i]);
	}
	stream.clear();
	stream << str;
	stream >> result;

	if(flag == true) {
		result *= -1;
	}
	if((result > INT_MAX) || (result < INT_MIN)) {
		result = 0;
	}
	return result;
}

int main() {
	int x1 = 123;
	int x2 = -1245;
	int x3 = 4500;

	cout << "reverse x1 = " << reverse(x1) << endl;
	cout << "reverse x2 = " << reverse(x2) << endl;
	cout << "reverse x3 = " << reverse(x3) << endl;
	return 0;
}

