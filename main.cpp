#include <iostream>
#include <vector>

long long pow(long long a, long long n) { 
    if (n == 0) return 1;
    if (n % 2 == 0)
        return pow((a * a), n / 2);
    else
        return (a * pow(a, n - 1));
}

long long ank(long long n, long long k) {
    long long ans = 1;
    for (int i = n - k + 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
    
}

long long bnk(long long n, long long k) {
    long long ans = pow(n, k);
    return ans;
    
}

long long cnk(long long n, long long k) {
    long long ans = 1;
    for (int i = std::max(k, n - k) + 1; i <= n; i++) {
        ans *= i;
    }
    for (int i = 2; i <= std::min(k, n - k); i++) {
        ans /= i;
    }
    return ans;
}

long long pn_rep(long long n, long long k, std::vector<long long> vec_n) {
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }
    for (int el : vec_n) {
        for (int i = 2; i <= el; i++) {
            ans /= i;
        }
    }
    return ans;
}

long long pn(long long n) {
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    };
    return ans;
}

void cnk() {
    std::cout << "Число сочетаний без повторений\n";
    std::cout << "В магазине продается n разных видов пирожных. Вася хочет купить k пирожных.\n Сколькими способами он может выбрать эти k пирожных из доступных n, если порядок, в котором он выбирает пирожные, не имеет значения?\n";
    long long n = 0, k = -1;
    std::cout << "Введите n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "Введено неверное значение: n должно быть > 0. Введите повторно n:\n";
        std::cin >> n;
    }
    std::cout << "Введите k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout <<  (k >= 0);
        std::cin >> k;
    }
    std::cout << "Ответ: " << cnk(n, k) << std::endl;
}

void ank() {
    std::cout << "Число размещений без повторений\n";
    std::cout << "В колоде из n карт выбираются k карт без возвращения. Сколько существует различных сочетаний этих карт,\n если все они должны быть различными достоинствами?\n";
    long long n = 0, k = -1;
    std::cout << "Введите n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "Введено неверное значение: n должно быть > 0. Введите повторно n:\n";
        std::cin >> n;
    }
    std::cout << "Введите k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout <<  (k >= 0);
        std::cin >> k;
    }
    std::cout << "Ответ: " << ank(n, k) << std::endl;
}

void pn() {
    std::cout << "Число перестановок без повторений\n";
    std::cout << "Сколько различных команд можно составить из n человек?\n";
    long long n = 0, k = -1;
    std::cout << "Введите n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "Введено неверное значение: n должно быть > 0. Введите повторно n:\n";
        std::cin >> n;
    }
    std::cout << "Ответ: " << pn(n) << std::endl;
}

void cnk_rep() {
    std::cout << "Число сочетаний с повторениями\n";
    std::cout << "В кафе предлагают n видов напитков, из которых Вася может выбрать любое количество.\n Сколько различных способов выбора напитков у Васи есть, если он может выбрать один и тот же напиток несколько раз?\n";
    long long n = 0, k = -1;
    std::cout << "Введите n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "Введено неверное значение: n должно быть > 0. Введите повторно n:\n";
        std::cin >> n;
    }
    std::cout << "Введите k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout <<  (k >= 0);
        std::cin >> k;
    }
    std::cout << "Ответ: " << cnk(k+n-1, k) << std::endl;
}

void bnk() {
    std::cout << "Число размещений с повторениями\n";
    std::cout << "У студента есть n разных учебника по математике и он хочет выбрать k из них для подготовки к экзамену.\n Сколько различных наборов учебников он может выбрать, если ему разрешено выбирать один и тот же учебник несколько раз?\n";
    long long n = 0, k = -1;
    std::cout << "Введите n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "Введено неверное значение: n должно быть > 0. Введите повторно n:\n";
        std::cin >> n;
    }
    std::cout << "Введите k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout << "Введено неверное значение: k должно быть >= 0. Введите повторно k:\n";
        std::cin >> k;
    }
    std::cout << "Ответ: " << bnk(n, k) << std::endl;
}

void pn_rep() {
    std::cout << "Число перестановок с повторениями\n";
    std::cout << "Сколько существует различных способов расположения на полке n книг, среди которых 4 группы: n1 одинаковые 'Мастер и Маргарита',\n n2 одинаковых 'Война и мир', n3 одинаковая 'Анна Каренина' и n4 одинаковая 'Братья Карамазовы'?\n";
    long long n = 0, k = 2;
    std::vector<long long> vec_n;
    std::cout << "Введите n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "Введено неверное значение: n должно быть > 0. Введите повторно n:\n";
        std::cin >> n;
    }
    std::cout << "Введите k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout << "Введено неверное значение: k должно быть >= 0. Введите повторно k:\n";
        std::cin >> k;
    }
    long long vrem = 0, sum = 0;
    std::cout << "Введите " << k << " чисел, вводя каждое с новой строки\n";
    for (long long i = 0; i < k; i++) {
        vrem = 0;
        std::cout << i + 1 << ") ";
        std::cin >> vrem;
        while (vrem <= 0) {
            std::cout << "Введено неверное значение: n[i] должно быть > 0.\nВведите повторно n[i]:\n" << i + 1 << ") ";
            std::cin >> vrem;
        }
        vec_n.push_back(vrem);
        sum += vrem;
    }
    if (sum != n) {
        std::cout << sum <<"Введено неверное значение: сумма n[i] должна быть равна n:\n\n\n";
        pn_rep();
    }
    std::cout << "Ответ: " << pn_rep(n, k, vec_n) << std::endl;
}
void menu() {
    long long num = 0;
    std::cout << "1. Задача на число сочетаний без повторений \n";
    std::cout << "2. Задача на число размещений без повторений \n";
    std::cout << "3. Задача на число перестановок без повторений \n";
    std::cout << "4. Задача на число сочетаний c повторениями \n";
    std::cout << "5. Задача на число размещений с повторениями \n";
    std::cout << "6. Задача на число перестановок с повторениями \n";
    std::cout << "7. Завершить программу \n";
    std::cout << "Введите номер задачи:";
    std::cin >> num;
    std::cout << std::endl;

    if (num == 1)
        cnk();
    else if (num == 2)
        ank();
    else if (num == 3)
        pn();
    else if (num == 4)
        cnk_rep();
    else if (num == 5)
        bnk();
    else if (num == 6)
        pn_rep();
    else if (num == 7){
        std::cout << "Конец выполнения программы\n";
        return;
    }
    else{
        std::cout << "Введено неверное значение.\n";
    }
    menu();
    
}
int main() {
    setlocale(LC_ALL, "Rus");
    menu();
}
