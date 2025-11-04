#include <iostream>
#include <string>

using namespace std;

// Рекурсивная функция для генерации последовательности чисел от 1 до n
string generateSequence(int number) {
    // Базовый случай: когда дошли до 1
    if (number == 1) {
        return "1";
    }
    // Рекурсивный случай: последовательность от 1 до n-1 + текущее число
    return generateSequence(number - 1) + " " + to_string(number);
}

int main() {
    setlocale(LC_ALL, "Ru");
    int upperLimit;
    cout << "Введите натуральное число n: ";
    cin >> upperLimit;
    cout << generateSequence(upperLimit);
    return 0;
}