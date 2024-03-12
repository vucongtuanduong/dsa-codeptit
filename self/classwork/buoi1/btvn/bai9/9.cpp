#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int count  = 0;
    int a[26], b[26];
    for (int i = 0; i < 26; i++) {
        a[i] = -1;
    }
    for (int i = 0; i < 52; i++) {
        if (a[s[i] - 'A'] == -1) { // first occurence
            a[s[i] - 'A'] = i;
        } else {
            b[s[i] - 'A'] = i; //second occurence
        }
    }

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(a[i] < a[j] && a[j] < b[i] && b[i] < b[j]){
                count++;
			}
		}
	}
    cout << count;
}