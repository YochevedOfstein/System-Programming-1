
#include "NumClass.h"

/* 
will return 0 if false and 1 if true
*/


int isPrime(int num){

if( num < 1) return 0;

if ((num == 1)||(num == 2)){
    return 1;
}

if (num % 2 == 0) return 0;

for (int i = 3; i*i <= num; i = i + 2){
    if(num%i == 0){
        return 0;
    }
}

return 1;

}

int factorial(int num){
    int fact = 1;
    if(( num == 0) || (num == 1)){
        return fact;
    }
    else{
        for(int i = 2; i <= num; i++){
            fact = fact*i;
        }
    }
    return fact;
}

int isStrong(int num){

int origNum = num;
int sum = 0;
int digit= 0;

while(num>0){
digit = num%10;
sum = sum + factorial(digit);
num = num/10;
}
if(origNum == sum){
    return 1;
}
return 0;
}