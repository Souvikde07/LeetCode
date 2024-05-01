/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {number}
 */

var pathSum = function(root, targetSum) {
    let result = 0
    const dfs = (node,targetSum, currSum, map) => {
        if(node == null) return;
        currSum += node.val
        if(currSum == targetSum) result ++
        if(map.has(currSum - targetSum)){
            result += map.get(currSum - targetSum)
        }
        map.set(currSum,(map.get(currSum)||0)+1)
        dfs(node.left, targetSum, currSum, map)
        dfs(node.right, targetSum, currSum, map)
        map.set(currSum, map.get(currSum)-1)
    }
    const map = new Map()
    dfs(root,targetSum, 0 , map)
    return result
};