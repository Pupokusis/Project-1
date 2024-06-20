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




int main()
{
    
}