"""
Progam Name: Stuff
Programmer: Mcqueen Zhang
Date: 04/08/2024

Purpose and Function of the Program
Purpose: A technical program for gamers



Funciton: The function is calculating the optimal system hardware to play a certain game, based on ideal experience, resolution, hardware, and software.
"""

hardList = []
# list of hardware to check for inputs
inputListCheck = ['intel', 'amd', 'nv', 'AMD', '12+', '10+', '8+', '2+', '7000+', '5000+', '3000+', '2000+', '1000+', '4080+', '4070+', '3060+', '3050+', '1660+', '960+', '1030+', '7900GRE+', '7700XT+', '7600+', 'RX Vega 56+', 'RX 6500XT+', 'Radeon 680M+', 'fps']
# introduction:
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

# global variable
totalScore = 0

# calculation for intel CPU
def intelPerformance(cgenInput):
    global totalScore  # Declare totalScore as global
    scores = {"12+": 20, "10+": 17, "8+": 12, "2+": 6}
    totalScore += scores.get(cgenInput, 0)

# calculation for amd CPU
def amdCPUPerformance(cgenInput):
    global totalScore  # Declare totalScore as global
    scores = {"7000+": 20.5, "5000+": 17, "3000+": 12, "2000+": 7, "1000+": 3.5}
    totalScore += scores.get(cgenInput, 0)

# calculation for nvidia gpu
def nvPerformance(ggenInput):
    global totalScore  # Declare totalScore as global
    scores = {"4080+": 18, "4070+": 16, "3060+": 13, "3050+": 7, "1660+": 5, "960+": 3.5, "1030+": 2.5}
    totalScore += scores.get(ggenInput, 0)

# calculation for amd gpu
def amdGPUPerformance(ggenInput):
    global totalScore  # Declare totalScore as global
    scores = {"7900GRE+": 17, "7700XT+": 15, "7600+": 13.25, "RX Vega 56+": 7, "RX 6500XT+": 4.75, "Radeon 680M+": 2.25}
    totalScore += scores.get(ggenInput, 0)

# calculation for resolutions
def resolutionPerformance(resInput):
    global totalScore  # 声明 totalScore 为全局变量
    scores = {"1": -10, "2": -5, "3": 0, "4": 5, "5": 10}
    print("Before: ", totalScore)  # 打印修改前的 totalScore
    totalScore += scores.get(resInput, 0)  # 更新 totalScore
    print("After: ", totalScore)  # 打印修改后的 totalScore
# calculation for the final score
#def totalScoreCalculation(performanceScores):
 #   finalScore = performanceScores / 10
  #  if finalScore >=



#while loop to check whether user want to play again
while True:
    # user input
    choosePerORHard = input("See Your FPS ingame [enter: 'fps']?: ")

    inputCheck = False
    for wordChecking in inputListCheck:
        if choosePerORHard.lower() == wordChecking.lower():
            inputCheck = True
            break

    if not inputCheck:
        print("Please enter something valid!!!")
        continue

    #selection for user to choose
    if choosePerORHard == "fps":
        #allowing user to enter their parts to evaluate + appending to list
        #Intel or AMD?
        cpuType = input("Intel/AMD: ")
        gpuType = input("NVIDIA/AMD: ")
        #hardware-brand
        if cpuType.lower() == "intel":
            #hardware-model
            cpuGenInput = input("CPU: ")
            gpuInput = input("GPU: ")
            resInput = int(input("Resolution: "))
            intelPerformance(cpuGenInput)
            resolutionPerformance(resInput)
            #nvidia gpu
            if gpuType.lower() == "nv":
                nvPerformance(gpuInput)
                print(f"Total Score: {totalScore}")
                # exit message
                exitInput = input("Do you want to play again [y/n]: ")
                if exitInput.lower() == "y":
                    continue
                elif exitInput.lower() == "n":
                    print("Goodbye")
                    break
                else:
                    print("Enter something valid!!!")
            #amd gpu
            elif gpuType.lower() == "amd":
                amdGPUPerformance(gpuInput)
                print(f"Total Score: {totalScore}")
                # exit message
                exitInput = input("Do you want to play again [y/n]: ")
                if exitInput.lower() == "y":
                    continue
                elif exitInput.lower() == "n":
                    print("Goodbye")
                    break
                else:
                    print("Enter something valid!!!")
        #user chose amd processors => repeat the same code again
        elif cpuType.lower() == "amd":
            #hardware-model
            cpuGenInput = input("CPU: ")
            gpuInput = input("GPU: ")
            resInput = int(input("Resolution: "))
            amdCPUPerformance(cpuGenInput)
            resolutionPerformance(resInput)
            #user choose nvidia graphics card
            if gpuType.lower() == "nv":
                nvPerformance(gpuInput)
                print(f"Total Score: {totalScore}")
                # exit message
                exitInput = input("Do you want to play again [y/n]: ")
                if exitInput.lower() == "y":
                    continue
                elif exitInput.lower() == "n":
                    print("Goodbye")
                    break
                else:
                    print("Enter something valid!!!")
            #amd gpu
            elif gpuType.lower() == "amd":
                amdGPUPerformance(gpuInput)
                print(f"Total Score: {totalScore}")
                # exit message
                exitInput = input("Do you want to play again [y/n]: ")
                if exitInput.lower() == "y":
                    continue
                elif exitInput.lower() == "n":
                    print("Goodbye")
                    break
                else:
                    print("Enter something valid!!!")
            elif gpuType.lower() == "restart":
                continue
            elif gpuType.lower() == "quit":
                print("Goodbye")
            else:
                print("Please enter something valid!!!")
                continue
        elif cpuType.lower() == "restart":
            continue
        elif cpuType.lower() == "quit":
            print("Goodbye")
            break
    else:
        print("Please enter something valid!!!")
        continue
 