#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int j = left % n;

    for (int i = left / n; i < n; i++) {
        for (; j < n; j++) {
            if (i * n + j > right) break;
            answer.push_back(i > j ? i + 1 : j + 1);
        }
        j = 0;
    }

    return answer;
}

int main() {

    vector<int> vec = solution(3, 2, 5);

    // print
    for (int i = 0; i < vec.size(); i++)
        printf("%d ", vec[i]);

    return 0;
}
