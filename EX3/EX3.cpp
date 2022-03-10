#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string maxName;
	string firstName;
	string secondName;
	int pay;
	string date;
	int max = 0;
	int summ = 0;

	ifstream statement;
	statement.open("D:\\RTY\\GITHUB\\Repositories\\homework-19\\EX3\\statement.txt");
	while (!statement.eof()) {

		statement >> firstName >> secondName >> pay >> date;
		cout << firstName << " " << secondName << " " << pay << " " << date << endl << endl;
		summ += pay;
		if (pay > max) {
			max = pay;
			maxName = firstName + " " + secondName + " " + to_string(max) + " " + date;
		}
	}
	statement.close();

	cout << "Max pay: " << maxName << endl;
	cout << "Summary pay: " << summ << endl;
	return 0;

}