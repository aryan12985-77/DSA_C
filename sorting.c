#include<stdio.h>

//functio declearation
void readArray(int arr[],int n);
void printArray(int arr[],int n);

void bubbleSort(int arr[],int n);
void selectionSort(int arr[],int n);
void insertionSort(int arr[],int n);

//read and print functions
void readArray(int arr[],int n){
printf("Enter %d elements:\n",n);
for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
}

void printArray(int arr[],int n){
for(int i=0;i<n;i++)
    printf("%d",arr[i]);
printf("\n");
}

int main(){
int arr[100],n,choice;

printf("Enter numbers of elements:");
scanf("%d",&n);

readArray(arr,n);
do{
printf("\nChoose sorting method\n");
printf("1.bubble\n2.selection\n3.insertion\n");
printf("-----------------\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:
    bubbleSort(arr,n);
    printf("\n Array after sorting:\t");
    break;
case 2:
    selectionSort(arr,n);
    printf("\n Array after sorting:\t");
    break;
case 3:
    insertionSort(arr,n);
    printf("\n Array after sorting:\t");
    break;
    deafult:
        printf("Invalid choice\n");
        return 0;
}
printArray(arr,n);
return 0;
}while(choice!=4);
}

//bubble sort:1.compare first and second element if first is greater then swap them
//2.repeat until end of pair,largest element goes for last
void bubbleSort(int arr[],int n){
int i,j,temp;
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[i]){
                //swaping
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
}

//selection sort:1.find the smallest element in array, swap it with first element
//2.continue it until all elements are sorted
void selectionSort(int arr[],int n){
int i,j,midIndex,temp;
for(i=0;i<n-1;i++);
midIndex=i; //assume i is smallest element and compare it to anothers
for(j=i+1;j<n;j++){
    if(arr[j]<arr[midIndex])
        midIndex=j; //found smaller element
}
//swaping
temp=arr[i];
arr[i]=arr[midIndex];
arr[midIndex]=temp;
}

//1.assume the first element is sorted
//2.take next element and compare it to elements with sorted part
//3.insert it on correct position,shift larger element to right,repeat for all
void insertionSort(int arr[],int n){
int i,key,j;
for(i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
}
