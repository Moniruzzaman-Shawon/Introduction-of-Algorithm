#include <bits/stdc++.h>
using namespace std;

void findTallest(vector<int> &height) {
    int n = height.size();
    
    int firstMaxIdx = 0;
    int secondMaxIdx = -1;

    for (int i = 1; i < n; i++) {
        if (height[i] > height[firstMaxIdx]) {
            firstMaxIdx = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != firstMaxIdx) {
            if (secondMaxIdx == -1 || height[i] > height[secondMaxIdx]) {
                secondMaxIdx = i;
            }
        }
    }

    if (firstMaxIdx > secondMaxIdx) swap(firstMaxIdx, secondMaxIdx);

    cout << firstMaxIdx << " " << secondMaxIdx << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int i = 0; i < n; i++) 
            cin >> height[i];

        findTallest(height);
    }

    return 0;
}