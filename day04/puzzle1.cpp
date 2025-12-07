#include <iostream>

#define MAX_LINE_LEN 200

class Grid {
    std::vector<std::vector<char>> array;
public:
    int width = 0;
    int height = 0;
    Grid() {
        char line[MAX_LINE_LEN];
        if (scanf("%s\n", line) == EOF)
            return;
            
        width = strlen(line);
        height = 0;

        while (true) {
            printf("read line: %s\n", line);
            array.push_back(std::vector<char>());
            for (int i = 0; i < width; i++)
                array[height].push_back(line[i]);

            height++; 
            if (scanf("%s\n", line) == EOF)
                break;

        }
    }
    bool roll_at(int x, int y) {
        if (x < 0 || y < 0 || x >= width || y >= height)
            return false;
        return array[y][x] == '@';
    }
    bool no_more_than_adjacent(int x, int y, int num_rolls) {
        bool ret = num_rolls > roll_at(x - 1, y)
            + roll_at(x + 1, y)
            + roll_at(x, y - 1)
            + roll_at(x, y + 1)
            + roll_at(x - 1, y - 1)
            + roll_at(x - 1, y + 1)
            + roll_at(x + 1, y - 1)
            + roll_at(x + 1, y + 1);
        return ret;
    }
};

int main(void) {
    Grid grid;
    int cnt = 0;
    for (int y = 0; y < grid.height; y++)
        for (int x = 0; x < grid.width; x++)
            if (grid.roll_at(x, y))
                cnt += grid.no_more_than_adjacent(x, y, 4);
    printf("%d\n", cnt);
}