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
    std::cout << "����� ��������� ��� ����������\n";
    std::cout << "� �������� ��������� n ������ ����� ��������. ���� ����� ������ k ��������.\n ��������� ��������� �� ����� ������� ��� k �������� �� ��������� n, ���� �������, � ������� �� �������� ��������, �� ����� ��������?\n";
    long long n = 0, k = -1;
    std::cout << "������� n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "������� �������� ��������: n ������ ���� > 0. ������� �������� n:\n";
        std::cin >> n;
    }
    std::cout << "������� k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout <<  (k >= 0);
        std::cin >> k;
    }
    std::cout << "�����: " << cnk(n, k) << std::endl;
}

void ank() {
    std::cout << "����� ���������� ��� ����������\n";
    std::cout << "� ������ �� n ���� ���������� k ���� ��� �����������. ������� ���������� ��������� ��������� ���� ����,\n ���� ��� ��� ������ ���� ���������� �������������?\n";
    long long n = 0, k = -1;
    std::cout << "������� n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "������� �������� ��������: n ������ ���� > 0. ������� �������� n:\n";
        std::cin >> n;
    }
    std::cout << "������� k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout <<  (k >= 0);
        std::cin >> k;
    }
    std::cout << "�����: " << ank(n, k) << std::endl;
}

void pn() {
    std::cout << "����� ������������ ��� ����������\n";
    std::cout << "������� ��������� ������ ����� ��������� �� n �������?\n";
    long long n = 0, k = -1;
    std::cout << "������� n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "������� �������� ��������: n ������ ���� > 0. ������� �������� n:\n";
        std::cin >> n;
    }
    std::cout << "�����: " << pn(n) << std::endl;
}

void cnk_rep() {
    std::cout << "����� ��������� � ������������\n";
    std::cout << "� ���� ���������� n ����� ��������, �� ������� ���� ����� ������� ����� ����������.\n ������� ��������� �������� ������ �������� � ���� ����, ���� �� ����� ������� ���� � ��� �� ������� ��������� ���?\n";
    long long n = 0, k = -1;
    std::cout << "������� n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "������� �������� ��������: n ������ ���� > 0. ������� �������� n:\n";
        std::cin >> n;
    }
    std::cout << "������� k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout <<  (k >= 0);
        std::cin >> k;
    }
    std::cout << "�����: " << cnk(k+n-1, k) << std::endl;
}

void bnk() {
    std::cout << "����� ���������� � ������������\n";
    std::cout << "� �������� ���� n ������ �������� �� ���������� � �� ����� ������� k �� ��� ��� ���������� � ��������.\n ������� ��������� ������� ��������� �� ����� �������, ���� ��� ��������� �������� ���� � ��� �� ������� ��������� ���?\n";
    long long n = 0, k = -1;
    std::cout << "������� n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "������� �������� ��������: n ������ ���� > 0. ������� �������� n:\n";
        std::cin >> n;
    }
    std::cout << "������� k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout << "������� �������� ��������: k ������ ���� >= 0. ������� �������� k:\n";
        std::cin >> k;
    }
    std::cout << "�����: " << bnk(n, k) << std::endl;
}

void pn_rep() {
    std::cout << "����� ������������ � ������������\n";
    std::cout << "������� ���������� ��������� �������� ������������ �� ����� n ����, ����� ������� 4 ������: n1 ���������� '������ � ���������',\n n2 ���������� '����� � ���', n3 ���������� '���� ��������' � n4 ���������� '������ ����������'?\n";
    long long n = 0, k = 2;
    std::vector<long long> vec_n;
    std::cout << "������� n:";
    std::cin >> n;
    while (n <= 0) {
        std::cout << "������� �������� ��������: n ������ ���� > 0. ������� �������� n:\n";
        std::cin >> n;
    }
    std::cout << "������� k:";
    std::cin >> k;
    while ((k < 0) || (k > n)) {
        std::cout << "������� �������� ��������: k ������ ���� >= 0. ������� �������� k:\n";
        std::cin >> k;
    }
    long long vrem = 0, sum = 0;
    std::cout << "������� " << k << " �����, ����� ������ � ����� ������\n";
    for (long long i = 0; i < k; i++) {
        vrem = 0;
        std::cout << i + 1 << ") ";
        std::cin >> vrem;
        while (vrem <= 0) {
            std::cout << "������� �������� ��������: n[i] ������ ���� > 0.\n������� �������� n[i]:\n" << i + 1 << ") ";
            std::cin >> vrem;
        }
        vec_n.push_back(vrem);
        sum += vrem;
    }
    if (sum != n) {
        std::cout << sum <<"������� �������� ��������: ����� n[i] ������ ���� ����� n:\n\n\n";
        pn_rep();
    }
    std::cout << "�����: " << pn_rep(n, k, vec_n) << std::endl;
}
void menu() {
    long long num = 0;
    std::cout << "1. ������ �� ����� ��������� ��� ���������� \n";
    std::cout << "2. ������ �� ����� ���������� ��� ���������� \n";
    std::cout << "3. ������ �� ����� ������������ ��� ���������� \n";
    std::cout << "4. ������ �� ����� ��������� c ������������ \n";
    std::cout << "5. ������ �� ����� ���������� � ������������ \n";
    std::cout << "6. ������ �� ����� ������������ � ������������ \n";
    std::cout << "7. ��������� ��������� \n";
    std::cout << "������� ����� ������:";
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
        std::cout << "����� ���������� ���������\n";
        return;
    }
    else{
        std::cout << "������� �������� ��������.\n";
    }
    menu();
    
}
int main() {
    setlocale(LC_ALL, "Rus");
    menu();
}
