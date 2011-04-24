// Copyright 2011 Joshua Cole
// MIT License
// Joshua Cole

#include "higher_order.h"

// Uses the recursive squaring algorithm to calculate powers. I've written this code
// in other languages. I wanted to see what it looked like in C++. This is the first
// in a series of functions that I'm writing to learn more about functors.
double Power(double a, int b)
{
  if (b < 0)
  {
    return -1;
  }
  if (b == 0)
  {
    return 1;
  }
  else if (b == 1)
  {
    return a;
  }
  else if (b == 2)
  {
    return a * a;
  }
  else if (b % 2 == 0)
  {
    return Power(Power(a, b / 2), 2);
  }
  else
  {
    return Power(a, b - 1) * a;
  }
}

// I'm writing this to familiarize myself with function pointers. See the comment on
// Power(double, double) for more details.
double HigherOrderPower(double (*f)(double, double), double a, int b)
{
  if (b < 0)
  {
    return -1;
  }
  if (b == 0)
  {
    return 1;
  }
  else if (b == 1)
  {
    return a;
  }
  else if (b == 2)
  {
    return f(a, a);
  }
  else if (b % 2 == 0)
  {
    return HigherOrderPower(f, HigherOrderPower(f, a, b / 2), 2);
  }
  else
  {
    return f(HigherOrderPower(f, a, b - 1), a);
  }
}

double Multiply(double a, double b)
{
  return a * b;
}

double AnotherHigherOrderPower(MultiplicationFunctor * f, double a, int b)
{
  if (b < 0)
  {
    return -1;
  }
  if (b == 0)
  {
    return 1;
  }
  else if (b == 1)
  {
    return a;
  }
  else if (b == 2)
  {
    return (*f)(a, a);
  }
  else if (b % 2 == 0)
  {
    return AnotherHigherOrderPower(f, AnotherHigherOrderPower(f, a, b / 2), 2);
  }
  else
  {
    return (*f)(AnotherHigherOrderPower(f, a, b - 1), a);
  }
}
