#include "NumClass.h"

/* 
will return 0 if false and 1 if true
*/

int isPalindrome(int num){

int reverse = 0;
int remainder = 0;
int origNum = num;

while(num != 0) {
    remainder = num % 10;
    reverse = reverse * 10 + remainder;
    num = num/10;
}
if (reverse == origNum){
    return 1;
}
return 0;
}

int Power(int num, int power){
    
    int result = 1;
    for(int i = 1; i<= power; i++){
        result = result * num;
        }
    
    return result;
}

int digitCount(int num){

 int digitCount = 0;
    while(num != 0) {
        num = num/10;
        digitCount++;
    }
    return digitCount;
}

int isArmstrong(int num){

    int origNum = num;
    int remainder = 0;
    int sum = 0;
    int digit = digitCount(num);


    while(num != 0) {
        remainder = num % 10;
        sum = sum + Power(remainder, digit);
        num = num/10;
    }

    if(sum == origNum){
        return 1;
    }
    return 0;
}