# CSE-5B-DAA-Project
DAA Project implementing various sorting techniques:


1. Smoothsort - Mehul
2. Gnome Sort - Mehul
2. Sehgal Sort - Kartikeya
3. Bitonic Sort - Kartikeya
5. Timsort - Kota
6. Pancake Sort - Kota 





# Algorithms


2. Sehgal Sort

```
SehgalSort():
	// declare 3 arrays a1, a2, a3
	// input values into a1
	// copy values of a1 into a2
	for k = 0 up to sizeof(int) * 8:
		for i = 0 up to n:
			a1[i] = a[i] >> 1
			if not a1[i]:
				a3[j++] = a2[i]
				a[i] = -1
	// Apply Insertion Sort on nearly sorted array arr3
        // print sorted array a3
```

3. Bitonic Sort

```
bitonic_sort(up, x):
	if len(x) <= 1:
	    return x
	else: 
	    first = bitonic_sort(True, x[:len(x) // 2])
	    second = bitonic_sort(False, x[len(x) // 2:])
	    return bitonic_merge(up, first + second)

bitonic_merge(up, x): 
    // assume input x is bitonic, and sorted list is returned 
    if len(x) == 1:
        return x
    else:
        bitonic_compare(up, x)
        first = bitonic_merge(up, x[:len(x) // 2])
        second = bitonic_merge(up, x[len(x) // 2:])
        return first + second

bitonic_compare(up, x):
    dist = len(x) // 2
    for i in range(dist):
        if (x[i] > x[i + dist]) == up:
            x[i], x[i + dist] = x[i + dist], x[i] #swap

```
