# push_swap_42
https://drive.google.com/file/d/1R-fAMy3LZvIgGA1jwhfDMlNTtIZxstga/view
<img width="1175" alt="pushswap" src="https://user-images.githubusercontent.com/82111543/218945459-8b5ccaf1-df83-465c-a27c-ae29d05a1295.png">
<img width="1365" alt="Screen Shot 2023-02-24 at 1 04 18 PM" src="https://user-images.githubusercontent.com/82111543/221137485-59a9dba9-ae7c-450b-a554-59291b451073.png">

In this project we had to code a sorting algorithm using two stacks and following these rules:
• You have 2 stacks named a and b. 
• At the beginning: ◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated. ◦ The stack b is empty. 
• The goal is to sort in ascending order numbers into stack a in the minimum number of steps. To do so you have the following operations at your disposal: 
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. 
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. ss : sa and sb at the same time. 
pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. 
pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. 
ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one. rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one. rr : ra and rb at the same time. 
rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
 rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one. 
rrr : rra and rrb at the same time.
I used a doubly linked list to represent my stacks. I indexed all the numbers and then sorted them using the index in chunks and then sorted the chunks so I wouldn't have to go through the whole stack each time to reduce the number of moves. You can see the output for six randomly generated numbers in the image and visualise the sorting as it happens in the video.


https://user-images.githubusercontent.com/82111543/221154695-abe951dd-f387-4e98-8ffc-ebcad3d7235d.mov

