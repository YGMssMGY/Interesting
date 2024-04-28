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

void generateSuperprimeRib(int num, int n) {
    if (!isPrime(num)) return;
    if (n == 0) {
        std::cout << num << std::endl;
        return;
    }
    for (int i = 1; i <= 9; i += 2) {  // 只考虑奇数，因为偶数不可能是质数
        generateSuperprimeRib(num * 10 + i, n - 1);
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 2; i <= 9; i++) {  // 从2开始生成数字，直到9
        generateSuperprimeRib(i, n - 1);
    }
    return 0;
}