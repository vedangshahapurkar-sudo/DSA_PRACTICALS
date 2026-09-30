#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define size 80

struct student {
    double s[size];
    int top;
} st;

int main() {
    char exp[size];
    int len;
    double result;
    double post(char[]);

    printf("\n Enter a postfix expression :");
    scanf("%79s", exp);
    len = strlen(exp);
    exp[len] = '$'; 
    exp[len + 1] = '\0';
    
    result = post(exp);
    printf("\n the value of the expression is : %f\n", result);

    return 0;
}

double post(char exp[]) {
    char ch;
    double result = 0, val, op1, op2;
    void push(double); 
    double pop();
    int i;

    st.top = -1;
    i = 0;
    ch = exp[i];

    while (ch != '$') {
        
        if (isdigit(ch)) {
            val = ch - '0';
            push(val);
        }
        
        else if (isalpha(ch)) {
            printf("Enter value for %c: ", ch);
            scanf("%lf", &val);
            push(val);
        }
        
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': result = op1 + op2; 
                break;
                case '-': result = op1 - op2;
                break;
                case '*': result = op1 * op2; 
                break;
                case '/': result = op1 / op2; 
                break;
                case '^': result = pow(op1, op2); 
                break;
            }
            push(result);
        }
        i++;
        ch = exp[i];
    }
    result = pop();
    return result;
}

void push(double val) {
    if (st.top >= size - 1) {
        printf("\n stack full");
    } else {
        st.top++;
        st.s[st.top] = val;
    }
}

double pop() {
    double val; 
    if (st.top == -1) {
        printf("\n stack is empty ");
        return 0;
    } else {
        val = st.s[st.top];
        st.top--;
        return val;
    }
}
