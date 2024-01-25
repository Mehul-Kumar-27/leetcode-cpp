/*
 * @lc app=leetcode id=229 lang=golang
 *
 * [229] Majority Element II
 */

// @lc code=start
func majorityElement(nums []int) []int {
    var el1 int = 0;
	var el2 int = 0;

	var cnt1 int = 0;
	var cnt2 int = 0;


	for _, v := range nums {
		if(cnt1 == 0 && v != el2){
			el1 = v
			cnt1++
		}else if(cnt2 == 0 && v != el1){
			el2 = v
			cnt2++
		}else if(v == el1){
			cnt1++
		}else if(v == el2){
			cnt2++
		}else{
			cnt1--
			cnt2--
		}
	}

	cnt1 = 0
	cnt2 = 0

	for _, v := range nums {
		if(v == el1){
			cnt1++
		}else if(v == el2){
			cnt2++
		}
	}

	var ans []int

	var threshold = len(nums)/3+1;
	if(cnt1 >= threshold){
		ans = append(ans, el1)
	}
	if(cnt2 >= threshold){
		ans = append(ans, el2)
	}

	//sort the ans
	sort.Ints(ans)

	return ans
}
// @lc code=end

