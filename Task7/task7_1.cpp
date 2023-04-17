#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
// Функция, которая возвращает приоритет оператора
int Prior(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Функция, которая преобразует математическое выражение в префиксную форму
string toPrefix(const  string& expression) {
    stack<char> operators;
    stack<string> operands;
    // Разбиваем выражение на токены
    stringstream ss(expression);
    string  chislo;

    while (ss >>  chislo) {
    // Если токен - число, добавляем его в стек операндов
        if (isdigit( chislo[0])) {
            operands.push(chislo);
        } 
        else if ( chislo == "(") {
            operators.push( chislo[0]);
        } 
        else if ( chislo == ")") {
        // Извлекаем операторы из стека и добавляем их в выражение
            while (operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                string operand1 = operands.top();
                operands.pop();
                string operand2 = operands.top();
                operands.pop();
                string result =  string(1, op) + operand2 + operand1;
                operands.push(result);
            }
        operators.pop(); // Удаляем открывающую скобку из стека
        } 
        else if ( chislo == "+" ||  chislo == "-" ||  chislo == "*" ||  chislo == "/") {
            // Извлекаем операторы с более высоким или равным приоритетом из стека
            while (!operators.empty() && Prior(operators.top()) >= Prior( chislo[0])) {
                char op = operators.top();
                operators.pop();
                string operand1 = operands.top();
                operands.pop();
                string operand2 = operands.top();
                operands.pop();
                string result =  string(1, op) + operand2 + operand1;
                operands.push(result);
            }
        // Добавляем оператор в стек
        operators.push( chislo[0]);
        }
    }

    // Извлекаем оставшиеся операторы из стека
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        string operand1 = operands.top();
        operands.pop();
        string operand2 = operands.top();
        operands.pop();
        string result =  string(1, op) + operand2 + operand1;
        operands.push(result);
    }

    // Результат на вершине стека операндов
    return operands.top();
}

int main() {
    string expression = "( 3 + 4 ) * ( 5 / 2 )";
    
    cout << "Prefix: " << toPrefix(expression);
    return 0;
}