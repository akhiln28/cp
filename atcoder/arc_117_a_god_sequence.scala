/*
    Need to build a sequence of a positive integers and b negative integers such all integers are distinct and sum of all the integers is zero.
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