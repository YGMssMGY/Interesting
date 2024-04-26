inputListCheck = ["intel", "amd", "nv", "AMD", "12+", "10+", "8+", "2+", "7000+", "5000+", "3000+", "2000+", "1000+", "4080+", "4070+", "3060+", "3050+", "1660+", "960+", "1030+", "7900GRE+", "7700XT+", "7600+", "RX Vega 56+", "RX 6500XT+", "Radeon 680M+", "fps"]
totalScore = 0

def main():
    print("Welcome to the program in which you can either:")
    print("    1. See Your approximate FPS in Valorant with your hardware")
    print("    2. See the approximate hardware required to get your ideal performance")
    print("Rules:")
    print("    1. Intel cpu enter 'intel', AMD cpu enter 'amd'")
    print("    2. NVIDIA gpu enter 'nv', AMD gpu enter 'AMD'")
    print("    3. Intel Generations: '12+', '10+', '8+', '2+'")
    print("    4. AMD Generations: '7000+', '5000+', '3000+', '2000+', '1000+'")
    print("    *** For Graphics card performance: 'https://benchmarks.ul.com/compare/best-gpus'***")
    print("    5. NVidia Generations: '4080+', '4070+', '3060+', '3050+', '1660+', '960+', '1030+'")
    print("    6. AMD Generations: '7900GRE+', '7700XT+', '7600+', 'RX Vega 56+', 'RX 6500XT+', 'Radeon 680M+'")
    print("    7. Choose the graphics card that is higher than or equivalent to the card model as listed above, please follow the *EXACT* format!!!")
    print("    8. Resolutions of monitor:")
    print("       - 720p: 1")
    print("       - 1080p: 2")
    print("       - 1440p: 3")
    print("       - 2560p: 4")

    while True:
        choosePerORHard = input("See Your FPS ingame [enter: 'fps']?: ").lower()

        if choosePerORHard not in inputListCheck:
            print("Please enter something valid!!!")
            continue

        if choosePerORHard == "fps":
            cpuType = input("Intel/AMD: ").lower()
            gpuType = input("NVIDIA/AMD: ").lower()

            if cpuType == "intel":
                cpuGenInput = input("CPU: ")
                gpuInput = input("GPU: ")
                resInput = int(input("Resolution: "))

                intelPerformance(cpuGenInput)
                resolutionPerformance(str(resInput))

                if gpuType == "nv":
                    nvPerformance(gpuInput)
                    print(f"Total Score: {totalScore}")
                    handleExitInput()
                elif gpuType == "amd":
                    amdGPUPerformance(gpuInput)
                    print(f"Total Score: {totalScore}")
                    handleExitInput()

            elif cpuType == "amd":
                cpuGenInput = input("CPU: ")
                gpuInput = input("GPU: ")
                resInput = int(input("Resolution: "))

                amdCPUPerformance(cpuGenInput)
                resolutionPerformance(str(resInput))

                if gpuType == "nv":
                    nvPerformance(gpuInput)
                    print(f"Total Score: {totalScore}")
                    handleExitInput()
                elif gpuType == "amd":
                    amdGPUPerformance(gpuInput)
                    print(f"Total Score: {totalScore}")
                    handleExitInput()
                elif gpuType == "restart":
                    continue
                elif gpuType == "quit":
                    print("Goodbye")
                    break
                else:
                    print("Please enter something valid!!!")
                    continue

            elif cpuType == "restart":
                continue
            elif cpuType == "quit":
                print("Goodbye")
                break

        else:
            print("Please enter something valid!!!")
            continue

def isValidInput(user_input):
    return user_input in inputListCheck

def handleExitInput():
    exitInput = input("Do you want to play again [y/n]: ").lower()
    if exitInput == "y":
        return
    elif exitInput == "n":
        print("Goodbye")
        exit()
    else:
        print("Enter something valid!!!")

def intelPerformance(cgenInput):
    global totalScore
    scores = {"12+": 20, "10+": 17, "8+": 12, "2+": 6}
    totalScore += scores.get(cgenInput, 0)

def amdCPUPerformance(cgenInput):
    global totalScore
    scores = {"7000+": 20.5, "5000+": 17.0, "3000+": 12.0, "2000+": 7.0, "1000+": 3.5}
    totalScore += scores.get(cgenInput, 0)

def nvPerformance(ggenInput):
    global totalScore
    scores = {"4080+": 18, "4070+": 16, "3060+": 13, "3050+": 7, "1660+": 5, "960+": 3, "1030+": 2}
    totalScore += scores.get(ggenInput, 0)

def amdGPUPerformance(ggenInput):
    global totalScore
    scores = {"7900GRE+": 17.0, "7700XT+": 15.0, "7600+": 13.25, "RX Vega 56+": 7.0, "RX 6500XT+": 4.75, "Radeon 680M+": 2.25}
    totalScore += scores.get(ggenInput, 0)

def resolutionPerformance(resInput):
    global totalScore
    scores = {"1": -10, "2": -5, "3": 0, "4": 5, "5": 10}
    totalScore += scores.get(resInput, 0)

if __name__ == "__main__":
    main()