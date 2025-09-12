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

// ---- interface ----
typedef void (*ColorPrinter)(int pairNumber, const char* major, const char* minor);

// ---- Core logic depends on Abstraction of Print Functionality ----
int printColorMap(ColorPrinter printer) {
    int majorCount, minorCount;
    const char** majorColors = getMajorColors(&majorCount);
    const char** minorColors = getMinorColors(&minorCount);

    int pairNumber = 0;
    for (int i = 0; i < majorCount; i++) {
        for (int j = 0; j < minorCount; j++) {
            printer(pairNumber, majorColors[i], minorColors[j]);
            pairNumber++;
        }
    }
    return pairNumber;
}

// ---- Default printer using printf ----
void consolePrinter(int pairNumber, const char* major, const char* minor) {
    printf("%d | %s | %s\n", pairNumber, major, minor);
}

// ---- Example test printer (captures output differently) ----
void testPrinter(int pairNumber, const char* major, const char* minor) {
    // Here we could store values in an array for unit tests
    printf("[TEST] %d - %s/%s\n", pairNumber, major, minor);
}

// ---- Usage ----
int main() {
    printf("Using console printer:\n");
    int total = printColorMap(consolePrinter);
    printf("Total pairs = %d\n\n", total);

    printf("Using test printer:\n");
    total = printColorMap(testPrinter);
    printf("Total pairs = %d\n", total);

    return 0;
}
