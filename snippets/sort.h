/**
    Collection of various popular sorting algorithms

    Includes:
    InsertionSort(int array[], int size)
    BubbleSort(int array[], int size)
    MergeSort(int array[], int size) **Not working yet
    QuickSort (int array[], int left, int right)

**/


void InsertionSort(int list[], int size) {

    int on_deck, comparing;

    if (size <= 1)
        return;

    for (int i = 1; i < size; i++) {
        on_deck = list[i];
        comparing = i - 1;

        while ((comparing >= 0) && (on_deck < list[comparing])) {
            list[comparing+1] = list[comparing];
            list[comparing] = on_deck;
            comparing -= 1;

        }
    }
}


void BubbleSort(int list[], int size) {

    int compare, on_deck;

    if (size <= 1)
        return;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            on_deck = list[j];
            compare = list[j+1];

            if (compare < on_deck) {
                int tmp = on_deck;
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
}

/**
void MergeSort(int list[], int size) {

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
}
***/

void QuickSort(int list[], int left, int right) {

    int i = left, j = right;
    int pivot = list[(i + j)/2];

    while (i <= j) {
        while (list[i] < pivot)
            i++;
        while (list[j] > pivot)
            j--;
        if (i <= j) {
            int tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;

            i++;
            j--;
        }
    }

    if (left < j)
        QuickSort(list, left, j);

    if (i < right)
        QuickSort(list, i, right);
}
