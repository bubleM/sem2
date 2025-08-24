#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef string phone_number;
typedef string country_code;
typedef string provider;
typedef string owner;
typedef string tariff_plan;
typedef bool unlimited_internet;
typedef int call_minutes;

struct MobileOperator 
{
    country_code code;
    provider prov;
    phone_number number;
};

struct MobileAccount 
{
    MobileOperator mobile_op;
    owner own;
    tariff_plan plan;
    unlimited_internet internet;
    call_minutes minutes;

    void print_info() const {
        cout << "Номер телефона: +" << mobile_op.code << " (" << mobile_op.prov << ") " << mobile_op.number << endl;
        cout << "Владелец: " << own << endl;
        cout << "Тарифный план: " << plan << endl;
        cout << "Безлимитный интернет: " << (internet ? "Да" : "Нет") << endl;
        cout << "Минуты на звонки во все сети: " << minutes << endl;
    }
};

bool operator == (const MobileAccount& acc1, const MobileAccount& acc2) {
    return (acc1.mobile_op.number == acc2.mobile_op.number && acc1.own == acc2.own);
}

bool operator > (const MobileAccount& acc1, const MobileAccount& acc2) {
    return acc1.minutes > acc2.minutes;
}

int main() {
    setlocale(LC_ALL, "Russian");

    MobileAccount account1 = { {"375", "МТС", "29 123 45 67"}, "Виктория Викторовна", "Smart", true, 500 };
    MobileAccount account2 = { {"375", "А1", "44 765 43 21"}, "Дарья Александровна", "Unlimited", true, 1000 };

    if (account1 == account2)
        cout << "Аккаунты одинаковые" << endl;
    else
        cout << "Аккаунты разные" << endl;

    if (account1 > account2)
        cout << "Первый аккаунт имеет больше минут" << endl;
    else
        cout << "Второй аккаунт имеет больше минут" << endl;

    cout << "\nИнформация об аккаунте 1:" << endl;
    account1.print_info();

    cout << "\nИнформация об аккаунте 2:" << endl;
    account2.print_info();

    return 0;
}
