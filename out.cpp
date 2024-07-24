//				(line 13)i cant spell repitition
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string decompress(const string& input) {
	string result;
	int length = input.length();
	int currentIndex = 0;
	while (currentIndex < length) {
		char character = input[currentIndex++];
		int repeatCount = 0;
		while (currentIndex < length && isdigit(input[currentIndex])) {
			repeatCount = repeatCount * 10 + (input[currentIndex++] - '0');
		}
		for (int repeatIndex = 0; repeatIndex < repeatCount; repeatIndex++) {
			result += character;
		}
	}
	return result;
}

int main() {
	string fileName;
	cout << "enter filename ";
	cin >> fileName;
	ifstream inputFile(fileName);
	string input((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
	inputFile.close();
	string decompressed = decompress(input);
	string outputFileName = fileName + "decompressed";
	ofstream outputFile(outputFileName);
	outputFile << decompressed;
	outputFile.close();
	cout << "written to " << outputFileName << endl;
	return 0;
}
