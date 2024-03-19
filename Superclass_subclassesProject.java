import java.util.Random;
import java.util.Scanner;

public class Superclass_subclassesProject {
    public static void main(String[] args) {
        Scanner evry = new Scanner(System.in);
        Random random = new Random();
        while(true){
            System.out.println("Christmas Gift Generator: ");
            System.out.println("1. Generate an Electronic Gift");
            System.out.println("2. Generate a Toy Gift");
            System.out.println("0. Exit");
            System.out.print("Enter Your Choice: ");
            int input = evry.nextInt();
            switch (input){
                case 1:
                    int randomNum = random.nextInt();
                    break;
                case 2:

                    break;
                case 3:
                    System.out.println("Exiting");
                    System.exit(0);

            }

        }
    }
    public class Gift{
        String name;
        public Gift(String namee){
            this.name = namee;
        }
        public String getName(){
            return this.name;
        }
        public void generate(){

        }
    }
}

