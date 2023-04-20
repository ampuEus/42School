#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
	int *temp;

	temp = a;
	a = b;
	b = temp;
}

void permute(int arr[], unsigned int len) {
	if (len = 1)
		printf("%i ", arr);
	else {
		for (int i = 0; i < len - 2; i++) {
			permute(arr, len-1);
			(len % 2) ? swap(&arr[0], &arr[len-1]) : swap(&arr[i], &arr[len-1]);
			permute(arr, len-1);
		}
	}
}

int main(int argc, char **argv)
{
	int data = strtok(argc, " ");
	permute(argv + 1, argc - 1);
	return (0);
}
