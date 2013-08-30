void swap(int& x, int& y) {
// Swaps values by reference with only two variables

    x = x + y;
    y = x - y;
    x = x - y;
}
