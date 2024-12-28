#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char c) {
if (c == '^')
return 3;
else if (c == '*' || c == '/')
return 2;
else if (c == '+' || c == '-')
return 1;
return -1;
}
char associativity(char c) {
if (c == '^')
return 'R';
return 'L';

}

void infixToPostfix(char* exp) {
int len = strlen(exp);

char* result = (char*)malloc((len + 1) * sizeof(char));
char* stack = (char*)malloc(len * sizeof(char));
if (!result || !stack) {
printf("Memory allocation failed\n");
return;
}

int resultIndex = 0, stackIndex = -1;

for (int i = 0; i < len; i++) {
char c = exp[i];

if (isalnum(c)) {
result[resultIndex++] = c;
}

else if (c == '(') {
stack[++stackIndex] = c;
}
else if (c == ')') {
while (stackIndex >= 0 && stack[stackIndex] != '(') {
result[resultIndex++] = stack[stackIndex--];


}
stackIndex--; // Remove '(' from stack
}

else {
while (stackIndex >= 0 &&
(precedence(c) < precedence(stack[stackIndex]) ||
(precedence(c) == precedence(stack[stackIndex]) &&
associativity(c) == 'L'))) {
result[resultIndex++] = stack[stackIndex--];
}
stack[++stackIndex] = c;
}
}

while (stackIndex >= 0) {
result[resultIndex++] = stack[stackIndex--];
}

result[resultIndex] = '\0';
printf("Postfix Expression: %s\n", result);

free(result);
free(stack);
}

int main() {

char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
printf("Infix Expression: %s\n", exp);
infixToPostfix(exp);
return 0;
}
