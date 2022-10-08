<h2><a href="https://leetcode.com/problems/same-tree/">100. Same Tree</a></h2><h3>Easy</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">Given the roots of two binary trees <code style="user-select: auto;">p</code> and <code style="user-select: auto;">q</code>, write a function to check if they are the same or not.</p>

<p style="user-select: auto;">Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg" style="width: 622px; height: 182px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> p = [1,2,3], q = [1,2,3]
<strong style="user-select: auto;">Output:</strong> true
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg" style="width: 382px; height: 182px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> p = [1,2], q = [1,null,2]
<strong style="user-select: auto;">Output:</strong> false
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg" style="width: 622px; height: 182px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> p = [1,2,1], q = [1,1,2]
<strong style="user-select: auto;">Output:</strong> false
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">The number of nodes in both trees is in the range <code style="user-select: auto;">[0, 100]</code>.</li>
	<li style="user-select: auto;"><code style="user-select: auto;">-10<sup style="user-select: auto;">4</sup> &lt;= Node.val &lt;= 10<sup style="user-select: auto;">4</sup></code></li>
</ul>
</div>