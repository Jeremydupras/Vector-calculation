#include "valid.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

void ProgramGreeting();
void printMenu();
int getSelection();
double pathTheorm(double, double);
double distanceFormula2D(double, double, double, double);
double distanceFormula3D(double, double, double, double, double, double);
double scalarDotProductMagnitude(double, double, double);
double scalarDotProductComponent(double, double, double, double, double,
                                 double);
double ScalarDotproductVectorAngle(double, double, double);
double vectorCrossProductMagnitude(double, double, double);
void findVectorComponents(double, double);
void vectorCrossProductUnits(double, double, double, double, double, double);
void calcCall(int);

const int QUIT = 0;

int main() {
  int selection = 0;
  double result;

  ProgramGreeting();
  printMenu();

  selection = getSelection();

  while (selection != QUIT) {

    calcCall(selection);
    printMenu();
    selection = getSelection();
  }

  cout << "Program terminated" << endl;
  // result = pathTheorm(x, y);
  // cout << result;
  return 0;
}

void printMenu() {
  cout << "Menu "
       << "Enter integer for selection" << endl;
  cout << setfill('_') << setw(80) << "" << endl;
  cout << "0. QUIT" << endl;
  cout << "1. Pythagorean theorem" << endl;
  cout << "2. Distance Formula 2D" << endl;
  cout << "3. Distance Formula 3D" << endl;
  cout << "4. Scalar DOT product vectors with (Magnitude)" << endl;
  cout << "5. Scalar DOT product vectors with (Components)" << endl;
  cout << "6. Angle between vectors with Scalar DOT Product" << endl;
  cout << "7. Vector Cross product for (Magnitude)" << endl;
  cout << "8. Vector components from Magnitude and angle" << endl;
  cout << "9. Vector Cross product with components" << endl;

  cout << setfill('_') << setw(80) << "" << endl;

  return;
}

// switch statment for calculations
void calcCall(int selection) {

  double result = 0;
  double x1;
  double y1;
  double z1;
  double x2;
  double y2;
  double z2;

  cout << setfill('_') << setw(80) << "" << endl;

  switch (selection) {
  case 0:
    cout << "Program over." << endl;
    break;
  case 1:
    cout << "Pythagorean theorem. Enter x and y value." << endl;
    x1 = getDouble("Enter x value: ");
    y1 = getDouble("Enter y value: ");
    result = pathTheorm(x1, y1);
    cout << "R value = " << result << endl;
    break;
  case 2:
    cout << "Distance formula 2D. Enter (x1, y1), (x2, y2)." << endl;
    x1 = getDouble("Enter x1 value: ");
    y1 = getDouble("Enter y1 value: ");
    x2 = getDouble("Enter x2 value: ");
    y2 = getDouble("Enter y2 value: ");
    result = distanceFormula2D(x1, y1, x2, y2);
    cout << "Distance between points = " << result << endl;
    break;
  case 3:
    cout << "Distance formula 3D. Enter (x1, y1, z1), (x2, y2 ,z2)." << endl;
    x1 = getDouble("Enter x1 value: ");
    y1 = getDouble("Enter y1 value: ");
    z1 = getDouble("Enter z1 value: ");
    x2 = getDouble("Enter x2 value: ");
    y2 = getDouble("Enter y2 value: ");
    z2 = getDouble("Enter z2 value: ");
    result = distanceFormula3D(x1, y1, z1, x2, y2, z2);
    cout << "Distance between points = " << result << endl;
    break;
  case 4:
    cout << "Vector Scalar Dot Product with magnitude. \nEnter the Magnitude "
            "of vector A and "
         << "B then enter theta in degrees." << endl;
    x1 = getDouble("Magnitude vector A: ");
    y1 = getDouble("Magnitude vector B: ");
    z1 = getDouble("Theta in degrees: ");
    result = scalarDotProductMagnitude(x1, y1, z1);
    cout << "The scalar dot product of vector A and B = " << result << endl;
    break;
  case 5:
    cout << "Vector Scalar Dot Product with magnitude. \n Enter the Components "
            "of Vector A and B"
         << endl;
    x1 = getDouble("Enter x1 value: ");
    x2 = getDouble("Enter x2 value: ");
    y1 = getDouble("Enter y1 value: ");
    y2 = getDouble("Enter y2 value: ");
    z1 = getDouble("Enter z1 value: ");
    z2 = getDouble("Enter z2 value: ");
    result = scalarDotProductComponent(x1, y1, z1, x2, y2, z2);
    cout << "The scalar dot product of vector A and B = " << result << endl;
    break;
  case 6:
    cout << "Angle between vectors with Scalar DOT product. \nEnter the "
            "Components of Vector A and B"
         << endl;
    x1 = getDouble("Enter x1 value: ");
    x2 = getDouble("Enter x2 value: ");
    y1 = getDouble("Enter y1 value: ");
    y2 = getDouble("Enter y2 value: ");
    z1 = getDouble("Enter z1 value: ");
    z2 = getDouble("Enter z2 value: ");
    result = scalarDotProductComponent(x1, y1, z1, x2, y2, z2);
    cout << "The scalar dot product of vector A and B " << result << endl;
    result = ScalarDotproductVectorAngle(
        result, distanceFormula3D(0, 0, 0, x2, y2, z2),
        distanceFormula3D(x1, y1, z1, 0, 0, 0));
    cout << "The angle between the vectors = " << result << " degrees." << endl;
    break;
  case 7:
    cout << "Vector Scalar Dot Product with magnitude. \nEnter the Magnitude "
            "of vector A and "
         << "B then enter theta in degrees." << endl;
    x1 = getDouble("Magnitude vector A: ");
    y1 = getDouble("Magnitude vector B: ");
    z1 = getDouble("Theta in degrees: ");
    result = vectorCrossProductMagnitude(x1, y1, z1);
    cout << "The magnitude of the cross product = " << result << endl;
    break;
    case 8:
      cout << "Find X/Y vector components based off Magnitude and angle."         << endl;
      x1 = getDouble("Magnitude of the vector: ");
      z1 = getDouble("Theta in degrees: ");
      findVectorComponents(x1, z1);
      break;
    case 9:
      cout << "Vector Cross Product with components. Enter components of Vector A/B." << endl;
      x1 = getDouble("Enter x1 value: ");
      y1 = getDouble("Enter y1 value: ");
      z1 = getDouble("Enter z1 value: ");
      x2 = getDouble("Enter x2 value: ");
      y2 = getDouble("Enter y2 value: ");
      z2 = getDouble("Enter z2 value: ");
      vectorCrossProductUnits(x1, y1, z1, x2, y2, z2);
      break;
  }
  
  cout << setfill('_') << setw(80) << "" << endl;
  return;
}

