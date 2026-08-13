func twoSum(nums []int, target int) []int {
    
    mp := make(map[int]int)

    for i := 0 ; i < len(nums) ; i++ {
        need := target - nums[i]

        if index,exists := mp[need];exists{
            return []int{index,i};
        }

        mp[nums[i]] = i
    }

    return []int{};
}