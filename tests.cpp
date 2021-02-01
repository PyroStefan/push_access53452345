#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "./helpers.h"

using std::cout;
using std::string;
using std::vector;

// executeFromHistory tests ------------------------

// checks default behaviour (0<n<total lines)
bool EFH_default_test()
{
    std::ifstream file("./osshell_history");
    vector<string> CPP_strings{""};
    string temp;
    while (std::getline(file, temp)) {
        CPP_strings.push_back(temp);
    }
    for (int i = 1; i < CPP_strings.size(); i++) {
        string expected = CPP_strings[i] + "\n";
        string EFH_string = executeFromHistory(i).input;  // what actually needs to happen tho
        if (expected.compare(EFH_string) != 0) {
            return false;
        }
    }
    return true;
}

// checks what happens for n > number of lines
bool EFH_high_line()  // should not error out
{
    std::ifstream file("./osshell_history");
    int n_lines = 1;
    while (!file.eof()) {
        string temp;
        std::getline(file, temp);
        n_lines += 1;
    }
    string output = executeFromHistory(n_lines + 5).input;
    cout << output.size() << "," << output;
    if (!output.size()) {  // if empty. TODO: discuss with Dinesh what output needs to be
        return true;
    }
    return false;
}
// checks what happens if n < 0
bool EFH_neg_line()
{
    std::ifstream file("./osshell_history");
    vector<string> CPP_strings{""};
    string temp;
    while (std::getline(file, temp)) {
        CPP_strings.push_back(temp);
    }
    int size = CPP_strings.size();
    for (int i = 1; i < size; i++) {
        string expected = CPP_strings[size - i];
        string EFH_string = executeFromHistory(-1 * i).input;
        if (!expected.compare(EFH_string)) {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<std::pair<string, bool>> test_descr{{"EFH expected behaviour:\t", EFH_default_test()},
                                               {"EFH when n > total lines:\t", EFH_high_line()},
                                               {"EFH when n < 0:\t", EFH_neg_line()}};
    for (const auto& test : test_descr) {
        std::cout << test.first;
        if (test.second) {
            std::cout << "passed\n";
        }
        else {
            std::cout << "FAILED!!\n";
        }
    }
}
