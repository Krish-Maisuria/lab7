#include <stdio.h>
#include <stdlib.h>

// Struct to represent an element and its swaps
typedef struct {
    int value;
    int swaps_bubble;
    int swaps_selection;
} Element;

// Function to perform Bubble Sort and count the number of swaps
int bubbleSort(Element arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                // Swap the elements
                Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                arr[j].swaps_bubble++;
                arr[j + 1].swaps_bubble++;
            }
        }
    }
    return swaps;
}

// Function to perform Selection Sort and count the number of swaps
int selectionSort(Element arr[], int n) {
    int swaps2 = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].value < arr[min_index].value) {
                min_index = j;
            }
        }
        if (min_index != i) {
            // Swap the elements
            Element temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps2++;
            arr[i].swaps_selection += swaps2; // Increment swap count for the selected element
            arr[min_index].swaps_selection += swaps2; // Increment swap count for the minimum element
        }
    }
    return swaps2;
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    // Create Element arrays to track swaps
    Element elements1[n1];
    Element elements2[n2];

    // Initialize Element arrays
    for (int i = 0; i < n1; i++) {
        elements1[i].value = array1[i];
        elements1[i].swaps_bubble = 0;
        elements1[i].swaps_selection = 0;
    }

    for (int i = 0; i < n2; i++) {
        elements2[i].value = array2[i];
        elements2[i].swaps_bubble = 0;
        elements2[i].swaps_selection = 0;
    }

    // Perform Bubble Sort and count swaps for array 1
    int total_swaps1_bubble = bubbleSort(elements1, n1);

    // Perform Selection Sort and count swaps for array 1
    //int total_swaps1_selection = selectionSort(elements1, n1);

    int total_swaps2_selection = selectionSort(elements2, n2);

    // Display swaps for array 1
    printf("Array 1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: Bubble Sort swaps: %d\n", elements1[i].value, elements1[i].swaps_bubble);
    }
    printf("Total Bubble Sort swaps: %d\n", total_swaps1_bubble);
    printf("\n");

    for (int i = 0; i < n2; i++) {
        printf("%d: Selection Sort swaps: %d\n", elements2[i].value, elements2[i].swaps_selection);
    }
    printf("Total Selection Sort swaps: %d\n", total_swaps2_selection);

    for (int i = 0; i < n1; i++) {
        printf("%d: Selection Sort swaps: %d\n", elements1[i].value, elements1[i].swaps_selection);
    }
    printf("Total Selection Sort swaps: %d\n", total_swaps2_selection);
    printf("\n");

    // Perform Bubble Sort and count swaps for array 2
    int total_swaps2_bubble = bubbleSort(elements2, n2);

    // Perform Selection Sort and count swaps for array 2
    int total_swaps1_selection = selectionSort(elements1, n1);
   // int total_swaps2_selection = selectionSort(elements2, n2);

    // Display swaps for array 2
    printf("Array 2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: Bubble Sort swaps: %d\n", elements2[i].value, elements2[i].swaps_bubble);
    }
    printf("Total Bubble Sort swaps: %d\n", total_swaps2_bubble);
    printf("\n");

   for (int i = 0; i < n1; i++) {
        printf("%d: Selection Sort swaps: %d\n", elements1[i].value, elements1[i].swaps_selection);
    }
    printf("Total Selection Sort swaps: %d\n", total_swaps1_selection);
    printf("\n");

    return 0;
}