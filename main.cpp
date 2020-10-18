#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<string> simulateBallDrop(int balls, int slots) {
  vector<string> pathForEachBall;
  srand(time(NULL));
  for (int i = 0; i < balls; ++i) {
    string path;
    for (int j = 0; j < slots - 1; ++j) {
      int randomNumber = (rand() % 2);
      if (randomNumber == 0) {
        path += "L";
      }
      else {
        path += "R";
      }
    }
    pathForEachBall.push_back(path);
  }
  return pathForEachBall;
}

vector<int> determineNumberOfSlot(vector<string> paths, int slots) {
  vector<int> result;
  for (int i = 0; i < slots; ++i) {
    result.push_back(0);
  }

  for (int i = 0; i < paths.size(); ++i) {
    int tempResult = 0;
    for (const char& c : paths[i]) {
      if (c == 'R') {
        ++tempResult;
      }
    }
    ++result[tempResult];
  }
  return result;
}

string drawTheBeamMachineOutput(vector<int>& beamSimulation) {
  string result;
  int maxNumber = 0;
  for (int number : beamSimulation) {
    if (number > maxNumber) {
      maxNumber = number;
      continue;
    }
  }
  cout << maxNumber << endl;
  while (maxNumber > 0) {
    result += '|';
    for (int i = 0; i < beamSimulation.size(); ++i) {
      if (beamSimulation[i] == maxNumber) {
        result += "0|";
        --beamSimulation[i];
      }
      else {
        result += " |";
      }
    }
    --maxNumber;
    result += '\n';
  }
  result += "|";
  for (int i = 0; i < beamSimulation.size(); ++i) {
    result += to_string(i);
    result += "|";
  }
  cout << result << endl;
}

int main() {
  // get the user input in the demanded format
  string numberOfBalls;
  string numberOfSlots;
  cout << "Enter the number of balls to drop " << endl;
  cin >> numberOfBalls;
  cout << "Enter the number of slots in the machine" << endl;
  cin >> numberOfSlots;

  int balls = stoi(numberOfBalls);
  int slots = stoi(numberOfSlots);

  // Get the path for each of the balls
  vector<string> pathForEachBall;
  pathForEachBall = simulateBallDrop(balls, slots);

  // Display the info about the balls
  cout << "\n\n" << endl;
  cout << "Path for each ball" << endl;
  int i = 1;
  for (const string& s : pathForEachBall) {
    cout << "The path for ball " << i << " is " << s << endl;
    ++i;
  }

  // Determine the number of the slot
  vector<int> slotsList;
  slotsList = determineNumberOfSlot(pathForEachBall, slots);

  int j = 0;
  for (int i : slotsList) {
    cout << j << " " << i << endl;
    ++j;
  }

  drawTheBeamMachineOutput(slotsList);

  return 0;
}
