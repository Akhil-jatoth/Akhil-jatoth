#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include<windows.h>
using namespace std;

bool compareIgnoreCase(string a, string b) {
    SetConsoleOutputCP(CP_UTF8);
    if (a.length() != b.length()) return false;
    for (size_t i = 0; i < a.length(); i++) {
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    }
    return true;
}