while(True):
    num1 = int(input("\nEnter your 1st number = "))
    num2 = int(input("Enter your 2nd number = "))
    num1=num1+num2
    num2=num1-num2
    num1=num1-num2
    print("Now 1st no. = {}, 2nd no. = {}".format(num1, num2))
