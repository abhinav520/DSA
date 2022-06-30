import java.util.*;
import java.time.*;
import java.time.format.DateTimeFormatter;

public class hello{
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        String s=scn.nextLine();
        System.out.println("Hello World and "+s);
        scn.close();
        // DateTimeFormatter dtf=DateTimeFormatter.ofPattern("HH:mm:ss dd:MM:YYYY");
        // LocalDateTime now=LocalDateTime.now();
        // System.out.println(dtf.format(now));;
        
    }
}