#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для вывода матрицы
void printMatrix(vector<vector<int>>& matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

// Функция быстрой сортировки для матрицы (сортировка по первому столбцу)
void quickSortMatrix(vector<vector<int>>& matrix, int leftBound, int rightBound) {
    // Базовый случай: если левая граница больше или равна правой, выходим
    if (leftBound >= rightBound) return;

    // Выбор опорного элемента (первый элемент средней строки)
    int pivot = matrix[(leftBound + rightBound) / 2][0];
    int leftIndex = leftBound, rightIndex = rightBound;

    // Разделение матрицы относительно опорного элемента первого столбца
    while (leftIndex <= rightIndex) {
        // Поиск строки слева, у которой первый элемент больше или равен опорному
        while (matrix[leftIndex][0] < pivot) leftIndex++;
        // Поиск строки справа, у которой первый элемент меньше или равен опорному
        while (matrix[rightIndex][0] > pivot) rightIndex--;

        // Если индексы не пересеклись, меняем строки местами
        if (leftIndex <= rightIndex) {
            swap(matrix[leftIndex], matrix[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }

    // Рекурсивная сортировка левой и правой частей
    quickSortMatrix(matrix, leftBound, rightIndex);
    quickSortMatrix(matrix, leftIndex, rightBound);
}

int main() {
    setlocale(LC_ALL, "Ru");
    const int ROWS = 10, COLUMNS = 10;
    vector<vector<int>> matrix(ROWS, vector<int>(COLUMNS));

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение матрицы случайными числами от 6 до 60
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLUMNS; col++) {
            matrix[row][col] = rand() % (61 - 6) + 6;
        }
    }

    cout << "Первоначальная матрица:" << endl;
    printMatrix(matrix, ROWS, COLUMNS);
    cout << endl;

    // Сортировка матрицы по первому столбцу
    quickSortMatrix(matrix, 0, ROWS - 1);

    cout << "Матрица после сортировки по первому столбцу:" << endl;
    printMatrix(matrix, ROWS, COLUMNS);

    return 0;
}