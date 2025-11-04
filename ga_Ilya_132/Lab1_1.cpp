#include <iostream>
#include <cstdlib>  // Для функции rand()
#include <ctime>    // Для функции time()

using namespace std;

// Функция для вывода элементов массива
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    const int ARRAY_SIZE = 7;  // Размер массива
    int numbers[ARRAY_SIZE];   // Основной массив

    // Инициализация генератора случайных чисел текущим временем
    srand(time(NULL));

    cout << "Первоначальный массив: ";
    // Заполнение массива случайными числами и их вывод
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // Генерация чисел в диапазоне [2; 105]
        numbers[i] = rand() % 104 + 2;
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Сортировка выбором
    for (int currentIndex = 0; currentIndex < ARRAY_SIZE; currentIndex++) {
        int minElementIndex = currentIndex; // Индекс минимального элемента в неотсортированной части

        // Поиск минимального элемента в оставшейся части массива
        for (int nextIndex = currentIndex + 1; nextIndex < ARRAY_SIZE; nextIndex++) {
            if (numbers[nextIndex] < numbers[minElementIndex]) {
                minElementIndex = nextIndex; // Обновляем индекс минимального элемента
            }
        }

        // Обмен местами текущего элемента с найденным минимальным
        int temporary = numbers[currentIndex];
        numbers[currentIndex] = numbers[minElementIndex];
        numbers[minElementIndex] = temporary;
    }

    cout << "Отсортированный массив: ";
    printArray(numbers, ARRAY_SIZE);

    return 0;
}