/**
 * Created by aleksandrs on 3/11/17.
 */

public class StrShift {

    String rotateStringLeft(String str, int num){
        num %= str.length(); //num must be mod stringLength to avoid arrayOutOfBounds
        char[] chars = str.toCharArray();
        char[] keepShifted = new char[num+1];         //keep part of the string to be shifted (ex.: he from hello for num = 2)
        char[] moveLeft = new char[str.length()-num]; //keep part of the string to move left (ex.: llo from hello for num = 2)
        for (int i = 0; i < chars.length; i++){
            System.out.println("We are at number: " + i);
            if (i < num) {
                System.out.printf("adding char %c to keepShifted", chars[i]);
                System.out.println();
                keepShifted[i] = chars[i];
                continue;
            }
            else {
                System.out.printf("adding char %c to moveLeft", chars[i]);
                System.out.println();
                moveLeft[i-num] = chars[i];

            }
        }
        return String.valueOf(moveLeft) + String.valueOf(keepShifted);
    }

    String rotateStringRight(String str, int num){
        num %= str.length(); //num must be mod stringLength to avoid arrayOutOfBounds
        char[] chars = str.toCharArray();
        char[] keepShifted = new char[str.length() - num]; //keep part of the string to be shifted (ex.: Microso from Microsoft for num = 2)
        char[] moveRight = new char[num + 1]; //keep part of the string to move right (ex.: ft from Microsoft for num = 2)
        for (int i = chars.length-1; i >= 0; i--){
            System.out.println("We are at number: " + i);
            if (i >= (str.length() - num)) {
                System.out.printf("adding char %c to moveRight", chars[i]);
                System.out.println();
                moveRight[i-(str.length()-num)] = chars[i];

            }
            else {
                System.out.printf("adding char %c to keepShifted", chars[i]);
                System.out.println();
                keepShifted[i] = chars[i];
                continue;

            }
        }
        return String.valueOf(moveRight) + String.valueOf(keepShifted);
    }

    public static void main(String[] args) {
        String str = "Microsoft";
        System.out.println("Initial String = " + str);
        String newStr = new StrShift().rotateStringLeft(str, 2);
        System.out.println("New String = " + newStr);

        String anotherStr = new StrShift().rotateStringRight(str, 2);
        System.out.println("anotherStr = " + anotherStr);
    }
}
