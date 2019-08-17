#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

//random int in(min,max)
int random_unint(unsigned int min, unsigned int max);

//swap a and b
template <typename T>
void swap(T& a, T& b);

//Randomized-Select
template <typename T>
T RandomizedSelect(std::vector<T>& A, int p, int r, int i);

//Randomized-Partition
template <typename T>
int RandomizedPartition(std::vector<T>& A, int p, int r);
