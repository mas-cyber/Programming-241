#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// Функция для вывода матрицы смежности
void printMatrix(vector<vector<int>>& matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    int verticesCount, startVertex, endVertex;
    cin >> verticesCount >> startVertex >> endVertex;

    // Матрица смежности графа
    vector<vector<int>> adjacencyMatrix(verticesCount, vector<int>(verticesCount));
    for (int i = 0; i < verticesCount; i++) {
        for (int j = 0; j < verticesCount; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    // Вывод матрицы для проверки
    printMatrix(adjacencyMatrix, verticesCount);

    // Массив для хранения кратчайших расстояний
    vector<int> shortestDistances(verticesCount, numeric_limits<int>::max());
    shortestDistances[startVertex - 1] = 0;

    // Приоритетная очередь для алгоритма Дейкстры
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({ 0, startVertex - 1 });

    while (!minHeap.empty()) {
        int currentDistance = minHeap.top().first;
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        // Пропускаем устаревшие записи
        if (currentDistance > shortestDistances[currentVertex]) continue;

        // Обход всех соседей текущей вершины
        for (int neighbor = 0; neighbor < verticesCount; neighbor++) {
            if (adjacencyMatrix[currentVertex][neighbor] != -1) {  // Если есть ребро
                int newDistance = shortestDistances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];

                // Если найден более короткий путь
                if (newDistance < shortestDistances[neighbor]) {
                    shortestDistances[neighbor] = newDistance;
                    minHeap.push({ newDistance, neighbor });
                }
            }
        }
    }

    // Вывод результата
    int result = shortestDistances[endVertex - 1];
    if (result == numeric_limits<int>::max()) {
        result = -1;
    }
    cout << "Кратчайший путь до конечной вершины = " << result << endl;

    return 0;
}