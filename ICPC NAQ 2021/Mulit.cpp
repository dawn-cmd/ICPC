// 引入C++标准库的头文件
#include "bits/stdc++.h"

// 告诉编译器使用std命名空间
using namespace std;

// 主函数
int main() {
    // 定义整数变量n
    int n;

    // 定义整型向量ans，用于存储结果
    vector<int> ans;

    // 定义整数变量tmp和init
    int tmp;
    int init = -1;

    // 从标准输入流中读入n的值
    cin >> n;

    // 循环n次，每次读入一个整数tmp
    while (n--) {
        cin >> tmp;

        // 如果init的值为-1，将init的值设为tmp并继续下一次循环
        if (init == -1) {
            init = tmp;
            continue;
        }

        // 如果tmp能够整除init，将tmp加入结果数组ans中
        // 并将init的值设为-1，表示需要重新找到下一个init
        if (tmp % init == 0) {
            ans.emplace_back(tmp);
            init = -1;
        }
    }

    // 遍历结果数组ans中的每个元素，输出其值
    for (const auto &ele : ans) {
        cout << ele << '\n';
    }
}

