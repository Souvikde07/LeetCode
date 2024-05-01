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
 * @return {number}
 */
var goodNodes = function(root) {
    let count = 1
    const countGoodNode = (node,maxVal) => {
        if (!node) return
        if (node.val>=maxVal) count ++
        countGoodNode(node.left,Math.max(maxVal,node.val))
        countGoodNode(node.right,Math.max(maxVal,node.val))
    }
    countGoodNode(root.left,root.val)
    countGoodNode(root.right,root.val)
    return count
};