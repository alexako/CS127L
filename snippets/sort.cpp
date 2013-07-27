/**
    Collection of various popular sorting algorithms

    Includes:
    InsertionSort()
    BubbleSort()
    MergeSort()
    QuickSort ()

    *All functions return a pointer to a sorted int array
        When function is called, must be assigned to int *
        Dependency:
            Swap.cpp --> Swap()
**/

#include <iostream>
#include <cstdlib>

using namespace std;


int * InsertionSort(int list[], int size) {

    int on_deck, comparing;

    if (size <= 1)
        return list;

    for (int i = 1; i < size; i++) {
        on_deck = list[i];
        comparing = i - 1;

        while ((comparing >= 0) && (on_deck < list[comparing])) {
            list[comparing+1] = list[comparing];
            list[comparing] = on_deck
            comparing -= 1;

        }
    }

    return list;
}

int * BubbleSort(int list[], int size) {

    int compare, on_deck;

    if (size <= 1)
        return list;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            on_deck = list[i];
            compare = list[j];

            if (compare < on_deck) {
                Swap(on_deck, compare);
            }
        }
    }

    return list;
}


int * MergeSort(int list[], int size) {

    int sizeL, sizeR;

    if (size <= 1)
        return list;

    //Don't think this part works
    //Declaration of arrays work like this:
    // int array[] = {};
    int mid = size / 2;
    int left[] = MergeSort(list[:mid]);
    int right[] = MergeSort(list[mid:]);

    int sorted_list[size] = {};

    while ((sizeL > 0) && (sizeR > 0)) {
            if (left[0] > right[0])
                sorted_list.append(right.pop(0));
            else
                sorted_list.append(left.pop(0));
    }

    //This part definitely won't work
    if (sizeL > 0) {
        sorted_list.extend(MergeSort(left));
    else
        sorted_list.extend(MergeSort(right));
    }

    return sorted_list;
}


int * QuickSort(int list[], int size) {

    if (size <= 1)
        return list;

    int sorted_list[size] = {};
    int last = size - 1,
        change = list[last];

    int low[] = {};
    int high[] = {};

    for (int index = 0;index < )

    return sorted_list;
}


int main() {

    int nums[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter a number: ";
        cin >> nums[i];
    }

    Quicksort(nums, 5);

    cout << "Sorted array: ";
    for (int i = 0; i < 5; i++)
        cout << nums[i] << " ";

    cout << endl;

    return 0;
}
