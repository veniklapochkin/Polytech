library(mvtnorm)

sgn <- function(z) {
  result <- 1
  if (z < 0) result <- -1
  result
}

avg <- function(selection) {
  result <- 0
  for (i in 1:length(selection)) {
    result <- result + selection[i]	
  }
  result <- result/length(selection)
  result
}

med <- function(selection) {
  len <- length(selection)
  if (len %% 2 != 0)
    result <- selection[len/2 + 0.5]
  else
    result <- (selection[len/2] + selection[len/2 + 1])/2
  result 
}

ranks <- function (selection, sort_selection) {
  result <- 0
  temp <- sort_selection
  for (i in 1:length(selection)) {
    for (j in 1:length(temp)) {
      if (selection[i] == temp[j]) {
        result[i] <- j
        temp[j] <- Inf
        break
      }
    }
  }
  result
}

r <- function (x, y, n) {
  avgx <- avg(x)
  avgy <- avg(y)
  Sx <- 0
  Sy <- 0
  sum <- 0
  for (i in 1:n) {
    delx <- x[i] - avgx
    dely <- y[i] - avgy
    Sx <- Sx + delx*delx
    Sy <- Sy + dely*dely
    sum <- sum + delx*dely
  }
  Sx <- sqrt(Sx/n)
  Sy <- sqrt(Sy/n)
  result <-sum/(n*Sx*Sy)
  result
}

rs <- function(rx, ry, n) {
  medrx <- med(rx)
  medry <- med(ry)	
  sum <- 0
  sumrx <- 0
  sumry <- 0 
  for (i in 1:n) {
    delrx <- rx[i] - medrx
    delry <- ry[i] - medry
    sum <- sum + delrx*delry
    sumrx <- sumrx + delrx*delrx 
    sumry <- sumry + delry*delry
  }
  result <- sum/sqrt(n*sumrx*sumry)
  result
}

rq <- function (x, y, n) {
  medx <- med(x)
  medy <- med(y)
  sum <- 0
  for (i in 1:n) {
    sum <- sum + sgn(x[i] - medx)*sgn(y[i] - medy)
  }
  result <- sum/n
  result
}

#??????????????????
n_20_0 <- rmvnorm(20, c(0,0), matrix(c(1,0,0,1),2,2))
n_20_05 <- rmvnorm(20, c(0,0), matrix(c(1,0.5,0.5,1),2,2))
n_20_09 <- rmvnorm(20, c(0,0), matrix(c(1,0.9,0.9,1),2,2))
n_100_0 <- rmvnorm(100, c(0,0), matrix(c(1,0,0,1),2,2))
n_100_05 <- rmvnorm(100, c(0,0), matrix(c(1,0.5,0.5,1),2,2))
n_100_09 <- rmvnorm(100, c(0,0), matrix(c(1,0.9,0.9,1),2,2))
#????????????????????
badn_22_09 <- matrix(c(n_20_09 [,1],10,-10,n_20_09 [,2],-10,10),22,2)


#???????????????????? ???????????????????????????? ???????????????????????? ??????????
sn_20_0_sx <- sort(n_20_0[,1])
sn_20_0_sy <- sort(n_20_0[,2])

sn_20_05_sx <- sort(n_20_05[,1])
sn_20_05_sy <- sort(n_20_05[,2])

sn_20_09_sx <- sort(n_20_09[,1])
sn_20_09_sy <- sort(n_20_09[,2])

sn_100_0_sx <- sort(n_100_0[,1])
sn_100_0_sy <- sort(n_100_0[,2])

sn_100_05_sx <- sort(n_100_05[,1])
sn_100_05_sy <- sort(n_100_05[,2])

sn_100_09_sx <- sort(n_100_09[,1])
sn_100_09_sy <- sort(n_100_09[,2])

badsn_22_09_sx <- sort(badn_22_09[,1])
badsn_22_09_sy <- sort(badn_22_09[,2])

