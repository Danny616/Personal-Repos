#include <iostream>
#include <vector>

using namespace std;

int minRefills(int distance, int tank, vector<int>& stops) {
    int numRefills = 0;
    int currentRefill = 0;
    int lastRefill;

    while (currentRefill < stops.size() - 1) {
        lastRefill = currentRefill;

        // Find the farthest reachable stop
        while (currentRefill < stops.size() - 1 && stops[currentRefill + 1] - stops[lastRefill] <= tank) {
            currentRefill++;
        }

        // If the farthest reachable stop is the current stop, then it's impossible to reach the destination
        if (currentRefill == lastRefill) {
            return -1;
        }

        // If the farthest reachable stop is not the destination, increment the number of refills
        if (currentRefill < stops.size() - 1) {
            numRefills++;
        }
    }

    return numRefills;
}

int main() {
    int distance, tank;
    vector<int> stops;

    cout << "Enter the distance between cities: ";
    cin >> distance;

    cout << "Enter the mileage of the car with a full tank: ";
    cin >> tank;

    int n;
    cout << "Enter the number of gas stations on the way: ";
    cin >> n;

    stops.resize(n + 2); // Including the starting and ending points

    cout << "Enter the distances of gas stations from the starting point:\n";
    stops[0] = 0; // Starting point
    for (int i = 1; i <= n; i++) {
        cin >> stops[i];
    }

    stops[n + 1] = distance; // Ending point

    int minStops = minRefills(distance, tank, stops);

    if (minStops == -1) {
        cout << "It's impossible to reach the destination.";
    } else {
        cout << "Minimum number of stops: " << minStops;
    }

    return 0;
}