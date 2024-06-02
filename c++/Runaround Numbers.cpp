#include<bits/stdc++.h>
using namespace std;

int digitsUsed[10], digitPlace[10], resultArray[1000005], total;
inline void addNumber(int upperLimit){
    int result=0, flag=0;
    for(int index=1; index<=upperLimit; ++index){
        if(!digitPlace[index]) flag=1;
        result = result*10 + digitPlace[index];
    }
    if(!flag) resultArray[++total] = result;
}

inline void depthFirstSearch(int position, int x, int upperLimit){
    if(x > upperLimit){
        addNumber(upperLimit);
        return;
    }
    for(int digit=1; digit<=9; ++digit){
        if(!digitsUsed[digit]){
            int nextPosition = (position-1 + digit) % upperLimit + 1;
            if(x != upperLimit){
               if(!digitPlace[nextPosition]){
                    digitPlace[position] = digit;
                    digitsUsed[digit] = 1;
                    depthFirstSearch(nextPosition, x+1, upperLimit);
                    digitPlace[position] = 0;
                    digitsUsed[digit] = 0;
               }
            }
            else{
                if(nextPosition == 1){
                    digitPlace[position] = digit;
                    digitsUsed[digit] = 1;
                    depthFirstSearch(nextPosition, x+1, upperLimit);
                    digitPlace[position] = 0;
                    digitsUsed[digit] = 0;
                }
            }
        }
    }
}

int main(){
    int inputNumber;
    scanf("%d", &inputNumber);
    for(int i=1; i<=9; ++i){
        depthFirstSearch(1, 1, i);
    }
    sort(resultArray+1, resultArray+1+total);
    for(int i=1; i<=total; ++i){
        if(resultArray[i] > inputNumber){
            printf("%d\n", resultArray[i]);
            break;
        }
    }
    return 0;
}