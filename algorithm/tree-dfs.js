function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

function dfs(root) {
    if (root == null) return;

    process.stdout.write(root.val + ' ');
    dfs(root.left);
    dfs(root.right);
}

function bfs(root) {
    var nodes = [root];
    while (nodes.length != 0) {
        var cur = nodes.shift()
        process.stdout.write(cur.val + ' ');
        if (cur.left != null) nodes.push(cur.left);
        if (cur.right != null) nodes.push(cur.right);
    }
}

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
dfs(tree);
console.log();
bfs(tree);
console.log();
