#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/* chmod 755 *.txt */

int count = 0;



char *concatenate(const char *a, const char *b, const char *c, const char *d, const char *e) {
	size_t alen = strlen(a);
	size_t blen = strlen(b);
	size_t clen = strlen(c);
	size_t dlen = strlen(d);
	size_t elen = strlen(e);
	char *res = malloc(alen + blen + clen + dlen + elen + 1);
	if (res) {
		memcpy(res, a, alen);
		memcpy(res + alen, b, blen);
		memcpy(res + alen + blen, c, clen);
		memcpy(res + alen + blen + clen, d, dlen);
		memcpy(res + alen + blen + clen + dlen, e, elen + 1);
	}
	return (res);
}

int file_creation(int arr[], int end) {
	char*	filename;
	char	buffer[11];
	char	nbrCount[11];
	char	line[11];

	sprintf(nbrCount, "%i", end+1);
	sprintf(line, "%i", count);
	filename = concatenate("permute_", nbrCount, "nbrs_", line, ".txt");
	int fd = open(filename, O_WRONLY | O_CREAT);
	if (fd == -1) {
		perror("open");
		return (1);
	}
	for (int i = 0; i <= end; i++) {
		sprintf(buffer, "%i ", arr[i]);
		write(fd, buffer, strlen(buffer));
	}
	close(fd);
	free(filename);
	return (0);
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int arr[], int start, int end) {
	if (start == end) {
		file_creation(arr, end);
		count++;
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
