// Copyright 2011 Joshua Cole
// MIT License
// Joshua Cole

// This is a project for short C++ snippets that don't warrant their own project. The goal
// is to keep the project explorer free from trash.

#include <cstdio>

#include "functors/higher_order.h"

void RunFunctors(void);

int main(void)
{
  RunFunctors();
  return 0;
}

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