// self explanitory
double pathTheorm(double x1, double y1) {
  double hyp = 0;
  hyp = sqrt(pow(x1, 2) + pow(y1, 2));
  return hyp;
}

// calcualtes the distance between 2 points in 2D space
double distanceFormula2D(double x1, double y1, double x2, double y2) {
  double distance = 0;
  distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  return distance;
}

// calcuaates the distance between two points in 3D space
double distanceFormula3D(double x1, double y1, double z1, double x2, double y2,
                         double z2) {
  double distance;
  distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
  return distance;
}

// calculates the scalar dot product of 2 vectors with their Magnitude
double scalarDotProductMagnitude(double magA, double magB, double theta) {
  double result;
  double pi = 3.14159265;
  if (theta != 90) {
    result = abs(magA) * abs(magB) * cos(theta * (pi / 180));
  } else {
    result = 0;
  }
  return result;
}

// calculates the scalar dot product between 2 vectors using the components
double scalarDotProductComponent(double x1, double y1, double z1, double x2,
                                 double y2, double z2) {
  double result;
  result = (x1 * x2) + (y1 * y2) + (z1 * z2);
  return result;
}

// calculates the angle between two vectors using the dot product
double ScalarDotproductVectorAngle(double dotProd, double magA, double magB) {
  double result;
  double pi = 3.14159265;
  result = acos(dotProd / (magA * magB)) * (180 / pi);
  return result;
}

// calculates the magnitude if the cross product
double vectorCrossProductMagnitude(double magA, double magB, double theta) {
  double result;
  double pi = 3.14159265;
  result = magA * magB * sin(theta * (pi / 180));
  return result;
}


//calculates the vector components from magnitude and angle
void findVectorComponents(double mag, double theta){
  double xVal;
  double yVal;
  double pi = 3.14159265;

  yVal = sin(theta * (pi/180)) * mag;
  xVal = cos(theta * (pi/180)) * mag;
  cout << "x = " << xVal << endl;
  cout << "y = " << yVal << endl;
  return;
}


//calculates the cross product
void vectorCrossProductUnits(double x1, double y1, double z1, double x2, double y2, double z2){
  double i;
  double j;
  double k;

  i = (y1*z2)-(y2*z1);
  j = -1 * ((x1*z2) - (x2*z1));
  k = (x1*y2) - (x2*y1);

  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  cout << "k = " << k << endl;

  return; 
}


// Program greeeting
void ProgramGreeting() {
  cout << setfill('_') << setw(80) << "" << endl;
  cout << "This is a math pragram for general formulas. Figure it out." << endl;
  cout << setfill('_') << setw(80) << "" << endl;
  return;
}

// used for menu selection
int getSelection() {
  int selection = 0;
  selection = getInteger("Enter selection here: ");
  return selection;
}
