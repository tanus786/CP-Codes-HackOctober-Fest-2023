import java.util.Scanner;

public class FlowerCounter

{

    public static void main(String[] args)

    {

        String[] flowers = new String[5];

        double[] price = {.50, .75, 1.50, .50, .80};

        Scanner keyboard = new Scanner(System.in);

        System.out.println("What kind of flower would you " +

            "like to purchase? \nPetunia, Pansy, Rose," +

            " Violet, or Carnation?");

        String index = keyboard.nextLine();

        System.out.println("How many " + index +"s" + " would you like?");

        int count = keyboard.nextInt();

        double total = count * price.length;

        System.out.println("The cost for " + count  +  index  + " is " + total);             

    }        

}

