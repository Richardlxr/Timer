# Timer Project (高精度计时器)

这是一个基于 C++ 标准库 `std::chrono` 实现的高精度计时器演示项目。程序旨在测试系统 `sleep_for` 函数的精度，通过统计多次睡眠间隔的实际时长，计算出延迟的统计分布（平均值、P50、P90、P99 等）。

## 📚 项目目录结构

本项目采用了标准的 C++ 项目目录结构，清晰且易于扩展：

```
.
├── src/                # 源代码文件 (.cpp)
│   └── timer.cpp       # 计时器核心实现
├── include/            # 头文件 (.h)
│   └── timer.h         # 计时器类声明
├── build/              # 编译中间文件 (.o) - 自动生成
├── .vscode/            # Visual Studio Code 配置文件
├── main.cpp            # 主程序入口
├── Makefile            # 自动化编译脚本
└── README.md           # 项目说明文档
```

## ✨ 功能特性

*   **高精度计时**：利用 C++11 `std::chrono` 库确保微秒/纳秒级的时间测量。
*   **统计分析**：自动计算并输出时间间隔的统计指标，帮助分析系统调度的抖动情况：
    *   **Average**: 平均间隔
    *   **P50**: 中位数（50% 的样本小于此值）
    *   **P80/P90/P95/P99**: 各分位数值，用于评估长尾延迟。
*   **跨平台兼容**：支持 macOS 和 Linux 环境（依赖 pthread 和 make）。

## � 环境配置指南 (从零开始)

如果你是第一次在电脑上运行 C++ 和 Makefile 项目，请按照以下步骤配置你的开发环境。

### macOS

macOS 用户通常只需要安装 Xcode Command Line Tools 即可。

1.  打开终端 (Terminal)。
2.  输入以下命令并回车：
    ```bash
    xcode-select --install
    ```
3.  系统会弹出一个窗口询问是否安装，点击“安装”并同意协议即可。
4.  安装完成后，验证安装是否成功：
    ```bash
    make --version
    g++ --version
    ```

### Linux (Ubuntu/Debian)

在大多数 Linux 发行版中，你需要安装 `build-essential` 软件包。

1.  打开终端。
2.  更新软件源并安装：
    ```bash
    sudo apt update
    sudo apt install build-essential
    ```
3.  验证安装：
    ```bash
    make --version
    g++ --version
    ```

### Windows

Windows 原生不支持 Make 和 Linux 风格的 C++ 开发。推荐使用 **WSL (Windows Subsystem for Linux)**，这能让你在 Windows 上拥有完整的 Linux 开发体验。

1.  **安装 WSL**:
    *   以管理员身份打开 PowerShell 或命令提示符。
    *   输入命令：`wsl --install`。
    *   重启电脑。
2.  **设置 Linux**:
    *   重启后会自动弹出 Ubuntu 窗口，按照提示设置用户名和密码。
3.  **安装编译工具**:
    *   在 Ubuntu 窗口中输入：
        ```bash
        sudo apt update
        sudo apt install build-essential
        ```
4.  **在 VS Code 中使用**:
    *   在 Windows 上安装 VS Code。
    *   安装 "WSL" 扩展。
    *   在 Ubuntu 终端中进入你的项目目录，输入 `code .` 即可用 VS Code 打开项目。

## 🚀 快速开始

### 1. 编译项目


项目提供了完善的 `makefile`，并在 `.vscode` 中集成了构建任务。

**使用命令行：**
```bash
make        # 编译项目 (生成 "main" 可执行文件)
make clean  # 清理编译生成的文件
make help   # 查看所有可用命令
```


### 2. 运行程序

程序需要一个命令行参数来指定时间间隔（单位：秒）。

**基本用法：**
```bash
./main <interval>
```

**示例：**
```bash
./main 0.05
```
这将启动计时器，每隔 0.05 秒（50毫秒）采样一次，共采样 100 次，然后输出统计结果。

### 3. 运行结果示例

运行 `./main 0.01` 的输出可能如下所示：

```text
Current date and time: Thu Feb  5 10:00:00 2026
... (省略中间输出) ...
Current date and time: Thu Feb  5 10:00:01 2026
Average interval 0.010 seconds
P50 0.010 seconds
P80 0.010 seconds
P90 0.010 seconds
P95 0.011 seconds
P99 0.012 seconds
```

## 📝 许可证

此项目仅供学习和演示使用。
