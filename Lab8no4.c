#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random1to100();
int searchNum(int arr[],int size,int val);
int checkNum(int arr[],int size);
void printAr(int arr[],int size);
void best3_by_select(int arr[],int out[]);
void best3_by_sort(int arr[],int out[]);

int main(){
    int s1[4]={65,80,75,90};
    int s2[4]={65,80,75,90};
    int top[3];
    int i=0;

    best3_by_select(s1,top);
    printf("Best 3 (select): ");
    while(i<3){
        printf("%d ",top[i]);
        i++;
    }

    printf("\n");

    best3_by_sort(s2,top);
    printf("Best 3 (sort): ");
    for(i=0;i<3;i++)
        printf("%d ",top[i]);

    return 0;
}

void printAr(int arr[],int size){
    int i=0;
    do{
        printf("%d ",arr[i]);
        i++;
    }while(i<size);
}

int checkNum(int arr[],int size){
    int n=random1to100();
    while(searchNum(arr,size,n)==1)
        n=random1to100();
    return n;
}

void best3_by_select(int arr[],int out[]){
    int a=arr[0],b=arr[1],c=arr[2],d=arr[3];
    int i,j,temp;
    int tmp[4]={a,b,c,d};

    for(i=0;i<3;i++){
        for(j=i+1;j<4;j++){
            if(tmp[i]<tmp[j]){
                temp=tmp[i];
                tmp[i]=tmp[j];
                tmp[j]=temp;
            }
        }
        out[i]=tmp[i];
    }
}

void best3_by_sort(int arr[],int out[]){
    int i=0,j,temp;

    while(i<4){
        j=0;
        while(j<3){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            j++;
        }
        i++;
    }

    for(i=0;i<3;i++)
        out[i]=arr[i];
}

int searchNum(int arr[],int size,int val){
    int i;
    for(i=0;i<size;i++)
        if(arr[i]==val)
            return 1;
    return 0;
}

int random1to100(){
    return rand()%100+1;
}
