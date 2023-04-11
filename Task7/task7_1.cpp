#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

int prior(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

string pref(string& infix) {
    stack<char> operators;
    stack<string> znaki;

    // Разделяем выражение на символы
    stringstream ss(infix); //строка-поток
    string simvol;

    while (ss >> simvol) {
        // Если число, добавляем его в стек знаков
        if (isdigit(simvol[0])) {
            znaki.push(simvol);
        } 
        else if (simvol == "(") {
            operators.push(simvol[0]);
        } 
        else if (simvol == ")") {
        // Извлекаем операторы из стека и добавляем их в выражение
            while (operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                string operand1 = znaki.top();
                znaki.pop();
                string operand2 = znaki.top();
                znaki.pop();
                string result = string(1, op) + operand2 + operand1;
                znaki.push(result);
            }
            operators.pop(); // Удаляем открывающую скобку из стека
        } 
        else if (simvol == "+" || simvol == "-" || simvol == "*" || simvol == "/") {
            // Извлекаем операторы с более высоким или равным приоритетом из стека
            while (!operators.empty() && prior(operators.top()) >= prior(simvol[0])) {
                char op = operators.top();
                operators.pop();
                string operand1 = znaki.top();
                znaki.pop();
                string operand2 = znaki.top();
                znaki.pop();
                string result = string(1, op) + operand2 + operand1;
                znaki.push(result);
            }
            
            operators.push(simvol[0]);
        }
    }

    // Извлекаем оставшиеся операторы из стека
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        string operand1 = znaki.top();
        znaki.pop();
        string operand2 = znaki.top();
        znaki.pop();
        string result = string(1, op) + operand2 + operand1;
        znaki.push(result);
    }

    // Результат находится на вершине стека операндов
    return znaki.top();
}

int main() {
    string infix = "(3+4)*(5/2)";
    cout<<pref(infix);
    return 0;
}