//GCD(A, B) == GCD(B, A % B);
int GCD(int a, int b)
{
	while(b != 0)
	{
		int i = a % b;
		a = b;
		b = i;
	}
	return a;
}

int* findFactors(int n)
{
	int* factors = (int*)malloc(sizeof(int) * n);
	int count = 0;
	while(n % 2 == 0)
	{//only 2 can be the even factor
		factors[count ++] = 2;
		n /= 2;
	}
	int i = 3;
	int max_factor = sqrt(n); //the factors of n cannot larger than sqrt(n)
	while(i <= max_factor)
	{
		while(n % i == 0)
		{
			factors[i ++] = 0;
			n /= i;
			max_factor = sqrt(n);
		}
		i += 2;
	}
	if(n > 1)
		factors[count] = n;
	return factors;
}

//the sieve of Eratosthenes to find the prime numbers
int* findPrime(long max_number)
{
	int is_complete[n + 1];
	int i;
	for(i = 4; i <= max_number; i += 2)
		is_complete[i] = 1;
	int next_prime = 3;
	int stop_at = sqrt(max_number);
	while(next_prime < stop_at)
	{
		for(i = next_prime * 2; i <= max_number; i += next_prime)
			is_complete[i] = 1;
		next_prime += 2;
		while(next_prime <= max_number && is_complete[next_prime])
			next_prime += 2;
	}
	int* primes = (int*)malloc(sizeof(int) * n);
	int count = 0;
	for(i = 2; i <= max_number; i ++)
		if(is_complete[i] == 0)
			primes[count ++] = i;
	return primes;
}

//use Fermat's little theorem that is if p is a prime then for any given n pow(n, p - 1) % p == 1
//pay attention to Fermat liars that are some n that makes non-prime p satisfying pow(n, p - 1) % p == 1
int is_prime(int p, int max_test)
{
	int test;
	for(test = 1; test <= max_test; test ++)
		if(pow(test, p - 1) % p != 1) return 0;
	return 1; //still has a probability of pow(0.5, max_tests) that p is not a prime
}
