#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    stack<char> stck;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            stck.push('(');
        else
            if (!stck.empty())
                stck.pop();
            else
                return false;
    }

    if (stck.size() > 0)
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
