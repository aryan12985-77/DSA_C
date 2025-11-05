#include<stdio.h>
int main(){
int arr[50],n,x,i,low,high,mid,pos=-1;
printf("Enter size of an array:\n");
scanf("%d",&n);
printf("Enter sorted elements:\n");
for(i=0;i<n;i++){
     scanf("%d",&arr[i]);
}
printf("Enter elements to search:\n");
scanf("%d",&x);
low=0;
high=n-1;
while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==x){
        pos=mid;
    break;
      }else if(arr[mid]<x){
    low=mid+1;
     }else{
           high=mid-1;
   }
}
if(pos==-1){
    printf("%d not found in an array",x);
}else{
printf("%d\nfound at position%d",x,pos+1);
}
return 0;
}
