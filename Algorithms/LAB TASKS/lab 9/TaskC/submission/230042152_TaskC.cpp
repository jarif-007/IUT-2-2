#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

string longestNiceSubstring(string s)
{
    if (s.length() < 2)
        return "";

    unordered_set<char> chars;
    for (char c : s)
        chars.insert(c);

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (chars.count(tolower(c)) == 0 || chars.count(toupper(c)) == 0)
        {
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            return left.length() >= right.length() ? left : right;
        }
    }

    return s;
}

int main()
{
    string s;
    cin >> s;

    cout << longestNiceSubstring(s) << endl;
}