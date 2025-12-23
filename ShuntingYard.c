#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * TIME COMPLEXITY ANALYSIS:
 * - getPrecedence(): O(1) - constant time lookup
 * - convertInfixToPostfix(): O(n) where n is expression length
 *   - Single pass through input: O(n)
 *   - Each character pushed/popped at most once: O(n)
 * 
 * SPACE COMPLEXITY: O(n)
 *   - Stack can hold up to n operators in worst case
 *   - Output postfix string is also O(n)
 */

#define MAX_SIZE 100

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void convertInfixToPostfix(char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[k++] = symbol;
        } 
        else if (symbol == '(') {
            stack[++top] = symbol;
        } 
        else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;
        } 
        else {
            while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(symbol)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = symbol;
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
}

int main() {
    char infixExpression[MAX_SIZE] = "a+b*(c^d-e)";
    char postfixResult[MAX_SIZE];

    convertInfixToPostfix(infixExpression, postfixResult);

    printf("Infix:   %s\n", infixExpression);
    printf("Postfix: %s\n", postfixResult);

    return 0;
}