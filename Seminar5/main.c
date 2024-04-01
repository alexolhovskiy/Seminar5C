#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int seedCount(int* arr) {
    return pow(2, arr[0] - 1);
}

int commDevisor(int* arr) {
    int i;
    if (arr[0] >= arr[1]) {
        i = arr[1];
    }
    else {
        i = arr[0];
    }

    for (i; i > 0; i--) {
        if ((arr[0] % i == 0) && (arr[1] % i == 0)) {
            return i;
        }
    }
    return 0;
}

int getCount(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int* getComponents(int num,int*size) {
    *size = getCount(num);
    int* newArr = (int*)malloc(*size);
    int n = 0;
    while (num > 0) {
        newArr[n++] = num % 10;
        num /= 10;
    }
    return newArr;
}

int isSumEqualMult(int* arr) {
    int sum=0,mult=1,i,size = 0;
    int*newArr = getComponents(arr[0], &size);
    for (i = 0; i < size; i++) {
        sum += newArr[i];
        mult *= newArr[i];
    }
    return sum == mult ? 1 : 0;
}


int sumAllNumbers(int* arr) {
    int i,sum = 0;
    for (i = 1; i <= arr[0]; i++) {
        sum += i;
    }
    return sum;
}

int main(void)
{
    setlocale(LC_ALL, "Rus");
    int arr[10];

    //1
    printf("Task 1\n");
    printf("Enter number 1-64\n");
    scanf_s("%d", &arr[0]);
    printf("Result is %d\n", seedCount(arr));
    printf("\n\n");

    //2
    printf("Task 2\n");
    printf("Enter 2 numbers\n");
    scanf_s("%d %d", &arr[0],&arr[1]);
    printf("Result is %d\n", commDevisor(arr));
    printf("\n\n");

    //3
    printf("Task 3\n");
    printf("Enter number\n");
    scanf_s("%d", &arr[0]);
    isSumEqualMult(arr)==1?printf("YES\n"):printf("NO\n");
    printf("\n\n");

    //4
    printf("Task 4\n");
    printf("Enter number\n");
    scanf_s("%d", &arr[0]);
    printf("Result is %d\n", sumAllNumbers(arr));
    printf("\n\n");


    //5
    printf("Task 5\n");
    printf("Enter string of '(' and ')'\n");
    int n = 0;
    char c;
    while ((c = getchar()) != '.') {
        switch (c) {
        case '(':n++; break;
        case ')':n--; break;
        default:;
        }
    }
    n == 0 ? printf("YES\n") : printf("NO\n");
    printf("\n\n");

    return 0;
}
