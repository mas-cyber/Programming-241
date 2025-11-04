#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция быстрой сортировки (QuickSort)
void quickSort(int array[], int leftBound, int rightBound) {
    // Базовый случай: если левая граница больше или равна правой, выходим
    if (leftBound >= rightBound) return;

    // Выбор опорного элемента (середина массива)
    int pivot = array[(leftBound + rightBound) / 2];
    int leftIndex = leftBound, rightIndex = rightBound;

    // Разделение массива относительно опорного элемента
    while (leftIndex <= rightIndex) {
        // Поиск элемента слева, который больше или равен опорному
        while (array[leftIndex] < pivot) leftIndex++;
        // Поиск элемента справа, который меньше или равен опорному
        while (array[rightIndex] > pivot) rightIndex--;

        // Если индексы не пересеклись, меняем элементы местами
        if (leftIndex <= rightIndex) {
            swap(array[leftIndex], array[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }

    // Рекурсивная сортировка левой и правой частей
    quickSort(array, leftBound, rightIndex);
    quickSort(array, leftIndex, rightBound);
}

int main() {
    setlocale(LC_ALL, "Ru");
    const int ARRAY_SIZE = 50;
    int numbers[ARRAY_SIZE];

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    cout << "Исходный массив:" << endl;
    // Заполнение массива случайными числами от 51 до 100
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = rand() % (100 - 51 + 1) + 51;
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Сортировка всего массива
    quickSort(numbers, 0, ARRAY_SIZE - 1);

    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}