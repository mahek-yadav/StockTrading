#include <iostream>
#include <string>
using namespace std;

class Stock {
public:
    string name;
    double price;
};

class Portfolio {
public:
    int quantity[5];
    double balance;
    double startBalance;

    Portfolio() {
        balance = 100000;
        startBalance = 100000;

        for(int i = 0; i < 5; i++) {
            quantity[i] = 0;
        }
    }

    void buy(Stock s[], int index, int qty) {

        double cost = s[index].price * qty;

        if(cost > balance) {
            cout << "Not enough balance!\n";
            return;
        }

        balance = balance - cost;
        quantity[index] = quantity[index] + qty;

        cout << "Stock purchased successfully.\n";
    }

    void sell(Stock s[], int index, int qty) {

        if(quantity[index] < qty) {
            cout << "You don't have enough shares.\n";
            return;
        }

        quantity[index] = quantity[index] - qty;
        balance = balance + s[index].price * qty;

        cout << "Stock sold successfully.\n";
    }

    void showPortfolio(Stock s[]) {

        cout << "\n--- Portfolio ---\n";

        double totalStockValue = 0;

        for(int i = 0; i < 5; i++) {

            if(quantity[i] > 0) {

                double value = quantity[i] * s[i].price;

                cout << s[i].name << "  Shares: " << quantity[i]
                     << "  Value: " << value << endl;

                totalStockValue = totalStockValue + value;
            }
        }

        cout << "Cash Balance: " << balance << endl;
        cout << "Total Portfolio Value: " << balance + totalStockValue << endl;
    }

    void profitLoss(Stock s[]) {

        double totalValue = balance;

        for(int i = 0; i < 5; i++) {
            totalValue = totalValue + quantity[i] * s[i].price;
        }

        double result = totalValue - startBalance;

        cout << "\n--- Profit / Loss ---\n";
        cout << "Initial Balance: " << startBalance << endl;
        cout << "Current Value: " << totalValue << endl;

        if(result > 0)
            cout << "Profit: " << result << endl;
        else if(result < 0)
            cout << "Loss: " << result << endl;
        else
            cout << "No Profit No Loss\n";
    }
};

int main() {

    Stock market[5];

    market[0].name = "TCS";
    market[0].price = 3500;

    market[1].name = "INFY";
    market[1].price = 1500;

    market[2].name = "RELIANCE";
    market[2].price = 2700;

    market[3].name = "HDFC";
    market[3].price = 1600;

    market[4].name = "ADANI";
    market[4].price = 3000;

    Portfolio user;

    int choice;

    do {

        cout << "\n===== Stock Trading Simulation =====\n";
        cout << "1. View Market\n";
        cout << "2. Buy Stock\n";
        cout << "3. Sell Stock\n";
        cout << "4. View Portfolio\n";
        cout << "5. View Profit/Loss\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {

            cout << "\n--- Market Prices ---\n";

            for(int i = 0; i < 5; i++) {
                cout << i+1 << ". " << market[i].name
                     << "  Price: " << market[i].price << endl;
            }
        }

        else if(choice == 2) {

            int stock, qty;

            cout << "Enter stock number: ";
            cin >> stock;

            cout << "Enter quantity: ";
            cin >> qty;

            user.buy(market, stock-1, qty);
        }

        else if(choice == 3) {

            int stock, qty;

            cout << "Enter stock number: ";
            cin >> stock;

            cout << "Enter quantity: ";
            cin >> qty;

            user.sell(market, stock-1, qty);
        }

        else if(choice == 4) {

            user.showPortfolio(market);
        }

        else if(choice == 5) {

            user.profitLoss(market);
        }

    } while(choice != 6);

    cout << "Program ended.\n";

    return 0;
}