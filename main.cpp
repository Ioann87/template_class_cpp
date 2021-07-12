#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename T2>
class CalcMemmory {
private:
    vector<T> first;
    vector<T2> operation;
    vector<T> second;
    vector<T> result;

public:
    CalcMemmory();
    ~CalcMemmory() {};

    vector<T> get_first();
    vector<T2> get_operation();
    vector<T> get_second();
    vector<T> get_result();
    void update_memmory(T num1, T2 oper, T num2);
    void update_result(T num1, T2 oper, T num2);
};
template <typename T, typename T2>
vector<T> CalcMemmory<T, T2>::get_first()
{
    return move(first);
}
template <typename T, typename T2>
vector<T2> CalcMemmory<T, T2>::get_operation()
{
    return move(operation);
}
template <typename T, typename T2>
vector<T> CalcMemmory<T, T2>::get_second()
{
    return move(second);
}
template <typename T, typename T2>
vector<T> CalcMemmory<T, T2>::get_result()
{
    return move(result);
}
template <typename T, typename T2>
CalcMemmory<T, T2>::CalcMemmory()
{
    first[0];
    operation[0];
    second[0];
    result[0];
}

template <typename T, typename T2>
void CalcMemmory<T, T2>::update_memmory(T num1, T2 oper, T num2)
{
    first.push_back(num1);
    operation.push_back(oper);
    second.push_back(num2);
    update_result(num1, oper, num2);
    return;
}
template <typename T, typename T2>
void CalcMemmory<T, T2>::update_result(T num1, T2 oper, T num2)
{
    switch (oper) {
    case '+':
        result.push_back(num1 + num2);
        break;
    case '*':
        result.push_back(num1 * num2);
        break;
    case '/':
        result.push_back(num1 / num2);
        break;
    case '%':
        result.push_back(int(num1) % int(num2));
        break;
    case '^':
        result.push_back((num1 + num2) / 2);
        break;
    }
}

int main()
{

    CalcMemmory<int, char> obj;

    obj.update_memmory(12, '+', 24);
    obj.update_memmory(3, '*', 24);
    obj.update_memmory(48, '/', 24);
    obj.update_memmory(28, '%', 24);
    obj.update_memmory(12, '^', 24);

    vector<int> f;
    f = obj.get_first();

    vector<int> s;
    s = obj.get_second();

    vector<char> ch;
    ch = obj.get_operation();

    vector<int> res;
    res = obj.get_result();

    for (size_t i = 0; i < f.size(); i++) {
        cout << f[i] << " "
             << ch[i] << " "
             << s[i] << " = "
             << res[i] << endl;
    }

    CalcMemmory<double, char> obj2;

    obj2.update_memmory(12.3, '+', 24.34);
    obj2.update_memmory(3.15, '*', 24.54);
    obj2.update_memmory(48.45, '/', 24.85);
    obj2.update_memmory(28.45, '%', 24.78);
    obj2.update_memmory(12.789, '^', 24.654);

    vector<double> fd;
    fd = obj2.get_first();

    vector<double> sd;
    sd = obj2.get_second();

    vector<char> chd;
    chd = obj2.get_operation();

    vector<double> resd;
    resd = obj2.get_result();

    for (size_t i = 0; i < fd.size(); i++) {
        cout << fd[i] << " "
             << chd[i] << " "
             << sd[i] << " = "
             << resd[i] << endl;
    }

    return 0;
}
