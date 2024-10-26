# 简介
<e>这是一个功能完善的XML解析器<e><p><a>
在项目中添加我们的"XML.h"头文件就可以使用了<p>
</a></s>
# <a>函数介绍</a>
## XML构造函数<p>
>参数:
>>传入一个字符串路径
><p>示例:<p>
```
XML X0("C:/add/cnm/j.xml");//定义一个XML类的对象并传参
```
## ~ XML析构函数
<p><A><s>没啥软用
</s><p>运用了高级的析构程序
</A></p>

# OPENXML函数
### 简介
3个函数重载<p>
用于查询元素内的内容<p>
### 语法1
```c++
X0.OPENXML("int");
```
### 语法2
```c++
X0.OPENXML("class","int");
```
### 语法3
```c++
X0.OPENXML("class","d","int");
```
## 这样的一个XML文件
```XML
<?xml version="1.0" encoding="GB18030"?>
<root>
    <class id="a">
        <int>整数</int>
    </class>
    <class>
        <int>小鼠</int>
    </class>
    <class id="d">
        <int>小数</int>
    </class>
    <add>
        <int>大数</int>
    </add>
</root>
```
### 语法1会输出
```
整数
```
### 语法2会输出
```
整数
```
### 语法3会输出
```
小数
```
# OUTXML_CLASS函数
### 简介
<A>四个函数重载<p></a>
用于向一个根元素写入一个子元素
### 语法1
```c++
X0.OUT_CLASS("class","add");
```
### 语法2
```c++
X0.OUT_CLASS("class","z","abb");
```
###语法3
```c++
X0.OUT_CLASS("class","ID","r","abb");
```
###语法4
```c++
X0.OUT_CLASS("class","x""ID","z","abb");
```
## 以这个XML文件为标准
```xml
<?xml version="1.0" encoding="GB18030"?>
<root>
    <class>
    </class>
    <class ID= "z">
    </class>
    <class ID="x">
    </class>
</root>
```
### 语法1执行后:
```xml
<?xml version="1.0" encoding="GB18030"?>
<root>
    <class>
    <!--这里多出了一个add元素(实际项目没有这个注释)-->
    <add>
    </add>
    </class>
    <class ID= "z">
    </class>
    <class ID="x">
    </class>
</root>
```
### 语法2执行后:
```xml
<?xml version="1.0" encoding="GB18030"?>
<root>
    <class>
    </class>
    <class ID= "z">
    <!--这里多出了ann元素-->
    <abb>
    </abb>
    </class>
    <class ID="x">
    </class>
</root>
```
### 语法3执行后:
```xml
<?xml version="1.0" encoding="GB18030"?>
<root>
    <class>
    <!--这里多出了编号为'r'的abb元素-->
    <abb ID="r">
    </abb>
    </class>
    <class ID= "z">
    </class>
    <class ID="x">
    </class>
</root>
```
### 语法4执行后:
```xml
<?xml version="1.0" encoding="GB18030"?>
<root>
    <class>
    </class>
    <class ID= "z">
    </class>
    <class ID="x">
    <!--这里多出了ID为'z'的元素-->
    <abb ID="z">
    </abb>
    </class>
</root>
```
# OUTXML_SHUXING函数

## 简介:
四个函数重载<p>
用于向根元素里写入一个带内容的元素
<p>

## 语法
### 语法1:
```cpp
X0.OUT_XMLSHUXING("class","nbLAN","我真帅")
```
### 语法2:
```cpp
X0.OUT_XMLSHUXING("class","s","nbLAN","我真帅")
```
### 语法3:
```cpp
X0.OUT_XMLSHUXING("class","ID","X","nbLAN","我真帅")
```
### 语法4:
```cpp
X0.OUT_XMLSHUXING("class","x","M","a","nbLAN","我真帅")
```
## 以这个XML文件为标准
```xml
<root>
    <class>
    </class>
    <class ID="x">
    </class>
    <class ID="s">
    </class>
</root>
```
### 语法1执行后:
```xml
<root>
    <class>
    <nbLan>我真帅</nbLAN>
    </class>
    <class ID="x">
    </class>
    <class ID="s">
    </class>
</root>
```
### 语法2执行后:
```xml
<class>
    </class>
    <class ID="x">
    </class>
    <class ID="s">
    <nbLAN>我真帅<nbLAN>
    </class>
</root>
```
### 语法3执行后:
```xml
<root>
    <class>
    <nbLAN ID="x">我真帅</nbLAN>
    </class>
    <class ID="x">
    </class>
    <class ID="s">
    </class>
</root>
```
### 语法4执行后:
```xml
<root>
    <class>
    </class>
    <class ID="x">
    <nbLAN M="a">我真帅</nbLAN>
    </class>
    <class ID="s">
    </class>
</root>
```
# OUTXML_DELETE函数
## 简介
3个函数重载
<a>用于删除元素<p>
<s>该死的我,为什么要写这个文档</a>
<p></s>

## 语法
### 语法1
```cpp
X0.OUTXML_DELETE("class1")
```
### 语法2
```cpp
X0.OUTXML_DELETE("class","class1")
```
### 语法3
```cpp
X0.OUTXML_DELETE("class","a","int")
```
## 以这个XML文件为例
```xml
<root>
    <class id="z">
        <a></a>
    </class>
    <class>
        <class1>
            <int>z</int>
        </class1>
    </class>
    <class ID="a">
        <int>add</int>
    </class>
</root>
```
### 语法1执行后:
```xml
<root>
    <class id="z">
        <a></a>
    </class>
    <class>
    <!--这里的class1元素不见了-->
    </class>
    <class ID="a">
        <int>add</int>
    </class>
</root>
```
### 语法2执行后:
```xml
<root>
    <class id="z">
        <a></a>
    </class>
    <class>
    <!--还是这里的class1不见了-->
    </class>
    <class ID="a">
        <int>add</int>
    </class>
</root>
```
### 语法3执行后:
```xml
<root>
    <class id="z">
        <a></a>
    </class>
    <class>
        <class1>
            <int>z</int>
        </class1>
    </class>
    <class ID="a">
        <!--这里的int不见了-->
    </class>
</root>
```
# 后言
<s><a>写这个真TM折磨人啊</s></a>
<p>这是初中生的作品，有学校看上了就联系一下吧QWQ<p>
<a>邮箱:"zuoyaoquan@outlook.com"