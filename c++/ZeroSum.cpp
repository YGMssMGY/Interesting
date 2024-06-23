#include<bits/stdc++.h>
using namespace std;
vector<string> sequences;

void generateSequences(string currentSequence, int currentIndex, int n) {
    if (currentIndex > n) {
        sequences.push_back(currentSequence);
        return;
    }
    if (currentIndex > 1) { 
        generateSequences(currentSequence + " " + to_string(currentIndex), currentIndex + 1, n);
    }

    generateSequences(currentSequence + "+" + to_string(currentIndex), currentIndex + 1, n);

    generateSequences(currentSequence + "-" + to_string(currentIndex), currentIndex + 1, n);
}

int calculateSum(const string& sequence) {
    int sum = 0;
    int number = 0;
    char sign = '+';
    for (char ch : sequence) {
        if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
        } else if (ch == '+' || ch == '-') {
            sum += (sign == '+') ? number : -number;
            number = 0;
            sign = ch;
        }
    }
    sum += (sign == '+') ? number : -number; 
    return sum;
}

int main() {
    int N;
    cin >> N;
    generateSequences("1", 2, N);
    vector<string> result;
    for (string& sequence : sequences) {
        if (calculateSum(sequence) == 0) {
            result.push_back(sequence);
        }
    }

    sort(result.begin(), result.end());
    for (const string& seq : result) {
        cout << seq << endl;
    }
    return 0;
}