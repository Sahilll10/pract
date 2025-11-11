#include <bits/stdc++.h>
using namespace std;

struct Call {
    int customerID;
    int callTime;
};
struct Operator {
    queue<Call> calls;
    vector<Call> logs;
    int total = 0;

    void addCall(Call c) {
        calls.push(c);
        total+= c.callTime;
    }
    void answerCall() {
        if (calls.empty()) {
            cout << "No calls in queue\n";
            return;
        }
        Call c = calls.front();
        calls.pop();
        total -= c.callTime;
        logs.push_back(c);
        cout<< "Answered call " << c.customerID << endl;
    }
    void viewQueue() {
        if (calls.empty()) {
            cout << "Queue empty\n";
            return;
        }
        queue<Call> temp = calls;
        while (!temp.empty()) {
            cout << "Call " << temp.front().customerID << " (" << temp.front().callTime << " min)\n";
            temp.pop();
        }
    }
    void avgWait() {
        if (calls.empty()) {
            cout << "No waiting calls\n";
            return;
        }
        queue<Call> temp = calls;
        int total = 0, count = 0;
        while (!temp.empty()) {
            total += temp.front().callTime;
            count++;
            temp.pop();
        }
        cout << "Average waiting time: " << (float)total / count << " min\n";
    }
    void nextFree() {
        cout << "Next available in " << total<< " min\n";
    }
    void longestWait() {
        if (calls.empty()) {
            cout << "No waiting calls\n";
            return;
        }
        Call c = calls.front();
        cout << "Longest waiting call: " << c.customerID << " (" << c.callTime << " min)\n";
    }
    void showLogs() {
        if (logs.empty()) {
            cout << "No calls answered yet\n";
            return;
        }
        for (auto &c : logs)
            cout << "Answered call " << c.customerID << " (" << c.callTime << " min)\n";
    }
};
int main() {
    Operator op;  
    int ch;
    do {
        cout << "\n Call Center Menu\n";
        cout << "1. Add Call\n2. Answer Call\n3. View Queue\n4. Average Wait\n";
        cout << "5. Next Free Time\n6. Longest Wait\n7. Show Logs\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        if (ch == 1) {
            int id, time;
            cout << "Enter Customer ID and Call Time: ";
            cin >> id >> time;
            op.addCall({id, time});
        } 
        else if (ch == 2) {
            op.answerCall();
        } 
        else if (ch == 3) {
            op.viewQueue();
        } 
        else if (ch == 4) {
            op.avgWait();
        } 
        else if (ch == 5) {
            op.nextFree();
        } 
        else if (ch == 6) {
            op.longestWait();
        } 
        else if (ch == 7) {
            op.showLogs();
        } 
        else if (ch == 8) {
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid choice!\n";
        }

    } while (ch != 8);

    return 0;
}

