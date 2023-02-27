#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int partitionQS(int arr[], int start, int end){
  int pivot = arr[end];
  int j = start - 1;
  for (int i = start; i <= end-1; i++) {
    if(arr[i] <= pivot){
      j++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[j+1], arr[end]);
  return j+1;
}

void quickSort(int arr[], int start, int end){
  if(start < end){
    int pivot = partitionQS(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
  }
}

void selectionSort(int arr[], int n){
  for(int i = 0; i < n-1; i++){
    int min = i;
    for (int j = i+1; j < n; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}

void reverseSelectionSort(int arr[], int n){
  for(int i = 0; i < n; i++){
    int max = i;
    for (int j = i+1; j < n; j++){
      if(arr[j] > arr[max]){
        max = j;
      }
    }
    swap(arr[i], arr[max]);
  }
}

int main() {
  int arr[] = {7, 2, 1, 200, 6, 8, 5, 300, 3, 4, 10, 9, 30, 80, 500, 90, 40, 50, 400, 70, 20, 60, 100};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("=== QUICK SORTING ===\n");
  quickSort(arr, 0, n-1);
  printf("SORTED ARRAY: \n");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  } printf("\n");

  printf("=== SELECTION SORTING ===\n");
  reverseSelectionSort(arr, n);
  printf("REVERSE SORTED ARRAY: \n");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  } printf("\n");


  selectionSort(arr, n);
  printf("SORTED ARRAY: \n");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  } printf("\n");

  return 0;
}