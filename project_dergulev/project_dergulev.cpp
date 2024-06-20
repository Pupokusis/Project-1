#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <ctime>
#include <set>

using namespace std;

// Функция для генерации случайных чисел
vector<int> generateRandomNumbers(int n, int min, int max) {
    vector<int> numbers(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    for (int i = 0; i < n; ++i) {
        numbers[i] = dis(gen);
    }
    return numbers;
}

// Функция для ручного ввода массива
vector<int> inputNumbers(int n) {
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    return numbers;
}

// Функция для вывода массивов
void printArrays(const set<vector<int>>& uniqueArrays) {
    int i = 1;
    cout << endl;
    for (const auto& array : uniqueArrays) {
        cout << "Игрок " << i++ << ": ";
        for (int num : array) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Функция для проверки наличия 5 одинаковых чисел
bool isImpossible(const map<int, int>& counts) {
    for (const auto& pair : counts) {
        if (pair.second == 5) {
            return true;
        }
    }
    return false;
}

// Функция для проверки наличия 4 одинаковых чисел
bool isFourOfAKind(const map<int, int>& counts) {
    for (const auto& pair : counts) {
        if (pair.second == 4) {
            return true;
        }
    }
    return false;
}

// Функция для проверки наличия Full House (3 одинаковых + 2 одинаковых)
bool isFullHouse(const map<int, int>& counts) {
    bool three = false, two = false;
    for (const auto& pair : counts) {
        if (pair.second == 3) {
            three = true;
        }
        if (pair.second == 2) {
            two = true;
        }
    }
    return three && two;
}

// Функция для проверки наличия Straight (5 последовательных чисел)
bool isStraight(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < 4; ++i) {
        if (numbers[i] + 1 != numbers[i + 1]) {
            return false;
        }
    }
    return true;
}

// Функция для проверки наличия 3 одинаковых чисел
bool isThreeOfAKind(const map<int, int>& counts) {
    for (const auto& pair : counts) {
        if (pair.second == 3) {
            return true;
        }
    }
    return false;
}

// Функция для проверки наличия двух пар
bool isTwoPairs(const map<int, int>& counts) {
    int pairs = 0;
    for (const auto& pair : counts) {
        if (pair.second == 2) {
            pairs++;
        }
    }
    return pairs == 2;
}

// Функция для проверки наличия одной пары
bool isOnePair(const map<int, int>& counts) {
    for (const auto& pair : counts) {
        if (pair.second == 2) {
            return true;
        }
    }
    return false;
}

// Структура для хранения результата с приоритетом и максимальным числом
struct Result {
    string handType;
    int priority;
    int maxNumber;
    bool operator<(const Result& other) const {
        if (priority != other.priority)
            return priority > other.priority; // Чем выше приоритет, тем лучше
        return maxNumber < other.maxNumber;   // При равном приоритете сравниваем по максимальному числу
    }
};

// Функция для проверки условий и вывода результата
Result checkHand(const vector<int>& numbers) {
    // Подсчет количества каждого числа
    map<int, int> counts;
    for (int num : numbers) {
        counts[num]++;
    }
    // Определение максимального числа в массиве
    int maxNumber = *max_element(numbers.begin(), numbers.end());

    // Проверка условий с присвоением приоритетов
    if (isImpossible(counts)) {
        return { "Impossible", 1, maxNumber };
    }
    else if (isFourOfAKind(counts)) {
        return{ "Four of a Kind", 2, maxNumber };
    }
    else if (isFullHouse(counts)) {
        return { "Full House", 3, maxNumber };
    }
    else if (isStraight(numbers)) {
        return { "Straight", 4, maxNumber };
    }
    else if (isThreeOfAKind(counts)) {
        return { "Three of a Kind", 5, maxNumber };
    }
    else if (isTwoPairs(counts)) {
        return { "Two Pairs", 6, maxNumber };
    }
    else if (isOnePair(counts)) {
        return { "One Pair", 7, maxNumber };
    }
    else {
        return { "Nothing", 8, maxNumber };
    }
}

// Функция для проверки глобального распределения чисел в массивах
bool isValidGlobalDistribution(const set<vector<int>>& arrays) {
    map<int, int> globalCounts;
    for (const auto& array : arrays) {
        for (int num : array) {
            globalCounts[num]++;
            if (globalCounts[num] > 4) {
                return false; // Если какое-то число встречается больше 4 раз в глобальном масштабе
            }
        }
    }
    return true;
}

// Функция для ввода массивов случайным образом
void inputArraysRandomly(set<vector<int>>& uniqueArrays, const int numArrays) {
    uniqueArrays.clear();
    while (uniqueArrays.size() < numArrays) {
        vector<int> numbers;
        // Генерация уникального массива чисел
        do {
            numbers = generateRandomNumbers(5, 1, 13);
        } while (uniqueArrays.find(numbers) != uniqueArrays.end());
        // Временное добавление массива для проверки глобального распределения
        uniqueArrays.insert(numbers);
        // Проверка глобального распределения
        if (!isValidGlobalDistribution(uniqueArrays)) {
            uniqueArrays.erase(numbers); // Удаление массива, если условие не выполнено
        }
    }
}

// Функция для ручного ввода массивов
void inputArraysManually(set<vector<int>>& uniqueArrays, const int numArrays) {
    uniqueArrays.clear();
    int i = 1;
    while (uniqueArrays.size() < numArrays) {
        cout << "Игрок " << i++ << " - ";
        vector<int> numbers = inputNumbers(5);
        // Временное добавление массива для проверки глобального распределения
        uniqueArrays.insert(numbers);
        // Проверка глобального распределения
        if (!isValidGlobalDistribution(uniqueArrays)) {
            uniqueArrays.erase(numbers); // Удаление массива, если условие не выполнено
            cout << "Введенный массив нарушает глобальное распределение чисел. Попробуйте снова." << endl;
        }
    }
}

// Функция для нахождения и вывода самого старшего условия
void findBestHand(const set<vector<int>>& uniqueArrays) {
    Result bestResult = { "", INT_MAX, INT_MIN };
    int bestPlayerIndex = -1;
    cout << endl << "Комбинации игроков:" << endl;
    int playerIndex = 1;
    for (const auto& hand : uniqueArrays) {
        Result currentResult = checkHand(hand);
        cout << "Игрок " << playerIndex << "- " << currentResult.handType << endl;
        if (!(currentResult < bestResult)) {
            bestResult = currentResult;
            bestPlayerIndex = playerIndex;

        }
        playerIndex++;
    }
    cout << endl << "Лучшее условие у Игрока " << bestPlayerIndex << ": " << bestResult.handType << endl;
    cout << "Комбинация: ";
    auto it = uniqueArrays.begin();
    advance(it, bestPlayerIndex - 1);
    for (int num : *it) {
        cout << num << " ";
    }
    cout << endl;
}


int main()
{
    setlocale(LC_ALL, "ru");
    const int numArrays = 5;
    set<vector<int>> uniqueArrays;

    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Ввод массивов случайным образом" << endl;
        cout << "2. Ручной ввод массивов" << endl;
        cout << "3. Вывод массивов" << endl;
        cout << "4. Проверка условий и вывод" << endl;
        cout << "5. Завершение программы" << endl;
        cout << "Ваш выбор: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            inputArraysRandomly(uniqueArrays, numArrays);
            break;
        case 2:
            inputArraysManually(uniqueArrays, numArrays);
            break;
        case 3:
            printArrays(uniqueArrays);
            break;
        case 4:
            findBestHand(uniqueArrays);
            break;
        case 5:
            cout << "Завершение программы." << endl;
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        cout << endl; // Пустая строка для разделения выводов разных итераций меню
    }

}