// OrderStatistics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Orderstatistics.h"
//random int in(min,max)
int random_unint(unsigned int min, unsigned int max)
{
	static std::default_random_engine e(time(NULL));
	std::uniform_int_distribution<int> u(min, max);
	return u(e);
}

//swap a and b
template <typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//Randomized-Select
template <typename T>
T RandomizedSelect(std::vector<T>& A,int p,int r, int i)
{
	if (p == r)
		return A[p];
	int q = RandomizedPartition(A, p, r);
	int j = q - p + 1;
	if (j == i)
		return A[q];
	else if (j > i)
		return RandomizedSelect(A, p, q - 1, i);
	else
		return RandomizedSelect(A, q + 1, r, i - j);
}

//Randomized-Partition
template <typename T>
int RandomizedPartition(std::vector<T>& A, int p, int r)
{
	if (p == r)
		return p;
	for (int i = p; i < r; i++)
	{
		int j = random_unint(i, r);
		swap(A[i], A[j]);
	}
	T pivot = A[r];
	int j = p;
	for (int i = p; i < r; i++)
	{
		if (A[i] < pivot)
		{
			swap(A[i], A[j]);
			j++;
		}
	}
	swap(A[r], A[j]);
	return j;
}

//main
int main()
{
	std::vector<int> A = { 5,9,2,10,-5,6,23 };
    std::cout << RandomizedSelect(A,0,A.size()-1,7)<<std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
