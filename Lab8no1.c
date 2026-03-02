#include <stdio.h>

void addone(int number[], int add[]);
void addtwo(int number[], int pos[], int x);
void addthree(int number[], int pos[][2], int Arrsize);
int findMax(int num[]);
void PrintArray(int arr[]);

int main(){
    int number[5] = {20, 50, 100, 99, 9};
    int add[5];
    int pos[5];
    int posthree[5][2];
    int x, max;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &add[i]);
    }
    addone(number, add);

    for (int i = 0; i < 5; i++) {
        scanf("%d", &pos[i]);
    }
    scanf("%d", &x);
    addtwo(number, pos, x);

    for (int i = 0; i < 5; i++) {
        scanf("%d %d", &posthree[i][0], &posthree[i][1]);
    }
    addthree(number, posthree,5);

    PrintArray(number);
    max = findMax(number);
    printf("Maximum of these number is %d\n", max);

    return 0;
}

void addone(int number[], int add[]) {
    for (int i = 0; i < 5; i++) {
        number[i] += add[i];
    }
}

void addtwo(int number[], int pos[], int x) {
    for (int i = 0; i < 5; i++) {
        if (pos[i] > 0) {
            number[pos[i] - 1] += x;
        }
    }
}

void addthree(int number[], int pos[][2], int Arrsize)
{
    for(int i = 0; i < Arrsize; i++)
    {
        number[pos[i][0] - 1] += pos[i][1];
    }
}

int findMax(int num[]) {
    int max = num[0];
    for (int i = 1; i < 5; i++) {
        if (num[i] > max)
            max = num[i];
    }
    return max;
}

void PrintArray(int arr[]) {
    for (int i = 0; i < 5; i++) {
        printf("number[%d] : %d\n", i + 1, arr[i]);
    }
}

