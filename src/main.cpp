#include "Car.h"

int main()
{
	Car car;
	int result;
	bool isRun = true;
	while (isRun)
	{
		result = Menu();
		switch (result)
		{
		case 0:
			isRun = false;
			continue;
		case 1:
			car.AddCar();
			continue;
		case 2:
			car.ShowCar();
			continue;
		case 3:
			car.DeleteCar();
			continue;
		default:
			std::cout << "Error navigation in menu!!!" << std::endl;
			std::cout << "Not command of namber: " << result << std::endl;
			std::cout << std::endl;
			continue;
		}
	}
	return 0;
}