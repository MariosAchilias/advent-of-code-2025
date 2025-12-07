#include <iostream>
#include <cinttypes>

bool repeats(uint64_t i);

int main(void) {
    uint64_t sum = 0;

    while (true) {
        uint64_t start, end;
        if (scanf("%" SCNu64 "-%" SCNu64 ",", &start, &end) == EOF && scanf("%" SCNu64 "-%" SCNu64, &start, &end) == EOF)
            break;

        for (uint64_t i = start; i <= end; i++) {
            if (repeats(i))
                sum += i;
        }
    }

    printf("Sum: %" SCNu64 "\n", sum);
}

int num_digits(uint64_t i) {
    int cnt = 1;
    while ((i = i / 10) != 0 && cnt++);
    return cnt;
}

uint64_t pow(uint64_t b, uint64_t exp) {
    while (--exp) b *= b;
    return b;
}
bool repeats(uint64_t i) {
    uint64_t digits = num_digits(i);
    if (digits % 2 != 0)
        return false;

    uint64_t div = pow(10, digits / 2);

    return i / div == i % div;
}