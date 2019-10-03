# CSE-5B-DAA-Project
DAA Project implementing various sorting techniques:


1. Smoothsort - Mehul
2. Gnome Sort - Mehul
2. Sehgal Sort - Kartikeya
3. Bitonic Sort - Kartikeya
5. Timsort - Kota
6. Introsort - Kota 





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
	// print sorted array a3
```