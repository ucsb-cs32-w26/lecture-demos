#include<iostream>
/**
 * Function to merge two halves of the array
 * arr: input array
 * assume two sorted halves: [left, mid] and (mid, right]
 */
void merge(int arr[], int left, int mid, int right) {
    // Step 4: make sure you uncomment the call to merge() in mergeSort() function

    // Step 5: fix n1 and n2 to reflect actual size of the halves
    int n1 = 0;     // Size of the left half
    int n2 = 0;     // Size of the right half

    // Create temporary arrays to hold the two halves
    int L[n1], R[n2];

    // Copy data into temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the two halves back into arr[]
    
    // Step 6: initialize i, j, k
    int i = 0, j = 0, k = 0;

    // Step 7: fix compare and copy
    while(i < n1 && j < n2) {
        // Step 7a: fix the condition here
        if(true) {
            arr[k] = L[i];
            ++i;
        } else {
            // Step 7b: fix steps to do when you need to copy from R
        }
        ++k;
    }

    // Copy any remaining elements of L[] (if any)
    while(i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Step 8: Copy any remaining elements of R[] (if any)
    while(false) {
        ;
    }    
}

/**
 * Recursive Merge Sort function
 */
void mergeSort(int arr[], int left, int right) {
    std::cout<<"mergeSort(arr, "<<left<<", "<<right<<")\n";
    
    // Step 1: update condition to ensure recursion teminates properly
    if (false) {        
        // Step 2: find the middle point
        int mid = 0;

        // Step 3: recursively sort the first and second halves
        

        // leave the call to merge() commented out for activity 1
        // Merge the sorted halves
        // merge(arr, left, mid, right);

    }
}
