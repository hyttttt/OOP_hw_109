#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	double n = 0.0, r = 0.0, guess = 0.0, sub = 0.0, preguess = 0.0; 
	while (std::cin >> n) //���\���ƿ�Jn
	{
		guess = n / 2.0;
		do
		{
			preguess = guess;
			r = n / guess;
			guess = (guess + r) / 2.0;
			sub = abs(preguess - guess); //�e�@���q����s�q�����Ȥ��t�������
		} while (sub > 0.01); //�t���j��0.01�N�~���

		std::cout << std::setprecision(2) << std::fixed << guess << std::endl;
	}
	
}