#include <iostream>
#include <string>
using namespace std;

int L, C;
char clist[16];
bool is[26];
void make(int, int, int, string);

int main()
{
    cin >> L >> C;
    for (int i = 1; i <= C; i++)
    {
        char c;
        cin >> c;
        is[c - 97] = true;
    }

    for (int i = 0, temp = 1; i < 26; i++)
    {
        if (is[i])
        {
            clist[temp] = i + 97;
            temp++;
        }
    }
    make(1, 2, 0, string());
    return 0;
}

void make(int vowel, int consonant, int index, string str)
{
    if (str.size() == L || index == C)
    {
        if (str.size() == L && vowel <= 0 && consonant <= 0)
            cout << str << '\n';
        return;
    }
    index++;
    //not include

    str.push_back(clist[index]);
    if (clist[index] == 'a' || clist[index] == 'e' ||
        clist[index] == 'i' || clist[index] == 'o' || clist[index] == 'u')
    {
        make(vowel - 1, consonant, index, str);
    }
    else
    {
        make(vowel, consonant - 1, index, str);
    }
    str.erase(str.end() - 1);
    make(vowel, consonant, index, str);
    return;
}