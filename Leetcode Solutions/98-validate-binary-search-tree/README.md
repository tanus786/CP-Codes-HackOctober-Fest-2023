<h2><a href="https://leetcode.com/problems/validate-binary-search-tree/">98. Validate Binary Search Tree</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">Given the <code style="user-select: auto;">root</code> of a binary tree, <em style="user-select: auto;">determine if it is a valid binary search tree (BST)</em>.</p>

<p style="user-select: auto;">A <strong style="user-select: auto;">valid BST</strong> is defined as follows:</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">The left subtree of a node contains only nodes with keys <strong style="user-select: auto;">less than</strong> the node's key.</li>
	<li style="user-select: auto;">The right subtree of a node contains only nodes with keys <strong style="user-select: auto;">greater than</strong> the node's key.</li>
	<li style="user-select: auto;">Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg" style="width: 302px; height: 182px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> root = [2,1,3]
<strong style="user-select: auto;">Output:</strong> true
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg" style="width: 422px; height: 292px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> root = [5,1,4,null,null,3,6]
<strong style="user-select: auto;">Output:</strong> false
<strong style="user-select: auto;">Explanation:</strong> The root node's value is 5 but its right child's value is 4.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">The number of nodes in the tree is in the range <code style="user-select: auto;">[1, 10<sup style="user-select: auto;">4</sup>]</code>.</li>
	<li style="user-select: auto;"><code style="user-select: auto;">-2<sup style="user-select: auto;">31</sup> &lt;= Node.val &lt;= 2<sup style="user-select: auto;">31</sup> - 1</code></li>
</ul>
</div>