# A - God Sequence

Created Time: Apr 20, 2021 8:30 AM
Day Completed: https://www.notion.so/21-April-21-5356657b3a114ca1806b086f4b095f3d
Last edited time: Apr 20, 2021 8:32 AM
Points: 1000
Source: https://atcoder.jp/contests/arc117/tasks/arc117_a
Status: done

![atcoder.png](problems/A%20-%20God%20Sequence%20bbe3246425c348a0b5cd32262800feae/atcoder.png)

### Problem Statement

Construct one god sequence.

We can prove that at least one god sequence exists under Constraints of this problem.

### Output

Print the elements of your sequence in one line, with space as separator.

If there are multiple god sequences, any of them will be accepted.

It also satisfies the other conditions and thus is a god sequence.

A sequence (−8,−6,−9,120,−97) contains A=1 positive integer and B=4 negative integers totaling (−8)+(−6)+(−9)+120+(−97)=0.

It also satisfies the other conditions and thus is a god sequence.

---

```scala
/*
    Need to build a sequence of a positive integers and b negative integers 
		such all integers are distinct and sum of all the integers is zero.
*/
object Main extends App {
    var input = scala.io.StdIn.readLine()
    var arr = input.split(" ")
    val a = arr(0).toInt
    val b = arr(1).toInt
    if (a <= b) {
        val alist = 1 to a - 1
        val blist = -b to -1
        val remaining = (b * (b + 1))/2 - (a * (a - 1))/2
        println((alist ++ blist :+ remaining).mkString(" "))
    }
    else {
        val alist = 1 to a
        val blist = -(b - 1) to -1
        val remaining = (a * (a + 1))/2 - (b * (b - 1))/2
        println((alist ++ blist :+ -remaining).mkString(" "))
    }
}
```