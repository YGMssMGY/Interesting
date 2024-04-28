#include <bits/stdc++.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isPalindrome(int num) {
    int reversed = 0, original = num;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

void findPrimePalindromes(int a, int b) {
    if (a % 2 == 0) a++;  // 如果a是偶数，那么将它增加1，使它变为奇数
    for (int i = a; i <= b; i += 2) {  // 每次增加2，跳过所有的偶数
        if (isPalindrome(i) && isPrime(i)) {
            std::cout << i << std::endl;
        }
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    findPrimePalindromes(a, b);
    return 0;
}