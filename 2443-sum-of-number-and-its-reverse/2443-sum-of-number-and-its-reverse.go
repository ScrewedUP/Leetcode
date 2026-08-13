func sumOfNumberAndReverse(num int) bool {

    for i := 0; i <= num; i++ {
        s := []byte(strconv.Itoa(i))

        slices.Reverse(s)

        reversed, _ := strconv.Atoi(string(s))

        if i+reversed == num {
            return true
        }
    }

    return false
}