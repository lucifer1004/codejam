fun main() {
    val t = readLine()!!.toInt()
    for (i in 1 until t + 1) {
        val (n, b, _) = readLine()!!.split(" ").map(String::toInt)
        val query = Array(4) { IntArray(n) { 0 } }
        for (q in 0 until 4)
            for (j in 0 until n) {
                query[q][j] = if (j and (1 shl q) > 0) 1 else 0;
            }

        val result = IntArray(n - b) { 0 }
        for (q in 0 until 4) {
            val queryString = query[q].joinToString("")
            println(queryString)
            val resultString = readLine()!!.trim().toCharArray()
            for (j in 0 until n - b)
                result[j] += if (resultString[j] == '0') 0 else (1 shl q)
        }

        var loop = 0
        val occur = BooleanArray(n)
        for (j in 0 until n - b) {
            occur[loop * 16 + result[j]] = true
            if (j < n - b - 1 && result[j] >= result[j + 1])
                loop++
        }

        val judge = mutableListOf<Int>()
        for (j in 0 until n) {
            if (!occur[j])
                judge.add(j)
        }
        println(judge.joinToString(" "))
    }
}