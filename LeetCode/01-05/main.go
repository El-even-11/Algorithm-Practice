package main

func oneEditAway(first string, second string) bool {
	if len(first)-len(second) >= 2 || len(first)-len(second) <= -2 {
		return false
	}

	if len(first) == len(second) {
		flag := false
		for i := 0; i < len(first); i++ {
			if flag && first[i] != second[i] {
				return false
			}
			if first[i] != second[i] {
				flag = true
			}
		}

		return true
	}

	oneEdit := func(shorter, longer []byte) bool {
		flag := false
		for i := 0; i < len(shorter); i++ {
			if flag && shorter[i] != longer[i] {
				return false
			}
			if shorter[i] != longer[i] {
				longer = append(longer[:i], longer[i+1:]...)
				flag = true
				i--
			}
		}

		return true
	}

	if len(first) < len(second) {
		return oneEdit([]byte(first), []byte(second))
	}

	return oneEdit([]byte(second), []byte(first))
}
