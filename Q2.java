import java.util.Arrays;
class Q2{
    public static void main(String[] args)
    {   
        int[] a = {1,2,9};
        System.out.println("Input : "+Arrays.toString(a));
        for(int i=a.length-1; i>=0; i--)
        {
            a[i]++;
            if(a[i]>9)
            {
                a[i]=0;
            }
            else{
                System.out.println("Output : "+Arrays.toString(a));
                return;
            }
        }
        int[] b = new int[a.length+1];
        b[0]=1;
        System.arraycopy(a, 0, b, 1, a.length);
        System.out.println("Output : "+Arrays.toString(b));        
    }
}