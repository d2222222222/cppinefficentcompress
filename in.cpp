#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string compress(const string& input) {
	string result;
	int length = input.length();
	for(int currentIndex = 0; currentIndex < length; currentIndex++) {
		int count =1;
		while (currentIndex < length - 1 && input[currentIndex] == input[currentIndex + 1]) {
			count++;
			currentIndex++;
		}
		result += input[currentIndex];
		result += to_string(count);
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
	string compressed = compress(input);
	string outputFileName = fileName + "compressed";
	ofstream outputFile(outputFileName);
	outputFile << compressed;
	outputFile.close();
	cout << "written to " << outputFileName << endl;
	return 0;
}
