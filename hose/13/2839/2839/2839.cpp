#include <stdio.h>

int main() {
	int number = 0;
	int index = 0;
	double count = 0;
	int fiveKg = -1;
	int threeKg = -1;
	int result = 0;


	scanf("%d", &number);

	if (number < 3 || number>5000) return 0;

	if (number % 5 == 0)
	{
		printf("%d\n", number / 5);
	}
	else
	{
		while (1)
		{
			count = (double)(number - (5 * index)) / 3;// 카운트가 정수라면?
			if (count - (int)count == 0)
			{
				fiveKg = index;
				threeKg = (int)count;
			}

			index++;
			if (number - (5 * index) < 3) break;
		}

		if (fiveKg == -1 && threeKg == -1)
		{
			printf("-1\n");
		}
		else if (fiveKg == -1 && threeKg != -1)
		{
			printf("%d\n", threeKg);
		}
		else
		{
			printf("%d\n", fiveKg + threeKg);
		}
	}

	return 0;
}
