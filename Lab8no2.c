#include <stdio.h>

int checkscore(char std[], char ans[]);
int FirstAns(char std[],char key);
void checkHardest(char std[], char keys[], int temp[],int *MIN);

int main() {
    char charkeys[10] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};
    char ans[8][10]={
        {'A','B','A','C','C','D','E','E','A','D'},//7
        {'D','B','A','B','C','A','E','E','A','D'},//6
        {'E','D','D','A','C','B','E','E','A','D'},//5
        {'C','B','A','E','D','C','E','E','A','D'},//4
        {'A','B','D','C','C','D','E','E','A','D'},//8
        {'B','B','E','C','C','D','E','E','A','D'},//7
        {'B','B','A','C','C','D','E','E','A','D'},//7
        {'E','B','E','C','C','D','E','E','A','D'}};//7
    int sum=0;
    for (int i = 0; i < 8; i++) {
        printf("std %d score: %d\n", i + 1, checkscore(charkeys, ans[i]));
    }
    int first = 0;
    for (int i = 0; i < 8; i++) {
        first += FirstAns(ans[i], charkeys[0]);
    }
    printf("first choice = %d\n",first);

    int temp[10] = {0};
	int MIN;
    for(int i = 0; i < 8; i++) {
        checkHardest(ans[i], charkeys, temp,&MIN);
    }
    printf("The hardest question : %d\n",MIN+1);


    return 0;
}

int checkscore(char std[], char ans[]) {
    int count=0;
    for (int i=0; i<10; i++) {
        if (ans[i]==std[i]) {
            count++;
        }
    }
    return count;
}

int FirstAns(char std[], char key) {
    if (std[0] == key) {
        return 1;
    } else {
        return 0;
    }
}

void checkHardest(char std[], char keys[], int temp[],int *MIN) {
    int i;
    for(i = 0; i < 10; i++) {
        if(std[i] == keys[i]) {
            temp[i]++;
        }
    }
    *MIN = temp[0];
    for(i = 0; i < 10; i++) {
        if(temp[i] < *MIN) {
            *MIN = i;
        }
    }
}
