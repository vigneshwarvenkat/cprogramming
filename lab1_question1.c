#include <stdio.h>
#include <math.h>
#define PI 3.14f
int main() //Debugging Exercise
{
  printf("Debugging Exercise \n");
  float radius_cylinder, _radius_cone, height_cylinder, _height_cone;
  float CYLINDER_Volume, CONE_Volume;
  float CONE_SA_1, CONE_SA_bottom_1;  //variable name cannot start with number
  float CYLINDER_BSA_2, CYLINDER_LSA_2; //variable name cannot start with number
  float SA_large_bottom_cone, SA_small_bottom_cone, circumference_cylinder;//cannot use hyphen as can be mistaken for a minus sign

  // ####### INPUT#########
  printf("Please enter the radius of a cylinder: ");
  scanf("%f", &radius_cylinder);// had to separate the scanf statement to a printf and scanf as the user will not receive
  //the prompt to input their radius value in the original code
  printf("Please enter the height of a cylinder:");
  scanf("%f", &height_cylinder);//never add ampersand
  _radius_cone = radius_cylinder*2;
  _height_cone = height_cylinder/2; //variable was initialised as _height_cone NOT height_cone

  //#####VOLUME#######
  CYLINDER_Volume = PI * radius_cylinder * radius_cylinder * height_cylinder;
  CONE_Volume = (1.0/3) * PI * _radius_cone * _height_cone;
  printf("Volume of a Cylinder = %.3f\n", CYLINDER_Volume);
  printf("Volume of a cone is : %.3f\n", CONE_Volume);
  printf("Total volume of the arrow is : %3f \n", (CONE_Volume + CYLINDER_Volume));

  //#######CYLINDER AREA#######
  CYLINDER_BSA_2 = PI * pow(radius_cylinder,2);// to square need to use pow(radius_cylinder, 2)
  printf("Bottom Surface Area of a cylinder = %.3f\n", CYLINDER_BSA_2);//never add ;
  circumference_cylinder = 2 * PI * radius_cylinder;
  CYLINDER_LSA_2 = circumference_cylinder * height_cylinder;
  printf("Lateral Surface Area of a cylinder = %3f\n", CYLINDER_LSA_2);//supposed to be %3f and not %.3d

  //######CONE AREA#########
  CONE_SA_1 = PI * _radius_cone * sqrt(_radius_cone * _radius_cone + _height_cone * _height_cone);
  SA_large_bottom_cone = PI * _radius_cone * _radius_cone;//previously written as SA_large_bottom_cone, SA_large_BC
  //has not been initialised
  SA_small_bottom_cone = PI * radius_cylinder * radius_cylinder;//previously written as SA_small_bottom_cone, SA_small_BC
  // has not been initialised
  CONE_SA_bottom_1 = SA_large_bottom_cone - SA_small_bottom_cone; //hyphen change to underscore
  printf("Surface area of cone is: %3f, Surface bottom area of cone is : %.3f \n", CONE_SA_1, CONE_SA_bottom_1);// %3c does
  //not work since CONE_SA_1 is a float and not a character/string ,variable name problem is same

  //########TOTAL AREA OF ARROW######
  printf("Total area of the arrow is : %.3f\n", (CONE_SA_1 + CONE_SA_bottom_1 +CYLINDER_LSA_2 +CYLINDER_BSA_2));// % sign is
  //missing in front of the .3f

  return 0;


}



