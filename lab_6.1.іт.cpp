#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція формування масиву за допомогою генератора випадкових чисел
void Create(int* p, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
    {
        p[i] = Low + rand() % (High - Low + 1);
    }
}

// Функція виведення масиву в рядок
void Print(const int* p, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << p[i];
    }
    cout << endl;
}

// Функція обчислення кількості елементів, що задовольняють критерію (від'ємні парні)
int Count(const int* p, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (p[i] < 0 && p[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

// Функція обчислення суми елементів, що задовольняють критерію (від'ємні парні)
int Sum(const int* p, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (p[i] < 0 && p[i] % 2 == 0)
        {
            sum += p[i];
        }
    }
    return sum;
}

// Функція заміни нулями елементів, що задовольняють критерію
void UpdateArray(int* p, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (p[i] < 0 && p[i] % 2 == 0)
        {
            p[i] = 0;
        }
    }
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int SIZE = 20;
    const int Low = -20;
    const int High = 34;

    int p[SIZE];

    // Формування та виведення початкового масиву
    Create(p, SIZE, Low, High);
    cout << "Initial array:" << endl;
    Print(p, SIZE);
    cout << endl;

    // Обчислення кількості та суми
    int c = Count(p, SIZE);
    int s = Sum(p, SIZE);

    cout << "Count = " << c << endl;
    cout << "Sum = " << s << endl;
    cout << endl;

    // Модифікація масиву (заміна нулями) та виведення результату
    UpdateArray(p, SIZE);
    cout << "Modified array:" << endl;
    Print(p, SIZE);
    cout << endl;

    return 0;
}
