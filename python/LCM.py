def lcm(num1,num2):
    i=1
    while(True):
        Greatest=max(num1,num2)*i
        if(Greatest%num1==0 and Greatest%num2==0):
            return Greatest
        i+=1

num1=int(input("\nEnter your 1st number = "))
num2 = int(input("Enter your 2nd number = "))

ans = lcm(num1,num2)
print("LCM of {} and {} = {}".format(num1,num2,ans))
