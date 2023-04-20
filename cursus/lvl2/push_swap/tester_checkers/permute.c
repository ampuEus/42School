#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int arr[], int start, int end) {
	if (start == end) {
		for (int i = 0; i <= end; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i <= end; i++) {
		swap(&arr[start], &arr[i]);
		permute(arr, start+1, end);
		swap(&arr[start], &arr[i]);
	}
}

int main(int argc, char **argv)
{
	unsigned int len = 0;

	int *arr = malloc(argc * sizeof(*arr));
	if (!arr)
		return (1);
	while (argv[++len])
		arr[len-1] = strtol(argv[len], NULL, 10);
	len -= 2;
	permute(arr, 0, len);
	free(arr);
	return (0);
}
