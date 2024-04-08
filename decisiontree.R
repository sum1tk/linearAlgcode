library(rpart,quietly = TRUE) 
library(caret,quietly = TRUE) 
library(rpart.plot,quietly = TRUE) 
library(rattle)
library(readr) 
library(caTools) 
library(dplyr) 
library(party) 
library(partykit) 
library(rpart.plot)

dataset <- read.csv("D:/assignments/BigData/archive/Social_Network_Ads.csv") 
dataset <-dataset[3:5]
str(dataset)

# number of rows with missing values 
nrow(dataset) - sum(complete.cases(dataset)) 
table(dataset$Age,dataset$Purchased)
number.perfect.splits <- apply(X=dataset[-1], MARGIN = 2, FUN = function(col){ t <- table(dataset$Purchased,col)
sum(t == 0)
})

# Descending order of perfect splits
order <- order(number.perfect.splits,decreasing = TRUE) 
number.perfect.splits <- number.perfect.splits[order]

# Plot graph 
par(mar=c(10,2,2,2)) 
barplot(number.perfect.splits,main="Number of perfect splits vs feature", xlab="",ylab="Feature",las=2,col="wheat")
#data splicing 
set.seed(123)
train <- sample(1:nrow(dataset),size = ceiling(0.80*nrow(dataset)),replace = FALSE) # training set
d_train <- dataset[train,] 

# test set
d_test <- dataset[-train,]
penalty.matrix <- matrix(c(0,1,10,0), byrow=TRUE, nrow=2) 
tree <- rpart(Purchased~.,data=d_train,parms = list(loss = penalty.matrix), method = "class")
rpart.plot(tree, nn=TRUE)
ctree_ <- ctree(Purchased ~ ., d_train) 
plot(ctree_)
#Testing the model
pred <- predict(object=tree,d_test,type="class") 
pred
predict_model<-predict(ctree_, d_test) 
m_at <- table(d_test$Purchased, pred) 
m_at
ac_Test <- sum(diag(m_at)) / sum(m_at) 
print(paste('Accuracy for test is found to be', ac_Test))
