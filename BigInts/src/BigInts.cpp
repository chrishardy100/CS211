#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int convert(char x) {
    return x - '0';
}


string add(string a, string b) {

    int arraysize = max(a.length(), b.length()) + 1;
    int aidx = a.length() - 1, bidx = b.length() - 1, cidx = arraysize - 1;
    bool done = false;
    int* arr = new int[arraysize];
    char first, second, sum = 0, carry = 0;


    while (cidx >= 0) {

        first = convert(a[aidx]);
        second = convert(b[bidx]);

        int sum = first + second;

        if (aidx < 0) {
            first = 0;
        }
        if (bidx < 0) {
            second = 0;
        }

        sum = first + second + carry;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        else {
            carry = 0;
        }

        arr[cidx] = sum;
        aidx -= 1;
        bidx -= 1;
        cidx -= 1;
    }

    string ans = "";
    for (int i = 0; i < arraysize; i++) {
        if (i == arraysize) return ans;
        ans += to_string(arr[i]);
        
    }
    if (ans[0] == '0')ans = ans.substr(1);

    return ans;
}
int main() {

    cout << (add("1243", "5321") == "6564") << endl;
    cout << (add("39725", "33") == add("33", "39725")) << endl;
    cout << (add("123", "99") == "222") << endl;
    cout << (add("100", "900") == "1000") << endl;
    cout << (add("111111111111111111111111111111111111111111111111", "22") == "111111111111111111111111111111111111111111111133") << endl;

}
