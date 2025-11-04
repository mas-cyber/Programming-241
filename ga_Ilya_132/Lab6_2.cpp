#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    int citiesCount;
    cin >> citiesCount;

    // Массив цен на бензин в каждом городе
    vector<int> fuelPrices(citiesCount);
    for (int i = 0; i < citiesCount; i++) {
        cin >> fuelPrices[i];
    }

    int roadsCount;
    cin >> roadsCount;

    // Граф: список смежности (город -> {сосед, цена бензина в текущем городе})
    vector<vector<pair<int, int>>> roadNetwork(citiesCount);

    for (int i = 0; i < roadsCount; i++) {
        int cityA, cityB;
        cin >> cityA >> cityB;
        cityA--; cityB--; // Преобразуем в 0-индексацию

        // Добавляем дороги в обе стороны
        roadNetwork[cityA].push_back({ cityB, fuelPrices[cityA] });
        roadNetwork[cityB].push_back({ cityA, fuelPrices[cityB] });
    }

    // Массив для хранения минимальной стоимости достижения каждого города
    vector<int> minCost(citiesCount, INT_MAX);
    minCost[0] = 0; // Начальный город

    // Приоритетная очередь для алгоритма Дейкстры
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({ 0, 0 });

    while (!minHeap.empty()) {
        int currentCost = minHeap.top().first;
        int currentCity = minHeap.top().second;
        minHeap.pop();

        // Пропускаем устаревшие записи
        if (currentCost > minCost[currentCity]) continue;

        // Если достигли конечного города, можно завершать
        if (currentCity == citiesCount - 1) break;

        // Обход всех соседних городов
        for (auto& road : roadNetwork[currentCity]) {
            int neighborCity = road.first;
            int roadCost = road.second;

            int totalCost = minCost[currentCity] + roadCost;
            if (totalCost < minCost[neighborCity]) {
                minCost[neighborCity] = totalCost;
                minHeap.push({ totalCost, neighborCity });
            }
        }
    }

    // Вывод результата
    int result = minCost[citiesCount - 1];
    if (result == INT_MAX) {
        result = -1;
    }
    cout << "Минимальное количество бензина на путь = " << result << endl;

    return 0;
}