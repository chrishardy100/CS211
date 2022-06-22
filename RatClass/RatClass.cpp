#include <iostream>
using namespace std;

class Rat {
private:
    int n;
    int d;

public:
    // Constructors
    Rat() { // default constructor
        n = 0;
        d = 1;
    }
    Rat(int i, int j) { // 2 parameter constructor
        n = i;
        d = j;
    }
    Rat(int i) { // conversion constructor
        n = i;
        d = 1;
    }

    // accessor & mutator functions 
    int getN() { return n; }
    int getD() { return d; }
    void setN(int i) { n = i; }
    void setD(int i) { d = i; }

    // Operator Overloads
    Rat operator+(Rat r) {
        Rat t;
        t.n = n * r.d + d * r.n;
        t.d = d * r.d;
        t.reduce();
        return t;
    }
    Rat operator-(Rat r) {
        Rat t;
        t.n = n * r.d - d * r.n;
        t.d = d * r.d;
        t.reduce();
        return t;

    }
    Rat operator*(Rat r) {
        Rat t;
        t.n = n * r.n;
        t.d = d * r.d;
        t.reduce();
        return t;
    }
    Rat operator/(Rat r) {
        Rat t;
        t.n = n * r.d;
        t.d = d * r.n;
        t.reduce();
        return t;

    }
    
    // GCD & Reduce
    int gcd(int n, int d) { //finds the largest common divisor
        return d == 0 ? n : gcd(d, n % d);
    }
    void reduce() {
        // Write a function to reduce the Rat to lowest terms.
        // 1. Use the GCD function provided above to find the greatest common divisor
        // 2. divide both n and d by the number found in step 1
        // 3. also double check if denominator is negative, if so, add negative sign to both n and d 
        int gcd_ = gcd(n, d);
        n /= gcd_;
        d /= gcd_;
        if (d < 0) { // Make sure the denominator is positive
            d = -d;
            n = -n;
        }
    }

    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts n and d.
ostream& operator<<(ostream& os, Rat r) {
    // Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
    // 3/2 should be printed as 1 1/2
    // 1/2 should be printed as 1/2
    // 2/1 should be printed as 2
    // 0/1 should be printed as 0
    // -3/2 should be printed as -1 1/2
    r.reduce();

    //if (r.n == r.d)
    //    cout << 1;
    if (r.n == 0 || r.d == 1)
        cout << r.n << endl;
    else if (abs(r.n) < r.d)
        cout << r.n << " " << r.d << endl;
    else if(abs(r.n) >= r.d) {
        if (r.n > -1)
            cout << r.n / r.d << " " << r.n % r.d << "/" << r.d << endl;
        else
            cout << r.n / r.d << " " << -r.n % r.d << "/" << r.d << endl;
    }

    //if (r.n == r.d)
    //    os << 1;
    //else if (r.n % r.d == 0)
    //    os << (r.n) / (r.d);
    //else if (r.n == 0)
    //    os << 0;
    //else if (r.n > r.d) {
    //    int whole;
    //    int partial;
    //    whole = r.n / r.d;
    //    partial = r.n - (whole)*r.d;
    //    os << whole << " " << partial << "/" << r.d;
    //}
    //else
    //    os << r.n << "/" << r.d;

    // Step 1 : reduce r
    // Step 2 : if n == 0 or d == 1, print n
    // Step 3 : else if abs(n) < d (case abs(numerator) < denominator), print n then d
    // Step 4 : else (case abs(numerator) >= denominator)
        // 4.1: if n is positive, print n/d, then n%d, then d
        // 4.2: else, print n/d, then -n%d, then d

    return os;
}
istream& operator>>(istream& is, Rat& r) {
    is >> r.n >> r.d;
    return is;
}

int main() {
    Rat r1(5, 2), r2(3, 2);

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
     cout << "r1 + r2: " << r1 + r2 << endl;
     cout << "r1 - r2: " << r1 - r2 << endl;
     cout << "r1 * r2: " << r1 * r2 << endl;
     cout << "r1 / r2: " << r1 / r2 << endl;
     cout << endl;

     r1 = r2;
     r2 = r1 * r2;

     cout << "r1: " << r1 << endl;
     cout << "r2: " << r2 << endl;
     cout << "r1 + r2: " << r1 + r2 << endl;
     cout << "r1 - r2: " << r1 - r2 << endl;
     cout << "r1 * r2: " << r1 * r2 << endl;
     cout << "r1 / r2: " << r1 / r2 << endl;
     cout << endl;

    // r1 = r2 + r1 * r2 / r1;
    // r2 = r2 + r1 * r2 / r1;

    // cout << "r1: " << r1 << endl;
    // cout << "r2: " << r2 << endl;
    // cout << "r1 + r2: " << r1 + r2 << endl;
    // cout << "r1 - r2: " << r1 - r2 << endl;
    // cout << "r1 * r2: " << r1 * r2 << endl;
    // cout << "r1 / r2: " << r1 / r2 << endl;

    //Rat x(1, 2), y(2, 3), z;
    //z = x + y;
    //cout << z << endl;
    //y.setN(7);
    //y.setD(2);
    //z = x + y;
    //cout << z << endl;
    //z = x - y;
    //cout << z << endl;
    //z = x / y;
    //cout << z << endl;
    //cin >> x;
    //cout << x;  

    //z = 3 * x + y * 5 + 10;
    //cout << z << endl;
    return 0;
}
