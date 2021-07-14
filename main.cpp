#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

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

    friend ofstream& operator << (ofstream& out, const CalcMemmory<T, T2>& obj) {
        out << "first number: ";
        for (size_t i = 0; i < obj.first.size(); i++)
        {
            out << setw(5) << obj.first[i] << setw(6);
        }
        out << endl;
        out << "operation: ";
        for (size_t i = 0; i < obj.operation.size(); i++)
        {
            out << setw(5) << obj.operation[i] << setw(6);
        }
        out << endl;
        out << "second number: ";
        for (size_t i = 0; i < obj.second.size(); i++)
        {
            out << setw(5) << obj.second[i] << setw(6);
        }
        out << endl;
        out << "result: ";
        out << setw(12);
        for (size_t i = 0; i < obj.result.size(); i++)
        {
            out << obj.result[i] << setw(6);
        }
        out << endl;
        return out;
    }
    friend ifstream& operator >> (ifstream& in, CalcMemmory<T, T2> obj) {
        in >> obj.first;
        in >> obj.operation;
        in >> obj.second;
        in >> obj.result;
        return in;
    }
};

template <typename T, typename T2>
vector<T> CalcMemmory<T, T2>::get_first()
{
    return first;
}
template <typename T, typename T2>
vector<T2> CalcMemmory<T, T2>::get_operation()
{
    return operation;
}
template <typename T, typename T2>
vector<T> CalcMemmory<T, T2>::get_second()
{
    return second;
}
template <typename T, typename T2>
vector<T> CalcMemmory<T, T2>::get_result()
{
    return result;
}
template <typename T, typename T2>
CalcMemmory<T, T2>::CalcMemmory()
{
    first.reserve(0);
    operation.reserve(0);
    second.reserve(0);
    result.reserve(0);
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

    ofstream int_file;
    int_file.open("C:/Users/st/source/repos/homework27/int_res.txt");
    int_file << obj;

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

    ofstream double_file;
    double_file.open("C:/Users/st/source/repos/homework27/double_res.txt");
    double_file << obj2;

    return 0;
}