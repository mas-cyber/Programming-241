#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для вывода вектора пар (для отладки)
void printTimeSlots(vector<pair<int, int>>& timeSlots) {
    for (auto slot : timeSlots) {
        cout << slot.first << " " << slot.second << endl;
    }
}

// Компаратор для сортировки по времени окончания
bool compareByEndTime(pair<int, int>& firstSlot, pair<int, int>& secondSlot) {
    return firstSlot.second < secondSlot.second;
}

int main() {
    setlocale(LC_ALL, "Ru");
    int numberOfRequests;
    cout << "Введите количество заявок: ";
    cin >> numberOfRequests;

    // Вектор для хранения заявок (время начала, время окончания)
    vector<pair<int, int>> timeSlots(numberOfRequests);

    // Чтение данных о заявках
    for (int i = 0; i < numberOfRequests; i++) {
        cin >> timeSlots[i].first >> timeSlots[i].second;
    }

    // Сортировка заявок по времени окончания (жадный алгоритм)
    sort(timeSlots.begin(), timeSlots.end(), compareByEndTime);

    int acceptedRequestsCount = 0;    // Счетчик принятых заявок
    int currentEndTime = 0;           // Время окончания последней принятой заявки

    // Жадный выбор: берем заявки с наименьшим временем окончания
    for (auto slot : timeSlots) {
        if (slot.first >= currentEndTime) {
            acceptedRequestsCount++;
            currentEndTime = slot.second;
        }
    }

    cout << "Максимальное количество заявок, которые можно выполнить: " << acceptedRequestsCount;
    return 0;
}