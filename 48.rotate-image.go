/*
 * @lc app=leetcode id=48 lang=golang
 *
 * [48] Rotate Image
 */

// @lc code=start
package leetcode
func rotate(matrix [][]int)  {
    var rows int = len(matrix)

	///Transpose the matrix

	for i := 0 ; i < rows ; i++ {
		for j := i +1 ; j < rows ; j++{
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}

	/// reverser each row

	for i := 0 ; i < rows ; i++ {
		for j := 0 ; j < rows/2 ; j++{
			matrix[i][j], matrix[i][rows-1-j] = matrix[i][rows-1-j], matrix[i][j]
		}
	}



}
// @lc code=end

