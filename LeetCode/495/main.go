package main

func findPoisonedDuration(timeSeries []int, duration int) int {
	var ret int
	var p int
	n := len(timeSeries)

	for i := 0; i < n; i++ {
		if timeSeries[i] > p {
			p = timeSeries[i] + duration
			ret += duration
		} else if timeSeries[i]+duration > p {
			ret += (timeSeries[i] + duration - p)
			p = timeSeries[i] + duration
		}
	}

	return ret
}
