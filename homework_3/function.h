#pragma once
#include "function.cpp"

template<typename T1, typename T2, typename T3>
T1 fit01(T1, T2, T3);

void FillList(std::list<float> &, unsigned int);

void PrintList(std::list<float> &);

void average(std::list<float> &);