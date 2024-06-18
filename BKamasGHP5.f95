program ghpfive
!Written by Betsy Kamas
!for GHP5 CS431
!Written in Silverfrost FORTRAN95
!Nov2022
!this program reads in values from a file into a 100 element array
implicit none
dimension nbrs(100) ! hold numbers from file
character(64):: f ! for file name
integer nbrs,i,x,s,len
s=1 !represents starting element
len=100!represents ending element
! Task 1
print*, "Enter filename of file containing 100 integers"
read*, f
OPEN(55, file = f)
! Task 2
do i=1,len
  read(55,*)x
  nbrs(i)=x
  end do
close(55)
print*, 'The integers in the file'
call printit(nbrs,len)
! Task 3
print*, 'Using selection sort:'
call selection(nbrs+0,len)
! Task 4
print*,'Using quicksort'
call quick(nbrs,s+0,len+0)
end program

subroutine selection(nums,length)
!Written by Betsy Kamas
!for GHP5 CS431
!Written in Silverfrost FORTRAN95
!Nov2022

!this sorts an array of 100 elements via selection sort
dimension nums(length)
integer nums,r,p,length

do r=1,length!going through array changing value being checked
  do p=1, length !going through array checking this value against all
   	if(nums(r)<nums(p)) THEN !swapping larger with smaller
      call swap(nums,r,p)
    endif
  end do
end do

call printit(nums,length) !print array

return
end subroutine




recursive subroutine quick(nums,st,en)
!Written by Betsy Kamas
!for GHP5 CS431
!Written in Silverfrost FORTRAN95
!Nov2022

! This subroutine sorts an array using a recursive quicksort when
! the array, starting location, and ending location is passed in
! Based on Algorithm pseudocode on https://www.mygreatlearning.com/blog/quick-sort-algorithm/

integer nums,st,en,pivot,right,left
dimension nums(100)

if(st.lt.en)then ! This checks to make sure it is a valid array search area 
  
  pivot=en ! Setting the pivot number as the last one
  right=en-1 ! This is setting the right most search location
  left=st ! This is setting the left most search location
  
  do
    do ! This starts searching from the left most location
      if(nums(left).ge.nums(pivot)) exit !checking until number is larger than pivot
        left=left+1 ! increasing location to next one
    enddo
    
	if(left.eq.right)exit ! exits when the locations are equal, meaning full search has completed
    
    do ! this starts searching from the right most location
      if(nums(right).le.nums(pivot))exit !checking until number is smaller than pivot
        right=right-1 ! Decreasing location to the next one
    enddo

    if(left.ge.right)exit ! making sure search does not pass mid-point
    call swap(nums,left+0,right+0) ! swapping elements
    left=left+1 ! moving locations accordingly 
    right=right-1
  enddo
  
  !print*,'swapping',nums(left),nums(pivot)
  !placing pivot into place
  call swap(nums,left+0,pivot+0) ! Swaps the pivot into place
  
  if(st.lt.right)then ! calling quick again for the numbers to the left of the pivot
    call quick(nums,st+0,left-1)
    endif
    
  if(left.lt.en)then ! calling quick again for numbers to the right of the pivot
    call quick(nums,left+1,en+0)
  endif  
  
endif

if((st.eq.1).and.(en.eq.100))then !verifying that only the original call will display the results of the sort
  call printit(nums,en)
  endif

return
end

subroutine swap(nums,x,y)
!Written by Betsy Kamas
!for GHP5 CS431
!Written in Silverfrost FORTRAN95
!Nov2022

! This swaps two elements in an array
  
dimension nums(100)
integer nums,x,y,temp

temp=nums(x) ! assigning temp value so accessible after overwritten
nums(x)=nums(y) ! overwritting value
nums(y)=temp ! Setting location with temp value

return
end subroutine  

subroutine printit(nums,length)
!Written by Betsy Kamas
!for GHP5 CS431
!Written in Silverfrost FORTRAN95
!Nov2022

!this prints out an array of size length
integer nums,x
dimension nums(length)

do x=1,length !printing array
  	print*, nums(x)
end do

return
end subroutine
