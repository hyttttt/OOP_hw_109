#include <iostream>

int main()
{
	unsigned long long int n = 0, h = 0, m = 0, s = 0;
	while (std::cin >> n) //���\���ƿ�Jn
	{
		s = n % 60; //���o��
		n /= 60;
		m = n % 60; //���o��
		n /= 60;
		h = n; // ���o�p��
		std::cout << h << " hours " << m << " minutes and " << s << " seconds" << std::endl;
	}
	
}