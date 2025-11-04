#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    unordered_set<int> numberSet;  // Множество для хранения уникальных чисел

    // Чтение данных из файла
    ifstream inputFile("input.txt");
    int currentNumber;
    cout << "Первоначальный вид файла: ";
    while (inputFile >> currentNumber) {
        cout << currentNumber << " ";

        // Обработка чисел согласно условию задачи
        if (currentNumber > 0) {
            numberSet.insert(currentNumber);  // Добавляем положительные числа
        }
        else if (currentNumber < 0) {
            numberSet.erase(-currentNumber);  // Удаляем числа по модулю
        }
        else {
            break;  // Завершаем обработку при встрече 0
        }
    }
    inputFile.close();
    cout << endl;

    // Преобразование множества в вектор для сортировки
    cout << "Отсортированный массив: ";
    vector<int> sortedNumbers;
    for (auto number : numberSet) {
        sortedNumbers.push_back(number);
    }

    // Сортировка чисел по возрастанию
    sort(sortedNumbers.begin(), sortedNumbers.end());

    // Запись результата в файл и вывод на экран
    ofstream outputFile("output.txt");
    for (auto number : sortedNumbers) {
        cout << number << " ";
        outputFile << number << " ";
    }
    outputFile.close();

    return 0;
}