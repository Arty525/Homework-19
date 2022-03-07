#include <fstream>
#include <iostream>

using namespace std;

int search(string word) {
	string text;
	ifstream read;
	int counter = 0;
	
	read.open("D:\\RTY\\GITHUB\\Repositories\\homework-19\\EX1\\textfile.txt");
	for (int i = 0; !read.eof(); i += text.length()+1) {
		read >> text;
		counter += text == word;
	}
	read.close();

	return counter;
}

int main() {
	string word = "hello";

	cout << "Words found: " << search(word);

	return 0;
}