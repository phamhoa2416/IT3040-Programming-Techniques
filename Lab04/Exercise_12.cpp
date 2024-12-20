#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; ++i) {
        // Use a virtual height of 0 at the end
        int currentHeight = (i == n) ? 0 : heights[i];

        while (!s.empty() && currentHeight < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();

            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    return maxArea;
}

int main() {
    ifstream inputFile("Test BTVN 4-12.txt"); 
    ofstream outputFile("Result BTVN 4-12.txt"); 

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.substr(0, 5) == "case=") {
            string caseNumber = line;
            getline(inputFile, line); 

            int n = stoi(line.substr(6)); 
            vector<int> heights;

            getline(inputFile, line); 
            stringstream ss(line);
            int height;

            while (ss >> height) {
                heights.push_back(height);
            }

            if (heights.size() != n) {
                outputFile << caseNumber << "\n";
                outputFile << "Error: Mismatch in input size. Expected " << n << " but got " << heights.size() << "\n\n";
                continue;
            }

            int result = largestRectangleArea(heights);
            outputFile << caseNumber << "\n";
            outputFile << "The largest rectangle area is: " << result << "\n\n";
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}