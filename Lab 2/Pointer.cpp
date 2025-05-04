#include <stdio.h>
#include<cstdlib>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is Palindrome
void Palindrome(int *num) {
    int temp = *num, reversed = 0, remainder;
    while (temp > 0) {
        remainder = temp % 10;
        reversed = reversed * 10 + remainder;
        temp /= 10;
    }
    if(*num == reversed)
    {
        printf("It is an Palindrme\n");
    }
    else
    {
        printf("It is not an Palindrome\n");
    }
}

// Function to check if a number is Armstrong
void Armstrong(int *num) {
    int temp = *num, sum = 0, digits = 0, digit;
    while (temp>0) {
        digits++;
        temp /= 10;
    }
    temp = *num;
    while (temp>0) {
        digit = temp % 10;
        sum += pow(digit, digits);//digit^digits
        temp /= 10;
    }
    if(*num == sum)
    {
        printf("It is an Armstrong Number\n");
    }
    else
    {
        printf("It is not an Armstrong Number\n");
    }
}

// Function to check if a number is Perfect
void Perfect(int *num) {
    int sum = 0;
    for (int i = 1; i <= *num / 2; i++) {
        if (*num % i == 0) {
            sum += i;
        }
    }
    if (sum == *num)
    {
        printf("Perfect Number\n");
    }
    else
    {
        printf("Not a Perfect Number\n");
    }
}

int main() {
    int *choice;
    choice=(int *)malloc(sizeof(int));
    while (1) {
        printf("\nMenu:\n");
        printf("1. Palindrome\n2. Armstrong Number\n3. Perfect Number\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", choice);

        if (*choice == 4) {
            printf("Exiting...\n");
            break;
        }

        int *num = (int *)malloc(sizeof(int));
        printf("Enter a number: ");
        scanf("%d", num);

        switch (*choice) {
            case 1:
                Palindrome(num);
                break;
            case 2:
                Armstrong(num);
                break;
            case 3:
                Perfect(num);
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

        free(num); //To free allocated memory
    }
    return 0;
}
