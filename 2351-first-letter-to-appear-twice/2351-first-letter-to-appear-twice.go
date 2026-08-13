func repeatedCharacter(s string) byte {
    m := make(map[byte]int)

    for i := 0 ; i < len(s) ; i++{

        _,found := m[s[i]]

        if found{
            return s[i];
        }

        m[s[i]]++;
    }

    return 0;
}