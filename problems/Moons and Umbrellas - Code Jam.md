---
Created Time: Mar 29, 2021 8:41 AM
Last edited time: May 23, 2021 8:53 AM
Source: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1145
Status: waiting
---

# Moons and Umbrellas - Code Jam

### Problem
Cody-Jamal is working on his latest piece of abstract art: a mural consisting of a row of waning moons and closed umbrellas. Unfortunately, greedy copyright trolls are claiming that waning moons look like an uppercase C and closed umbrellas look like a J, and they have a copyright on CJ and JC. Therefore, for each time CJ appears in the mural, Cody-Jamal must pay , and for each time JC appears in the mural, he must pay .
![Moons%20and%20Umbrellas%20-%20Code%20Jam%204ab955cf56e34f81ad15b4e68b25f2e0/moons_and_umbrellas.png](Moons%20and%20Umbrellas%20-%20Code%20Jam%204ab955cf56e34f81ad15b4e68b25f2e0/moons_and_umbrellas.png)
Cody-Jamal is unwilling to let them compromise his art, so he will not change anything already painted. He decided, however, that the empty spaces he still has could be filled strategically, to minimize the copyright expenses.
For example, if `CJ?CC?` represents the current state of the mural, with `C` representing a waning moon, `J` representing a closed umbrella, and `?` representing a space that still needs to be painted with either a waning moon or a closed umbrella, he could finish the mural as `CJCCCC`, `CJCCCJ`, `CJJCCC`, or `CJJCCJ`. The first and third options would require paying  in copyrights, while the second and fourth would require paying .
Given the costs  and  and a string representing the current state of the mural, how much does Cody-Jamal need to pay in copyrights if he finishes his mural in a way that minimizes that cost?
### Input
The first line of the input gives the number of test cases, .  lines follow. Each line contains two integers  and  and a string  representing the two costs and the current state of the mural, respectively.
### Output
For each test case, output one line containing `Case #:` , where  is the test case number (starting from 1) and  is the minimum cost that Cody-Jamal needs to pay in copyrights for a finished mural.
### Limits
### Test Set 1 (Visible Verdict)
### Test Set 2 (Visible Verdict)
### Extra credit!
What if some copyright holders could pay Cody-Jamal for the advertisement instead of being paid? Cody-Jamal getting paid is represented by a negative cost.
### Test Set 3 (Hidden Verdict)
### Sample
Note: there are additional samples that are not run on submissions down below. 
In Sample Case #2, Cody-Jamal is already finished, so he does not have a choice. There are two `CJ`s and one `JC` in his mural.
In Sample Case #3, substituting either `C` or `J` results in one `CJ` either from the second and third characters or the first and second characters, respectively.
In Sample Case #4, Cody-Jamal can finish his mural with all `J`s. Since that contains no instance of `CJ` nor `JC`, it yields no copyright cost.
### Additional Sample - Test Set 3
The following additional sample fits the limits of Test Set 3. It will not be run against your submitted solutions. 
In Sample Case #1 for Test Set 3, Cody-Jamal can finish his mural optimally as `JCJJCC` or `JCJJJC`. Either way, there is one `CJ` and two `JC`s in his mural.
Patterns: 