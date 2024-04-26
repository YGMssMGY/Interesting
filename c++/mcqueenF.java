import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class mcqueenF {
    private static final String[] inputListCheck = {"intel", "amd", "nv", "AMD", "12+", "10+", "8+", "2+", "7000+", "5000+", "3000+", "2000+", "1000+", "4080+", "4070+", "3060+", "3050+", "1660+", "960+", "1030+", "7900GRE+", "7700XT+", "7600+", "RX Vega 56+", "RX 6500XT+", "Radeon 680M+", "fps"};
    private static int totalScore = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the program in which you can either:");
        System.out.println("    1. See Your approximate FPS in Valorant with your hardware");
        System.out.println("    2. See the approximate hardware required to get your ideal performance");
        System.out.println("Rules:");
        System.out.println("    1. Intel cpu enter 'intel', AMD cpu enter 'amd'");
        System.out.println("    2. NVIDIA gpu enter 'nv', AMD gpu enter 'AMD'");
        System.out.println("    3. Intel Generations: '12+', '10+', '8+', '2+'");
        System.out.println("    4. AMD Generations: '7000+', '5000+', '3000+', '2000+', '1000+'");
        System.out.println("    *** For Graphics card performance: 'https://benchmarks.ul.com/compare/best-gpus'***");
        System.out.println("    5. NVidia Generations: '4080+', '4070+', '3060+', '3050+', '1660+', '960+', '1030+'");
        System.out.println("    6. AMD Generations: '7900GRE+', '7700XT+', '7600+', 'RX Vega 56+', 'RX 6500XT+', 'Radeon 680M+'");
        System.out.println("    7. Choose the graphics card that is higher than or equivalent to the card model as listed above, please follow the *EXACT* format!!!");
        System.out.println("    8. Resolutions of monitor:");
        System.out.println("       - 720p: 1");
        System.out.println("       - 1080p: 2");
        System.out.println("       - 1440p: 3");
        System.out.println("       - 2560p: 4");

        while (true) {
            System.out.print("See Your FPS ingame [enter: 'fps']?: ");
            String choosePerORHard = scanner.nextLine().toLowerCase();

            if (!isValidInput(choosePerORHard)) {
                System.out.println("Please enter something valid!!!");
                continue;
            }

            if (choosePerORHard.equals("fps")) {
                System.out.print("Intel/AMD: ");
                String cpuType = scanner.nextLine().toLowerCase();
                System.out.print("NVIDIA/AMD: ");
                String gpuType = scanner.nextLine().toLowerCase();

                if (cpuType.equals("intel")) {
                    System.out.print("CPU: ");
                    String cpuGenInput = scanner.nextLine();
                    System.out.print("GPU: ");
                    String gpuInput = scanner.nextLine();
                    System.out.print("Resolution: ");
                    int resInput = Integer.parseInt(scanner.nextLine());

                    intelPerformance(cpuGenInput);
                    resolutionPerformance(String.valueOf(resInput));

                    if (gpuType.equals("nv")) {
                        nvPerformance(gpuInput);
                        System.out.println("Total Score: " + totalScore);
                        handleExitInput(scanner);
                    } else if (gpuType.equals("amd")) {
                        amdGPUPerformance(gpuInput);
                        System.out.println("Total Score: " + totalScore);
                        handleExitInput(scanner);
                    }
                } else if (cpuType.equals("amd")) {
                    System.out.print("CPU: ");
                    String cpuGenInput = scanner.nextLine();
                    System.out.print("GPU: ");
                    String gpuInput = scanner.nextLine();
                    System.out.print("Resolution: ");
                    int resInput = Integer.parseInt(scanner.nextLine());

                    amdCPUPerformance(cpuGenInput);
                    resolutionPerformance(String.valueOf(resInput));

                    if (gpuType.equals("nv")) {
                        nvPerformance(gpuInput);
                        System.out.println("Total Score: " + totalScore);
                        handleExitInput(scanner);
                    } else if (gpuType.equals("amd")) {
                        amdGPUPerformance(gpuInput);
                        System.out.println("Total Score: " + totalScore);
                        handleExitInput(scanner);
                    } else if (gpuType.equals("restart")) {
                        continue;
                    } else if (gpuType.equals("quit")) {
                        System.out.println("Goodbye");
                        break;
                    } else {
                        System.out.println("Please enter something valid!!!");
                        continue;
                    }
                } else if (cpuType.equals("restart")) {
                    continue;
                } else if (cpuType.equals("quit")) {
                    System.out.println("Goodbye");
                    break;
                }
            } else {
                System.out.println("Please enter something valid!!!");
                continue;
            }
        }

        scanner.close();
    }

    private static boolean isValidInput(String input) {
        for (String validInput : inputListCheck) {
            if (input.equals(validInput)) {
                return true;
            }
        }
        return false;
    }

    private static void handleExitInput(Scanner scanner) {
        System.out.print("Do you want to play again [y/n]: ");
        String exitInput = scanner.nextLine().toLowerCase();
        if (exitInput.equals("y")) {
            return;
        } else if (exitInput.equals("n")) {
            System.out.println("Goodbye");
            System.exit(0);
        } else {
            System.out.println("Enter something valid!!!");
        }
    }

    private static void intelPerformance(String cgenInput) {
        Map<String, Integer> scores = new HashMap<>();
        scores.put("12+", 20);
        scores.put("10+", 17);
        scores.put("8+", 12);
        scores.put("2+", 6);
        totalScore += scores.getOrDefault(cgenInput, 0);
    }

    private static void amdCPUPerformance(String cgenInput) {
        Map<String, Double> scores = new HashMap<>();
        scores.put("7000+", 20.5);
        scores.put("5000+", 17.0);
        scores.put("3000+", 12.0);
        scores.put("2000+", 7.0);
        scores.put("1000+", 3.5);
        totalScore += scores.getOrDefault(cgenInput, 0.0).intValue();
    }

    private static void nvPerformance(String ggenInput) {
        Map<String, Integer> scores = new HashMap<>();
        scores.put("4080+", 18);
        scores.put("4070+", 16);
        scores.put("3060+", 13);
        scores.put("3050+", 7);
        scores.put("1660+", 5);
        scores.put("960+", 3);
        scores.put("1030+", 2);
        totalScore += scores.getOrDefault(ggenInput, 0);
    }
    private static void amdGPUPerformance(String ggenInput) {
        Map<String, Double> scores = new HashMap<>();
        scores.put("7900GRE+", 17.0);
        scores.put("7700XT+", 15.0);
        scores.put("7600+", 13.25);
        scores.put("RX Vega 56+", 7.0);
        scores.put("RX 6500XT+", 4.75);
        scores.put("Radeon 680M+", 2.25);
        totalScore += scores.getOrDefault(ggenInput, 0.0).intValue();
    }
    
    private static void resolutionPerformance(String resInput) {
        Map<String, Integer> scores = new HashMap<>();
        scores.put("1", -10);
        scores.put("2", -5);
        scores.put("3", 0);
        scores.put("4", 5);
        scores.put("5", 10);
        totalScore += scores.getOrDefault(resInput, 0);
    }
}