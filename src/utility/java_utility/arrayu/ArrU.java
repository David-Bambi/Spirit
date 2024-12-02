package array_utility;

public class ArrU 
{
    public static int Max(int [] arr)
    {
        int n = arr.length;

        if(n == 0)
            return 0;

        int max = arr[0];
        for (int i = 0 ; i<n ; i++)
	        if (arr[i] > max)
		        max  = arr[i];

        return max;
    }
}