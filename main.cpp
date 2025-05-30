#include <iostream>
#include <fstream>
#include <string>
#include "my_string1.h"
#include "my_string2.h"

using namespace std;

// Прототипи функцій для кожного завдання
void task1();
void task2();

int main() {
    int num;
    do {
        // Вивід меню
        cout << "\n=========== Task Menu ===========\n";
        cout << " 1 - Replace part of a string (task1)\n";
        cout << " 2 - Count words in lines from file (task2)\n";
        cout << " 0 - Exit the program\n";
        cout << "---------------------------------\n";
        cout << "Your choice: ";

        if (!(cin >> num)) {
            // Якщо введено не число
            cin.clear(); // скидаємо стан потоку
            cin.ignore(32767, '\n'); // очищаємо буфер
            cout << " Error: please enter a valid number!\n";
            continue;
        }

        cin.ignore(32767, '\n'); // очищаємо залишки потоку

        switch (num) {
        case 0:
            cout << " Exiting the program...\n";
            break;
        case 1:
            task1(); // Виконання першого завдання
            break;
        case 2:
            task2(); // Виконання другого завдання
            break;
        default:
            cout << " Invalid task number! Try again.\n";
        }
    } while (num != 0);

    return 0;
}

void task1() {
    // Масив символів і string для зберігання введеного рядка
    char cstr[256];
    string std_str;

    cout << "Enter string: ";
    cin.getline(cstr, 256); // Зчитування рядка в масив символів
    std_str = cstr;         // Копіювання в string

    int pos, len;
    char substr[256];
    cout << "Enter position: ";
    cin >> pos; // позиція вставки
    cout << "Enter length: ";
    cin >> len; // кількість символів для заміни
    cin.ignore();

    cout << "Enter replacement substring: ";
    cin.getline(substr, 256); // новий рядок для вставки

    // Метод з використанням стандартного string::replace
    string std_result = std_str;
    std_result.replace(pos, len, substr);
    cout << "[std::string::replace] -> " << std_result << endl;

    // Метод, реалізований вручну
    my_replace(cstr, pos, len, substr);
    cout << "[my_replace] -> " << cstr << endl;
}

void task2() {
    ifstream fin("input_string2.txt");  // відкриття вхідного файлу
    ofstream fout("output_string2.txt"); // відкриття вихідного файлу
    if (!fin.is_open()) {
        cout << "Cannot open input file!" << endl;
        return;
    }

    if (!fout.is_open()) {
        cout << "Cannot open output file!" << endl;
        fin.close();
        return;
    }

    string line;
    int line_num = 1;
    while (getline(fin, line)) {
        int count = count_words(line); // обчислення кількості слів у рядку
        fout << "Line " << line_num << ": " << count << " words" << endl;
        ++line_num;
    }

    fin.close();
    fout.close();
    cout << "Results written to output_string2.txt" << endl; // повідомлення про завершення
}
