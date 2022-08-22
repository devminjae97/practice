#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {

    vector<pair<int, int>> vec;

    int n;
    int tmp; 
    int* arr;

    scanf("%d", &n);

    arr = new int[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        pair<int, int> p = make_pair(tmp, i);
        vec.push_back(p);
    }

    sort(vec.begin(), vec.end(), comp);

    int cor = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && vec[i - 1].first == vec[i].first) {
            cor++;
        }
        arr[vec[i].second] = i - cor;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
