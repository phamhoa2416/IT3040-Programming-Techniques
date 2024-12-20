#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);

    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    ifstream inputFile("Test BTVN 4-10.txt");
    ofstream outputFile("Result BTVN 4-10.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.substr(0, 5) == "case=") {
            string caseNumber = line; 
            getline(inputFile, line); 

            int N = stoi(line.substr(6)); 

            vector<string> documents;
            map<string, int> documentFrequency; 
            vector<map<string, int>> termFrequency; 

            for (int i = 0; i < N; ++i) {
                getline(inputFile, line);
                documents.push_back(line);

                vector<string> words = split(line, ',');
                map<string, int> wordCount;

                for (const string& word : words) 
                    wordCount[word]++;

                termFrequency.push_back({});
                for (const auto& pair : wordCount) {
                    const string& word = pair.first;
                    int count = pair.second;
                    documentFrequency[word]++;
                    termFrequency.back()[word] = count;
                }
            }

            getline(inputFile, line);
            int Q = stoi(line);

            vector<string> queries;

            for (int i = 0; i < Q; ++i) {
                getline(inputFile, line);
                queries.push_back(line);
            }

            outputFile << caseNumber << endl; 

            for (int q = 0; q < Q; ++q) {
                vector<string> queryWords = split(queries[q], ',');
                vector<double> scores(N, 0.0);

                for (int i = 0; i < N; ++i) {
                    for (const string& word : queryWords) {
                        if (termFrequency[i].find(word) != termFrequency[i].end()) {
                            int f_td = termFrequency[i][word];
                            int max_f_d = max_element(termFrequency[i].begin(), termFrequency[i].end(),
                                            [](const pair<string, int>& a, const pair<string, int>& b) {
                                                 return a.second < b.second;
                                                })->second;

                            double tf = 0.5 + 0.5 * ((double) f_td / max_f_d);
                            double idf = log2((double) N / documentFrequency[word]);

                            scores[i] += tf * idf;
                        }
                    }
                }

                int best_doc = -1;
                double best_score = -1.0;
                for (int i = 0; i < N; ++i) {
                    if (scores[i] > best_score) {
                        best_score = scores[i];
                        best_doc = i;
                    }
                }
                outputFile << best_doc + 1 << endl;
            }
            outputFile << endl; 
        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
