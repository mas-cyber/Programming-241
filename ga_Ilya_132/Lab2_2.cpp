#include <iostream>
#include <string>

using namespace std;

// Рекурсивная функция для генерации последовательности в порядке возрастания
string generateAscendingSequence(int start, int end) {
    // Базовый случай: когда начальное и конечное значения равны
    if (start == end) {
        return to_string(end);
    }
    // Рекурсивный случай: текущее число + последовательность от start+1 до end
    return to_string(start) + " " + generateAscendingSequence(start + 1, end);
}

// Рекурсивная функция для генерации последовательности в порядке убывания
string generateDescendingSequence(int start, int end) {
    // Базовый случай: когда начальное и конечное значения равны
    if (start == end) {
        return to_string(end);
    }
    // Рекурсивный случай: текущее число + последовательность от start-1 до end
    return to_string(start) + " " + generateDescendingSequence(start - 1, end);
}

int main() {
    setlocale(LC_ALL, "Ru");
    int startValue, endValue;
    cout << "Введите значения A и B: ";
    cin >> startValue >> endValue;

    if (startValue < endValue) {
        cout << "Рекурсия в порядке возрастания: " << generateAscendingSequence(startValue, endValue);
    }
    else {
        cout << "Рекурсия в порядке убывания: " << generateDescendingSequence(startValue, endValue);
    }
    return 0;
}