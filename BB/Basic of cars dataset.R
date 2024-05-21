#create a car dataset
data_cars=cars

#car speed value only
table(data_cars$speed)

#view the table
View(data_cars)

#dimension of the cars dataset
dim(data_cars)

#summary
summary(data_cars$speed)

sum_speed=sum(cars$speed)
print(sum_speed) #print say direct priint hota hai warna terminal mai same variable lekh dena

#mean calculate
mean(c(1:100))

#standard deviation
sd(data_cars$speed)

#varience dist
var(data_cars$dis)
var(data_cars$speed)

#plot the graph of speed vs indices
plot(data_cars$speed,main="scatter plot of speed v/s indices")
#red color graph
plot(data_cars$speed,col="red",main="scatter plot of speed v/s indices")

plot(data_cars$speed,col="red",main="scatter plot of speed v/s indices",xlab="indices",ylab="speed")


plot(data_cars$dist,main="scatter plot of distance v/s indices")
plot(data_cars$dist,col="red",main="scatter plot of distance v/s indices")
plot(data_cars$dist,col="red",main="scatter plot of distance v/s indices",xlab="indices",ylab="distance")
plot(data_cars$speed,data_cars$dist,col="red",main="scatter plot of speed v/s distance",xlab="indices",ylab="distance")
plot(data_cars$speed,data_cars$dist,col="red",main="scatter plot of speed v/s distance",xlab="speed",ylab="distance")

#histogram
hist(data_cars$speed,col="purple",main="histogram of speed")
table(data_cars$speed)
hist(data_cars$speed,col="purple",main="histogram of speed",breaks=2)
hist(data_cars$speed,col="purple",main="histogram of speed",breaks=10)
hist(data_cars$speed,col="purple",main="histogram of speed",breaks=49)