#???????????????????? ????????????
n_20_0_rx <- ranks(n_20_0[,1], sn_20_0_sx)
n_20_0_ry <- ranks(n_20_0[,2], sn_20_0_sy)

n_20_05_rx <- ranks(n_20_05[,1], sn_20_05_sx)
n_20_05_ry <- ranks(n_20_05[,2], sn_20_05_sy)

n_20_09_rx <- ranks(n_20_09[,1], sn_20_09_sx)
n_20_09_ry <- ranks(n_20_09[,2], sn_20_09_sy)

n_100_0_rx <- ranks(n_100_0[,1], sn_100_0_sx)
n_100_0_ry <- ranks(n_100_0[,2], sn_100_0_sy)

n_100_05_rx <- ranks(n_100_05[,1], sn_100_05_sx)
n_100_05_ry <- ranks(n_100_05[,2], sn_100_05_sy)

n_100_09_rx <- ranks(n_100_09[,1], sn_100_09_sx)
n_100_09_ry <- ranks(n_100_09[,2], sn_100_09_sy)

badn_22_09_rx <- ranks(badn_22_09[,1], badsn_22_09_sx)
badn_22_09_ry <- ranks(badn_22_09[,2], badsn_22_09_sy)

#???????????????????? ?????????????????????????? ????????????????????
r_20_0 = r(n_20_0[,1], n_20_0[,2], length(n_20_0[,1]))
r_20_05 = r(n_20_05[,1], n_20_05[,2], length(n_20_05[,1]))
r_20_09 = r(n_20_09[,1], n_20_09[,2], length(n_20_09[,1]))
r_100_0 = r(n_100_0[,1], n_100_0[,2], length(n_100_0[,1]))
r_100_05 = r(n_100_05[,1], n_100_05[,2], length(n_100_05[,1]))
r_100_09 = r(n_100_09[,1], n_100_09[,2], length(n_100_09[,1]))

rs_20_0 = rs(n_20_0_rx, n_20_0_ry, length(n_20_0_rx))
rs_20_05 = rs(n_20_05_rx, n_20_05_ry, length(n_20_05_rx))
rs_20_09 = rs(n_20_09_rx, n_20_09_ry, length(n_20_09_rx))
rs_100_0 = rs(n_100_0_rx, n_100_0_ry, length(n_100_0_rx))
rs_100_05 = rs(n_100_05_rx, n_100_05_ry, length(n_100_05_rx))
rs_100_09 = rs(n_100_09_rx, n_100_09_ry, length(n_100_09_rx))

rq_20_0 = rq(n_20_0[,1], n_20_0[,2], length(n_20_0[,1]))
rq_20_05 = rq(n_20_05[,1], n_20_05[,2], length(n_20_05[,1]))
rq_20_09 = rq(n_20_09[,1], n_20_09[,2], length(n_20_09[,1]))
rq_100_0 = rq(n_100_0[,1], n_100_0[,2], length(n_100_0[,1]))
rq_100_05 = rq(n_100_05[,1], n_100_05[,2], length(n_100_05[,1]))
rq_100_09 = rq(n_100_09[,1], n_100_09[,2], length(n_100_09[,1]))

r_22_09 = r(badn_22_09[,1], badn_22_09[,2], length(badn_22_09[,1]))
rs_22_09 = rs(badn_22_09_rx, badn_22_09_ry, length(badn_22_09_rx))
rq_22_09 = rq(badn_22_09[,1], badn_22_09[,2], length(badn_22_09[,1]))

#??????????????????
plot(n_20_0)
plot(n_20_05)
plot(n_20_09)
plot(n_100_0)
plot(n_100_05)
plot(n_100_09)

#???????????????????? 
r_20_0
rs_20_0
rq_20_0

r_20_05
rs_20_05
rq_20_05

r_20_09
rs_20_09
rq_20_09

r_100_0
rs_100_0
rq_100_0

r_100_05
rs_100_05
rq_100_05

r_100_09
rs_100_09
rq_100_09

r_22_09
rs_22_09
rq_22_09
