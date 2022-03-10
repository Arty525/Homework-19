#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
	string text;

	cout << "Input file address: ";
	cin >> address;

	ifstream file;
	file.open(convert(address), ios::binary);
	if (file.is_open()) {
		cout << "File is open." << endl;
	}
	else {
		cout << "File is not open." << endl;
		return main();
	}
	while (getline(file, text))
	{
		cout << text << endl;
	}
	file.close();
	return 0;
}
