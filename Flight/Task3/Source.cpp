#include <iostream>
#include <cmath>
int main(int argc, char* argv[])
{
	int n = 0;
	int count = 0;
	std::cin >> n;
	int dobryj = 0;
	if (n != 0)
	{
		dobryj = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int vecher = 0;
	if (n != 0)
	{
		vecher = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int Grigorij = 0;
	if (n != 0)
	{
		Grigorij = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int Anatolevich = 0;
	if (n != 0)
	{
		Anatolevich = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int za = 0;
	if (n != 0)
	{
		za = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int chto = 0;
	if (n != 0)
	{
		chto = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int Vy = 0;
	if (n != 0)
	{
		Vy = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int dali = 0;
	if (n != 0)
	{
		dali = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int mne = 0;
	if (n != 0)
	{
		mne = n % 10;
		n = n / 10;
		count = count + 1;

	}
	int eto = 0;
	if (n != 0)
	{
		eto = n % 10;
		n = n / 10;
		count = count + 1;

	}

	switch (count)
	{
	case 1:
		std::cout << dobryj;
		break;
	case 2:
		std::cout << dobryj << vecher;
		break;
	case 3:
		std::cout << dobryj << vecher << Grigorij;
		break;
	case 4:
		std::cout << dobryj << vecher << Grigorij << Anatolevich;
		break;
	case 5:
		std::cout << dobryj << vecher << Grigorij << Anatolevich << za;
		break;
	case 6:
		std::cout << dobryj << vecher << Grigorij << Anatolevich << za << chto;
		break;
	case 7:
		std::cout << dobryj << vecher << Grigorij << Anatolevich << za << chto << Vy;
		break;
	case 8:
		std::cout << dobryj << vecher << Grigorij << Anatolevich << za << chto << Vy << dali;
		break;
	case 9:
		std::cout << dobryj << vecher << Grigorij << Anatolevich << za << chto << Vy << dali << mne;
		break;
	case 10:
		std::cout << dobryj << vecher << Grigorij << Anatolevich << za << chto << Vy << dali << mne << eto;
		break;



	}

	return EXIT_SUCCESS;
}