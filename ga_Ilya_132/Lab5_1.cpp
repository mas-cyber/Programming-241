#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

// Функция для вывода кратчайшего пути
void printPath(vector<string>& path) {
    cout << "Кратчайший путь от S до I: ";
    for (auto node : path) {
        cout << node;
    }
    cout << endl;
}

// Функция поиска кратчайшего пути в графе (BFS)
vector<string> findShortestPath(string startNode, string endNode, unordered_map<string, vector<string>>& graph) {
    queue<string> nodeQueue;                           // Очередь для BFS
    unordered_set<string> visitedNodes;               // Посещенные вершины
    unordered_map<string, string> parentNode;         // Родительские вершины для восстановления пути

    nodeQueue.push(startNode);
    visitedNodes.insert(startNode);
    parentNode[startNode] = "";

    bool pathFound = false;

    // BFS обход графа
    while (!nodeQueue.empty() && !pathFound) {
        string currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Проверяем всех соседей текущей вершины
        if (graph.find(currentNode) != graph.end()) {
            for (string neighbor : graph[currentNode]) {
                if (visitedNodes.find(neighbor) == visitedNodes.end()) {
                    visitedNodes.insert(neighbor);
                    parentNode[neighbor] = currentNode;
                    nodeQueue.push(neighbor);

                    // Если достигли конечную вершину
                    if (neighbor == endNode) {
                        pathFound = true;
                        break;
                    }
                }
            }
        }
    }

    // Восстановление пути от конечной вершины к начальной
    vector<string> path;
    if (pathFound) {
        string current = endNode;
        while (current != "") {
            path.push_back(current);
            current = parentNode[current];
        }
    }
    return path;
}

int main() {
    setlocale(LC_ALL, "Ru");

    // Чтение графа из файла
    ifstream inputFile("input.txt");
    string line;
    unordered_map<string, vector<string>> graph;

    cout << "Граф прочтённый из файла input.txt:" << endl;
    while (getline(inputFile, line)) {
        string node = line.substr(0, 1);
        cout << node << ": ";

        // Обработка списка смежных вершин
        for (auto adjacentNode : line.substr(line.find(">") + 1)) {
            string neighbor(1, adjacentNode);
            graph[node].push_back(neighbor);
            cout << adjacentNode << " ";
        }
        cout << endl;
    }
    inputFile.close();

    // Поиск кратчайшего пути от S до I
    string startNode = "S";
    string endNode = "I";
    vector<string> shortestPath = findShortestPath(startNode, endNode, graph);
    reverse(shortestPath.begin(), shortestPath.end());
    printPath(shortestPath);

    return 0;
}