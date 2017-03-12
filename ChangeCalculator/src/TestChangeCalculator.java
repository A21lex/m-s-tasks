/**
 * Created by aleksandrs on 3/10/17.
 */

import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class TestChangeCalculator {


    @Test
    public void testMakeChange(){
        ChangeCalculator changeCalculator = new ChangeCalculator(); //testing changeCalculator
        assertEquals(4, changeCalculator.makeChange(135));
        assertEquals(3, changeCalculator.makeChange(71));
        assertEquals(3, changeCalculator.makeChange(111));
        assertEquals(24, changeCalculator.makeChange(2027));
        assertEquals(102, changeCalculator.makeChange(10006));
    }

    @Test (expected = NumberFormatException.class)
    public void testNumberFormatException(){
        ChangeCalculator changeCalculator = new ChangeCalculator(); //testing negative inputs to changeCalculator
        changeCalculator.makeChange(-10);
    }

}
