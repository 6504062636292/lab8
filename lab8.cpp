#include <stdio.h>

int findMax(int num[],int size);
void printAr(int myAr[],int size);
main() {
	int number[5] = {22,50,100,99,9};
	int score[10] = {20,56,10,96,5,5,30,39,24,9};
	int max;

	max = findMax(number,5);
	printAr(number,5);
	//printf("number[0] : %d\n",number[0]);
	//printf("number[1] : %d\n",number[1]);
	//printf("number[2] : %d\n",number[2]);
	//printf("number[3] : %d\n",number[3]);
	//printf("number[4] : %d\n",number[4]);
	printf("Maximum of these number is %d\n",max);
}
void printAr(int myAr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("number[%d] : %d\n",i,myAr[i]);
	}
}

int findMax(int num[],int size) {
	int maximum,i=0;
	maximum = num[i];

	for(i=0;i<5;i++) {
		if(num[i] > maximum)
			maximum = num[i];
	}
	return maximum;
	
}

/* result
number[1] : 20
number[2] : 50
number[3] : 100
number[4] : 99
number[5] : 9
Maximum of these number is 100
*/
