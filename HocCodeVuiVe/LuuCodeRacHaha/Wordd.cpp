#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <cctype>
#include <set>
using namespace std; // tạo set;

int main() // Quaaaaaaqua
{ // temp qu
    string s;
    cin >> s;
    string temp = "";
    char c = s[0];
    s[0] = tolower(c);
    bool flag = false;
    int k = 0;
    int solan = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i+1])
        {
            k++;
            flag = true;
        }
        if (s[i] != s[i+1] && k > 1 && flag == true)
        {
            solan++;
        }
        if (i + 1 > s.size() && solan)
        {

        }
    }
    system("pause");
}