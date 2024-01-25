#include <stdio.h>
#include "NumClass.h"

int main(){

    int number1;
    int number2;

    printf("Enter first number:\n");
    scanf("%d", &number1);

    printf("Enter second number:\n");
    scanf("%d", &number2);
    
        printf("The Armstrong numbers are:");
    
    for( int i =number1; i<= number2; i++){
        if(isArmstrong(i) == 1){
          printf(" %d", i);
        }
    }
    
    printf("\nThe Palindromes are:");

    for( int i =number1; i<= number2; i++){
        if(isPalindrome(i) == 1){
         printf(" %d", i);
        }
    }


    printf("\nThe Prime numbers are:");

        for( int i =number1; i<= number2; i++){
        if(isPrime(i) == 1){
          printf(" %d", i);  
        }
    } 
    
    printf("\nThe Strong numbers are:");

    for( int i =number1; i<= number2; i++){
        if(isStrong(i) == 1){
          printf(" %d", i); 
        }
    }
     printf("\n");      
}
