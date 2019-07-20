package L


class L1108kotlin {
    fun defangIPaddr(address: String): String {
        val split = address.split("\\.".toRegex()).dropLastWhile { it.isEmpty() }.toTypedArray()
        val answer = StringBuilder()

        for (i in split.indices) {
            answer.append(split[i])
            if (split.size - 1 != i) {
                answer.append("[.]")
            }
        }
        return answer.toString()
    }

}
