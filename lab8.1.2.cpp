#include <stdio.h>

int findMax(int num[], int size);
void printAr(int myAr[], int size);
void addone(int number[], int add[], int sizeNum);
void addtwo(int number[], int pos[], int x);


int main() {
    int number[5] = {22, 50, 100, 99, 9};
    int score[10] = {20, 56, 10, 96, 5, 5, 30, 39, 24, 9};
    int n1[5] = {1, 2, 3, 4, 5};
    int pos[5];
    int max,x;

    max = findMax(number, 5);
    printf("%d\n", max);
    printf("\n");
    printAr(number,5);
    addone(number, score, 5);
    
    for(int i=0;i<5;i++){
    	scanf("%d",&pos[i]);
	}
	scanf("%d",&x);
	addtwo(number,pos,x);

    printf("\n");
    printAr(number, 5);
    
    printf("Maximum of these number is %d\n", max);
    
    return 0;
}
void addtwo(int number[], int pos[], int x){
	int i;
	for(i=0;i<5;i++){
		pos[i] += x;
	}
}

void addone(int number[], int add[], int sizeNum) {
    int i;
    for(i = 0; i < sizeNum ; i++) {
        number[i] = number[i] + add[i];
    }
}

void printAr(int myAr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("number[%d] : %d\n", i, myAr[i]);
    }
}

int findMax(int num[], int size) {
    int maximum, i = 0;
    maximum = num[0];

    for(i = 0; i < size; i++) {
        if(num[i] > maximum)
            maximum = num[i];
    }
    return maximum;
}
