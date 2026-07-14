#pragma once
#include <unordered_map>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "User.h"
#include "Settlement.h"

// Tracks directed pairwise debts (debtor -> creditor -> amount), netting
// opposing debts, and can simplify everything to the fewest settlements.
class BalanceSheet {
    std::unordered_map<User*, std::unordered_map<User*, double>> owes_;

    double amount_owed(User* debtor, User* creditor) const {
        auto it = owes_.find(debtor);
        if (it == owes_.end()) return 0.0;
        auto jt = it->second.find(creditor);
        return jt != it->second.end() ? jt->second : 0.0;
    }

    static double round2(double v) { return std::round(v * 100.0) / 100.0; }

public:
    // Record that debtor owes creditor, netting against any opposite debt.
    void add_debt(User* debtor, User* creditor, double amount) {
        double opposite = amount_owed(creditor, debtor);
        if (opposite >= amount) {
            owes_[creditor][debtor] = opposite - amount;
            return;
        }
        if (opposite > 0) {
            owes_[creditor][debtor] = 0.0;
            amount -= opposite;
        }
        owes_[debtor][creditor] = amount_owed(debtor, creditor) + amount;
    }

    void show() const {
        bool any = false;
        for (const auto& e : owes_) {
            for (const auto& c : e.second) {
                if (c.second > 0.001) {
                    std::cout << "  " << e.first->name() << " owes " << c.first->name()
                              << " $" << std::fixed << std::setprecision(2) << c.second << "\n";
                    any = true;
                }
            }
        }
        if (!any) std::cout << "  All settled up.\n";
    }

    std::vector<Settlement> simplify(const std::vector<User*>& users) const {
        std::unordered_map<User*, double> net;
        for (User* u : users) net[u] = 0.0;
        for (const auto& e : owes_) {
            for (const auto& c : e.second) {
                if (c.second > 0.001) {
                    net[e.first] -= c.second;   // debtor
                    net[c.first] += c.second;   // creditor
                }
            }
        }

        std::vector<Settlement> settlements;
        while (true) {
            User* creditor = extreme(net, true);
            User* debtor = extreme(net, false);
            if (!creditor || !debtor) break;
            double credit = net[creditor];
            double debt = -net[debtor];
            if (credit < 0.01 || debt < 0.01) break;
            double amount = std::min(credit, debt);
            settlements.push_back(Settlement{debtor, creditor, round2(amount)});
            net[creditor] -= amount;
            net[debtor] += amount;
        }
        return settlements;
    }

private:
    static User* extreme(const std::unordered_map<User*, double>& net, bool positive) {
        User* best = nullptr;
        double best_val = positive ? 0.01 : -0.01;
        for (const auto& e : net) {
            if (positive && e.second > best_val) { best_val = e.second; best = e.first; }
            if (!positive && e.second < best_val) { best_val = e.second; best = e.first; }
        }
        return best;
    }
};
