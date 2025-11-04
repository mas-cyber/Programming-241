#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

// Функция для вывода элементов массива
void printArray(int array[], int size) {
    for (int index = 0; index < size; index++) {
        cout << array[index] << " ";
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
    for (int index = 0; index < ARRAY_SIZE; index++) {
        // Генерация случайных чисел в диапазоне [0; 100]
        numbers[index] = rand() % 101;
        cout << numbers[index] << " ";
    }
    cout << endl;

    int maxIndex, temporary;
    for (int currentIndex = 0; currentIndex < ARRAY_SIZE; currentIndex++) {
        // Предполагаем, что текущий элемент является максимальным
        maxIndex = currentIndex;

        // Поиск реального максимального элемента в оставшейся части массива
        for (int nextIndex = currentIndex + 1; nextIndex < ARRAY_SIZE; nextIndex++) {
            // Если находим элемент больше текущего максимального, обновляем индекс
            if (numbers[nextIndex] > numbers[maxIndex]) {
                maxIndex = nextIndex;
            }
        }

        // Обмен местами: текущий элемент и найденный максимальный
        // Это перемещает максимальный элемент в правильную позицию
        temporary = numbers[currentIndex];
        numbers[currentIndex] = numbers[maxIndex];
        numbers[maxIndex] = temporary;
    }

    cout << "Массив отсортированный по убыванию: ";
    printArray(numbers, ARRAY_SIZE);

    return 0;
}