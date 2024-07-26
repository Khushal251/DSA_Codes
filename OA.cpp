#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int numBooks;
    cin >> numBooks;

    int budget;
    cin >> budget;

    map<string, int> comicPrices;
    vector<pair<string, int>> affordableComics;

    // Input comic names and prices
    for (int i = 0; i < numBooks; ++i) {
        string comicName;
        cin >> comicName;

        int price;
        cin >> price;

        comicPrices[comicName] = price;
    }

    // Create a vector of affordable comics
    for (const auto& entry : comicPrices) {
        if (entry.second <= budget && entry.second % 2 == 0) {
            affordableComics.push_back(entry);
        }
    }

    // Sort the affordable comics by price and then by name
    sort(affordableComics.begin(), affordableComics.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });

    // Output the purchased comic books
    int remainingBudget = budget;
    for (const auto& comic : affordableComics) {
        if (comic.second <= remainingBudget) {
            cout << comic.first << " - " << comic.second << endl;
            remainingBudget -= comic.second;
        }
    }

    // If no comics can be purchased, print "NONE"
    if (remainingBudget == budget) {
        cout << "NONE" << endl;
    }

    return 0;
}
