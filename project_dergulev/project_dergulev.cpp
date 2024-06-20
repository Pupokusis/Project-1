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


int main()
{
    
}