#include <iostream>
#include <cmath>
#include <array>
#include <vector>

constexpr int kDimensions = 2;
constexpr int kDataPoints = 20;
constexpr std::array<std::array<float, kDimensions>, kDataPoints> points = {{{3.8686992545234347, 1.3559682753431659},
                                                                             {0.5180993375153686, 5.117486709676035},
                                                                             {3.5386436080165806, 1.5271125008781592},
                                                                             {4.728401339990676, 1.114753166423772},
                                                                             {9.023721046916886, 4.338066212680383},
                                                                             {0.01162719298319903, 6.076772652356936},
                                                                             {5.991635210658819, 1.2966680782036724},
                                                                             {6.065836085221114, 1.3272013121118933},
                                                                             {8.116481067645926, 3.0424908489990976},
                                                                             {3.4596129148699015, 1.5745584744071195},
                                                                             {3.311476661626893, 1.6702222128461326},
                                                                             {5.877037623043535, 1.2538389984467715},
                                                                             {1.292978422219696, 3.8484017956257546},
                                                                             {4.721539277238149, 1.11550807482421},
                                                                             {8.506311207767968, 3.5588436571438553},
                                                                             {0.6057636006285494, 4.961862706712194},
                                                                             {7.104743838802512, 1.985989325395428},
                                                                             {4.479413884955205, 1.1542019806354862},
                                                                             {3.0128605724511037, 1.8897446209038709},
                                                                             {1.9357873494944466, 2.9778798335036534}}};


/* we are gonna apply a 
simplest linear regression for this set of points
linear regression just is a line fitting
*/
std::string model(const std::array<std::array<float, kDimensions>, kDataPoints>& points){

  std::string coefficients;

  //Equation of line is Ax + By + C=0.
  float  X = 0, Y = 0, XY = 0, X2 = 0, Y2 = 0;
  float A,B,C;


  for (auto const& point:points){

     X  += point[0]; // sum x
     Y  += point[1]; // sum y
     XY += point[0] * point[1]; // sum xy
     X2 += point[0] * point[0]; // sum x^2
     Y2 += point[1] * point[1]; // sum y^2

  }

   // mean of sums
   X  /= kDataPoints;
   Y  /= kDataPoints;
   XY /= kDataPoints;
   X2 /= kDataPoints;
   Y2 /= kDataPoints;

   A = - ( XY - X * Y ); //Common for both solution

   // other solutions
   float Bx = X2 - X * X;
   float By = Y2 - Y * Y;

   if( fabs( Bx ) < fabs( By ) ) //Test verticality/horizontality
   { // Line is more Vertical.
      B = By;
      std::swap(A,B);
   }
   else
   {  // Line is more Horizontal.
      // Classical solution, when we expect more horizontal-like line
      B = Bx;
   }
   
   // we get c
   C = - ( A * X + B * Y );

  // we built output of coefficients
  coefficients = std::to_string(A)+" "+std::to_string(B)+" "+std::to_string(C);
  return coefficients;

}

int main() {
  /*
   *Use a model of your choice to approximate the relationship between the
   independent/dependent variable pairs above. Model choice is up to you - just
   print out coefficients!
   */
  std::cout << model(points) << std::endl;
  /*
   *Note: this is a suggested function signature, feel free to implement
   whatever you see fit!
   */
}
