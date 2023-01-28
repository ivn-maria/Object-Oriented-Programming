#ifndef KINDLE_SERIALIZE_H
#define KINDLE_SERIALIZE_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void writeString(std::ofstream& outFile, const string& str);

string readString(std::ifstream& inFile);

void writeVector(std::ofstream& outFile, const vector<size_t>& v);

vector<size_t> readVector(std::ifstream& inFile);
void writeCommentsToFile(std::ofstream& outFile, const pair<string, string>& p);

pair<string, string> readCommentsFromFile(std::ifstream& inFile);

void writeRatesToFile(std::ofstream& outFile, const pair<string, unsigned>& comments);

pair<string, unsigned> readRatesFromFile(std::ifstream& inFile);

#endif //KINDLE_SERIALIZE_H
