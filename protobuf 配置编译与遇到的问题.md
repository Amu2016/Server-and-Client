
官方文档
https://github.com/google/protobuf/blob/master/cmake/README.md

可以产考
https://blog.csdn.net/program_anywhere/article/details/77365876


windows编译protobuf库（用Visual Studio编译）
https://blog.csdn.net/jack_20/article/details/73359512


error LNK2038: 检测到“_ITERATOR_DEBUG_LEVEL”的不匹配项: 值“0”不匹配值“2

解决办法

1、可能是release模式下引用了debug模式下生成的库，所以工程的模式和库的模式要保持一致

2、可能是库的编译选项和工程的编译选项不同，例如都使用相同的运行模式（属性--->C/C++------>代码生成）即多线程调试MTD