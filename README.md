## ROS使用相关问题
### 1、rosdep失效解决策略
https://www.bilibili.com/video/BV1Ci4y1L7ZZ?p=15  
https://www.bilibili.com/video/BV1Ci4y1L7ZZ?p=16&spm_id_from=pageDriver
## 三种通信方式
## Topic：
1、单向接收/发送  
## Service：
1、双向请求/响应
### 话题和服务的区别

| 条目 | 话题 |服务 |
| ------ | ------ | ------ |
| 同步性 | 异步 | 同步 |
| 通信模型 | 发布/订阅 | 客户端/服务器 |
| 反馈机制 | 无 | 有 |
| 底层协议 | ROSTCP/ROSUDP | ROSTCP/ROSUDP |
| 缓冲区 | 有 | 无 |
| 实时性 | 弱 | 强 |
| 节点关系 | 多对多 | 一对多 |
| 使用场景 | 弱逻辑处理，多数据传输 | 强逻辑处理，少数据传输 |

## Action：
1.双向消息{目标(goal)/结果（result）/反馈(feedback)}可以反馈状态信息 （周期反馈给客户端目前的状态)   
2.周期反馈任务运行的监控数据   
3.可以取消动作    
4.向客户端发送任务的执行结果（只发布一次）   
5.发布任务目标 

<div align=center>
  <font color=#0099ff size=20 face="楷体">Action</font>
</div>

<div align=center>
<img src="https://user-images.githubusercontent.com/62461065/158843530-f69b0915-07ad-4606-b56b-f93107ab4aaf.png" width="50%" height="50%" />
</div>

## parameter
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

