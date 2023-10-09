#pragma once
#include <fstream>
#include <string>
#include <regex>
#include <variant>
#include <stdexcept>
using namespace std;

variant<int, float, double> extractIFDFromTxt(const string& fileName) {

    if (fileName.find(".txt") == string::npos) {
        throw runtime_error("Invalid file format");
    }

    locale::global(locale("en_US.UTF-8"));

    ifstream file(fileName);

    if (!file.is_open()) {

        throw runtime_error("Could not open the file");
    }

    string line;
    if (getline(file, line)) {

        regex intRegex("\\d+");
        regex floatRegex("\\d+\\.\\d");
        regex doubleRegex("\\d+\\.\\d+");

        if (regex_match(line, intRegex)) {
            return stoi(line);
        }
        else if (regex_match(line, floatRegex)) {
            return stof(line);
        }
        else if (regex_match(line, doubleRegex)) {

            return stod(line);
        }
        else {
            throw runtime_error("It is impossible to determine the type of number in a string");
        }
    }
    else {
        throw runtime_error("File is empty");
    }
}