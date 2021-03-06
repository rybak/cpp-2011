#include <fstream>
#include <cmath>
#include <vector>

// polygon square

int main()
{
   std::ifstream input("in.txt");
   std::ofstream output("out.txt");
   
   double x1, y1, x2, y2, x0, y0, s = 0;

   input >> x0 >> y0;
   x1 = x0;
   y1 = y0;

   while (input >> x2 >> y2)
   {
      s += (x1 - x2) * (y1 + y2);
      x1 = x2;
      y1 = y2;
   }
   
   s += (x1 - x0) * (y1 + y0);
   
   output << std::fixed <<fabs(s) / 2;
 
   return 0;
}
