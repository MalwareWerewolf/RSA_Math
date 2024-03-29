#include <iostream>
#include "RsaMath.h"

int main()
{
	unsigned int p, q, e, isPrime, n, lambda, d, numberToEncrypt, encryptResult, decryptResult;

	std::cout << "Enter the first prime number: ";
	std::cin >> p;
	isPrime = prime(p);
	if (isPrime == 0)
	{
		std::cout << "\nWrong Input, you must enter a prime number" << std::endl;
		std::cin.get();
		return 0;
	}

	std::cout << "\nEnter the second prime number: ";
	std::cin >> q;
	isPrime = prime(q);
	if (isPrime == 0)
	{
		std::cout << "\nWrong Input, you must enter a prime number";
		std::cin.get();
		return 0;
	}

	n = p * q;
	std::cout << "\nThe compute of n is: " << n << std::endl;

	lambda = lcm(p - 1, q - 1);
	std::cout << "The lambda value is: " << lambda << std::endl;

	std::cout << "Choose a coprime number < " << lambda << ": ";
	std::cin >> e;

	if (e > lambda) {
		std::cout << "\nWrong Input, you must choose a prime number < " << lambda << std::endl;
		std::cin.get();
		return 0;
	}

	isPrime = prime(e);
	if (isPrime == 0)
	{
		std::cout << "\nWRONG INPUT\n";
		std::cin.get();
		return 0;
	}

	d = modInverse(e, lambda);
	std::cout << "The compute of d is: " << d << std::endl;

	std::cout << "Enter a number to encrypt: ";
	std::cin >> numberToEncrypt;

	encryptResult = moduloPow(numberToEncrypt, e, n);
	std::cout << "\nThe encrypt number is: " << encryptResult << std::endl;

	decryptResult = moduloPow(encryptResult, d, n);
	std::cout << "The decrypt number is: " << decryptResult << std::endl;

	std::cin.get();
	return 0;
}