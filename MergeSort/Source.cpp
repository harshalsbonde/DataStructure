#include <cstddef>
#include <malloc.h>
#include <iostream>
void Merge(int* a, int p, int q, int r)
{
	int* a1 = NULL;
	int* a2 = NULL;

	int N1 = q - p+1;
	int N2 = r - q;

	a1 = (int*)malloc(sizeof(int) * N1);
	if (a1 == NULL)
		return;

	a2 = (int*)malloc(sizeof(int) * N2);
	if (a2 == NULL)
		return;

	int cnt = 0;
	for (cnt = 0; cnt < N1; ++cnt)
		a1[cnt] = a[p + cnt];

	for (cnt = 0; cnt < N2; ++cnt)
		a2[cnt] = a[q + 1 + cnt];

	int i = 0;
	int j = 0;
	int k = 0;

	while (true)
	{
		if (a1[i] <= a2[j])
		{
			a[p + k] = a1[i];
			k = k + 1;
			i = i + 1;
			if (i == N1)
			{
				while (j < N2)
				{
					a[p + k] = a2[j];
					k = k + 1;
					j = j + 1;
				}
				break;
			}
		}
		else
		{
			a[p + k] = a2[j];
			k = k + 1;
			j = j + 1;
			if (j == N2)
			{
				while (i < N1)
				{
					a[p + k] = a1[i];
					k = k + 1;
					i = i + 1;
				}
				break;
			}
		}
	}

	free(a1); a1 = NULL;
	free(a2); a2 = NULL;
}

void MergeSort(int* a, int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;

		MergeSort(a, p, q);
		MergeSort(a, q + 1, r);
		Merge(a, p, q, r);
	}
}

int main()
{
	int a[] = { 67,22,99,44,12,63,45,9 };

	for (int i = 0; i <= 7; ++i)
		std::cout << a[i] << std::endl;

	MergeSort(a, 0, 7);

	for (int i = 0; i <= 7; ++i)
		std::cout << a[i] << std::endl;
}
