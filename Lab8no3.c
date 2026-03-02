#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random1to100();
int searchNum(int arr[], int size, int key);
int checkNum(int arr[], int size);
void printAr(int arr[], int size);
void best3_by_select(int arr[], int top3[]);
void best3_by_sort(int arr[], int top3[]);

int main(){
    int score1[4]={65,80,75,90};
    int score2[4]={65,80,75,90};
    int best3[3];
    int k;

    best3_by_select(score1,best3);
    printf("Best 3 (select): ");
    for(k=0;k<3;k++)
        printf("%d ",best3[k]);

    printf("\n");

    best3_by_sort(score2,best3);
    printf("Best 3 (sort): ");
    for(k=0;k<3;k++)
        printf("%d ",best3[k]);

    return 0;
}

void printAr(int arr[],int size){
    int k=0;
    while(k<size){
        printf("%d ",arr[k]);
        k++;
    }
}

int checkNum(int arr[],int size){
    int x=random1to100();
    while(searchNum(arr,size,x)!=0)
        x=random1to100();
    return x;
}

void best3_by_select(int arr[],int top3[]){
    int used[4]={0,0,0,0};
    int i,j,largest,pos;

    for(i=0;i<3;i++){
        largest=-9999;
        for(j=0;j<4;j++){
            if(!used[j] && arr[j]>largest){
                largest=arr[j];
                pos=j;
            }
        }
        top3[i]=largest;
        used[pos]=1;
    }
}

void best3_by_sort(int arr[],int top3[]){
    int i,j,tmp;
    for(i=0;i<3;i++){
        for(j=i+1;j<4;j++){
            if(arr[i]<arr[j]){
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    for(i=0;i<3;i++)
        top3[i]=arr[i];
}

int searchNum(int arr[],int size,int key){
    int i=0;
    while(i<size){
        if(arr[i]==key)
            return 1;
        i++;
    }
    return 0;
}

int random1to100(){
    return (rand()%100)+1;
}
