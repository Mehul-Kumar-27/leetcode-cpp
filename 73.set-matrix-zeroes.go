/*
 * @lc app=leetcode id=73 lang=golang
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start

package leetcode
func setZeroes(matrix [][]int)  {
    var row int = len(matrix)
	var col int = len(matrix[0])

	var r = make([]int, row)
	var c = make([]int, col)

	for i := 0 ; i < row; i++{
		for j := 0; j < col; j++{
			if matrix[i][j] == 0{
				r[i] = 1
				c[j] = 1
			}
		}
	}

	for i := 0 ; i < row; i++{
		for j := 0; j < col; j++{
			if r[i] == 1 || c[j] == 1{
				matrix[i][j] = 0
			}
		}
	}

}
// @lc code=end

