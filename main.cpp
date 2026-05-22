#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

// ==========================================
//      ANIMATION & HELPER FUNCTIONS
// ==========================================

void clearScreen() {
    // Clears the console screen
    cout << "\033[2J\033[1;1H";
}

void sleepMs(int ms) {
    // Pauses the program for a specific number of milliseconds
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void typeText(const string& text, int speed = 15) {
    // Prints text character by character
    for (char letter : text) {
        cout << letter << flush; 
        sleepMs(speed);
    }
    cout << "\n";
}

void showLoadingSpinner(const string& message, int durationMs = 1000) {
    // Shows a spinning animation next to a message
    cout << message << " ";
    const string spinner = "|/-\\"; 
    int iterations = durationMs / 100; 
    
    for (int i = 0; i < iterations; ++i) {
        cout << spinner[i % 4] << "\b" << flush; 
        sleepMs(100);
    }
    cout << "Done!\n";
}

double getNumberInput(string prompt) {
    // Safely gets a number and prevents crashes from bad input
    double value;
    while (true) { 
        cout << prompt;
        cin >> value;

        if (cin.fail()) { 
            cout << "  [!] Oops! Please enter a valid number.\n";
            cin.clear();              
            cin.ignore(10000, '\n');  
        } else {
            return value; 
        }
    }
}

bool askToRepeat() {
    // Asks the user if they want to run the current tool again
    char choice;
    cout << "\nWould you like to do this again? (y/n): ";
    cin >> choice;
    
    // Clear out the input buffer in case they typed "yes" instead of just "y"
    cin.ignore(10000, '\n'); 
    
    // Returns true if they typed 'y' or 'Y'
    return (choice == 'y' || choice == 'Y');
}

// ==========================================
//          PROBLEM IMPLEMENTATIONS
// ==========================================

void largestOfThree() {
    do {
        clearScreen();
        typeText("\n--- Largest of Three Numbers ---", 20);
        double a = getNumberInput("Enter the 1st number: ");
        double b = getNumberInput("Enter the 2nd number: ");
        double c = getNumberInput("Enter the 3rd number: ");

        showLoadingSpinner("Analyzing inputs...");

        double largest = a;
        if (b > largest) { largest = b; }
        if (c > largest) { largest = c; }

        cout << "The largest number is: " << largest << "\n";
    } while (askToRepeat());
}

void simpleCalculator() {
    do {
        clearScreen();
        typeText("\n--- Simple Calculator ---", 20);
        double num1 = getNumberInput("Enter the first number: ");
        
        char op; 
        cout << "Enter an operator (+, -, *, /): ";
        cin >> op;

        double num2 = getNumberInput("Enter the second number: ");
        
        showLoadingSpinner("Calculating...");
        
        cout << "Result: ";
        switch (op) {
            case '+': cout << (num1 + num2) << "\n"; break;
            case '-': cout << (num1 - num2) << "\n"; break;
            case '*': cout << (num1 * num2) << "\n"; break;
            case '/': 
                if (num2 == 0) cout << "Error! You cannot divide by zero.\n";
                else cout << (num1 / num2) << "\n";
                break;
            default: 
                cout << "Invalid operator!\n";
        }
    } while (askToRepeat());
}

void multiplicationTable() {
    do {
        clearScreen();
        typeText("\n--- Multiplication Table ---", 20);
        int num = getNumberInput("Enter a whole number: ");
        
        showLoadingSpinner("Generating table...", 600);
        
        cout << "\nHere is the table for " << num << ":\n";
        for (int i = 1; i <= 10; i++) {
            cout << "  " << num << " x " << setw(2) << i << " = " << (num * i) << "\n";
            sleepMs(50); 
        }
    } while (askToRepeat());
}

void daysConversion() {
    do {
        clearScreen();
        typeText("\n--- Days Conversion ---", 20);
        int totalDays = getNumberInput("Enter the total number of days: ");
        
        showLoadingSpinner("Converting time...");
        
        int years = totalDays / 365;
        int remainingDays = totalDays % 365; 
        int months = remainingDays / 30; 
        int days = remainingDays % 30;       

        cout << "That is roughly equivalent to:\n"
             << " * " << years << " Years\n"
             << " * " << months << " Months\n"
             << " * " << days << " Days\n";
    } while (askToRepeat());
}

void metricConversion() {
    do {
        clearScreen();
        typeText("\n--- Metric Conversion ---", 20);
        cout << "What unit are you starting with?\n";
        cout << "  1. Millimeters (mm)\n  2. Centimeters (cm)\n  3. Meters (m)\n";
        
        int choice = getNumberInput("\nSelect (1-3): ");
        double value = getNumberInput("Enter the value: ");
        
        showLoadingSpinner("Crunching numbers...", 800);
        
        double mm, cm, m;
        if (choice == 1) { mm = value; cm = value / 10.0; m = value / 1000.0; } 
        else if (choice == 2) { mm = value * 10.0; cm = value; m = value / 100.0; } 
        else { mm = value * 1000.0; cm = value * 100.0; m = value; }

        cout << "Conversions:\n"
             << " - Millimeters: " << mm << " mm\n"
             << " - Centimeters: " << cm << " cm\n"
             << " - Meters     : " << m << " m\n";
    } while (askToRepeat());
}

void palindromeChecker() {
    do {
        clearScreen();
        typeText("\n--- Palindrome Number Checker ---", 20);
        int num = getNumberInput("Enter an integer: ");
        
        showLoadingSpinner("Reversing digits...", 1200);
        
        int original = num;
        int reversed = 0;
        int temp = abs(num); 

        while (temp > 0) {
            int lastDigit = temp % 10;              
            reversed = (reversed * 10) + lastDigit; 
            temp = temp / 10;                       
        }

        if (abs(original) == reversed) {
            cout << "[YES] " << original << " is a Palindrome!\n";
        } else {
            cout << "[NO] " << original << " is not a Palindrome.\n";
        }
    } while (askToRepeat());
}

void areaOfShapes() {
    do {
        clearScreen();
        typeText("\n--- Area of Shapes ---", 20);
        cout << "  1. Circle\n  2. Triangle\n  3. Square\n  4. Rectangle\n";
        
        int choice = getNumberInput("\nSelect a shape (1-4): ");
        double area = 0.0;
        const double PI = 3.14159; 

        if (choice == 1) {
            double r = getNumberInput("Enter the radius: ");
            area = PI * r * r;
        } else if (choice == 2) {
            double base = getNumberInput("Enter the base: ");
            double height = getNumberInput("Enter the height: ");
            area = 0.5 * base * height;
        } else if (choice == 3) {
            double side = getNumberInput("Enter the side length: ");
            area = side * side;
        } else if (choice == 4) {
            double length = getNumberInput("Enter the length: ");
            double width = getNumberInput("Enter the width: ");
            area = length * width;
        } else {
            cout << "Invalid choice! Returning to menu...\n";
            sleepMs(1500);
            return; 
        }

        showLoadingSpinner("Calculating geometry...");
        cout << "The area is: " << fixed << setprecision(2) << area << "\n";
    } while (askToRepeat());
}

void numberProperties() {
    do {
        clearScreen();
        typeText("\n--- Number Properties ---", 20);
        int num = getNumberInput("Enter a whole number: ");

        showLoadingSpinner("Inspecting integer...");

        cout << "Properties for " << num << ":\n";
        
        if (num > 0) cout << " [+] Positive\n";
        else if (num < 0) cout << " [-] Negative\n";
        else cout << " [0] Zero (Neither positive nor negative)\n";

        if (num % 2 == 0) cout << " [=] Even\n";
        else cout << " [~] Odd\n";
    } while (askToRepeat());
}

void searchElement() {
    do {
        clearScreen();
        typeText("\n--- Search for an Element ---", 20);
        
        int arr[5]; 
        for (int i = 0; i < 5; i++) {
            arr[i] = getNumberInput("Enter number " + to_string(i + 1) + ": ");
        }

        int target = getNumberInput("\nEnter a number to search for: ");
        
        showLoadingSpinner("Scanning array elements...", 1500);
        
        bool found = false; 
        for (int i = 0; i < 5; i++) {
            if (arr[i] == target) {
                cout << "[!] Found " << target << " at position " << (i + 1) << "!\n";
                found = true;
                break; 
            }
        }

        if (!found) cout << "[X] The number " << target << " is not in the array.\n";
    } while (askToRepeat());
}

void reverseArray() {
    do {
        clearScreen();
        typeText("\n--- Reverse Array Elements ---", 20);
        
        int arr[5]; 
        for (int i = 0; i < 5; i++) {
            arr[i] = getNumberInput("Enter number " + to_string(i + 1) + ": ");
        }

        showLoadingSpinner("Inverting array memory...");

        cout << "Array in reverse order: \n[ ";
        for (int i = 4; i >= 0; i--) {
            cout << arr[i] << " ";
            sleepMs(150); 
        }
        cout << "]\n";
    } while (askToRepeat());
}

// ==========================================
//          MAIN APPLICATION LOGIC
// ==========================================

void bootSequence() {
    clearScreen();
    typeText("Initializing C++ Core...", 30);
    showLoadingSpinner("Loading modules", 1500);
    typeText("System Ready.\n", 20);
    sleepMs(500);
}

void displayMenu() {
    clearScreen();
    cout << "=================================================\n";
    cout << "||            C++ UTILITY SUITE v4.0           ||\n";
    cout << "=================================================\n";
    cout << "  [1]  Largest of Three Numbers\n";
    cout << "  [2]  Simple Calculator\n";
    cout << "  [3]  Multiplication Table\n";
    cout << "  [4]  Days Conversion\n";
    cout << "  [5]  Metric Conversion\n";
    cout << "  [6]  Palindrome Number Checker\n";
    cout << "  [7]  Area of Shapes\n";
    cout << "  [8]  Check Even/Odd, Positive/Negative\n";
    cout << "  [9]  Search for an Element\n";
    cout << " [10]  Reverse Array Elements\n";
    cout << "-------------------------------------------------\n";
    cout << "  [0]  Exit Application\n\n";
}

int main() {
    bootSequence(); 

    bool isRunning = true; 
    
    while (isRunning) {
        displayMenu();
        int choice = getNumberInput("-> Select an option (0-10): ");

        switch (choice) {
            case 1:  largestOfThree(); break;
            case 2:  simpleCalculator(); break;
            case 3:  multiplicationTable(); break;
            case 4:  daysConversion(); break;
            case 5:  metricConversion(); break;
            case 6:  palindromeChecker(); break;
            case 7:  areaOfShapes(); break;
            case 8:  numberProperties(); break;
            case 9:  searchElement(); break;
            case 10: reverseArray(); break;
            
            case 0: 
                isRunning = false; 
                typeText("\nShutting down systems... Have a fantastic day coding!\n", 30);
                break;
                
            default: 
                cout << "\n[!] Invalid choice. Please pick a number from the menu.\n";
                sleepMs(1500); // Give them a second to read the error before re-drawing the menu
        }
    }

    return 0; 
}
