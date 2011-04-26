// Copyright 2011 Joshua Cole
// MIT License
// Joshua Cole

// An implementation of the quick sort sorting algorithm completed while working through
// MIT's Introduction To Algorithms.

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

// This is a helper function for the partition function. Nothing much to see here.
template <class T>
void Swap(T * array, int pos_one, int pos_two)
{
  T temp = array[pos_one];
  array[pos_one] = array[pos_two];
  array[pos_two] = temp;
}

// Does an in place partition on a subsection of an array so that everything below the
// pivot is less than or equal to the pivot and everything above the pivot is greater
// than it. The subsection of the array are the indexes between start inclusive and end
// exclusive. Returns the index of the pivot.
//
// This algorithm grows linearly with the length of the subarray to partition. This can
// be deduced without math from the loop. The partition algorithm makes use of a loop
// invariant. At the start of the loop  everything between the [pivot, + 1 lower bound) is
// less than the pivot. Also, everything between [lower bound, upper bound) is greater
// than the pivot. Finally, everything between [upper bound, end) is unsorted. At the end
// of each loop this remains true. At the end of the loop the property is still true.
template <class T>
int Partition(T * array, int start, int end)
{
  int pivot_point = start;
  int less_bound = start + 1;
  for (int more_bound = less_bound; more_bound < end; more_bound++)
  {
    if (array[pivot_point] >= array[more_bound])
    {
      Swap(array, less_bound, more_bound);
      less_bound++;
    }
  }
  Swap(array, pivot_point, less_bound - 1);
  return less_bound - 1;
}

// Does an in place sort from the start inclusive to end exclusive. Should be called by
// user code like: QuickSort(array, 0, the_size_of_the_array).
template <class T>
void Quicksort(T * array, int start, int end)
{
  if (start < end)
  {
    int pivot_point = Partition(array, start, end);
    Quicksort(array, start, pivot_point);
    Quicksort(array, pivot_point + 1, end);
  }
}
#endif
