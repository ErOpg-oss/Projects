#include <iostream>

int main()
{
    float temper;
    std::cout << "Введите температуру на улице: ";
    std::cin >> temper;

    if (temper < 0)
    {
        std::cout << "Наденьте зимнюю одежду" << std::endl;
    }
    else if (temper >= 0 && temper <= 10)
    {
        std::cout << "Оденьтесь потеплее" << std::endl;
    }
    else if (temper >= 11 && temper <= 20)
    {
        std::cout << "Наденьте лёгкую одежду" << std::endl;
    }
    else
    {
        std::cout << "Наденьте летнюю одежду" << std::endl;
    }
    

    return 0;
}
