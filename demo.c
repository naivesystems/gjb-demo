#include <stdio.h>

#define redefined_for(x) for(x)
#define ARRAY_SIZE 10
int array[ARRAY_SIZE] = {0};

int procedure(int arg1, ...) {
    return arg1 + 1;
}

int arrayAccess(void) {
    int* arrPtr = array;
    return *(arrPtr + ARRAY_SIZE);
}

int fileProcess(char const *filename, char const *mode) {
    FILE *stream = NULL;
    if (NULL == (stream = fopen(filename, mode))) {
        return -1;
    } else {
        return 0;
    }
}

int counter = 0;

int main() {
	redefined_for (counter = 1; counter < 10; ++counter) {
		enum newEnum{e1 = 0, counter = 1} enumVar = counter;
		printf("%d\n", procedure(counter, counter + 1));
	}
    return 0;
}
