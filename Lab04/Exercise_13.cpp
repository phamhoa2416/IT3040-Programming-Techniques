#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

int countSubStringsWithEqual01(const string& line) {
    unordered_map<int, int> prefixCount; // To store occurrences of each balance
    int balance = 0; 
    int result = 0; 

    prefixCount[0] = 1; 

    for (char c : line) {
        if (c == '1') 
            balance++;
        else 
            balance--;

        // Check if the balance has been seen before
        if (prefixCount.find(balance) != prefixCount.end()) {
            result += prefixCount[balance]; 
        }

        prefixCount[balance]++;
    }

    return result;
}

int main() {
    ifstream inputFile("Test BTVN 4-13.txt"); 
    ofstream outputFile("Result BTVN 4-13.txt"); 

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

        string line;
    while (getline(inputFile, line)) {
        if (line.substr(0, 5) == "case=") {
            string caseNumber = line;
            getline(inputFile, line); 

            if (line.substr(0, 6) == "input=") {
                string binaryString = line.substr(6);
                int result = countSubStringsWithEqual01(binaryString);
                outputFile << caseNumber << "\n";
                outputFile << "output=" << result << "\n\n";
            } else {
                outputFile << caseNumber << "\n";
                outputFile << "Error: Missing or invalid input format.\n\n";
            }
        }
    }

    return 0;
}