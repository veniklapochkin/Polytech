avg <- function(selection) 
  sum(selection)/length(selection)

med <- function(some_selection) {
  selection <- sort(some_selection)
  len <- length(selection)
  if (len %% 2 != 0)
    selection[len/2 + 0.5]
  else
    (selection[len/2] + selection[len/2 + 1])/2
}

sets <- c(20,40,60,80,100,200,300,400,500,600,700,800,900,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000)
n <- rnorm(10000,1,1)
c <- rcauchy(10000,1,1)
medn <- c()
medc <- c()
avgn <- c()
avgc <- c()

for (i in 1:length(sets)) {
  medn <- c(medn, med(n[1:sets[i]]))
  medc <- c(medc, med(c[1:sets[i]]))
  avgn <- c(avgn, avg(n[1:sets[i]]))
  avgc <- c(avgc, avg(c[1:sets[i]]))
}


plot(log(sets), medn, xlab="ln(n)", ylab="med")
plot(log(sets), medc, xlab="ln(n)", ylab="med")
plot(log(sets), avgn, xlab="ln(n)", ylab="avg",ylim = c(0.8,1.5))
plot(log(sets), avgc, xlab="ln(n)", ylab="avg",ylim = c(0.8,1.5))

