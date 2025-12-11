# My Algorithm - 个人算法练习仓库
> 个人算法学习与练习仓库，包含各专题的 C++ 实现与题解。

## 📚 项目简介

以专题分类管理算法练习，主要使用 C++ 实现与验证。目录与文件结构已按实际工程划分到子文件夹。

## 🗂️ 项目结构（当前）
```plaintext
my_algorithm/
├── README.md
├── .vscode/                # 根目录 VS Code 任务配置
├── bit/                    # 位运算专题
│   └── test01.cpp
├── dp/                     # 动态规划专题
│   ├── .vscode/
│   ├── my_rand.cpp         # 随机数据生成与测试辅助
│   ├── test01.cpp          # 斐波那契/线性 DP
│   └── test02.cpp          # 矩阵/网格 DP
├── greedy/                 # 贪心算法专题
│   ├── greedy.txt          # 学习笔记/要点
│   └── test01.cpp
├── monotonic_stack/        # 单调栈与队列
│   ├── .vscode/
│   └── test01.cpp
└── simulation/             # 模拟/实现类题目
    ├── .vscode/
    ├── code43.cpp
    └── code43.exe
```

## 📋 目录与文件说明
- `dp/test01.cpp`（斐波那契/线性 DP）
  - 509 斐波那契数、70 爬楼梯、746 使用最小花费爬楼梯
  - 1137 第 N 个泰波那契数、198 打家劫舍、740 删除并获得点数
- `dp/test02.cpp`（矩阵/网格 DP）
  - 62 不同路径、64 最小路径和、63 不同路径 II
  - 120 三角形最小路径和、931 下降路径最小和、221 最大正方形
- `dp/my_rand.cpp` 随机数据工具
  - 生成随机整数/数组/矩阵，辅助性能与正确性测试
- `greedy/test01.cpp` 贪心练习入口
  - 区间调度、覆盖/跳跃、堆选择等常见模板的实现与尝试
- `bit/test01.cpp` 位运算练习
  - 基础按位操作、掩码技巧、低位提取等
- `monotonic_stack/test01.cpp` 单调栈/队列练习
  - 维护上升/下降栈以解决“下一个更大/更小”类问题
- `simulation/code43.cpp` 模拟题实现

### VS Code 任务
- 根目录与部分子目录提供 `.vscode/tasks.json`，可一键编译运行
- 在 VS Code 命令面板运行“Tasks: Run Task”选择对应任务
## 🚀 快速开始（Windows）

### 编译与运行
```cmd
:: 进入项目根目录
d:
cd d:\my_algorithm

:: 编译 DP 示例（使用 C++17）
g++ -O2 -std=c++17 .\dp\test01.cpp -o .\dp\test01.exe
.\dp\test01.exe

g++ -O2 -std=c++17 .\dp\test02.cpp -o .\dp\test02.exe
.\dp\test02.exe

:: 编译贪心示例
g++ -O2 -std=c++17 .\greedy\test01.cpp -o .\greedy\test01.exe
.\greedy\test01.exe

:: 编译单调栈示例
g++ -O2 -std=c++17 .\monotonic_stack\test01.cpp -o .\monotonic_stack\test01.exe
.\monotonic_stack\test01.exe

:: 编译位运算示例
g++ -O2 -std=c++17 .\bit\test01.cpp -o .\bit\test01.exe
.\bit\test01.exe
```

## 📚 学习建议
- 将题目按专题放入对应子目录，保持小而清晰的可执行单元
- 贪心类建议从“排序+扫描 → 堆选择 → 覆盖/跳跃 → 图/MST”逐步练
- 动态规划按“线性 → 区间/网格 → 状态压缩”递进，记录状态设计与转移式

## 📝 备注
- 本 README 已根据当前实际目录结构重写；后续如新增目录或示例，请同步在此处补充说明
