#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    int length = strlen(infix);
    char temp[MAX];

    for (int i = 0; i < length; i++) {
        if (infix[i] == '(')
            temp[length - i - 1] = ')';
        else if (infix[i] == ')')
            temp[length - i - 1] = '(';
        else
            temp[length - i - 1] = infix[i];
    }
    temp[length] = '\0';

    infixToPostfix(temp, prefix);

    int prefixLength = strlen(prefix);
    for (int i = 0; i < prefixLength / 2; i++) {
        char tempChar = prefix[i];
        prefix[i] = prefix[prefixLength - i - 1];
        prefix[prefixLength - i - 1] = tempChar;
    }
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int evaluatePostfix(char* postfix) {
    int i;
    int stack[MAX], top = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        }
        else {
            int val1 = stack[top--];
            int val2 = stack[top--];

            switch (c) {
                case '+': stack[++top] = val2 + val1; break;
                case '-': stack[++top] = val2 - val1; break;
                case '*': stack[++top] = val2 * val1; break;
                case '/': stack[++top] = val2 / val1; break;
                case '^': stack[++top] = power(val2, val1); break;
            }
        }
    }
    return stack[top];
}

int main() {
    int choice;
    char infix[MAX], postfix[MAX], prefix[MAX];

    do {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Evaluation of Postfix Expression\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter Infix expression: ");
                gets(infix);
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;

            case 2:
                printf("Enter Infix expression: ");
                gets(infix);
                infixToPrefix(infix, prefix);
                printf("Prefix Expression: %s\n", prefix);
                break;

            case 3:
                printf("Enter Postfix expression: ");
                gets(postfix);
                printf("Postfix Evaluation Result: %d\n", evaluatePostfix(postfix));
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}