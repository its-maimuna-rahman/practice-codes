#include <iostream>
#include <cmath>

int main() {
  const double PI = 3.141592653589793;    
  double r1, area1, per1, l1, w1, area2, per2,
  a, b, c, s, area3, per3, r2, vol1, x, y, z, vol2, r3, h, vol3;
  int dim, sp1, sp2;      
  
  std::cout << "enter dimention (1 for 2D & 2 for 3D) = ";
  std::cin >> dim;
  
  switch(dim) {
  case 1: 
    std::cout << "1. circle" << std::endl << "2. rectangle" << std::endl << "3. triangle" << std::endl;
    std::cout << "enter shape (1,2 or 3) = ";
    std::cin >> sp1;
    
    switch(sp1) {
    case 1:
      std::cout << "circle radius = ";
      std::cin >> r1;
      area1 = PI * r1 * r1;
      per1 = 2 * PI * r1;
      std::cout << "area = " << area1 << std::endl;
      std::cout << "perimeter = " << per1 << std::endl;
      break;
      
    case 2:
      std::cout << "rectangle length = ";
      std::cin >> l1;
      std::cout << "width = ";
      std::cin >> w1;
      area2 = l1 * w1;
      per2 = 2 * (l1 * w1);
      std::cout << "area = " << area2 << std::endl;
      std::cout << "perimeter = " << per2 << std::endl;
      break;
      
    case 3:
      std::cout << "triangle a = ";
      std::cin >> a;
      std::cout << "b = ";
      std::cin >> b;
      std::cout << "c = ";
      std::cin >> c;
      s = (a + b + c) / 2;
      area3 = sqrt(s * (s-a) * (s-b) * (s-c));
      per3 = a + b + c;
      std::cout << "area = " << area3 << std::endl;
      std::cout << "perimeter = " << per3 << std::endl;
      break;
      
    default:
      std::cout << "invalid input for shape" << std::endl;
      break;
    }
    break;
    
  case 2: 
    std::cout << "1. sphere" << std::endl << "2. cuboid" << std::endl << "3. cylinder" << std::endl;
    std::cout << "enter shape (1,2 or 3) = ";
    std::cin >> sp2;
    
    switch(sp2) {
    case 1:
      std::cout << "enter sphere radius = ";
      std::cin >> r2;
      vol1 = (4/3) * PI * r2 * r2 * r2;
      std::cout << "volume = " << vol1 << std::endl;
      break;
      
    case 2:
      std::cout << "enter cuboid x = ";
      std::cin >> x;
      std::cout << "enter y = ";
      std::cin >> y;
      std::cout << "enter z = ";
      std::cin >> z;
      vol2=x*y*z;
      std::cout << "volume = " << vol2 << std::endl;
      break;
      
    case 3:
      std::cout << "cylinder radius = ";
      std::cin >> r3;
      std::cout << "height = ";
      std::cin >> h;
      vol3 = PI * r3 * r3 * h;
      std::cout << "volume = " << vol3 << std::endl;
      break;
      
    default:
      std::cout << "invalid input for shape" << std::endl;
      break;
    }
    
    break;
    
  default:
    std::cout << "invalid input for dimention" << std::endl;
    break;
  }
  
  return 0;
}
