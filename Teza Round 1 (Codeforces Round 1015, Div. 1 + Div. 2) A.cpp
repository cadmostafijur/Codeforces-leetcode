By mostafijur721, contest: Teza Round 1 (Codeforces Round 1015, Div. 1 + Div. 2), problem: (A) Max and Mod, Accepted, #, Copy
#include <stdio.h>
 
int main() {
    int total_test_cases;
    scanf("%d", &total_test_cases);
    
    while (total_test_cases--) {
        int permutation_size;
        scanf("%d", &permutation_size);
        
        if (permutation_size % 2 == 0) {
            printf("-1\n");
        } else {
            printf("%d %d", permutation_size, 1);
            for (int current_index = 3; current_index <= permutation_size; current_index++) {
                printf(" %d", current_index - 1);
            }
            printf("\n");
        }
    }
    
    return 0;
}
