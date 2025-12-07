#include <iostream>
#include <cinttypes>

#define MAX_LINE_LEN 200

int main(void) {
    uint64_t sum = 0;
    int cnt = 0;
    while (true) {
        char line[MAX_LINE_LEN];
        if (scanf("%s\n", line) == EOF)
            break;
        
        int j = 0;
        for (int i = 0; i < strlen(line) - 1; i++)
            j = line[i] - '0' > line[j] - '0' ? i : j;
        
        int k = j + 1;
        for (int i = j + 1; i < strlen(line); i++)
            k = line[i] - '0' > line[k] - '0' ? i : k;

        sum += (line[j] - '0') * 10 + line[k] - '0';
    }
    printf("sum: %" SCNu64 "\n", sum);
}