# ArrayList in C

    ListPtr initialise()
Returns an empty list with an initial capacity of ten.

    ListPtr initialiseWithCapacity(int initialCapacity)
Returns an empty list with the specified `initialCapacity`.

    ListPtr initialiseWithArray(int arr[], int length)
Returns a list containing the elements of the array `arr`.

    ListPtr values(int n, ...)
Returns a list containing `n` elements passed after `n`.

    ListPtr range(int start, int stop, int step)
Returns a list of numbers, starting from `start`(inclusive), and ending at `stop`(exclusive) incrementing by `step`.

    ListPtr slice(ListPtr a, int start, int stop, int step)
Returns a list of elements from `a` starting from index `start`(inclusive) and ending at index `stop`(exclusive) incrementing the index by `step`.

    ListPtr copy(ListPtr a)
Returns a copy of the list `a`.

    bool clear(ListPtr a)
Removes all the elements from list `a`.

    bool ensureCapacity(ListPtr a, int minCapacity)
Increases the capacity of list `a`, if necessary, to ensure that it can hold at least the number of elements specified by the `minCapacity` argument.

    bool trimToSize(ListPtr a)
Trims the capacity of list `a` to be the list's current size.

    bool fill(ListPtr a, int value, int n)
Fills list `a` with `n` occurences of `value`.

    bool append(ListPtr a, int n)
Appends the specified element `n` to the end of list `a`.

    bool extendWithArray(ListPtr a, int arr[], int length)
Appends all the elements in the array `arr` to the end of list `a`.

    bool extend(ListPtr a, ListPtr b)
Appends all the elements in the list `b` to the end of list `a`.

    bool insert(ListPtr a, int index, int n)
Inserts the specified element `n` at the specified `index` in list `a`.

    int indexOf(ListPtr a, int value)
Returns the index of the first occurrence of the specified element `value` in list `a`, or -1 if the list does not contain the element.

    int lastIndexOf(ListPtr a, int value)
Returns the index of the last occurrence of the specified element `value` in list `a`, or -1 if the list does not contain the element.

    int binarySearch(ListPtr a, int value)
Returns the first found index of the specified element `value` in sorted list `a`, or -1 if the list does not contain the element.

    bool contains(ListPtr a, int value)
Returns true if list `a` contains the specified element `value`.

    bool isEmpty(ListPtr a)
Returns true if list `a` contains no elements.

    bool isEqual(ListPtr a, ListPtr b)
 Returns true if both lists `a` and `b` have the same size, and all corresponding pairs of elements in the two lists are equal.

    bool pop(ListPtr a, int index)
Removes the element at the specified `index` in list `a`.

    bool delete(ListPtr a, int value)
Removes the first occurrence of the specified element `value` from list `a`, if it is present.

    int get(ListPtr a, int index)
Returns the element at the specified `index` in list `a`.

    bool set(ListPtr a, int index, int value)
Replaces the element at the specified `index` in list `a` with the specified element `value`.

    bool reverse(ListPtr a)
Reverses the elements of list `a`.

    bool replace(ListPtr a, int oldValue, int newValue)
Replaces all occurrences of `oldValue` in list `a` with `newValue`.

    bool sort(ListPtr a)
Sorts the elements of list `a` in increasing order.

    bool sortReverse(ListPtr a)
Sorts the elements of list `a` in decreasing order.

    int count(ListPtr a, int value)
Returns the number of times `value` appears in list `a`.

    int sum(ListPtr a)
Returns the sum of all elements in list `a`.

    int len(ListPtr a)
Returns the number of elements in list `a`.

    int cap(ListPtr a)
Returns the current capacity of list `a`.

    int* toArray(ListPtr a)
Returns an array containing all the elements in list `a`.

    char* toString(ListPtr a)
Returns a string representation of the contents of list `a`.

    bool display(ListPtr a)
Prints a string representation of the contents of list `a`.
