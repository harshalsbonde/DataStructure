#include <iostream>
///////////////////////////////////////////////////
int partition(int* a, int p, int r) {
    int i, j;
    int tmp;
    int pivot;

    pivot = a[r];
    i = p - 1;
    for (j = p; j < r; ++j) {
        if (a[j] < pivot) {
            i = i + 1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }

    tmp = a[r];
    a[r] = a[i + 1];
    a[i + 1] = tmp;

    return (i + 1);
}
////////////////////////////////////////////////////
int QuickSort(int* a, int p, int r) {
    int q;

    if (p < r) {
        q = partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }

    return q;
}
////////////////////////////////////////////////////
int main()
{
	int a[] = { 67,22,99,44,12,63,45,9 };

	for (int i = 0; i <= 7; ++i)
		std::cout << a[i] << std::endl;

    QuickSort(a, 0, 7);

	for (int i = 0; i <= 7; ++i)
		std::cout << a[i] << std::endl;
}
////////////////////////////////////////////////////
