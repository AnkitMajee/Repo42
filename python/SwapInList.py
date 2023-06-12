def swapList(li,pos1,pos2):
    li[pos1],li[pos2]=li[pos2],li[pos1]
    return li

li=list(map(int,input("\n Enter list Element = ").strip().split()))
pos1=int(input("\n Enter the 1st index = "))
pos2=int(input("\n Enter the 2nd index = "))
print("After swapping the final array = ",swapList(li,pos1,pos2))
