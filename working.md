# 开发记录
2021年7月22日  
- 初步完成了py_image.py的处理工作  
- 梳理了一些函数
#### 问题
- __UXTB_RORn(a,b) 经查询，该函数是宏arm指令函数，用于将无符号数扩充到32字节，gcc编译不报错，只是警告。主要影响imlib_draw_image()函数，暂不做处理