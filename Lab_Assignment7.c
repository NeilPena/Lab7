#include <stdio.h>
#include <stdlib.h>

//Fucntion to swap the values
void swap(int* x, int* y){
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

//Bubble sorting method of the swap
void bubbleSort(int arr[], int n){
    int i, j; 
    int swaps = 0; 
    int swap_count[100] = {0}; 

    for(i = 0; i < n - 1; i++){ 
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swaps++; 
                swap_count[arr[j]]++;
            }
        }
    }
    //Print out the nunmbers and the amount of times they were swapped
    for(i = 0; i < n; i++){
        printf("%d: %d\n", arr[i], swap_count[arr[i]]);
}

    //Print total numebr of swaps
    printf("Number of swaps: %d\n", swaps); 

}

//Selection sorting method of the swap
void selectionSort(int arr[], int n){
    int i, j, min_index, temp;
    int swaps = 0;
    int swap_count[100] = {0};

    for(i = 0; i < n-1; i++){
        min_index = i; 
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
            //Swap and increment the number of times swapped
            temp = arr[i]; 
            arr[i] = arr[min_index]; 
            arr[min_index] = temp;
            swaps++;
            swap_count[temp]++; 
    }  
    //Print ot the array of numbers witht the amount of swaps
    for(i = 0; i < n; i++){
            printf("%d: %d\n", arr[i], swap_count[arr[i]] - 1);
        }
    printf("Number of swaps: %d\n", swaps);

}

//Print out the sorted array
void printArray(int arr[], int size){
    printf("Sorted Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;

    //Bubble sorting Array
    printf("Array 1 (Bubble Sort):\n");
    bubbleSort(arr1, n);
    printArray(arr1, n); 
    printf("\nArray 2 (Bubble Sort):\n");
    bubbleSort(arr2, n); 
    printArray(arr2, n); 

    //Section Sorting Array
    printf("\nArray 1 (Selection Sort):\n");
    selectionSort(arr1, n);
    printArray(arr1, n);
    printf("\nArray 2 (Selection Sort):\n");
    selectionSort(arr2, n); 
    printArray(arr2, n);

    return 0; 
}
