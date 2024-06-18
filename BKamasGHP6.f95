program ghpsix
!Written by Betsy Kamas
!For CS431 GHP6
!Written in Fortran95
!This program was written in order to calculate basic mathmatical functions on a user defined
!list of up to 30 numbers
implicit none

integer len,i,min,max,r
integer,dimension(30) :: nums ! To hold user defined input
real,dimension(30) :: vnums ! To hold the deviation calculation numbers
real arthmn,var,dev,tot,k,total

! Getting length
print*,"Enter integer <= 30 for length of list"
read*,len

! Getting values
print*,"Enter integers:"
do i=1,len
  read*,k
  nums(i)=k
enddo

! Setting base values
min = nums(1)
max=nums(1)
total = 0
tot = 0

! Comparing all nums to first in order to find smallest
do i=1,len
  if(nums(i)<min) then
    min=nums(i)
  endif
enddo  

! Comparing all nums to first in order to find largest
do i=1,len
  if(nums(i)>max) then
    max=nums(i)
  endif
enddo

! Finding Range
r = (max-min)

! Calculating sum of list for the mean
do i=1,len
  total = total + nums(i)
enddo

! Finding aorthmetic mean
arthmn = (total / len)

!Calclating values by comparison to the mean in order to calculate the variance
do i = 1,len
  vnums(i) = nums(i)-arthmn
  vnums(i) = vnums(i)*vnums(i)
  tot = tot + vnums(i)
enddo

var = tot / (len-1) ! finish calculating variance

! squareroot variance to find standard deviation
dev = SQRT(var)   

! Print results
print*,"Total integers:",len
print*,"Minimum:",min
print*,"Maximum:",max
print*,"Range:",r
print*,"Arithmetic Mean:",arthmn
print*,"Variance:",var
print*,"Standard Deviation:",dev
    
end program