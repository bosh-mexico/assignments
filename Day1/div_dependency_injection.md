# Division Function with Dependency Injection

This document demonstrates how to separate **business logic** from **I/O operations** using **dependency injection** across multiple programming languages.  
The business logic (`div`) performs division, while output handling (e.g., printing) is injected from outside.

---

## 📌 C++

```cpp
#include <iostream>
#include <functional>

// Business logic: performs integer division
int div(int x, int y) {
    return x / y;
}

// Higher-level function: accepts output strategy via dependency injection
void process_div(int x, int y, std::function<void(int)> output) {
    int result = div(x, y);
    output(result);
}

// Output strategy: print result to console
void print_result(int value) {
    std::cout << value << std::endl;
}

int main() {
    process_div(20, 5, print_result);          // Console output
    process_div(10, 2, [](int v){ /* mock */ }); // Mock (test usage)
    return 0;
}
```

---

## 📌 C#

```csharp
using System;

class Program
{
    // Business logic: performs integer division
    static int Div(int x, int y) => x / y;

    // Higher-level function: accepts output strategy via dependency injection
    static void ProcessDiv(int x, int y, Action<int> output)
    {
        int result = Div(x, y);
        output(result);
    }

    // Output strategy: print result to console
    static void PrintResult(int value) => Console.WriteLine(value);

    static void Main()
    {
        ProcessDiv(20, 5, PrintResult);              // Console output
        ProcessDiv(10, 2, result => { /* mock */ }); // Mock (test usage)
    }
}
```

---

## 📌 Python

```python
# Business logic: performs integer division
def div(x, y):
    return x // y  # use / for float division if needed

# Higher-level function: accepts output strategy via dependency injection
def process_div(x, y, output):
    result = div(x, y)
    output(result)

# Output strategy: print result to console
def print_result(value):
    print(value)

# Example usage
process_div(20, 5, print_result)          # Console output
process_div(10, 2, lambda v: None)        # Mock (test usage)
```

---

## 📌 Java

```java
import java.util.function.Consumer;

public class Main {
    // Business logic: performs integer division
    static int div(int x, int y) {
        return x / y;
    }

    // Higher-level function: accepts output strategy via dependency injection
    static void processDiv(int x, int y, Consumer<Integer> output) {
        int result = div(x, y);
        output.accept(result);
    }

    public static void main(String[] args) {
        processDiv(20, 5, System.out::println);    // Console output
        processDiv(10, 2, v -> { /* mock */ });    // Mock (test usage)
    }
}
```

---

## 📌 JavaScript

```javascript
// Business logic: performs integer division
function div(x, y) {
    return Math.floor(x / y); // integer division
}

// Higher-level function: accepts output strategy via dependency injection
function processDiv(x, y, output) {
    let result = div(x, y);
    output(result);
}

// Output strategy: print result to console
function printResult(value) {
    console.log(value);
}

// Example usage
processDiv(20, 5, printResult);         // Console output
processDiv(10, 2, v => { /* mock */ }); // Mock (test usage)
```

---

✅ In all versions:  
- `div(x, y)` is **pure logic** (no I/O).  
- `process_div` (or equivalent) injects the **output strategy**.  
- Output can be swapped (console, mock, test harness).  
