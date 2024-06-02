# CppStudy

#### 介绍
学习C++的练习



#### 安装教程

1.  安装C/C++编辑器 codeblocks

#### 使用说明

 1. 预处理
 cpp main.cpp > main.i
 2. 编译（将*.i文件编译成*.s文件）
 g++ -g -S main.i
 3. 汇编
 as -o test.o test.s
 4. 链接
 ld -o main main.o .......(链接所依赖的所有文件)
 
 
如何将*.o文件反汇编
objdump -d -M intel -S main.o > main.asm


g++编译*.cpp文件
g++ -o main main.cpp -g （-g  带有调试信息）


美国博士带你学C++
https://www.bilibili.com/video/BV1av411z7Qu?p=1

http://www.cplusplus.com/

https://gcc.gnu.org/onlinedocs/libstdc++/

cppreference国内镜像：
https://qingcms.gitee.io/cppreference/20210212/zh/
 
GDB
http://www.yolinux.com/TUTORIALS/GDB-Commands.html

http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html

https://zhuanlan.zhihu.com/p/36771960



#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
