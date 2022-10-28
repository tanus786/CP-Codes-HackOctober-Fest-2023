package multiple_inheritence;
class Box{
    double width,height, depth;
    Box(double w, double h, double d){
        width=w;
        height=h;
        depth=d;
    }
    Box(Box ob){
        width= ob.width;
        height= ob.height;
        depth= ob.depth;
    }
    void volume(){
        System.out.println("Volume = " +(width*height*depth));
    }
}
class BoxWeight extends Box{
    double weight;
    BoxWeight(double w, double h, double d, double m){
        super(w, h, d);
        weight=m;
    }
    BoxWeight(BoxWeight ob){
        super(ob);
        weight= ob.weight;
    }
}
public class Main {

    public static void main(String[] args) {
	// write your code here
        BoxWeight ob1 = new BoxWeight(10,20,30,40);
        BoxWeight ob2 = new BoxWeight(ob1);
        ob1.volume();
    }
}
