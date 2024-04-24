cmake_minimum_required(VERSION 3.15)
project(leetcode)
set(CMAKE_CXX_STANDARD 14)

add_executable(leecode
         editor/cn/[144]二叉树的前序遍历.cpp
        editor/cn/[145]二叉树的后序遍历.cpp
        editor/cn/[94]二叉树的中序遍历.cpp
        editor/cn/[102]二叉树的层序遍历.cpp
        "editor/cn/[107]二叉树的层序遍历 II.cpp"
        editor/cn/[199]二叉树的右视图.cpp
        editor/cn/[637]二叉树的层平均值.cpp
        "editor/cn/[429]N 叉树的层序遍历.cpp"
)
