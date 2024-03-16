#include <stdio.h>
#include <stdbool.h>


// <<<####>>> LOOK AT ALL THOSE FUNCTION DECLARATIONS (look at all those chickens) <<<###>>> //
void getHumanInput(int *humanInput);
bool isTemperatureInRange(int *humanInput);
bool isAscending(int array[], int size);
bool isDescending(int array[], int arraySize);
float calculateAverageTemperature(int array[], int arraySize);


// <<<@@@>>> MAIN LOOP - OH BOY, DO I LOVE COMMENTING AND LOOPING. <<<@@@>>> //
int main(void) {
  int temperatures[5];
  int temperatureIndex = 0;
  int humanInput = 0;
  int arraySize;
  float averageTemperature;

  while (temperatureIndex < 5) {
    getHumanInput(&humanInput);
    if (isTemperatureInRange(&humanInput)) {
      temperatures[temperatureIndex] = humanInput;
      temperatureIndex += 1;
    }
  }
  
  arraySize = sizeof(temperatures) / sizeof(temperatures[0]);
  if (isAscending(temperatures, arraySize)) {
    printf("\nGetting warmer.");
  }
  else if (isDescending(temperatures, arraySize)) {
    printf("\nGetting cooler.");
  }
  else {
    printf("\nIt's a mixed bag.");
  }

  // He's a beautiful baby boy, you leave him alone - he's just a bit weird.
  printf("\n5-day Temperature [%d, %d, %d, %d, %d]", temperatures[0], temperatures[1], temperatures[2], temperatures[3], temperatures[4]);
  
  averageTemperature = calculateAverageTemperature(temperatures, arraySize);
  printf("\nAverage Temperature is: %f degrees.", averageTemperature);
  
}


// <<<!!!>>> These are my functions, there may be many like them - but these are MINE. <<<!!!>>> //
void getHumanInput(int *humanInput) {
  printf("|>| Please input a temperature between -30F and 130F: ");
  scanf("%d", humanInput);
}

bool isTemperatureInRange(int *humanInput) {
  int maximumTemperature = 130;
  int minimumTemperature = -30;

  if (*humanInput < maximumTemperature && *humanInput > minimumTemperature) {
    return true;
  }
  else {
    printf("|>| Temperature %d is invalid, Please enter a valid temperature between -30 and 130", *humanInput);
    return false;
  }
}

bool isAscending(int array[], int arraySize) {
  int i;
  for (i = 0; i < arraySize - 1; i++) {
    if (array[i] >= array[i + 1]) {
      return false;
    }
  }
  return true;
}

bool isDescending(int array[], int arraySize) {
  int i;
  for (i = 0; i < arraySize - 1; i++) {
    if (array[i] <= array[i + 1]) {
      return false;
    }
  }
  return true;
}

float calculateAverageTemperature(int array[], int arraySize) {
  int i;
  int total = 0;
  float average;
  for (i = 0; i < arraySize; i++) {
    total += array[i];
  }
  average = total / arraySize;
  return average;
}