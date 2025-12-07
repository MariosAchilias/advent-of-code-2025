#include <iostream>
#include <cinttypes>

#define MAX_LINE_LEN 200

uint64_t pow(uint64_t b, uint64_t exp) {
    while (--exp) b *= b;
    return b;
}

int main(void) {
    uint64_t sum = 0;
    int cnt = 0;
    while (true) {
        char line[MAX_LINE_LEN];
        if (scanf("%s\n", line) == EOF)
            break;
        
        int len = strlen(line);
        double line_sum = 0.0;

        int curr_idx = 0;
        for (int i = 0; i < len - 11; i++)
            curr_idx = line[i] > line[curr_idx] ? i : curr_idx;
        
        line_sum += (line[curr_idx] - '0') * pow(10, 11);

        for (int i = 1; i < 12; i++) {
            curr_idx = curr_idx + 1;
            for (int j = curr_idx; j < len - (11 - i); j++)
                curr_idx = line[j] > line[curr_idx] ? j : curr_idx;
            
            line_sum += (line[curr_idx] - '0') * pow(10, 11 - i);
        }

        sum += line_sum;
    }
    printf("sum: %" SCNu64 "\n", sum);
}