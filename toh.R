data <- c(82, 78, 89,84,74,91,80,77)
binom.test(sum(data>85),length(data),alternative = "less")


data <- c(-1, 2, -3, 4, -5, 6, -7, 8)
binom_test_result <- binom.test(sum(data > 0), length(data), p=0.5,
                                 alternative="greater")
print(binom_test_result)


vec <- c(21,14,6,18,16,8,16,17,15,12,14,21,6,6,10)
mat <- matrix(vec,byrow=T,nrow=5)
mat
colnames(mat)<-c('Third','Second','First')
mat
chisq.test(mat)


b<- c(8,6,3.5,9.5,10,8,9,7)
a<- c(6.5,5,5.5,4,6.5,3.5,5,10)
wilcox.test(b,a,paired=T)


x = data.frame(A=c(50,62,75,48,65),
               B=c(80, 95, 98, 87, 90),
               C=c(60,45,30,58,57))
x
kruskal.test(x)


x<- data.frame(d1<-c(4,6,3,4,3,2,2,7,6,5),
               d2<-c(5,6,8,7,7,8,4,6,4,5),
               d3<-c(2,4,4,3,2,2,1,4,3,2))
friedman.test(as.matrix(x))
y<-c(4,6,3,4,3,2,2,7,6,5,5,6,8,7,7,8,4,6,4,5,2,4,4,3,2,2,1,4,3,2)
groups <- c(rep("d1",10),rep("d2",10),rep("d3",10))
friedman.test(y,groups)


metro <- rep(c(1,2,3),each =10)
metro<-as.factor(metro)
vol <- c(15,13.5,14.2,13,15,11,12.5,16,14.25,13.5,8,8.25,6.4,7.2,4.4,11.3,7.8,8.1,9,6.8,14.6,16.5,13.2,13.6,21,11.7,12.3,17,14.75,18)
summary(aov(vol~metro))

obs <- c(8,7,6,10,7,8,6,8,10,7,9,6,9,8,4,0,5,5,0,0,7)
groups<-rep(c("A","B","C"),times=7)
groups<-as.factor(groups)
summary(aov(obs~groups))


X=matrix(c(32513 ,18 ,5,
27897 ,20 ,7,
29928, 22, 8,
20159, 23, 6,
21554, 23, 7,
28466, 25, 5,
27842, 2, 8,
22671, 28, 6,
32214, 29, 5,
34550, 32, 7,
20920, 37, 9,
33714, 41, 6,
26998, 46, 7,
34294, 49, 8,
21912, 53, 6),nrow=15,byrow=T)
y = X[,1]
x1 = X[,2]
x2 = X[,3]
m=lm(y~x1+x2)
summary(m)
