/*
 NAME: Harish Palani
 CRN: 11467
 ASSIGNMENT: Lab 2
 SOURCES: stackoverflow.com
 */

#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Functions
string decimalToBinary(long long n);

int main() {
    long long base, exponent, divisor;
    long long product;
    string in;
    
    for (long long xyzabc = 0; xyzabc < 4; xyzabc++) {
        
        product = 1;
        
        /* BASE */
        cout << "Enter base (a) below." 
             << endl;
        cin >> in;
        
        // Ensure input is numeric
        try {
            base = stoll(in);
        } catch (exception &e) {
            cout << "\n"
                 << "Make sure you're entering an integer value!" 
                 << endl;
            cin >> base;
        }
        
        /* EXPONENT */
        cout << "Enter exponent (n) below." 
             << endl;
        cin >> in;
        
        // Ensure input is numeric
        try {
            exponent = stoll(in);
        } catch (exception &e) {
            cout << "\n"
                 << "Make sure you're entering an integer value!" 
                 << endl;
            cin >> exponent;
        }
        
        /* DIVISOR */
        cout << "Enter divisor below." 
             << endl;
        cin >> in;
        
        // Ensure input is numeric
        try {
            divisor = stoll(in);
        } catch (exception &e) {
            cout << "\n"
                 << "Make sure you're entering an integer value!" 
                 << endl;
            cin >> divisor;
        }
        
        string binary = decimalToBinary(exponent);
        reverse(binary.begin(), binary.end());
        for (int x = binary.length()-1; x >=0; x--) {
            if (binary[x] == '1') {
                product = product * (long long) powl(base, (long long) powl(2, x)) % divisor;
            }
        }

        long long x = 1, y = base;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                x = (x * y) % divisor;
            }
            y = (y * y) % divisor;
            exponent /= 2;
        }
        
        cout << x % divisor << endl;
    }
}

string decimalToBinary(long long n) { // Adapted from Stack Overflow
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}