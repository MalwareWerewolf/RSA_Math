#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int p, q, e, flag, n, lambda, d, message, c, m, encryptResult, decryptResult;

int lcm(int, int);
int prime(int);
int modInverse(int, int);
int modulo(int, int);
int moduloPow(int, int, int);

int prime(int pr) {
	int i, j;
	j = sqrt(pr);
	for (i = 2; i <= j; i++)
	{
		if (pr % i == 0)
			return 0;
	}
	return 1;

}

//The Euclidean algorithm
int gcd(int a, int h) {
	int temp;
	while (1)
	{
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
};

int lcm(int a, int b) {
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
};

int modulo(int n, int p) {
	int r = n % p;
	if (((p > 0) && (r < 0)) || ((p < 0) && (r > 0)))
		r += p;
	return r;
};

int modInverse(int n, int p) {
	n = modulo(n, p);
	for (int x = 1; x < p; x++) {
		if (modulo(n*x, p) == 1) return x;
	}
	return 0;
};

int moduloPow(int a, int b, int n) {
	long long x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x*y) % n;
		}
		y = (y*y) % n; // squaring the base
		b /= 2;
	}
	return x % n;
};

#endif /*FUNCTIONS_H_*/
