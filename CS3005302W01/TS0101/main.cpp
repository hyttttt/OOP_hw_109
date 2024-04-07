#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double n = 0.0, r = 0.0, guess = 0.0, sub = 0.0, preguess = 0.0; 
	while (std::cin >> n) //允許重複輸入n
	{
		guess = n / 2.0;
		do
		{
			preguess = guess;
			r = n / guess;
			guess = (guess + r) / 2.0;
			sub = abs(preguess - guess); //前一次猜測跟新猜測的值之差取絕對值
		} while (sub > 0.01); //差異大於0.01就繼續算

		std::cout << std::setprecision(2) << std::fixed << guess << std::endl;
	}
	
}