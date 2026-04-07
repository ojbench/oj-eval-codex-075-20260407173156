# Problem 075 - str

**ACMOJ Problem ID**: 1059

## Table of Contents

- [Problem 075 - str](#problem-075-str)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1059. str** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/075/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

你需要实现一个字符串类 `str`，支持下列功能/特性：

 - 默认值为空串。
 - 从 `char`/`char *`/`str` 构造实例。
 - 用 `char *`/`str` 对其赋值。
 - 可通过 `operator[]` 访问对应位置的字符（$0$-base）。
 - 成员函数 `len()`，返回其长度。
 - 成员函数 `join(strs)`，其中 `strs` 为 `std::vector<str>`。该函数用于将一系列字符串拼接成一个新的字符串，且原先字符串之间通过当前实例分隔。例如 `str(", ").join(std::vector<str>{'1', '2', '3'})` 会生成一个表示 `1, 2, 3` 的 `str` 实例。
 - 成员函数 `slice(l, r)`，表示切片，即提取出字符串中 `[l, r)` 的字符作为一个新的 `str` 实例。例如 `str("12345").slice(0, 2)` 会生成一个表示 `12` 的 `str` 实例。

具体来说，你要补充以下 `str.hpp`：
```cpp
#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
	//to do
public:
	str();//to do
	str(const char &c);//to do

	str(const char *&& s_);//to do

	str &operator=(const char *&& s_);//to do

	str(const str &other);//to do

	str &operator=(const str &other);//to do

	char &operator[](size_t pos);//to do

	size_t len() const;//to do

	str join(const std::vector<str> &strs) const;//to do

	str slice(size_t l, size_t r) const;//to do

	~str();//to do
};
```

提交的代码为 `str.hpp` 的所有内容。

### Input Format



### Output Format



### Samples

No sample data provided for this problem.

### Data Constraints

实现了除 `join` 和 `slice` 以外的所有功能，且保证不会发生内存泄漏，可以获得 $40$ 分。

**可以**增加必要的成员变量甚至成员函数。

`vector` 容器仅限使用 `join` 函数参数中给定的，不得另外新增。其余 STL 容器一律禁用。

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/075/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
