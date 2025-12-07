#include <iostream>

int main(void) {
    int dial = 50;
    int cnt = 0;

    while(true) {
        int d;
        char c;
        if (EOF == scanf("%c %d\n", &c, &d))
            break;

        cnt += d / 100;
        d = d % 100;

        dial = c == 'R' ? dial + d : dial - d;
 
        if ((dial < 0 || dial >= 100))
            cnt++;

        dial = (dial % 100 + 100) % 100;
    }
    printf("Dial: %d, Cnt: %d\n", dial, cnt);
}