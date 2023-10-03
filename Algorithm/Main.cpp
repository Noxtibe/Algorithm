#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Bubble Sort Algorithm
void bubbleSort(vector<int>& array) 
{
    int n = array.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in inner loop, the array is already sorted
        if (!swapped) 
        {
            break;
        }
    }
}

// Merge Sort Algorithm
void merge(vector<int>& array, int left, int middle, int right) 
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftarray(n1);
    vector<int> rightarray(n2);

    for (int i = 0; i < n1; i++) 
    {
        leftarray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) 
    {
        rightarray[i] = array[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (leftarray[i] <= rightarray[j]) 
        {
            array[k] = leftarray[i];
            i++;
        }
        else {
            array[k] = rightarray[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        array[k] = leftarray[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        array[k] = rightarray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& array, int left, int right) 
{
    if (left < right) 
    {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

int main() 
{
    vector<int> array = {100, 6, 12, 25, 7, 13, 18, 32, 4, 36, 3, 27, 11, 54, 76, 88, 55, 64, 94};
    vector<int> array2 = array; // Create a copy for merge sort

    cout << "Unsorted array : ";
    for (int num : array) 
    {
        cout << num << " ";
    }
    cout << "\n" << endl;

    // Measure time for Bubble Sort
    auto start = high_resolution_clock::now();
    bubbleSort(array);
    auto end = high_resolution_clock::now();
    auto durationBubble = duration_cast<microseconds>(end - start);

    cout << "Bubble Sort Result : ";
    for (int num : array) 
    {
        cout << num << " ";
    }
    cout << "\nBubble Sort Time : " << durationBubble.count() << " microseconds\n" << endl;

    // Measure time for Merge Sort
    start = high_resolution_clock::now();
    mergeSort(array2, 0, array2.size() - 1);
    end = high_resolution_clock::now();
    auto durationMerge = duration_cast<microseconds>(end - start);

    cout << "Merge Sort Result : ";
    for (int num : array2) 
    {
        cout << num << " ";
    }
    cout << "\nMerge Sort Time : " << durationMerge.count() << " microseconds\n" << endl;

    // Compare which algorithm is faster
    if (durationBubble.count() < durationMerge.count()) 
    {
        cout << "Bubble Sort is faster.\n" << endl;
    }
    else 
    {
        cout << "Merge Sort is faster.\n" << endl;
    }

    return 0;
}
