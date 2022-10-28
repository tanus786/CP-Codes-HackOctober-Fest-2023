abstarct class shape
{
public abstarct noofsides();
}

class Rectangle extends shape
  {
public void noofsides()
    {
System.out.print("\nrectangle has 4 sides");
    }
  }
  class Traingle extends shape
  {
public void noofsides()
    {
System.out.print("\nTraingle has 3 sides");
    }
  }
  class Hexagon extends shape
  {
public void noofsides()
    {
System.out.print("\nhexagon has 6 sides");
    }
  }
  
class polym
{
public static void main(String[] args)
{
  Rectangle r = new Rectangle();
  Traingle  t = new Traingle();
  Hexagon h = new Hexagon();

   t.noofsides();
   r.noofsides();
   h.noofsides();
}

}
