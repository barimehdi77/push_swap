# 🤔 Description
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.


# 🔁 push_swap

The **push_swap** project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

This project contains 2 programs:
- The first, named **checker**, which takes integer arguments and reads instructions on the standard output. Once read,checker executes them and displays `OK` if integers are sorted. Otherwise, it will display `KO`.
- The second one called **push_swap** which calculates and displays on the standard output the smallest progam using *push_swap instruction language* that sorts inte-ger arguments received.

## 🧰 push_swap instructions

- **sa**: *swap a* - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb**: *swap b* - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss**: sa and sb at the same time.
- **pa**: *push a* - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb**: *push b* - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra**: *rotate a* - shift up all elements of stack a by 1. The first element becomes the last one.
- **rb**: *rotate b* - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr**: ra and rb at the same time.
- **rra**: *reverse rotate a* - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb**: *reverse rotate b* - shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr**: rra and rrb at the same time.

## ⚙️ Compilation

Compile checker: `make checker`

Compile push_swap: `make push_swap`

Compile both: `make`

## 🔑 Execute

checker: `./checker 0 2 3 1` then program's waiting for user input

![checker](https://github.com/barimehdi77/push_swap/blob/main/images/checker.png)

push_swap: `./push_swap 0 2 3 1`

![push_swap](https://github.com/barimehdi77/push_swap/blob/main/images/push_swap.png)

to execute push_swap and checker: `./push_swap 7 6 5 4 3 2 1 | ./checker 7 6 5 4 3 2 1`

![push_swap and checker](https://github.com/barimehdi77/push_swap/blob/main/images/push_swap_checker.png)

## 👨‍💻 Tester

There is a bash script named `script.bash` that generate a random array of size n then test `push_swap | checker` till `the number of instructions >= [number of max instructions]` or any error happened, then the script stops and shows you the numbers when the error happened.

```
./script.bash [how many number] [number of max instructions]
```

![script image](https://github.com/barimehdi77/push_swap/blob/main/images/script.png)
