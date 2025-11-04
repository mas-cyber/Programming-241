#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для вывода вектора пар (для отладки)
void printBoxes(vector<pair<int, int>>& boxes) {
    for (auto box : boxes) {
        cout << box.first << " " << box.second << endl;
    }
}

// Компаратор для сортировки по сумме веса и прочности
bool compareByTotal(pair<int, int>& firstBox, pair<int, int>& secondBox) {
    return firstBox.first + firstBox.second < secondBox.first + secondBox.second;
}

int main() {
    setlocale(LC_ALL, "Ru");
    int numberOfBoxes;
    cout << "Введите количество коробок: ";
    cin >> numberOfBoxes;

    // Вектор для хранения коробок (вес, прочность)
    vector<pair<int, int>> boxes(numberOfBoxes);

    // Чтение данных о коробках
    for (int i = 0; i < numberOfBoxes; i++) {
        cin >> boxes[i].first >> boxes[i].second;
    }

    // Сортировка коробок по сумме веса и прочности
    sort(boxes.begin(), boxes.end(), compareByTotal);

    int totalWeight = 0;  // Общий вес сложенных коробок
    int stackHeight = 0;  // Количество коробок в стопке

    // Формирование стопки коробок
    for (auto box : boxes) {
        // Проверяем, выдержит ли текущая стопка вес новой коробки
        if (totalWeight <= box.second) {
            stackHeight++;
            totalWeight += box.first;
        }
    }

    cout << "Количество сложенных друг на друга коробок: " << stackHeight;
    return 0;
}