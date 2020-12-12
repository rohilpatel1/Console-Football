#pragma once
#ifndef RANDOMNUM_H
#define RANDOMNUM_H
#include <random>

double randnum(double start, double end);
double randnum();
int randint();
int randint(int start, int end);

double randnum(double start, double end) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(start, end);
  return dis(gen);
}
double randnum() { return randnum(0.0, 1.0); };

int randint() {
  return (int)randnum(0.0, 20.0);
}

int randint(int start, int end) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dis(0.0, 1.0);

  bool isNegative = (end - start < 0);
  int end_start = (!isNegative)
    ? end - start + 1
    : (end + (start - end)) - (start - (start - end)) + 1;

  return (int)((randnum() * end_start) + (isNegative ? end : start));
}

#endif