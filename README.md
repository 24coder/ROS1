## 👉🏽 ROS使用相关问题

#### rosdep失效解决策略

https://www.bilibili.com/video/BV1Ci4y1L7ZZ?p=15  
https://www.bilibili.com/video/BV1Ci4y1L7ZZ?p=16&spm_id_from=pageDriver

## 👉🏽 三种通信方式

#### Topic

1、单向接收/发送  

#### Service

1、双向请求/响应

#### 话题和服务的区别

| 条目     | 话题(topic)                              | 服务(service)                                |
| -------- | ---------------------------------------- | -------------------------------------------- |
| 同步性   | 异步                                     | 同步                                         |
| 通信模型 | 发布/订阅                                | 客户端/服务器                                |
| 反馈机制 | 无                                       | 有                                           |
| 底层协议 | ROSTCP/ROSUDP                            | ROSTCP/ROSUDP                                |
| 缓冲区   | 有                                       | 无                                           |
| 实时性   | 弱                                       | 强                                           |
| 节点关系 | 多对多                                   | 一对多                                       |
| 使用场景 | 弱逻辑处理，多数据传输                   | 强逻辑处理，少数据传输                       |
| 通信数据 | msg                                      | srv                                          |
| 使用时机 | 连续高频率数据的发布与接收：雷达，里程计 | 偶尔调用或执行某一项特定功能：拍照、语音识别 |


#### Action

1.双向消息{目标(goal)/结果（result）/反馈(feedback)}可以反馈状态信息 （周期反馈给客户端目前的状态)   
2.周期反馈任务运行的监控数据   
3.可以取消动作    
4.向客户端发送任务的执行结果（只发布一次）   
5.发布任务目标 

​                                                       action

<div align=center>
<img src="https://user-images.githubusercontent.com/62461065/158843530-f69b0915-07ad-4606-b56b-f93107ab4aaf.png" width="50%" height="50%" />
</div>

## 👉🏽 parameter

参数服务类似于程序中的全局变量  Talker可以改变全局变量的值  listener可以获取更新之后的全局变量的值，


rosrun subscriber的时候.cpp文件不能添加.cpp后缀，不然会报错  
💡service 中的 server and client和 topic中publisher and subscriber 有什么区别？  
A:topic中的message在publisher and subscriber中是一直进行发送和订阅  service 中message的 server and client server请求一次，服务器应答一次。
A2:更新之后需要添加密钥，具体参考下面
<a href="https://blog.csdn.net/wangxue_1231/article/details/92801510" target="_blank">添加秘钥</a>  
💡关于sudo apt update 和sudo apt upgrade 的作用以及区别
<a href="https://blog.csdn.net/harbor1981/article/details/86064888?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162558028716780262560189%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162558028716780262560189&biz_id=0&spm=1018.2226.3001.4187" target="_blank">update</a>

注:update只是更新软件安装索引目录，upgrade是真实地去更新软件目录中相比于目前更新版本的软件  
💡sources.list和sources.list.d有什么区别？
<a href="https://blog.csdn.net/harbor1981/article/details/86064888?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162558028716780262560189%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162558028716780262560189&biz_id=0&spm=1018.2226.3001.4187" target="_blank">update</a>  
💡如何使用rplidar进行建图和定位    功能包位于tutlebot_ws这个工作空间
<a href="https://blog.csdn.net/sinat_25923849/article/details/108527802?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162692453016780261971159%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162692453016780261971159&biz_id=0&spm=1018.2226.3001.4187" target="_blank">rplidar（单线激光雷达建图）</a>  
💡path-planning中所有所有路径规划算法均调通  
💡使用rosdep install  （功能包名称）安装功能包的时候会同时安装相关依赖 这样安装起来就很方便  
💡测试工具：ros内置rostest单元/集成测试框架  

#### 常用命令

rosparam list ：列出当前所有的参数

rosparam  get   变量名：    获取变量的值  

## 👉🏽ros常用API

#### ros 初始化函数

参数：

1、argc  封装实参的个数(n+1)

2、argv   封装参数的数组

3、name  为节点命名  在ros空间中不允许重名的节点

4、options  节点启动选项

①argc 和argv的使用：如果按照ROS中特定的格式传入实参，那么ROS可以加以使用，比如设置全局参数(设置完之后可以使用rosparam进行查看)，

②options的使用

给节点重命名（ros中有重名的节点启动时，之前的节点会被结束掉）

需求：特定场景下需要一个节点多次启动且能正常运行，这个时候options就起作用了

使用方式：ros::init(argc,argv,"需要多次启动的节点名"，**ros::init_options::AnonymousName**);

结果：每启动一次就会增加一个节点  这个节点名就是这个多次启动的节点名后面加上数字后缀编号（随机编号）

#### 话题和服务的相关对象

在 roscpp 中，话题和服务的相关对象一般由 NodeHandle 创建。

ros::nodehandle nh;

作用：创建发布者对象

```cpp
ros::Publisher pub = handle.advertise<std_msgs::Empty>("my_topic", 1);
```

advertise：

参数：

1、话题类型： std_msgs::Empty

2、话题名称： my_topic

3、队列长度：1

4、latch(可选)：如果设置为true，他会保存发布方的最后一条消息，并且新的订阅对象连接到发布者时，发布者会将这条消息发送给订阅方。

4.1 应用场景

