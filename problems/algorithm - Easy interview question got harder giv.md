---
Created Time: Dec 19, 2020 10:37 PM
Last edited time: Feb 18, 2021 7:45 AM
Source: https://stackoverflow.com/questions/3492302/easy-interview-question-got-harder-given-numbers-1-100-find-the-missing-numbe
Status: waiting
---

# algorithm - Easy interview question got harder: given numbers 1..100, find the missing number(s) given exactly k are missing - Stack Overflow

![apple-touch-icon@2.png](algorithm%20-%20Easy%20interview%20question%20got%20harder%20giv%20571f36d9d0bf4f63857c1a0b239604ff/apple-touch-icon2.png)
I had an interesting job interview experience a while back. The question started really easy:
> Q1: We have a bag containing numbers 1, 2, 3, …, 100. Each number appears exactly once, so there are 100 numbers. Now one number is randomly picked out of the bag. Find the missing number.
I've heard this interview question before, of course, so I very quickly answered along the lines of:
> A1: Well, the sum of the numbers 1 + 2 + 3 + … + N is (N+1)(N/2) (see Wikipedia: sum of arithmetic series). For N = 100, the sum is 5050. Thus, if all numbers are present in the bag, the sum will be exactly 5050. Since one number is missing, the sum will be less than this, and the difference is that number. So we can find that missing number in O(N) time and O(1) space.
At this point I thought I had done well, but all of a sudden the question took an unexpected turn:
> Q2: That is correct, but now how would you do this if TWO numbers are missing?
I had never seen/heard/considered this variation before, so I panicked and couldn't answer the question. The interviewer insisted on knowing my thought process, so I mentioned that perhaps we can get more information by comparing against the expected product, or perhaps doing a second pass after having gathered some information from the first pass, etc, but I really was just shooting in the dark rather than actually having a clear path to the solution.
The interviewer did try to encourage me by saying that having a second equation is indeed one way to solve the problem. At this point I was kind of upset (for not knowing the answer before hand), and asked if this is a general (read: "useful") programming technique, or if it's just a trick/gotcha answer.
The interviewer's answer surprised me: you can generalize the technique to find 3 missing numbers. In fact, you can generalize it to find *k* missing numbers.
> Qk: If exactly k numbers are missing from the bag, how would you find it efficiently?
This was a few months ago, and I still couldn't figure out what this technique is. Obviously there's a `Ω(N)` time lower bound since we must scan all the numbers at least once, but the interviewer insisted that the *TIME* and *SPACE* complexity of the solving technique (minus the `O(N)` time input scan) is defined in *k* not *N*.
So the question here is simple:
- How would you solve **Q2**?
- How would you solve **Q3**?
- How would you solve **Qk**?
### Clarifications
- Generally there are *N* numbers from 1..*N*, not just 1..100.
- I'm not looking for the obvious set-based solution, e.g. using a [bit set](http://en.wikipedia.org/wiki/Bit_array), encoding the presence/absence each number by the value of a designated bit, therefore using `O(N)` bits in additional space. We can't afford any additional space proportional to *N*.
- I'm also not looking for the obvious sort-first approach. This and the set-based approach are worth mentioning in an interview (they are easy to implement, and depending on *N*, can be very practical). I'm looking for the Holy Grail solution (which may or may not be practical to implement, but has the desired asymptotic characteristics nevertheless).
So again, of course you must scan the input in `O(N)`, but you can only capture small amount of information (defined in terms of *k* not *N*), and must then find the *k* missing numbers somehow.
Patterns: 