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

int main()
{
    
}