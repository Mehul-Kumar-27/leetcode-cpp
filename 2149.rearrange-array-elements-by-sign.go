/*
 * @lc app=leetcode id=2149 lang=golang
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
func rearrangeArray(nums []int) []int {
    var n int = len(nums)
	var ans []int = make([]int, n)
	var positiveIndex int = 0
	var negativeIndex int = 1

	for i := 0 ; i < n ; i++{
	if nums[i] > 0  {
		ans[positiveIndex] = nums[i]
		positiveIndex += 2
	}else{
		ans[negativeIndex] = nums[i]
		negativeIndex += 2
	}
}

	return ans
}
// @lc code=end

