#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    int n = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            n++;
        else
            n--;
        if (n < 0)
            return false;
    }

    if (n > 0)
        return false;

    return true;
}


int main() {

    string s = "((())())";
    bool b = solution(s);

    // print
    printf("%s", b ? "True" : "False");

    return 0;
}
