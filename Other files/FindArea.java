public class Main 
{
    //Driver Code
    public static void main(String[] args)
    {
        Rectangle obj = new Rectangle();
        // Calling function
        obj.Area(30, 20);
        obj.Area(12.5, 4.5);
        Circle obj1 = new Circle();
        // Calling function
        obj1.Area(3);
        obj1.Area(5.5);
        Square obj2 = new Square();
        // Calling function
        obj2.Area(20);
        obj2.Area(5.2);
        
    }
}
class Square 
{
    // Overloaded function to
    // calculate the area of the square
    // It takes one double parameter
    void Area(double side)
    {
        System.out.println("Area of the Square: "+ side * side);
    }
    // Overloaded function to
    // calculate the area of the square
    // It takes one float parameter
    void Area(float side)
    {
        System.out.println("Area of the Square: "+ side * side);
    }
}
class Circle 
{
    static final double PI = Math.PI;
  
    // Overloaded function to
    // calculate the area of the circle.
    // It takes one double parameter
    void Area(double r)
    {
        double A = PI * r * r;
  
        System.out.println("The area of the circle is :" + A);
    }
  
    // Overloaded function to
    // calculate the area of the circle.
    // It takes one float parameter
    void Area(float r)
    {
        double A = PI * r * r;
  
        System.out.println("The area of the circle is :" + A);
    }
}
class Rectangle 
{
     // Overloaded function to
    // calculate the area of the rectangle
    // It takes two double parameters
    void Area(double l, double b)
    {
        System.out.println("Area of the rectangle: " + l * b);
    }
    // Overloaded function to
    // calculate the area of the rectangle.
    // It takes two float parameters
    void Area(int l, int b)
    {
        System.out.println("Area of the rectangle: " + l * b);
    }
}
