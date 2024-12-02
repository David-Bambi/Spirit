
package array_utility;


import org.junit.Assert;
import org.junit.jupiter.api.Test;

/**
 * Test class for array utility
 */
public class ArrUTests  
{
    @Test
    public void GivenEmptyArr_WhenAskForMaxValue_ThenReturnZero ()
    {
        int [] arr = {};
        int result = ArrU.Max(arr);

        Assert.assertTrue("Result is not zero." , result==0);
        return;
    }
    @Test
    public void GivenArrWithVals_WhenAskForMaxValue_ThenReturnMax ()
    {
        int [] arr = {1,2,3,4};
        int result = ArrU.Max(arr);

        Assert.assertTrue("Result should be 4" , result==4);
        return;
    }
    @Test
    public void GivenArrWithDuplicateMax_WhenAskForMaxValue_ThenReturnAnyMaxVal ()
    {
        int [] arr = {4,4};
        int result = ArrU.Max(arr);

        Assert.assertTrue("Result should be 4" , result==4);
        return;
    }
      
}  
