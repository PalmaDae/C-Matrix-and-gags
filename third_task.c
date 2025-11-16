#include <stdio.h>

void someFunction(int n) {
    int cnt = 0;
    int x = n;
    int some = 0;
    int first = 0;
    first = n;
    while (x > 0)
    {
        some += x%10;
        x/=10;
        cnt++;

    }

    while (first >= 10) {
        first /= 10;
    }



    printf("Количество цифр: %d\n",cnt);

    printf("Сумма цифр: %d\n",some);
    
    printf("Первая цифра: %d\n",first);
}

int main() {
    someFunction(53);
    return 0;
}
