#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> nato;

int main()
{
    nato['A'] = "Alfa";
    nato['B'] = "Bravo";
    nato['C'] = "Charlie";
    nato['D'] = "Delta";
    nato['E'] = "Echo";
    nato['F'] = "Foxtrot";
    nato['G'] = "Golf";
    nato['H'] = "Hotel";
    nato['I'] = "India";
    nato['J'] = "Juliett";
    nato['K'] = "Kilo";
    nato['L'] = "Lima";
    nato['M'] = "Mike";
    nato['N'] = "November";
    nato['O'] = "Oscar";
    nato['P'] = "Papa";
    nato['Q'] = "Quebec";
    nato['R'] = "Romeo";
    nato['S'] = "Sierra";
    nato['T'] = "Tango";
    nato['U'] = "Uniform";
    nato['V'] = "Victor";
    nato['W'] = "Whiskey";
    nato['X'] = "Xray";
    nato['Y'] = "Yankee";
    nato['Z'] = "Zulu";
    nato['0'] = "Zero";
    nato['1'] = "One";
    nato['2'] = "Two";
    nato['3'] = "Three";
    nato['4'] = "Four";
    nato['5'] = "Five";
    nato['6'] = "Six";
    nato['7'] = "Seven";
    nato['8'] = "Eight";
    nato['9'] = "Nine";
    char buf[20];
    while (~scanf("%s", buf))
    {
        for (int i = 0; buf[i]; i++) {
            if (buf[i] >= 'a' && buf[i] <= 'z') {
                buf[i] = buf[i] - 'a' + 'A';
            }
        }
        printf("CQCQCQ this is %s", buf);
        for (int i = 0; buf[i]; i++) {
            printf(" %s", nato[buf[i]].c_str());
        }
        printf(" %s\n", buf);
    }
    return 0;
}
