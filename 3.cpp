#include <iostream>

int main()
{
    const int size = 10;
    int m[size];
    int sum = 0;
    int min;
    std::cout << "Введите 10 целых чисел:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> m[i];
        sum += m[i];
        if (i == 0 && m[i] < min) {
            min = m[i];
        }
    }
    std::cout << "\nИсходный массив:\n";
    for (int i = 0; i < size; i++) {
        std::cout << m[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Сумма элементов: " << sum << "\n";
    std::cout << "Минимальный элемент: " << min;
    return 0;
}