#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

string lowerCase(string s)
{
    string ret = "";
    for (char ch : s)
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
        }
        ret += ch;
    }
    return ret;
}

bool compareWords(string a, string b)
{
    vector<string> va, vb;
    stringstream sa;
    
    sa << a;
    string cur;
    while (sa >> cur)
        va.push_back(lowerCase(cur));

    stringstream sb;
    sb << b;
    while (sb >> cur)
        vb.push_back(lowerCase(cur));

    return (va == vb);
}


int main()
{
    char buf1[4096], buf2[4096];
    ifstream f1("user_output");
    ifstream f2("output");
    string s1, s2;

    int n = 0;
    while (f1.get(buf1, 4096)) 
    {
        if (!f2.get(buf2, 4096)) {
            return 1;
        }
        s1 = buf1;
        s2 = buf2;

        if (!compareWords(s1, s2))
            return 1;
    }
    
    return 0;
}
