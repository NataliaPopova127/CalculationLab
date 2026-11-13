#include <iostream>
#include <string>
#include <cmath> 
#include <windows.h>
// (m/n)
class Ratio {
private:
    int m;
    int n;
public:
    Ratio() {
        m = 0;
        n = 0;
    }
    std::string get() {
        return std::to_string(m) + " " + std::to_string(n);
    }
    void set(int r_m, int r_n) {
        if (r_n == 0) {
            throw "Ошибка! Знаменатель не может быть равен 0!";
        }
        else {
            if (r_n < 0) {
                r_m *= (-1);
                r_n *= (-1);
            }

            m = r_m;
            n = r_n;
        }  
    }
    //сокращение дроби
    void reduce() {
        int gcd_value = gcd(m, n);
        m /= gcd_value;
        n /= gcd_value;
    }
    // Алгоритм Евклида для нахождения НОД
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void print() {
        std::cout << std::to_string(m) << "/" << std::to_string(n);
    }
    void enter() {
        int m;
        int n;
        std::cin >> m >> n;
        set(m, n);
    }
    double toDouble() {
        return static_cast<double>(m) / n;
    }
    static void compare(Ratio rat1, Ratio rat2) {
        if (rat1.toDouble() == rat2.toDouble()) {
            std::cout << "Дроби равны\n";
        }
        else if (rat1.toDouble() > rat2.toDouble()) {
            std::cout << "Дробь ";
            rat1.print();
            std::cout << " больше чем дробь ";
            rat2.print();
        }
        else {
            std::cout << "Дробь ";
            rat1.print();
            std::cout << " меньше чем дробь ";
            rat2.print();
        }
    }
#pragma region Calculations
    static void sum(Ratio rat1, Ratio rat2) {
        Ratio sumRat;
        if (rat1.n == rat2.n) {
            sumRat.m = rat1.m + rat2.m;
            sumRat.n = rat1.n;
        }
        else {
            sumRat.n = rat1.n * rat2.n;
            sumRat.m = (rat1.m * rat2.n) + (rat2.m *rat1.n);
        }
        sumRat.reduce();
        sumRat.print();
    }
    static void subtraction(Ratio rat1, Ratio rat2) {
        Ratio sumRat;
        if (rat1.n == rat2.n) {
            sumRat.m = rat1.m - rat2.m;
            sumRat.n = rat1.n;
        }
        else {
            sumRat.n = rat1.n * rat2.n;
            sumRat.m = (rat1.m * rat2.n) - (rat2.m * rat1.n);
        }
        sumRat.reduce();
        sumRat.print();
    }
    static void division(Ratio rat1, Ratio rat2) {
        Ratio sumRat;

        sumRat.m = rat1.m * rat2.n;
        sumRat.n = rat1.n * rat2.m;
        
        sumRat.reduce();
        sumRat.print();
    }
    static void multiplication(Ratio rat1, Ratio rat2) {
        Ratio sumRat;

        sumRat.m = rat1.m * rat2.m;
        sumRat.n = rat1.n * rat2.n;

        sumRat.reduce();
        sumRat.print();
    }
    void pow(int p) {
        Ratio sumRat;

        sumRat.m = std::pow(m, p);
        sumRat.n = std::pow(n, p);

        sumRat.reduce();
        sumRat.print();
    }
#pragma endregion
};

int main()
{
    try {
        while(true) {
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            Ratio rat1;
            Ratio rat2;
            Ratio res;
            char sign;

            std::cout << "Рациональный Калькулятор (+, -, /, *)" << std::endl;
            std::cout << "Введите a, операцию, b: ";
            rat1.enter();
            std::cin >> sign;
            rat2.enter();
            std::cout << "Результат: ";
            rat1.print();
            std::cout << " " << sign << " ";
            rat2.print();
            std::cout << " = ";

            switch (sign) {
            case '+':
                Ratio::sum(rat1, rat2);
                break;
            case '-':
                Ratio::subtraction(rat1, rat2);
                break;
            case '*':
                Ratio::multiplication(rat1, rat2);
                break;
            case '/':
                Ratio::division(rat1, rat2);
                break;
            default:
                throw "Неизвестное выражение";
                break;
            }
            std::cout << "\n";
        }
    }
    catch (const char* error_message)
    {
        std::cout << error_message << std::endl;
        return 0;
    }
}
