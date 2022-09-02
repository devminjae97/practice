#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string loop = "";
    string tmp;
    int max = s.size() >> 1;
    int shortest = 1000;
    int n;
    int c = 1;

    for (int len = 1; len <= max + 1; len++) {
        n = s.size();

        for (int i = 0; i <= s.size() - len;) {
            tmp = s.substr(i, len);

            if (loop == tmp) {
                n -= len;
                c++;
                if (c == 2 || c == 10 || c == 100)
                    n++;
            }
            else {
                loop = tmp;
                c = 1;
            }

            i += len;
        }

        if (shortest > n)
            shortest = n;
    }
  
    return shortest;
}

int main() {
    string m = "ababcdcdababcdcd";
    
    int answer = solution(m);

    printf("%d", answer);

    return 0;
}
