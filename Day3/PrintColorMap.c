#include <stdio.h>

// ---- Data responsibility ----
const char** getMajorColors(int* size) {
    static const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    *size = sizeof(majorColors) / sizeof(majorColors[0]);
    return majorColors;
}

const char** getMinorColors(int* size) {
    static const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    *size = sizeof(minorColors) / sizeof(minorColors[0]);
    return minorColors;
}

// ---- Computation + Printing ----
int printColorMap() {
    int majorCount, minorCount;
    const char** majorColors = getMajorColors(&majorCount);
    const char** minorColors = getMinorColors(&minorCount);

    int pairNumber = 0;
    for (int i = 0; i < majorCount; i++) {
        for (int j = 0; j < minorCount; j++) {
            printf("%d | %s | %s\n", pairNumber, majorColors[i], minorColors[j]);
            pairNumber++;
        }
    }

    printf("Total pairs: %d\n", pairNumber);
    return pairNumber; // ✅ returns size for testability
}

// ---- Example usage ----
int main() {
    int total = p
