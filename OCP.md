### Functional Requirements

#### Payment Modes

The system must support the following payment modes:

- PayPal

- GooglePay

- CreditCard

- Any unsupported or invalid payment mode should be handled gracefully with an error message.

### Checkout Function

The system must provide a function named checkout that:

- Takes a PaymentMode (enum) as input.

- Takes the payment amount (double) as input.

- Processes the payment based on the selected PaymentMode.

### Processing Logic

For each payment mode, the system must print a confirmation message indicating:

- The selected payment mode.

- The amount being processed.

- Placeholder logic should be available for future integration with actual payment processing APIs.

#### C++ Implementtaion
```
#include <iostream>
#include <string>
using namespace std;

// Enum for Payment Modes
enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};

// Checkout function
void checkout(PaymentMode mode, double amount) {
    switch (mode) {
        case PaymentMode::PayPal:
            cout << "Processing PayPal payment of $" << amount << endl;
            // Add PayPal-specific logic here
            break;

        case PaymentMode::GooglePay:
            cout << "Processing GooglePay payment of $" << amount << endl;
            // Add GooglePay-specific logic here
            break;

        case PaymentMode::CreditCard:
            cout << "Processing Credit Card payment of $" << amount << endl;
            // Add Credit Card-specific logic here
            break;

        default:
            cout << "Invalid payment mode selected!" << endl;
            break;
    }
}

// Example usage
int main() {
    double amount = 150.75;

    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
```
