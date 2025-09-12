#include <iostream>
#include <vector>
#include <string>
#include <tuple>

// ---- Data responsibility ----
std::vector<std::string> getMajorColors() {
    return {"White", "Red", "Black", "Yellow", "Violet"};
}

std::vector<std::string> getMinorColors() {
    return {"Blue", "Orange", "Green", "Brown", "Slate"};
}

// ---- Computation responsibility ----
std::vector<std::tuple<int, std::string, std::string>>
generateColorMap(const std::vector<std::string>& majorColors,
                 const std::vector<std::string>& minorColors) {
    std::vector<std::tuple<int, std::string, std::string>> colorMap;

    int pairNumber = 0;
    for (size_t i = 0; i < majorColors.size(); i++) {
        for (size_t j = 0; j < minorColors.size(); j++) {
            colorMap.push_back({pairNumber++, majorColors[i], minorColors[j]});
        }
    }
    return colorMap;
}

// ---- Presentation responsibility ----
int printColorMap() {
    // Interacts with other responsibilities
    auto majorColors = getMajorColors();
    auto minorColors = getMinorColors();
    auto colorMap = generateColorMap(majorColors, minorColors);

    for (auto& entry : colorMap) {
        std::cout << std::get<0>(entry) << " | "
                  << std::get<1>(entry) << " | "
                  << std::get<2>(entry) << "\n";
    }

    std::cout << "Total pairs: " << colorMap.size() << "\n";

    // ✅ Return size for testability
    return static_cast<int>(colorMap.size());
}

// ---- Example usage ----
int main() {
    int total = printColorMap();
    std::cout << "Function returned: " << total << "\n";
    return 0;
}
