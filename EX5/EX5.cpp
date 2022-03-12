#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector <string>sectorq = { "1q.txt","2q.txt","3q.txt","4q.txt","5q.txt","6q.txt",
								"7q.txt","8q.txt","9q.txt","10q.txt","11q.txt","12q.txt","13q.txt" };
vector <string>sectora = { "1a.txt","2a.txt","3a.txt","4a.txt","5a.txt","6a.txt",
								"7a.txt","8a.txt","9a.txt","10a.txt","11a.txt","12a.txt","13a.txt" };
int i = 0;
int connoisseurs = 0;
int viewers = 0;

int main() {
	int offset;
	ifstream file;
	string text;
	string playerAnswer;

	cout << "Enter offset: ";
	cin >> offset;

	if (i + offset > 12) {
		i = offset - (12 - i);
	}
	else {
		i += offset;
	}

	while (sectorq[i] == "0"){
		if (i == 12) i = 0;
		++i;
	}

	string answer = "D:\\RTY\\GITHUB\\Repositories\\homework-19\\EX5\\answers\\" + sectora[i];
	string question = "D:\\RTY\\GITHUB\\Repositories\\homework-19\\EX5\\questions\\" + sectorq[i];

	cout << answer << endl;
	cout << question << endl;

	file.open(question);
	while (getline(file, text))
	{
		cout << text << endl;
	}
	file.close();

	cin.ignore();
	cin.clear();

	cout << "Your answer: ";
	getline(cin,playerAnswer);
	
	file.open(answer);
	getline(file, text);
	cout << text << endl;
	
	playerAnswer == text ? ++connoisseurs : ++viewers;
	file.close();

	sectorq[i] = "0";
	sectora[i] = "0";

	cout << "connoisseurs: " << connoisseurs << " viewers: " << viewers << endl;

	if (connoisseurs == 6) {
		cout << "Connoisseurs WIN!" << endl;
		return 0;
	}
	else if (viewers == 6) {
		cout << "Viewers WIN!" << endl;
		return 0;
	}
	else {
		return main();
	}
}