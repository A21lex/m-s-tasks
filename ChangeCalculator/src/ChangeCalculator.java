/**
 * Created by aleksandrs on 3/10/17.
 */

import java.util.ArrayList;
import java.util.Scanner;


public class ChangeCalculator {

    private ArrayList<Integer> possibleBills =
            new ArrayList<Integer>() {{
                add(100);
                add(50);
                add(20);
                add(10);
                add(5);
                add(1);
            }};

    int makeChange(int amountGiven) {
        //if we need to give change for an existing bill it is just the bill itself, so return 1
        if (possibleBills.contains(amountGiven)) {
            System.out.println("amountGiven is equal to one of the bills, return 1");
            return 1;
        }
        int billCount = 0;
        for (Integer bill : possibleBills) {
            if (amountGiven == 0) {
                break; //break once all the amount has been handled
            }
            //check if the bill is smaller than the amount we need to give change for
            else if (bill < amountGiven) {
                int obtainedAmountofBills = amountGiven / bill;
                billCount += obtainedAmountofBills; //for example: given 207 we see that it is bigger than 100
                // and thus will need to return at least 207/100 bills (i.e. 2 as it will be an int) so add 2 to billCount
                System.out.printf("We use %d bills of %d and now our total bill count is now: %d",
                        obtainedAmountofBills, bill, billCount);
                System.out.println();
                amountGiven -= obtainedAmountofBills * bill; //subtract the bills we have come up with already
                System.out.printf("Remaining amount is: %d", amountGiven);
                System.out.println();
                int newBillCount = makeChange(amountGiven); //recursively call the method to find the amount of bills
                // for what remains
                billCount += newBillCount; //the total amount of bills required
                break;
            }
            else if (bill > amountGiven) {
                System.out.printf("Bill %d is bigger than the given amount %d, continuing", bill, amountGiven);
                System.out.println();
            }
        }
        return billCount;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input amount to get change from: ");
        int amountGiven = sc.nextInt();
        int billCount = new ChangeCalculator().makeChange(amountGiven);
        System.out.printf("The minimum amount of bills returned is %d", billCount);
        sc.next();
    }

}
