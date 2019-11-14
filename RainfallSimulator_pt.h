#ifndef __RAINFALLSIMULATOR_PT_H__
#define __RAINFALLSIMULATOR_PT_H__
#include "Point.h"
#include <iostream>
#include <math.h>
#include <vector>

class RainfallSimulator_pt {
protected:
  int num_thread;
  int size;
  int raindropInterval;
  int absorptionRate;
  int operationTime;
  bool complete;
  std::vector<std::vector<Point>> landscape;
  void check(std::vector<std::pair<int, int>> &lowestNeighbor,
             int &min_elevation, const int &current_elevation, const int &i,
             const int &j, const std::vector<std::vector<int>> &elevations);
  std::vector<std::pair<int, int>>
  checkLowestNeighbor(const std::vector<std::vector<int>> &elevations, int i,
                      int j);
  void absorbAndricklyAway_pt(std::vector<std::vector<float>> &delta);

public:
  RainfallSimulator_pt(const std::vector<std::vector<int>> &elevations,
                       const int &P, const int &N, const int &M,
                       const float &A);
  void runOneTimestamp();
  bool isComplete();
  void printOperationTime();
  void printAbsorbedRainDrops();
  void printCurrentRainDrops();
};

struct subLandscape {
  std::vector<std::vector<Point>> *landscape;
  int start;
  int end;
  int size;
  std::vector<std::vector<float>> *delta;
};

#endif
