def check(num):
    if(num%2==0):
        return "even"
    return "Odd"
while(True):
    num = int(input("\nEnter your number = "))
    ans = check(num)
    print("You number is = ",ans)
