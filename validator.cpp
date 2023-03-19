#include <bits/stdc++.h>

using namespace std;

using llong = long long;

namespace vld {
    char cstore = 0;
    char peekchar() {
        cstore = (cstore? cstore : getchar());
        return cstore;
    }
    char readchar() {
        char temp = peekchar();
        cstore = 0;
        return temp;
    }

    // read string
    string readstr() {
        string val;
        while (!isspace(peekchar())) {
            val += readchar();
        }
        return val;
    }

    // read number
    int readint() {
        string str;
        while (isdigit(peekchar()) || peekchar() == '-') {
            str += readchar();
        }
        return stoi(str);
    }
    llong readll() {
        string str;
        while (isdigit(peekchar()) || peekchar() == '-') {
            str += readchar();
        }
        return stoll(str);
    }
    double readdbl() {
        string str;
        while (isdigit(peekchar()) || peekchar() == '-' || peekchar() == '.') {
            str += readchar();
        }
        return stod(str);
    }

    // read whitespace
    void readspace() {
        assert(readchar() == ' ');
    }
    void readnl() {
        assert(readchar() == '\n');
    }

    // read eof
    void readEOF() {
        assert(readchar() == EOF);
    }
}

using namespace vld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("out.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
    #endif

    return 0;
}