latch设置为true时，以静态地图为例、

方案1，可以使用固定频率发布地图数据，但是效率低，；

方案2，将地图发布者的latch设置为true，每当订阅者订阅这个话题的时候，就可以将地图数据发送给订阅者。

#### 回旋函数

作用：用于处理回调函数

ros::spin()

执行到ros::spin() 的时候，会回头看看有哪些回调函数，并且会进入这些循环，不会退出，循环执行这些回调函数，并且ros::spin() 之后的语句不会被执行。

ros::spinOnce() 

执行到ros::spinOnce() 的时候，会回头看看有哪些回调函数，待回调函数执行完一次的时候，就会接着ros::spinOnce()往下执行。

#### 时间函数


| 条目             | 时刻和时刻 | 时刻和持续时间 | 持续时间和持续时间 |
| ---------------- | ---------- | -------------- | ------------------ |
| 是否可以直接加减 | 不可以     | 可以           | 可以               |
| 返回类型         | nan        | 时刻           | 持续时间           |

#### 定时器

参数有四个：

参数1  时间间隔

参数2  回调函数

参数3  是否执行一次

参数4  是否自动启动(设置为false时需要手动调用，timer.start(),这个挺好用的)

注意：定时器启动后要使用ros::spin()

#### 动态参数

创建完客户端之后编译会生成中间文件   编写服务器端的时候要参考这个中间文件（其中创建server的时候会有指定类型参数）

#### 插件库

主程序和插件程序之间通过规范化的接口实现

## 👉🏽 launch

- pkg="包名"

  节点所属的包

- type="nodeType"

  可执行程序(与可执行文件相同的文件名，只是少了.cpp)

- name="nodeName"

  节点名称(在 ROS 网络拓扑中节点的名称)  节点初始化的时候定义的名称

- args (可选)

  将参数传递给节点   类似于形参

- machine="机器名"

  在指定机器上启动节点  可以在不同主机上进行启动节点

- respawn="true | false" (可选)

  如果节点退出，设置是否自动重启   应用于比较重要的设备 比如无人车上的激光雷达

- respawn_delay=" N" (可选)

  如果 respawn 为 true, 那么延迟 N 秒后启动节点

- required="true | false" (可选)

  该节点是否必须，如果为 true,那么如果该节点退出，将杀死整个 roslaunch

- ns="xxx" (可选)

  在指定命名空间 xxx 中启动节点   这个命名空间不用提前设置好

- clear_params="true | false" (可选)

  在启动前，删除节点的私有空间的所有参数   慎用！！！

- output="log | screen" (可选)

  日志发送目标，可以设置为 log 日志文件，或 screen 屏幕,默认是 log

★ include 

launch文件复用

★ remap

当两个节点需要通信的时候，如果话题名称不一样，可以使用remap将话题名进行更改 (我得儿立即接并不是从本质上上进行更改，只是一种重定向方法)

><remap from "节点1话题名"to  “节点2话题名” />

★param

使用的时候有两种格式，一种是直接添加在launch标签下，一种是添加在node标签下。

如果添加在node标签下的时候，会在前面添加命名空间，相当于私有命名空间。

我的理解是如果设置在launch文件下面的时候，设置的就是全局变量，如果设置在node标签下的时候，设置的是**node命名空间**(上面说的私有命名空间)下的变量。

★ rosparam

可以和yaml文件进行导入导出操作，但是当一个launch文件中有其他节点的时候可能会先执行导出参数操作导致导出的参数不是很全 ，可以将这个文件单独放置在一个launch文件中，单独进行启动。

★arg 

`<arg>`标签是用于动态传参，类似于函数的参数，可以增强launch文件的灵活性

例如：

```xml
<param name="A" value="0.55" />
<param name="B" value="0.55" />
<param name="C" value="0.55" />
```

当设置多个参数的时候，并且这些参数使用的是同一个值，上面那个需要将每个参数的值进行改变，使用下面的代码只需要改变一个数字即可

```xml
<param name="A" value="0.55" />
<param name="B" value=$(arg A) />
<param name="C" value=$(arg A) />
```

除此之外还可以在启动roslaunch的时候后面直接指定参数的值

例如 roslaunch  hello  hello.launch   A:=2

启动之后会将A的值2覆盖掉之前的值0.55

## 👉🏽 各种重名问题

**功能包重名  节点重名  话题重名   参数重名**

工作空间覆盖    功能包重名

不同的工作空间下面有相同名字的功能包，功能包的优先级是在bashrc文件由下到上依次递减

情景1 当有一个工作空间ws1依赖于另一个工作空间ws2的功能包A时，此时有另外一个工作空间ws3下的功能包和这个工作空间ws2里的功能包A重名，并且在bashrc文件中ws3将ws2的工作空间给覆盖了，这时候会产生隐患。

**在ros中对于功能包重名暂时没有相关补救策略，尽量避免功能包重名**

解决方式：两种策略  三种实现的方式

策略1：起别名  策略2：添加前缀（也就是添加命名空间）

1、rosrun设置命名空间与起别名

2、roslaunch设置命名空间与起别名

3、编码设置命名空间与起别名

创建私有(跟节点名有关，附属于节点名之下的)的名称的时候，要创建特定的节点句柄。

特殊：参数重名

原因：没有重映射机制

解决方式：只能使用添加前缀的方式（也就是设置命名空间）

