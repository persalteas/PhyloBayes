rm(list=ls())

par(mfrow=c(1,1))
agedata1 = read.table(file="../../tmp/aweber/PhyloBayes-master/run5.distH",header = F)
agedata2 = read.table(file="../../tmp/aweber/PhyloBayes-master/run6.distH",header = F)
agedata3 = read.table(file="../../tmp/aweber/PhyloBayes-master/run7.distH",header = F)

AllDist = c(as.numeric(as.vector(agedata1$V1)),as.numeric(as.vector(agedata2$V1)),as.numeric(as.vector(agedata3$V1))) 
ageAncetre = (1/AllDist)*6


thin10 = 1:(length(Morder)/10)

Mfiltered = ageAncetre[which(ageAncetre>1)]
Morder = Mfiltered[order(Mfiltered)]
median(Morder)
Morder[0.025*length(Morder)]
Morder[(1-0.025)*length(Morder)]



hist(ageAncetre,breaks=30,col="darkorange1",main="Age estimé de l'ancêtre commun",xlab="Age en Millions d'années")
abline(v=median(Morder),lwd=2)
abline(v=Morder[0.025*length(Morder)],lwd=2)
abline(v=Morder[(1-0.025)*length(Morder)],lwd=2)



#############

rawdata2 = read.table(file="../../tmp/aweber/PhyloBayes-master/run5.trace",header=T)
rawdata3 = read.table(file="../../tmp/aweber/PhyloBayes-master/run6.trace",header=T)
rawdata4 = read.table(file="../../tmp/aweber/PhyloBayes-master/run7.trace",header=T)
rawdata5 = read.table(file="../../tmp/aweber/PhyloBayes-master/run8.trace",header=T)
phasechauffe = 1500
AllRate = c(rawdata2[phasechauffe:length(rawdata5[,1]),2],rawdata3[phasechauffe:length(rawdata5[,1]),2],rawdata4[phasechauffe:length(rawdata5[,1]),2],rawdata5[phasechauffe:length(rawdata5[,1]),2])

hist(AllRate,col="darkorange1",breaks=20,main="Taux de mutation estimé",xlab="µ")

median(AllRate)
AllRate = AllRate[order(AllRate)]
AllRate[0.025*length(AllRate)]
AllRate[(1-0.025)*length(AllRate)]


abline(v=median(AllRate),lwd=2)
abline(v=AllRate[0.025*length(AllRate)],lwd=2)
abline(v=AllRate[(1-0.025)*length(AllRate)],lwd=2)
thin10 = 1:(length(AllRate)/10)
sd(AllRate[thin10])
mean(AllRate[thin10])


par(mfrow=c(2,2))
phasechauffe = 1500
size=0.35
plot(rawdata2[1:length(rawdata2[,1]),1],type='l',main="LogL",ylab="LogL",lwd=1,col="goldenrod1")
lines(rawdata3[1:length(rawdata3[,1]),1],type='l',lwd=1,col="firebrick1")
lines(rawdata4[1:length(rawdata3[,1]),1],type='l',lwd=1,col="royalblue2")
lines(rawdata5[1:length(rawdata3[,1]),1],type='l',lwd=1,col="seagreen")
abline(v=1500,lwd=3,col="darkorange1")

plot(rawdata2[phasechauffe:length(rawdata2[,1]),1],type='l',main="LogL post 1500",ylab="LogL",lwd=size,col="goldenrod1")
lines(rawdata3[phasechauffe:length(rawdata3[,1]),1],type='l',lwd=size,col="firebrick1")
lines(rawdata4[phasechauffe:length(rawdata3[,1]),1],type='l',lwd=size,col="royalblue2")
lines(rawdata5[phasechauffe:length(rawdata3[,1]),1],type='l',lwd=size,col="seagreen")

plot(rawdata2[1:length(rawdata2[,1]),2],type='l',main="Rate",ylab="Rate",lwd=1,col="goldenrod1")
lines(rawdata3[1:length(rawdata3[,1]),2],type='l',lwd=1,col="firebrick1")
lines(rawdata4[1:length(rawdata3[,1]),2],type='l',lwd=1,col="royalblue2")
lines(rawdata5[1:length(rawdata3[,1]),2],type='l',lwd=1,col="seagreen")
abline(v=1500,lwd=3,col="darkorange1")

plot(rawdata2[phasechauffe:length(rawdata2[,1]),2],type='l',main="Rate post 1500",ylab="Rate",lwd=size,col="goldenrod1")
lines(rawdata3[phasechauffe:length(rawdata3[,1]),2],type='l',lwd=size,col="firebrick1")
lines(rawdata4[phasechauffe:length(rawdata3[,1]),2],type='l',lwd=size,col="royalblue2")
lines(rawdata5[phasechauffe:length(rawdata3[,1]),2],type='l',lwd=size,col="seagreen")


thin10 = (1:(length(rawdata2[,1])/10-150))*10+1500

par(mfrow=c(1,1))
acf(rawdata2[phasechauffe:length(rawdata2[,2]),2],main="Autocorrelation de la chaîne 1")
acf(rawdata2[thin10,2],main="Autocorrelation avec thin = 10")
