#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool sub(string a) {
	char b[4] = {'.', 'P', 'N', 'G'};
	char c[4] = {'.', 'p', 'n', 'g'};
	int j = 0;
	for (int i = a.length()-4; i < a.length(); ++i) {
		if (a[i] != b[j] && a[i] != c[j]) return 0;
		++j;
	}
	return 1;
}

string convert(string address) {
	string buffer;
	for (int i = 0; i < address.length(); ++i) {
		buffer += address[i];
		if (address[i] == '\\' && address[i - 1] != '\\' && address[i + 1] != '\\') {
			buffer += '\\';
		}
	}
	return buffer;
}

int main() {
	string address;
	cout << "Specify the path to the file:" << endl;
	cin >> address;

	if (!sub(address)) {
		cout << "not .PNG format" << endl;
		return main();
	}

	ifstream picture;
	char title[4];

	char mask[4] = { -119, 'P', 'N', 'G' };

	picture.open(convert(address),ios::binary);
	picture.read(title, sizeof(title));

	for (int i = 0; i < 5; ++i) {
		if (title[i] != mask[i]) {
			cout << "It's not .PNG file" << endl;
			picture.close();
			return main();
		}
	}
	
	picture.close();
	
	cout << "It's .PNG file." << endl;

	return 0;
}
