#include <bits/stdc++.h>
using namespace std;

bool pileWord(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    int freq[26] = {0};

    for (size_t i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
        freq[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;

        if (pileWord(s1, s2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
