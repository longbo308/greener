#include <stdio.h>
#include <string.h>
int insert_sort (int* arr, int n){
    /*
     * Standard in-place insertion sort.
     * This avoids allocating a temporary array and does fewer copies:
     * - Best case (already sorted): O(n) comparisons, O(1) moves
     * - Worst case: O(n^2) shifts
     */
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        /* shift elements to the right to make room for key */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return 0; /* keep int return type for compatibility */
}
void bubble(int* arr,int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int arr[]={1,34,11,55,2};
    int arr1[]={1,34,11,55,2};
    bubble(arr,5);
    for (int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }printf("\n");
    insert_sort(arr1,5);
    for (int i=0;i<5;i++){
        printf("%d ",arr1[i]);
    }
    return 0;

}
