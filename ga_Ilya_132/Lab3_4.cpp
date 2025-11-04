#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// Структура для хранения данных о студенте
struct Student {
    string surname;
    string firstName;

    // Конструктор для удобной инициализации
    Student(string lastname, string name) {
        surname = lastname;
        firstName = name;
    }
};

// Функция для вывода массива студентов
void printStudentList(Student studentList[], int studentCount) {
    cout << "Список студентов:" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << studentList[i].surname + " " + studentList[i].firstName << endl;
    }
}

// Функция сравнения для qsort (сначала по фамилии, затем по имени)
int compareStudents(const void* firstStudent, const void* secondStudent) {
    const Student* student1 = (Student*)firstStudent;
    const Student* student2 = (Student*)secondStudent;

    // Сравнение фамилий
    int surnameComparison = student1->surname.compare(student2->surname);
    if (surnameComparison != 0) return surnameComparison;

    // Если фамилии одинаковые, сравниваем имена
    return student1->firstName.compare(student2->firstName);
}

int main() {
    setlocale(LC_ALL, "Ru");
    const int STUDENT_COUNT = 4;

    // Инициализация массива студентов
    Student studentList[STUDENT_COUNT] = {
        Student("Яковлев", "Александр"),
        Student("Крутиков", "Фёдор"),
        Student("Мацюшевский", "Егро"),
        Student("Мацюшевский", "Егор")
    };

    cout << "До сортировки:" << endl;
    printStudentList(studentList, STUDENT_COUNT);

    // Сортировка студентов с помощью qsort
    qsort(studentList, STUDENT_COUNT, sizeof(Student), compareStudents);

    cout << endl << "После сортировки:" << endl;
    printStudentList(studentList, STUDENT_COUNT);

    return 0;
}