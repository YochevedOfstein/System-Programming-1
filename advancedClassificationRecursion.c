#include "NumClass.h"

/* 
will return 0 if false and 1 if true
*/

int Power(int num, int power){
    
   if(power == 0) return 1;

   return num * Power(num, power-1);
}

int digitCount(int num){

    if(num == 0) return 0;

    return digitCount(num/10)+1;
}

int isPalindromeHelper(int num, int digits){

    if(digits<2) return 1;
    int dis = Power(10,digits-1);
    int lastD = num%10;
    int firstD = (num - (num % dis))/dis;
    if(firstD != lastD) return 0;

    return isPalindromeHelper(((num % dis)/10), digits - 2);
}


int isPalindrome(int num){
    
    int numOfDigits = digitCount(num);
    return(isPalindromeHelper(num,numOfDigits));
}

int isArmstrongHelper(int num, int digits){

    if(num == 0) return 0;

    return Power(num % 10, digits) + isArmstrongHelper(num/10,digits);
}

int isArmstrong(int num){

    if(num <= 0) return 0;

    int numOfDigits = digitCount(num);

    if(isArmstrongHelper(num,numOfDigits)==num){
        return 1;}

    return 0;
}