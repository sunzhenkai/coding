package code

func twoSum(nums []int, target int) []int {
	record := map[int]int{}
	for p, v := range nums {
		remain := target - v
		if i, ok := record[remain]; ok {
			return []int{i, p}
		} else {
			record[v] = p
		}
	}
	return nil
}
