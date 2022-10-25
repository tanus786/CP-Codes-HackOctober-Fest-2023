public class FactorialAndSum {

    public static void main(String[] args) {

        System.out.println(fact(6));
        System.out.println(sum(5));
    }

    static int fact(int n)
    {
        if (n==1) return 1;

        return n*fact(n-1);
    }
    static int sum(int a)
    {
        if (a==1) return 1;

        return a+sum(a-1);
    }
}
