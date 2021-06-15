object solution extends App {
    val nums = scala.io.StdIn.readLine().split(" ").map(_.toInt)
    val n = min(nums.length, 8)


    val power_n = 1 << n
    for (i <- 1 to power_n) {

        for (j <- 0 to n - 1) {
            if (i & (1 << j)) {

            }
        }
    }
}