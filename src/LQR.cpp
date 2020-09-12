#include <iostream>
#include <string>
using namespace std;


int negative(int p) {
    p = (p-1) / 2;
    return (p % 2) ? -1 : 1;
}

int twolegendre(int p) {
    if (p % 8 == 1 || p % 8 == 7) return 1;
    if (p % 8 == 3 || p % 8 == 5) return -1;
    else {
        printf("Error.\n");
        return 0;
    }
}

bool isPrime(int num) {
    bool retVal = true;
    if (num == 4) return false;
    for (int i = 2; i < num / 2; i++) {
        if (num % i == 0) {
            retVal = false;
            break;
        }
    }
    return retVal;
}

// assume num is not prime.
int factor(int &num) {
    int retval = num;
    if (num == 4) {
        num = 2;
        return 2;
    }
    for (int i = 2; i < num / 2; i++) {
        if (num % i == 0) {
            retval = i;
            num = num / i;
            break;
        }
    }
    return retval;
}

int legendre(int a, int p) {
    int factored;

    if (p <= 0) return 0;

    if (a > p) a = a % p;

    // cout << "a" << " is: " << a << "\n";
    // cout << "p" << " is: " << p << "\n";

    if (a < 0) return negative(p) * legendre(-a, p);

    if (a == 1) return 1;

    if (a == 2) return twolegendre(p);

    if (p == 3) return a ? 1 : -1;

    if (!isPrime(a)) {
        // cout << "Hooray! We factored " << a << " into ";
        factored = factor(a);
        // cout << factored << " and " << a << "\n";
        return legendre(factored, p) * legendre(a, p);
    }

    if (a % 4 == 3 && p % 4 == 3) {
        return -1 * legendre(p, a);
    }
    
    return legendre(p, a);
}

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int p = atoi(argv[2]);
    int retval;

    if (p % 2 == 0) {
        cout << "p must be odd prime!\n";
        return 0;
    }
    retval = legendre(a, p);
    cout << "(" << a << "/" << p << ") = " << retval << "\n";  
    return 0;
}