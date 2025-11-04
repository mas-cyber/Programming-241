#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Рекурсивная функция для нахождения простых делителей
void findPrimeDivisors(int number, int currentDivisor, vector<int>& divisors) {
    // Базовый случай: если число меньше или равно 1, завершаем рекурсию
    if (number <= 1) {
        return;
    }

    // Максимальный делитель для проверки - квадратный корень из number
    int maxDivisor = sqrt(number);

    // Если текущий делитель превысил максимальный, значит number - простое число
    if (currentDivisor > maxDivisor) {
        divisors.push_back(number);
        return;
    }

    // Проверяем, делится ли number на currentDivisor
    if (number % currentDivisor == 0) {
        // Добавляем найденный простой делитель
        divisors.push_back(currentDivisor);
        // Рекурсивно обрабатываем оставшуюся часть числа
        findPrimeDivisors(number / currentDivisor, currentDivisor, divisors);
    }
    else {
        // Переходим к следующему делителю
        findPrimeDivisors(number, currentDivisor + 1, divisors);
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    int inputNumber;
    cout << "Введите натуральное число n > 1: ";
    cin >> inputNumber;

    // Вектор для хранения простых делителей
    vector<int> primeDivisors;

    // Начинаем поиск с первого простого числа 2
    findPrimeDivisors(inputNumber, 2, primeDivisors);

    // Выводим найденные простые делители
    cout << "Простые делители числа " << inputNumber << ": ";
    for (int divisor : primeDivisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}