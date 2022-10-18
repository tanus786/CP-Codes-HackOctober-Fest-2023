import java.util.Random;

public class Random100{
	public static void main(String args[]){

	Random random=new Random(1000);

	for(int i=0;i<100;i++){

	System.out.print(random.nextInt(49)+" ");

	if(i==25 || i==50 || i==75)
		System.out.println("");
}



}

}