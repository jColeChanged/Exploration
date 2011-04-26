// Copyright 2011 Joshua Cole
// MIT License
// Joshua Cole

// This is a project for short C++ snippets that don't warrant their own project. The goal
// is to keep the project explorer free from trash.

#include <cstdio>

#include "functors/higher_order.h"
#include "sorting/quick_sort.h"

// void RunFunctors(void);
void RunQuickSort(void);

void PrintArray(int * array, int end);

int main(void)
{
  RunQuickSort();
  return 0;
}

/*
void RunFunctors(void)
{
  printf("The functors folder implements multiple methods of creating and \n"
         "using higher order functions.\n\n");
  printf("Power(2.0, 3) = %.1f\n", Power(2.0, 3));
  printf("HigherOrderPower(&Multiply, 2.0, 3) = %.1f\n",
         HigherOrderPower(&Multiply, 2.0, 3));
  MultiplyFunctor multiplyFunctor;
  printf("AnotherHigherOrderPower(&multiplyFunctor, 2.0, 3) = %.1f\n",
         AnotherHigherOrderPower(&multiplyFunctor, 2.0, 3));
}
*/

void RunQuickSort(void)
{
  int to_partition[] = {2, 1, 3, 7, 1, 3, 6, 4, 8, 3, 4, 1};
  int size = sizeof(to_partition) / sizeof(int);
  PrintArray(to_partition, size);
  Quicksort(to_partition, 0, size);
  PrintArray(to_partition, size);
}

void PrintArray(int * array, int end)
{
  for (int i = 0; i < end; i++)
  {
    printf("%d, ", array[i]);
  }
  printf("\n");
}
