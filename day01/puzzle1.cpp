#include <iostream>

int main(void) {
    int n = 50;
    int cnt = 0;

    while(true) {
        int d;
        char c;
        if (EOF == scanf("%c %d\n", &c, &d))
            break;

        n = (c == 'R' ? n + d : n - d) % 100;

        if (n == 0)
            cnt++;
    }
    printf("%ld\n", cnt);
}