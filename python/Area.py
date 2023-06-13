def square(side):
    return side*side

def rect(l, b):
    return l*b

#_main_
while(True):
    print('''
    Press 0 to exit
    Press 1 to calculate area of sqaure
    Press 2 to calculate area of rectangle
    ''')
    opt = int(input("Enter Your choice = "))
    if(opt==1):
        side = float(input("Enter side length of square = "))
        ans = square(side)
        print("Area of square of side length {} units = {} sq.units".format(side, ans))
    elif(opt==2):
        l = float(input("Enter 1st side of rectangle = "))
        b = float(input("Enter 2nd side of rectangle = "))
        ans = rect(l, b)
        print("Area of rectangle of side length {} units & {} units = {} sq.units".format(l, b, ans))
    elif(opt==0):
        print("Exited successfuly")
        break
    else:
        print("Only valid option is accepted. Try again...")
        continue
