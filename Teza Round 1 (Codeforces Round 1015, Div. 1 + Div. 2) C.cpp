By mostafijur721, contest: Teza Round 1 (Codeforces Round 1015, Div. 1 + Div. 2), problem: (C) You Soared Afar With Grace, Accepted, #, Copy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
void swapValues(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
int main(){
    int testCases;
    if(scanf("%d", &testCases) != 1)
        return 1;
    
    while(testCases--){
        int size;
        if(scanf("%d", &size) != 1)
            return 1;
        int *array1 = (int*)malloc((size+1)*sizeof(int));
        int *array2 = (int*)malloc((size+1)*sizeof(int));
        for (int i = 1; i <= size; i++){
            scanf("%d", &array1[i]);
        }
        for (int i = 1; i <= size; i++){
            scanf("%d", &array2[i]);
        }
        
        int *positionArray1 = (int*)malloc((size+1)*sizeof(int));
        for (int i = 1; i <= size; i++){
            positionArray1[array1[i]] = i;
        }
        
        int selfPairCount = 0, selfPairIndex = -1;
        for (int i = 1; i <= size; i++){
            if(array1[i] == array2[i]){
                selfPairCount++;
                selfPairIndex = i;
            }
        }
        if(size % 2 == 0){
            if(selfPairCount != 0){
                printf("-1\n");
                free(array1); free(array2); free(positionArray1);
                continue;
            }
        } else {
            if(selfPairCount != 1){
                printf("-1\n");
                free(array1); free(array2); free(positionArray1);
                continue;
            }
        }
        
        bool *isUsed = (bool*)calloc(size+1, sizeof(bool));
        int pairCount = 0;
        int maxPairs = size / 2 + 1;
        int *leftPair = (int*)malloc(maxPairs * sizeof(int));
        int *rightPair = (int*)malloc(maxPairs * sizeof(int));
        
        bool isValid = true;
        for (int i = 1; i <= size; i++){
            if(array1[i] == array2[i])
                continue;
            if(isUsed[i])
                continue;
            int j = positionArray1[array2[i]];
            if(j == i){
                isValid = false;
                break;
            }
            if(array2[j] != array1[i]){
                isValid = false;
                break;
            }
            int p = i, q = j;
            if(p > q){
                int temp = p; p = q; q = temp;
            }
            leftPair[pairCount] = p;
            rightPair[pairCount] = q;
            pairCount++;
            isUsed[i] = true;
            isUsed[j] = true;
        }
        free(isUsed);
        
        int nonSelfPairCount = size - ((size % 2) == 1 ? 1 : 0);
        if(2 * pairCount != nonSelfPairCount){
            isValid = false;
        }
        
        if(!isValid){
            printf("-1\n");
            free(array1); free(array2); free(positionArray1); free(leftPair); free(rightPair);
            continue;
        }
        
        int *finalArray = (int*)malloc((size+1)*sizeof(int));
        int leftPointer = 1, rightPointer = size;
        for (int i = 0; i < pairCount; i++){
            finalArray[leftPointer++] = leftPair[i];
            finalArray[rightPointer--] = rightPair[i];
        }
        if(size % 2 == 1){
            int middle = (size+1)/2;
            finalArray[middle] = selfPairIndex;
        }
        
        int *currentArray = (int*)malloc((size+1)*sizeof(int));
        int *positionMapping = (int*)malloc((size+1)*sizeof(int));
        for (int i = 1; i <= size; i++){
            currentArray[i] = i;
            positionMapping[i] = i;
        }
        int *operationI = (int*)malloc((size+1)*sizeof(int));
        int *operationJ = (int*)malloc((size+1)*sizeof(int));
        int operationCount = 0;
        for (int i = 1; i <= size; i++){
            if(currentArray[i] != finalArray[i]){
                int j = positionMapping[finalArray[i]];
                swapValues(&currentArray[i], &currentArray[j]);
                positionMapping[currentArray[i]] = i;
                positionMapping[currentArray[j]] = j;
                operationI[operationCount] = i;
                operationJ[operationCount] = j;
                operationCount++;
            }
        }
        
        printf("%d\n", operationCount);
        for (int i = 0; i < operationCount; i++){
            printf("%d %d\n", operationI[i], operationJ[i]);
        }
        
        free(array1); free(array2); free(positionArray1);
        free(leftPair); free(rightPair); free(finalArray);
        free(currentArray); free(positionMapping); free(operationI); free(operationJ);
    }
    return 0;
}
