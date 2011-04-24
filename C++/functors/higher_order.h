// Copyright 2011 Joshua Cole
// MIT License
// Joshua Cole

// Examples of higher order functions in C++.

// Returns the power of a raised to b. If b is below zero the function returns
// -1. This function is the first of a series of functions I am writing to
// get a better grasp of functors and higher order functions in C++.
double Power(double a, int b);


// This is a higher order function that returns a raised to the b power.
// However, the function for multiplication is passed in as a function
// pointer. In cases where b is below zero it will return -1. To give you
// an idea of how you might use this: giving an addition function results
// in multiplication like semantics. This function is part of a series of
// functions I am writing to get better grasp of functors and higher order
// functions.
double HigherOrderPower(double (*f)(double, double), double a, int b);



// This abstract base class is used to create a Functor which can be to
// the AnotherHigherOrderPower function. It is part of a series of things
// I'm writing to get a better grasp on C++ functors.
class MultiplicationFunctor
{
public:
  // This method would normally be the multiplication function used in a
  // recursive squaring power function.
  virtual double operator()(double a, double b) = 0;
};

// An implementation of a function which can be passed to HigherOrderPower.
double Multiply(double a, double b);

// An example implementation of MultiplicationFunctor.
class MultiplyFunctor : public MultiplicationFunctor
{
public:
  double operator()(double a, double b) { return a * b; }
};

// Accepts a derivation of the MultiplicationFunctor abstract base class.
// In cases where b is below zero the function will return -1.
double AnotherHigherOrderPower(MultiplicationFunctor * f, double a, int b);
