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
    string a = "";
    for (size_t i = 0; i < s.length(); i++)
    {
        a += tolower(s[i]);
    }
    string tmp = "";
    char c = s[0];
    s[0] = tolower(c);
    bool flag = false;
    int k = 0;
    int solan = 0;
    vector<string>v;
    for (size_t i = 0; i < a.size() - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            if (k == 0)
            {
                tmp += a[i];
            }
            k++;
           
        }
        else if (a[i] != a[i+1] && k > 0)
        {
            bool b1 = false;
            if (v.size() == 0)
            {
                v.push_back(tmp);
            }
            else
            {
                for (auto it : v)
                {
                    if (it == tmp)
                    {
                        b1 = true;
                        break;
                    }
                }
                if (!b1)
                {
                    v.push_back(tmp);
                }
            }  
            tmp = "";
            solan++;
            k = 0;
            
        }
        else
        {
            tmp += a[i];
        }
        if (i + 1 == a.size() - 1)
        {
            tmp += a[i];
            bool b1 = false;
            if (v.size() == 0)
            {
                v.push_back(tmp);
            }
            else
            {
                for (auto it : v)
                {
                    if (it == tmp)
                    {
                        b1 = true;
                        break;
                    }
                }
                if (!b1)
                {
                    v.push_back(tmp);
                }
            }
        }
    }
    cout << v.size();
}