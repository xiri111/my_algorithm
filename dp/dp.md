# 动态规划刷题计划

> 按以下 7 个阶段循序渐进，建议每个阶段完成后进行小结，整理出通用的状态转移模板。

---

## 目录

1. [第 1 周：入门篇（建立感觉）](#第-1-周入门篇建立感觉)
2. [第 2 周：线性 DP](#第-2-周线性-dp)
3. [第 3 周：背包问题](#第-3-周背包问题)
4. [第 4 周：股票系列](#第-4-周股票系列)
5. [第 5 周：区间 DP](#第-5-周区间-dp)
6. [第 6 周：树形 DP](#第-6-周树形-dp)
7. [第 7-8 周：进阶专题](#第-7-8-周进阶专题)

---

## 第 1 周：入门篇（建立感觉）

| 题号 | 题目 | 知识点 | 难度 |
|------|------|--------|------|
| [70](https://leetcode.cn/problems/climbing-stairs/) | 爬楼梯 | 递推 / 记忆化搜索 | 简单 |
| [509](https://leetcode.cn/problems/fibonacci-number/) | 斐波那契数 | 经典递推 | 简单 |
| [746](https://leetcode.cn/problems/min-cost-climbing-stairs/) | 使用最小花费爬楼梯 | 简单状态转移 | 简单 |
| [198](https://leetcode.cn/problems/house-robber/) | 打家劫舍 | 线性 DP | 中等 |
| [213](https://leetcode.cn/problems/house-robber-ii/) | 打家劫舍 II | 环形数组处理 | 中等 |
| [740](https://leetcode.cn/problems/delete-and-earn/) | 删除并获得点数 | 转化为打家劫舍 | 中等 |

---

## 第 2 周：线性 DP

| 题号 | 题目 | 知识点 | 难度 |
|------|------|--------|------|
| [300](https://leetcode.cn/problems/longest-increasing-subsequence/) | 最长递增子序列 | LIS 经典，掌握 `dp[i]` 定义 | 中等 |
| [673](https://leetcode.cn/problems/number-of-longest-increasing-subsequence/) | 最长递增子序列的个数 | LIS 进阶，记录个数 | 中等 |
| [354](https://leetcode.cn/problems/russian-doll-envelopes/) | 俄罗斯套娃信封 | LIS + 二分优化 / 排序技巧 | 困难 |
| [1143](https://leetcode.cn/problems/longest-common-subsequence/) | 最长公共子序列 | LCS 经典二维 DP | 中等 |
| [1035](https://leetcode.cn/problems/uncrossed-lines/) | 不相交的线 | LCS 换皮题 | 中等 |
| [72](https://leetcode.cn/problems/edit-distance/) | 编辑距离 | 经典二维 DP | 中等 |
| [583](https://leetcode.cn/problems/delete-operation-for-two-strings/) | 两个字符串的删除操作 | LCS 变形 | 中等 |
| [115](https://leetcode.cn/problems/distinct-subsequences/) | 不同的子序列 | 双串 DP | 困难 |
| [392](https://leetcode.cn/problems/is-subsequence/) | 判断子序列 | 双指针 / DP | 简单 |

---

## 第 3 周：背包问题

> 建议先学习 01 背包和完全背包的理论模板，再刷题。

| 题号 | 题目 | 背包类型 | 难度 |
|------|------|----------|------|
| [416](https://leetcode.cn/problems/partition-equal-subset-sum/) | 分割等和子集 | 01 背包（可行性） | 中等 |
| [1049](https://leetcode.cn/problems/last-stone-weight-ii/) | 最后一块石头的重量 II | 01 背包（最优值） | 中等 |
| [494](https://leetcode.cn/problems/target-sum/) | 目标和 | 01 背包（方案数） | 中等 |
| [474](https://leetcode.cn/problems/ones-and-zeroes/) | 一和零 | 二维费用 01 背包 | 中等 |
| [518](https://leetcode.cn/problems/coin-change-ii/) | 零钱兑换 II | 完全背包（方案数） | 中等 |
| [322](https://leetcode.cn/problems/coin-change/) | 零钱兑换 | 完全背包（最小值） | 中等 |
| [279](https://leetcode.cn/problems/perfect-squares/) | 完全平方数 | 完全背包 | 中等 |
| [377](https://leetcode.cn/problems/combination-sum-iv/) | 组合总和 Ⅳ | 完全背包（顺序相关） | 中等 |

---

## 第 4 周：股票系列

> 这一系列题目思路统一，建议连续刷完，体会状态定义的技巧。

| 题号 | 题目 | 限制条件 | 难度 |
|------|------|----------|------|
| [121](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) | 买卖股票的最佳时机 | 只能交易 1 次 | 简单 |
| [122](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/) | 买卖股票的最佳时机 II | 可无限次交易 | 中等 |
| [123](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/) | 买卖股票的最佳时机 III | 最多 2 次交易 | 困难 |
| [188](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/) | 买卖股票的最佳时机 IV | 最多 k 次交易 | 困难 |
| [309](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | 最佳买卖股票时机含冷冻期 | 卖出后冷冻 1 天 | 中等 |
| [714](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | 买卖股票的最佳时机含手续费 | 每笔交易有手续费 | 中等 |

---

## 第 5 周：区间 DP

| 题号 | 题目 | 特点 | 难度 |
|------|------|------|------|
| [516](https://leetcode.cn/problems/longest-palindromic-subsequence/) | 最长回文子序列 | 经典区间 DP | 中等 |
| [1312](https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/) | 让字符串成为回文串的最少插入次数 | 与 LCS 结合 | 困难 |
| [486](https://leetcode.cn/problems/predict-the-winner/) | 预测赢家 | 博弈类区间 DP | 中等 |
| [312](https://leetcode.cn/problems/burst-balloons/) | 戳气球 | 经典区间 DP，注意开区间思维 | 困难 |
| [1000](https://leetcode.cn/problems/minimum-cost-to-merge-stones/) | 合并石头的最低成本 | 区间 DP + 前缀和优化 | 困难 |

---

## 第 6 周：树形 DP

| 题号 | 题目 | 特点 | 难度 |
|------|------|------|------|
| [543](https://leetcode.cn/problems/diameter-of-binary-tree/) | 二叉树的直径 | 树形 DP 入门 | 简单 |
| [124](https://leetcode.cn/problems/binary-tree-maximum-path-sum/) | 二叉树中的最大路径和 | 后序遍历 + DP | 困难 |
| [337](https://leetcode.cn/problems/house-robber-iii/) | 打家劫舍 III | 树形 DP 经典 | 中等 |
| [968](https://leetcode.cn/problems/binary-tree-cameras/) | 监控二叉树 | 树形 DP，状态设计较复杂 | 困难 |

---

## 第 7-8 周：进阶专题

### 状态压缩 DP

| 题号 | 题目 | 特点 | 难度 |
|------|------|------|------|
| [526](https://leetcode.cn/problems/beautiful-arrangement/) | 优美的排列 | 状压 DP 入门 | 中等 |
| [1349](https://leetcode.cn/problems/maximum-students-taking-exam/) | 参加考试的最大学生数 | 状压经典，位运算技巧 | 困难 |
| [1125](https://leetcode.cn/problems/smallest-sufficient-team/) | 最小的必要团队 | 状压 + 背包思想 | 困难 |
| [464](https://leetcode.cn/problems/can-i-win/) | 我能赢吗 | 记忆化搜索 / 状压 | 中等 |

### 数位 DP

| 题号 | 题目 | 难度 |
|------|------|------|
| [233](https://leetcode.cn/problems/number-of-digit-one/) | 数字 1 的个数 | 困难 |
| [902](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/) | 最大为 N 的数字组合 | 困难 |
| [1012](https://leetcode.cn/problems/numbers-with-repeated-digits/) | 至少有 1 位重复的数字 | 困难 |

### 其他经典 DP

| 题号 | 题目 | 知识点 | 难度 |
|------|------|--------|------|
| [10](https://leetcode.cn/problems/regular-expression-matching/) | 正则表达式匹配 | 双串 DP | 困难 |
| [44](https://leetcode.cn/problems/wildcard-matching/) | 通配符匹配 | 双串 DP | 困难 |
| [32](https://leetcode.cn/problems/longest-valid-parentheses/) | 最长有效括号 | 栈 / DP | 困难 |
| [264](https://leetcode.cn/problems/ugly-number-ii/) | 丑数 II | 多指针 DP | 中等 |
| [55](https://leetcode.cn/problems/jump-game/) | 跳跃游戏 | 贪心 / DP | 中等 |
| [45](https://leetcode.cn/problems/jump-game-ii/) | 跳跃游戏 II | 贪心 / DP | 中等 |
| [132](https://leetcode.cn/problems/palindrome-partitioning-ii/) | 分割回文串 II | 区间 DP + 预处理 | 困难 |
| [221](https://leetcode.cn/problems/maximal-square/) | 最大正方形 | 二维 DP | 中等 |
| [85](https://leetcode.cn/problems/maximal-rectangle/) | 最大矩形 | 单调栈 / 基于 221 拓展 | 困难 |

---

## 学习建议

1. 每道题先思考 `dp[i]` 或 `dp[i][j]` **代表什么含义**，这是最关键的一步。
2. 先写**记忆化搜索（自顶向下）**，熟练后再改写为**递推（自底向上）**。
3. 背包问题建议先理解**一维数组的逆序/正序优化**，这是面试常考的细节。
4. 股票问题建议统一用**状态机 DP** 的框架，别用贪心混着做，才能一通百通。
