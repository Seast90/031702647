# AutoTest
一个自动评测系统

## 使用方法
- 根据评测需求编写main.lua脚本
- 使用luajit运行脚本

## 提供函数
- cd:`cd [文件夹名]`
- msbuild:`"[msbuild位置]MSBuild" "[文件名]" /t:Rebuild /p:Configuration=Release /p:Platform=x86`
- javac:`javac "[文件名]"`
- runExe:`"[exe名]" > "[输出文件名]"`
- runClass:`java "[文件名]" > "[输出文件名]"`
- copy:`copy "[old]" "[new]"`
- clone:`git clone --recursive --depth=1 [地址] [文件夹名]`