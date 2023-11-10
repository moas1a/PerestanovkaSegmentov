#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int m, i, j;
    cin >> m >> i >> j;
    if (i % 2 != 0 && j % 2 != 0) {
        int l = m + i;
        char temp = s[l];
        for (int k = 0; k < i + j - 1; k++) {
            int r = l - j;
            if (r >= m) s[l] = s[r];
            else {
                r = r - m;
                r = m + i + j + r;
                s[l] = s[r];
            }
            l = r;
            //cout << s << endl; // проверка
        }
        s[l] = temp;
    }
    else if (i % 2 == 0 && j % 2 == 0) {
        int l = m + i;
        char temp = s[l];
        for (int k = 0; k < i + j - 2; k++) {
            int m = l - j;
            if (m > m) s[l] = s[m];
            else if (m < m) {
                m = m - m;
                m = m + i + j + m;
                s[l] = s[m];
            }
            else {
                s[l] = s[m];
                s[m] = temp;
                temp = s[m + 1];
                m++;
            }
            l = m;
            //cout << s << endl; // проверка
        }
        s[l] = temp;
    }
    else if (j % 2 == 0) {
        int l = m + i;
        char temp = s[l];
        for (int k = 0; k < i + j - 1; k++) {
            int m = l - j;
            if (m >= m) s[l] = s[m];
            else {
                m = m - m;
                m = m + i + j + m;
                s[l] = s[m];
            }
            l = m;
            //cout << s << endl; // проверка
        }
        s[l] = temp;
    }
    else {
        int l = m + i - 1;
        char temp = s[l];
        for (int k = 0; k < i + j - 1; k++) {
            int m = l - j;
            if (m >= m) s[l] = s[m];
            else {
                m = m - m;
                m = m + i + j + m;
                s[l] = s[m];
            }
            l = m;
            //cout << s << endl; // проверка
        }
        s[l] = temp;
    }
    cout << endl << s << endl;

    return 0;
}
