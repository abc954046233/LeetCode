#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int get_value(char roman_char) {
        switch(roman_char) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
    }
    
    int romanToInt(string s) {
        int res = 0;
        
        int i;
        for (i = 0; i < s.size() - 1; ++i) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    res += 4;
                    ++i;
                }
                else if (s[i + 1] == 'X') {
                    res += 9;
                    ++i;
                }
                else {
                    res += get_value(s[i]);
                }
            }
            else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    res += 40;
                    ++i;
                } else if (s[i + 1] == 'C') {
                    res += 90;
                    ++i;
                } else {
                    res += get_value(s[i]);
                }
            }
            else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    res += 400;
                    ++i;
                } else if (s[i + 1] == 'M') {
                    res += 900;
                    ++i;
                } else {
                    res += get_value(s[i]);
                }
            }
            else res += get_value(s[i]);
        }
        if (i < s.size())
            res += get_value(s[s.size() - 1]);

        return res;
    }   
};

int main(int argc, char** argv) {
    string s = argv[1];
    cout << Solution().romanToInt(s) << '\n';
    return 0;
}
