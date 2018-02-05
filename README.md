# LibMediainfo
开源库，用于获取媒体信息

# 一、参考网址

https://sourceforge.net/projects/mediainfo/files/source/libmediainfo/17.12/

LibMediainfo 依赖于Zenlib zlib，可以直接选择 libmediainfo_17.12_AllInclusive.7z 进行打包下载。


# 二、编译安装

## 2.1 编译 libz

（suse 11已经有了这个库，跳过此步）

```
./config;
make;
make install;
```

执行完上面的命令，会在/usr/local/lib/目录 下生成 libz.a 在/usr/local/include目录 下生成zlib.h(这个文件移植没用到)

## 2.2 编译libzen

（需要安装doxygen ,在ubuntu上 sudo apt-get install doxygen）
 (autogen这个命令需要安装automake libtool ，在ubuntu上 sudo apt-get install automake;sudo apt-get install libtool)

```
cd ./Source/Doc;
doxygen Doxyfile;
cd -;
cd ./Project/GNU/Library
chmod +x autogen;
./autogen;
./configure  --enable-shared;
make clean;
make;
make install;
ls -lrt /usr/local/lib/libzen*;
```

如果上面的步骤执行成功，应该看到以下5个函数库：libzen.a   libzen.la    libzen.so   libzen.so.0   libzen.so.0.0  5个函数库


## 2.3 编译libmediainfo

```
cd ./Source/Doc/;
doxygen Doxyfile;
cd -;
cd ./Project/GNU/Library;
chmod +x autogen;
./autogen;
./configure --enable-shared;
make clean;
make;
make install;
ls -lrt /usr/local/lib/libmediainfo*
```
如果上面的步骤执行成功，应该看到以下2个函数库：libmediainfo.a libmediainfo.la
