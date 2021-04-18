function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */


var lowestCommonAncestor = function(root, p, q) {
    var result = null
    var solve = function (cur) {
        if (cur == null || result != null) return 0
        var count = 0
        if (cur.val == p || cur.val == q) {
            count += 1;
        }
        count += solve(cur.left);
        count += solve(cur.right);
        if (count == 2 && result == null)
            result = cur;
        return count;
    }
    solve(root);
    return result;
};

// 构造树
function buildTree(nums, idx) {
    var v = nums.shift();
    if (v == null || v == undefined) return null;

    var node = new TreeNode(v);
    node.left = buildTree(nums);
    node.right = buildTree(nums);
    return node;
}

var t = [1, 2, 4, 6, null, null, null, 5, 7, 8, null, null, 9, null, null, null, 3, null, null];
var tree = buildTree(t);

var node = lowestCommonAncestor(tree, 6, 5);
console.log(node.val)
