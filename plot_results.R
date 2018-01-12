setwd("/home/persalteas/Cours et tutoriels/INSA Cours-TP/5BIM/Stats Bayésiennes/insaphylo")

chauffe = 5000
filename = "ch1"
d = read.table(paste(filename,".trace", sep= ""), h=T)
par(mfrow=c(2,1))
plot(d$rate[chauffe:length(d$rate)], type = 'l', xlab = "iterations", ylab = "rate u")
plot(d$lnL[chauffe:length(d$lnL)], type = 'l', xlab = "iterations", ylab = "logLikelihood", col = 2)
