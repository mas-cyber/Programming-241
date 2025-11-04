#include <iostream>

using namespace std;

// Рекурсивная функция для вычисления суммы цифр числа
int calculateDigitSum(int number) {
    // Базовый случай: если число меньше или равно 0
    if (number <= 0) return 0;
    // Рекурсивный случай: последняя цифра + сумма цифр оставшейся части числа
    return number % 10 + calculateDigitSum(number / 10);
}

int main() {
    setlocale(LC_ALL, "Ru");
    int inputNumber;
    cout << "Введите натуральное число N: ";
    cin >> inputNumber;
    cout << calculateDigitSum(inputNumber);
    return 0;
}