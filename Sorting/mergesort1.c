#include<stdio.h>
#define MAX 100
void merge(int arr[],int l, int mid, int r){
    int n1 = mid - l +1;
    int n2 = r - mid;
    int Left[n1], Right[n2];
    int k = l;
    for(int i = 0;i<n1;i++){
        Left[i]=arr[k++];
    }
    for(int j = 0;j<n2;j++){
        Right[j]=arr[k++];
    }

int i = 0, j =0;
k=l;
while(i<n1 && j<n2){
    if(Left[i]<=Right[j]){
        arr[k++]=Left[i++];
    }
    else{
        arr[k++]=Right[j++];
    }
}
while(i<n1){
    arr[k++]=Left[i++];
}
while(j<n2){
    arr[k++]=Right[j++];
}

}void mergeSort(int arr[],int l, int r){
    if(l>=r){
        return ;
    }
    int mid = l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}int main(){
    int arr[MAX];
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    printf("Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

