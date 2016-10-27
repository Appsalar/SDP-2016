#include <iostream>

void swap(int v[], int i, int j) {
	int	t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void print(int v[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

// това е най-простият аглоритъм за генериране на пермутации 
// и на базата на тази конструкция, могат да бъдат генерирани 
// останалите комбинаторни обекти 
void permSimple(int v[], int n, bool used[], int k = 0)
{
	if (k >= n)
	{
		print(v, n);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i - 1] == false)
		{
			used[i - 1] = true;
			v[k] = i;
			permSimple(v, n, used, k + 1);
			used[i - 1] = false;
		}
	}
}


void perm(int v[], int n, int k) {

	if (k == n) {
		print(v, n);
	}
	else
		for (int i = k; i<n; i++) {
			swap(v, k, i);
			perm(v, n, k + 1);
			swap(v, k, i);
		}
}

void heap_perm(int v[], int n, int maxN)
{
	if (n == 1)
	{
		print(v, maxN);
		return;
	}
	int i = 0;
	while (true)
	{
		heap_perm(v, n - 1, maxN);
		if (i == n - 1)
			break; //може и return
		if (n % 2 == 0)
			swap(v, i, n - 1);
		else
			swap(v, 0, n - 1);
		++i;
	}
}


void comb(int v[], int n, int maxK, int start = 1, int k = 0)
{
	if (k >= maxK)
	{
		print(v, maxK);
		return;
	}

	// в цикъла може да е до n, няма да бъде оптимизиран 
	// # Минко > Преслав Наков
	for (int i = start; i <= n - maxK + k + 1; i++)
	{
		v[k] = i;
		comb(v, n, maxK, i + 1, k + 1);
	}
}


void combMulti(int v[], int n, int maxK, int start = 1, int k = 0)
{
	if (k >= maxK)
	{
		print(v, maxK);
		return;
	}

	for (int i = start; i <= n + 1; i++)
	{
		v[k] = i;
		comb(v, n, maxK, i, k + 1);
	}
}


void var(int v[], int n, int maxK, bool used[], int k = 0)
{
	if (k >= maxK)
	{
		print(v, maxK);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (used[i - 1] == false)
		{
			used[i - 1] = true;
			v[k] = i;
			var(v, n, maxK, used, k + 1);
			used[i - 1] = false;
		}
	}
}


void varMulti(int v[], int n, int maxK, int k = 0)
{
	if (k >= maxK)
	{
		print(v, maxK);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		v[k] = i;
		varMulti(v, n, maxK, k + 1);
	}
}


int main()
{
	const int N = 4;
	int K = 2;
	int v[N];
	bool used[N];

	for (int i = 0; i < N; i++)
		v[i] = i + 1;

	for (int i = 0; i < N; i++)
		used[i] = false;

	//perm(v, N, 0);
	//heap_perm(v, N);
	//comb(v, N, K);
	//var(v, N, K, used);
	//varMulti(v, N, K);
	permSimple(v, N, used);

	return 0;
}