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


int main()
{
    
}