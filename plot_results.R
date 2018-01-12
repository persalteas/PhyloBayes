setwd("/home/persalteas/Cours et tutoriels/INSA Cours-TP/5BIM/Stats Bayésiennes/insaphylo")

chauffe = 5000
filename = "ch1"
d = read.table(paste(filename,".trace", sep= ""), h=T)
par(mfrow=c(2,1))
plot(d$rate[chauffe:length(d$rate)], type = 'l', xlab = "iterations", ylab = "rate u")
plot(d$lnL[chauffe:length(d$lnL)], type = 'l', xlab = "iterations", ylab = "logLikelihood", col = 2)


rawdata = read.table(file="ch1.distH",header = F)
distH = as.numeric(as.vector(rawdata$V1))
ageAncetre = (1/distH)*6
hist(ageAncetre,breaks=20,col="darkorange1",main="Age estime de l'ancetre commun")

