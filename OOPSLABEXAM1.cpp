#include <bits/stdc++.h>
using namespace std;
#define int long long int


// class RainfallAnalyzer {
// private:
//     vector<double> rainfall;

// public:
//     void inputRainfall() {
//         for (int i = 0; i < 12; ++i) {
//             double amount;
//             while (true) {
//                 cout << "Enter rainfall for month " << i + 1 << ": ";
//                 cin >> amount;
//                 if (amount < 0) {
//                     cout << "Rainfall amount must be a positive number." << endl;
//                     continue;
//                 }
//                 rainfall.push_back(amount);
//                 break;
//             }
//         }
//     }

//     void displayMonthly() {
//         for (int i = 0; i < rainfall.size(); ++i) {
//             cout << "Month " << i + 1 << ": " << rainfall[i] << " inches" << endl;
//         }
//     }


//     void displayTotal() {
//         double total = 0;
//         for (const auto &amount : rainfall) {
//             total += amount;
//         }
//         cout << "Total rainfall for the year: " << total << " inches" << endl;
//     }


//     void displayAverage() {
//         double total = 0;
//         for (const auto &amount : rainfall) {
//             total += amount;
//         }
//         double average = total / rainfall.size();
//         cout << "Average monthly rainfall: " << average << " inches" << endl;
//     }


//     void displayHigh() {
//         auto maxIt = max_element(rainfall.begin(), rainfall.end());
//         double maxAmount = *maxIt;
//         int month = distance(rainfall.begin(), maxIt) + 1;
//         cout << "Highest monthly rainfall: Month " << month << ", " << maxAmount << " inches" << endl;
//     }

//     // Function to display lowest rainfall amount and month
//     void displayLow() {
//         auto minIt = min_element(rainfall.begin(), rainfall.end());
//         double minAmount = *minIt;
//         int month = distance(rainfall.begin(), minIt) + 1;
//         cout << "Lowest monthly rainfall: Month " << month << ", " << minAmount << " inches" << endl;
//     }
// };






int32_t main(){
    // RainfallAnalyzer analyzer;

    // analyzer.inputRainfall();

    // while (true) {
    //     cout << "\nMenu:" << endl;
    //     cout << "1 Display monthly amounts" << endl;
    //     cout << "2 Display total amount" << endl;
    //     cout << "3 Display average amount" << endl;
    //     cout << "4 Display highest amount" << endl;
    //     cout << "5 Display lowest amount" << endl;
    //     cout << "6 End program" << endl;

    //     int choice;
    //     cout << "Enter your choice: ";
    //     cin >> choice;

    //     switch (choice) {
    //         case 1:
    //             analyzer.displayMonthly();
    //             break;
    //         case 2:
    //             analyzer.displayTotal();
    //             break;
    //         case 3:
    //             analyzer.displayAverage();
    //             break;
    //         case 4:
    //             analyzer.displayHigh();
    //             break;
    //         case 5:
    //             analyzer.displayLow();
    //             break;
    //         case 6:
    //             return 0; // Exit the program
    //         default:
    //             cout << "Invalid choice. Please enter a valid option (1-6)." << endl;
    //     }
    // }

    return 0;
}
