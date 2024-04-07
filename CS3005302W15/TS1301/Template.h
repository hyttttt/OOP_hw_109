#pragma once
#ifndef TEMPLATE_H
#define TEMPLATE_h

// Intent: Iteratively find whether the key element is in the array with binary search
// Pre: Input the array, start, end, and key element. Use reference variable found and location to store the result
// Post: If key element is found, found becomes true, and location is the index.
// 	  	 Otherwise, found remains false.
template <typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	found = false;
	while (first <= last && !found)
	{
		int mid = (first + last) / 2;
		if (a[mid] > key)
		{
			last = mid - 1;
		}
		else if (a[mid] < key)
		{
			first = mid + 1;
		}
		else
		{
			found = true;
			location = mid;
		}
	}
}

// Intent: Recursivly find whether the key element is in the array with binary search
// Pre: Input the array, start, end, and key element. Use reference variable found and location to store the result
// Post: If key element is found, found becomes true, and location is the index.
// 	  	 Otherwise, found remains false.
template <typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	if (first <= last && !found)
	{
		int mid = (first + last) / 2;
		if (a[mid] > key)
		{
			last = mid - 1;
		}
		else if (a[mid] < key)
		{
			first = mid + 1;
		}
		else
		{
			found = true;
			location = mid;
		}
		RecBinarySearch(a, first, last, key, found, location);
	}
}

#endif // !TEMPLATE_H