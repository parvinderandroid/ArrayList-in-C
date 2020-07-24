#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

typedef struct List List;
typedef struct List* ListPtr;
struct List {
	int capacity;
	int size;
	int *arr;
};

ListPtr initialiseWithCapacity(int initialCapacity) {
	ListPtr a = malloc(sizeof *a);
	a->capacity = initialCapacity;
	a->arr = malloc(a->capacity * sizeof *(a->arr));
	a->size = 0;
	return a;
}

ListPtr initialise() {
	return initialiseWithCapacity(10);
}

ListPtr initialiseWithArray(int arr[], int length) {
	ListPtr a = initialiseWithCapacity(length);
	for(int i = 0;  i < length; i++)
		a->arr[a->size++] = arr[i];
	return a;
}

ListPtr values(int n, ...) {
	va_list valist;
	va_start(valist, n);
	ListPtr a = initialiseWithCapacity(n);
	for(int i = 0; i < n; i++) {
		a->arr[a->size++] = va_arg(valist, int);
	}
	va_end(valist);
	return a;
}

ListPtr range(int start, int stop, int step) {
	if(step == 0)
		return initialiseWithCapacity(0);
	ListPtr a = initialiseWithCapacity( abs(stop - start) / abs(step) + 1 );
	if(step > 0) {
		for(int i = start; i < stop; i += step)
			a->arr[a->size++] = i;
	}
	else {
		for(int i = start; i > stop; i += step)
			a->arr[a->size++] = i;
	}
	return a;
}

ListPtr slice(ListPtr a, int start, int stop, int step) {
	if(step == 0 || start < 0 || stop < -1 || start >= a->size || stop >= a->size)
		return initialiseWithCapacity(0);
	ListPtr b = initialiseWithCapacity( abs(stop - start) / abs(step) + 1 );
	if(step > 0) {
		for(int i = start; i < stop; i += step)
			b->arr[b->size++] = a->arr[i];
	}
	else {
		for(int i = start; i > stop; i += step)
			b->arr[b->size++] = a->arr[i];
	}
	return b;
}

bool clear(ListPtr a) {
	free(a->arr);
	a->arr = malloc(0);
	a->capacity = 0;
	a->size = 0;
	return true;
}

bool ensureCapacity(ListPtr a, int minCapacity) {
	if(minCapacity > a->capacity) {
		a->capacity += (a->capacity >> 1);
		if(a->capacity < minCapacity)
			a->capacity = minCapacity;
		a->arr = realloc(a->arr, a->capacity * sizeof *(a->arr));
	}
	return true;
}

bool trimToSize(ListPtr a) {
	a->capacity = a->size;
	a->arr = realloc(a->arr, a->capacity * sizeof *(a->arr));
	return true;
}

bool fill(ListPtr a, int value, int n) {
	ensureCapacity(a, n);
	a->size = n;
	for(int i = 0; i < n; i++) {
		a->arr[i] = value;
	}
	return true;
}

bool append(ListPtr a, int n) {
	ensureCapacity(a, a->size + 1);
	a->arr[a->size++] = n;
	return true;
}

bool extendWithArray(ListPtr a, int arr[], int length) {
	ensureCapacity(a, a->size + length);
	for(int i = 0; i < length; i++)
		a->arr[a->size++] = arr[i];
	return true;
}

bool extend(ListPtr a, ListPtr b) {
	extendWithArray(a, b->arr, b->size);
	return true;
}

bool insert(ListPtr a, int index, int n) {
	if(index < 0)
		index = a->size + index;
	
	if(index > a->size || index < 0)
		return false;
	
	if(index == a->size) {
		append(a, n);
		return true;
	}
	
	ensureCapacity(a, a->size + 1);
	for(int i = a->size; i > index; i--) {
		a->arr[i] = a->arr[i-1];
	}
	a->arr[index] = n;
	a->size++;
	return true;
}

ListPtr copy(ListPtr a) {
	ListPtr b = initialiseWithCapacity(a->capacity);
	extendWithArray(b, a->arr, a->size);
	return b;
}

