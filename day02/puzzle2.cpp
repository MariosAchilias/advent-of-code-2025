#include <iostream>
#include <cinttypes>

bool repeats_seq(uint64_t i);

int main(void) {
    uint64_t sum = 0;

    while (true) {
        uint64_t start, end;
        if (scanf("%" SCNu64 "-%" SCNu64 ",", &start, &end) == EOF && scanf("%" SCNu64 "-%" SCNu64, &start, &end) == EOF)
            break;

        for (uint64_t i = start; i <= end; i++) {
            if (repeats_seq(i)) {
                sum += i;
            }
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

bool repeats_seq_of_len(uint64_t n, int seq_len) {
    uint64_t div = pow(10, seq_len);
    uint64_t first = n % div;
    while ((n = n / div)) {
        if (n % div != first)
            return false;
    }
    return true;
}

bool repeats_seq(uint64_t n) {
    uint64_t digits = num_digits(n);
    for (int seq_len = 1; seq_len <= digits / 2; seq_len++)
        if ((digits % seq_len == 0) && repeats_seq_of_len(n, seq_len))
            return true;

    return false;
}