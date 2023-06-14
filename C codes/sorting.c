#include <stdio.h>
#include <stdlib.h>

int main()
{
    in
    return 0;
}
int fill(int arr[],int size){
  for(int i=0;i<size;i++){
        printf("please enter the arr= ");
        scanf("%d",&arr[i]);
    }
    }
int printarr(int arr[],int size){
  for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
    }
int max(int arr[],int size){
    int max=arr[0];
  for(int i=0;i<size;i++){
        if (arr[i]>max)
            max=arr[i];
    }
    return max;
    }

int min(int arr[],int size){
    int min=arr[0];
  for(int i=0;i<size;i++){
        if (arr[i]<min)
            min=arr[i];
    }
    return min;
    }

int search(int arr[],int size,int key){
    int ff=arr[0];
  for(int i=0;i<size;i++){
        if (arr[i]==key)
            return i;
    }

    return -1;
    }
int sorrt(int arr[],int size){
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