int indexOf(ListPtr a, int value) {
	for(int i = 0; i < a->size; i++) {
		if(a->arr[i] == value)
			return i;
	}
	return -1;
}

int lastIndexOf(ListPtr a, int value) {
	for(int i = a->size - 1; i >= 0; i--) {
		if(a->arr[i] == value)
			return i;
	}
	return -1;
}

int binarySearch(ListPtr a, int value) {
	int lower = 0, upper = a->size - 1, mid = 0;
	while(lower <= upper) {
		mid = (lower + upper) / 2;
		if(a->arr[mid] == value)
			return mid;
		else if(a->arr[mid] < value)
			lower = mid + 1;
		else
			upper = mid - 1;
	}
	return -1;
}

bool contains(ListPtr a, int value) {
	return indexOf(a, value) >= 0;
}

bool isEmpty(ListPtr a) {
	return a->size == 0;
}

bool isEqual(ListPtr a, ListPtr b) {
	if(a->size != b->size)
		return false;
	for(int i = 0; i < a->size; i++) {
		if(a->arr[i] != b->arr[i])
			return false;
	}
	return true;
}

bool pop(ListPtr a, int index) {
	if(index < 0)
		index = a->size + index;
	
	if(index >= a->size || index < 0)
		return false;
	
	for(int i = index; i < a->size-1; i++)
		a->arr[i] = a->arr[i+1];
	a->size--;
	
	return true;
}

bool delete(ListPtr a, int value) {
	int index = indexOf(a, value);
	if(index == -1)
		return false;
	return pop(a, index);
}

int get(ListPtr a, int index) {
	if(index < 0)
		index = a->size + index;
	
	if(index >= a->size || index < 0)
		return -1;
	
	return a->arr[index];
}

bool set(ListPtr a, int index, int value) {
	if(index < 0)
		index = a->size + index;
	
	if(index >= a->size || index < 0)
		return false;
	
	a->arr[index] = value;
	return true;
}

bool reverse(ListPtr a) {
	for(int start = 0, stop = a->size-1; start < stop; start++, stop--) {
		int t = a->arr[start];
		a->arr[start] = a->arr[stop];
		a->arr[stop] = t;
	}
	return true;
}

bool replace(ListPtr a, int oldValue, int newValue) {
	for(int i = 0; i < a->size; i++) {
		if(a->arr[i] == oldValue)
			a->arr[i] = newValue;
	}
	return true;
}

/*Code for sorting begins*/
int comparisonFunctionAscending (const void *a, const void *b) {
	return ( *(int*)a - *(int*)b );
}

int comparisonFunctionDescending (const void *a, const void *b) {
	return ( *(int*)b - *(int*)a );
}

bool sort(ListPtr a) {
	qsort(a->arr, a->size, sizeof(int), comparisonFunctionAscending);
	return true;
}

bool sortReverse(ListPtr a) {
	qsort(a->arr, a->size, sizeof(int), comparisonFunctionDescending);
	return true;
}
/*Code for sorting ends*/

int count(ListPtr a, int value) {
	int c = 0;
	for(int i = 0; i < a->size; i++) {
		if(a->arr[i] == value)
			c++;
	}
	return c;
}

int sum(ListPtr a) {
	int s = 0;
	for(int i = 0; i < a->size; i++)
		s += a->arr[i];
	return s;
}

int len(ListPtr a) {
	return a->size;
}

int cap(ListPtr a) {
	return a->capacity;
}

int* toArray(ListPtr a) {
	int *b = malloc(a->size * sizeof *b);
	for(int i = 0; i < a->size; i++)
		b[i] = a->arr[i];
	return b;
}

char* toString(ListPtr a) {
	int iMax = a->size - 1;
	if(iMax == -1)
		return "[]";
	char *str = malloc( (a->size * 12 + 1) * sizeof *str );
	strcpy(str, "[");
	for(int i = 0; ; i++) {
		char temp[11];
		sprintf(temp, "%d", a->arr[i]);
		strcat(str, temp);
		if(i == iMax) {
			strcat(str, "]");
			return str;
		}
		strcat(str, ", ");
	}
}

bool display(ListPtr a) {
	printf("%s \n", toString(a));
	return true;
}