#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int d = 1; n >= d * (d + 1) / 2; d++) {
        if ((n - d * (d + 1) / 2) % d == 0)
            answer++;
    }

    return answer;
}

int main() {
    int n = solution(15);

    //print
    printf("%d\n", n);

    return 0;
}
