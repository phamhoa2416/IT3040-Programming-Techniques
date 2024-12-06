#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSchedule(const string &schedule, int K1, int K2) {
    int length = schedule.size();
    int consecutiveWork = 0;

    // Check if there are two days off
    for (int i = 0; i < length; ++i) {
        if (i > 0 && schedule[i] == '0' && schedule[i - 1] == '0') 
            return false;

        // Count the number of consecutive working days
        if (schedule[i] == '1') {
            consecutiveWork ++;
        } else {
            if (consecutiveWork > 0 && (consecutiveWork < K1 || consecutiveWork > K2)) 
                return false;
            
            consecutiveWork = 0;
        }
    }

    // Check the last consecutive working days
    if (consecutiveWork > 0 && (consecutiveWork < K1 || consecutiveWork > K2)) 
        return false;

    return true;
}

void generateScheduleRecursive(int N, int K1, int K2, string currentSchedule, vector<string>& validSchedules) {
    if (currentSchedule.size() == N) {
        if (isValidSchedule(currentSchedule, K1, K2)) {
            validSchedules.push_back(currentSchedule);
        }
        return;
    }

    if (currentSchedule.empty() || currentSchedule.back() == '1') {
        // If the last day is a working day, the next day can be a day off or a working day
        generateScheduleRecursive(N, K1, K2, currentSchedule + '0', validSchedules);
    }

    // If the last day is a day off, the next day must be a working day
    generateScheduleRecursive(N, K1, K2, currentSchedule + '1', validSchedules);
}

void generateSchedule(int N, int K1, int K2) {
    vector<string> validSchedules;
    generateScheduleRecursive(N, K1, K2, "", validSchedules);

    sort(validSchedules.begin(), validSchedules.end());

    for (const string &schedule: validSchedules) {
        cout << schedule << endl;
    }
}

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    generateSchedule(N, K1, K2);
    return 0;
}