while(True):
    num1=int(input("\n Enter your 1st number = "))
    num2=int(input("\n Enter your 2nd number = "))
    temp = num1
    num1 = num2
    num2 = temp
    print("Now 1st no.={}, 2nd no. ={}".format(num1,num2))
