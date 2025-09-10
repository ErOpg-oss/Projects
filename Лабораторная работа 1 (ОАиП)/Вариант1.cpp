#include <iostream>
#include <climits>

int main(){
    const int size = 10;
    int a[size];
    int sum = 0, min = INT_MAX;

    std::cout << "Введите элементы массива" << std::endl;

    for (int i = 0; i < size; i++){
        std::cout << "Введите элемент " << i+1 << ": ";
        std::cin >> a[i];
        sum = sum + a[i];
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    std::cout << "Введенный массив: ";
    for (int i = 0; i < size; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Минимальный элемент массива: " << min << std::endl;
    std::cout << "Сумма элементов массива: " << sum << std::endl;
}
