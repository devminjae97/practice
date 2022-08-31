#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <stdio.h>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> vec;
    stringstream ss(str);
    string tmp;

    while (getline(ss, tmp, delimiter))
        vec.push_back(tmp);

    return vec;
}

int calcRT(string t1, string t2) {
    vector<string> ts;
    int time = 0;

    ts = split(t2, ':');
    time += stoi(ts[0]) * 60 + stoi(ts[1]);
    ts = split(t1, ':');
    time -= stoi(ts[0]) * 60 + stoi(ts[1]);

    return time;
}

string switchSharp(string str) {
    str = regex_replace(str, regex("C#"), "c");
    str = regex_replace(str, regex("D#"), "d");
    str = regex_replace(str, regex("F#"), "f");
    str = regex_replace(str, regex("G#"), "g");
    str = regex_replace(str, regex("A#"), "a");

    return str;
}

string solution(string m, vector<string> musicinfos) {
    int max_time = 0;
    string candidate;

    m = switchSharp(m);

    for (string info : musicinfos) {
        vector<string> vec = split(info, ',');

        string sheet = switchSharp(vec[3]);

        string music = "";

        int time = calcRT(vec[0], vec[1]);
        int len = sheet.length();

        for (int i = 0; i < time / len; i++)
            music += sheet;
        music += sheet.substr(0, time % len);

        int pos = music.find(m);
        if (pos != string::npos) {
            if (time > max_time) {
                max_time = time;
                candidate = vec[2];
            }
        }
    }

    if (max_time > 0)
        return candidate;

    return "(None)";
}

int main() {
    string m = "ABCDEFG";
    
    vector<string> musicinfos = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
    
    string answer = solution(m, musicinfos);

    printf("%s", answer.c_str());

    return 0;
}
