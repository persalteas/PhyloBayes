def getGoodChar(s):
	news = ""
	for i in s:
		if i in "()AZERTYUIOOPQSDFGHJKLLMWXCVBoN":
			news+=i
	return news

f = open("ch1.treelist","r")
lignes = f.readlines()
f.close()

newtab = []

for i in range(8000,len(lignes)):
	s = ""
	l = lignes[i].split('_')
	for k in range(len(l)):
		s+=getGoodChar(l[k])
	valH = ""
	valP = ""
	if "PHoo" in s:
		valH = lignes[i].split("Homo_sapiens:")[1][0:8]
		valP = lignes[i].split("Pan_paniscus:")[1][0:8]
		newtab.append(valH+"\n")

f = open("ch1.distH","w")
f.writelines(newtab)
f.close()	
