/* Omar Elsaghir
 * CSE-5311-005
 * Algorithms Project
 * Sorting algorithms source file
 */
#include <stdio.h>
#include <stdint.h>
#include "sorting_algorithms.h"
#include "utilities.h"

// Mergesort implementation. This function handles the implementation of merging 
// the two sorted halves (array[0] -> array[n/2], array[n/2 + 1] -> array[n-1]) into one array
// in ascending order.
void merge(int array[], int left, int middle, int right)
{
    int i, j, k;
    int m1 = middle - left + 1;
    int m2 = right - middle;

    int Left[m1], Right[m2];

    for(i = 0; i < m1; i++)
    {
        Left[i] = array[left + i];
    }
    for(j = 0; j < m2; j++)
    {
        Right[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < m1 && j < m2)
    {
        if(Left[i] <= Right[j])
        {
            array[k] = Left[i];
            i++;
        }
        else
        {
            array[k] = Right[j];
            j++;
        }
        k++;
    }

    while(i < m1)
    {
        array[k] = Left[i];
        i++;
        k++;
    }

    while(j < m2)
    {
        array[k] = Right[j];
        j++;
        k++;
    }

}

// This function implements the whole implementation of merge sort algorithm
void merge_sort(int array[], int left, int right)
{
    if(left < right)
    {
        // Calculate middle index of array
        int middle = left + (right -left) / 2;

        // Sorted left and right halves of array
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        // Merge both sorted halves into one final sorted array
        merge(array, left, middle, right);
    }
}

// Heap sort implementation
void Heapify(int array[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if((left < size) && (array[left] > array[i]))
    {
        largest = left;
    }

    if((right < size) && (array[right] > array[largest]))
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(&array[i], &array[largest]);
        Heapify(array, size, largest);
    }
}

void Heap_sort(int array[], int size)
{
    for(int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(array, size, i);
    }

    for(int i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        Heapify(array, i, 0);
    }
}

// Insertion sort implementation
void insertion_sort(int array[], int size)
{
    int key, j;
    for(int i = 0; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while(j >= 0 && key < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Selection sort implementation
void selection_sort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}

// Bubble sort implementation
void bubble_sort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
           if(array[j] > array[j + 1])
           {
              swap(&array[j], &array[j + 1]);
           }
        }
    }
}

// Partition implementation for quick sort
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

    return (i + 1);
}


void median_of_three(int array[], int low, int high)
{
    int mid = (low + high) / 2;

    if(array[low] > array[mid])
    {
        swap(&array[low], &array[mid]);
    }

    if(array[low] > array[high])
    {
        swap(&array[low], &array[high]);
    }

    if(array[mid] > array[high])
    {
        swap(&array[mid], &array[high]);
    }

    swap(&array[mid], &array[high]);
}

// This function represents the regular implementation of quick sort
void quick_sort_regular(int array[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(array, low, high);
        quick_sort_regular(array, low, pivot - 1);
        quick_sort_regular(array, pivot + 1, high);
    }
}

// This function implements the 3 medians version of quick sort
void quick_sort_three_medians(int array[], int low, int high)
{
    if(low < high)
    {
        median_of_three(array, low, high);
        int pivot = partition(array, low, high);
        quick_sort_three_medians(array, low, pivot - 1);
        quick_sort_three_medians(array, pivot + 1, high);
    }
}