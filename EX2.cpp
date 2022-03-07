#include <iostream>
#include <fstream>

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
	string address = "D:\\RTY\\GITHUB\\Repositories\\homework-19\\EX1\\textfile.txt";
	//string text;
	string chunk;

	//cout << "Input file address: ";
	//cin >> address;

	ifstream file;
	file.open(convert(address), ios::binary);
	if (file.is_open()) {
		cout << "File is open." << endl;
	}
	else {
		cout << "File is not open." << endl;
		return main();
	}
	while (!file.eof()) {
		file >> chunk;
		cout << chunk << " ";
	}
	file.close();
	return 0;
}