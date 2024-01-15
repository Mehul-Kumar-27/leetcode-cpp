/*
 * @lc app=leetcode id=26 lang=golang
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	n := len(nums)

    // Handle edge case
    if n == 0 {
        return 0
    }

    count := 1 // At least one unique element
    for i := 1; i < n; i++ {
        if nums[i] != nums[i-1] {
            nums[count] = nums[i]
            count++
        }
    }

    return count
}
// @lc code=end

