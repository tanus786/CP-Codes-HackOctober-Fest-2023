<h2><a href="https://leetcode.com/problems/longest-common-subsequence/">1143. Longest Common Subsequence</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">Given two strings <code style="user-select: auto;">text1</code> and <code style="user-select: auto;">text2</code>, return <em style="user-select: auto;">the length of their longest <strong style="user-select: auto;">common subsequence</strong>. </em>If there is no <strong style="user-select: auto;">common subsequence</strong>, return <code style="user-select: auto;">0</code>.</p>

<p style="user-select: auto;">A <strong style="user-select: auto;">subsequence</strong> of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;">For example, <code style="user-select: auto;">"ace"</code> is a subsequence of <code style="user-select: auto;">"abcde"</code>.</li>
</ul>

<p style="user-select: auto;">A <strong style="user-select: auto;">common subsequence</strong> of two strings is a subsequence that is common to both strings.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> text1 = "abcde", text2 = "ace" 
<strong style="user-select: auto;">Output:</strong> 3  
<strong style="user-select: auto;">Explanation:</strong> The longest common subsequence is "ace" and its length is 3.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> text1 = "abc", text2 = "abc"
<strong style="user-select: auto;">Output:</strong> 3
<strong style="user-select: auto;">Explanation:</strong> The longest common subsequence is "abc" and its length is 3.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> text1 = "abc", text2 = "def"
<strong style="user-select: auto;">Output:</strong> 0
<strong style="user-select: auto;">Explanation:</strong> There is no such common subsequence, so the result is 0.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= text1.length, text2.length &lt;= 1000</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">text1</code> and <code style="user-select: auto;">text2</code> consist of only lowercase English characters.</li>
</ul>
</div>