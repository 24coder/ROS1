my ros learning record
点击go to file进入文件列表    点击文件名进入文件详情页进行操作
rosrun subscriber的时候.cpp文件不能添加.cpp后缀，不然会报错

Q1:service 中的 server and client和 message中publisher and subscriber 有什么区别？

A:message在publisher and subscriber中是一直进行发送和订阅  service 中的 server and client server请求一次，服务器应答一次。


Q2:为什么更新源之后会出现下面这个问题？

![image](https://user-images.githubusercontent.com/62461065/124609950-ac32a300-dea2-11eb-8b00-21ae10496b78.png)


A2:更新之后需要添加密钥，具体参考下面

https://blog.csdn.net/wangxue_1231/article/details/92801510

Q3：关于sudo apt update 和sudo apt upgrade 的作用以及区别

https://blog.csdn.net/harbor1981/article/details/86064888?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162558028716780262560189%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162558028716780262560189&biz_id=0&spm=1018.2226.3001.4187

注:update只是更新软件安装索引目录，upgrade是真实地去更新软件目录中相比于目前更新版本的软件

Q3:sources.list和sources.list.d有什么区别？



Q4:如何使用rplidar进行建图和定位    功能包位于tutlebot_ws这个工作空间
https://blog.csdn.net/sinat_25923849/article/details/108527802?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162692453016780261971159%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162692453016780261971159&biz_id=0&spm=1018.2226.3001.4187

path-planning中所有所有路径规划算法均调通

action：
1.可以反馈状态信息 （周期反馈给客户端目前的状态） 
2.周期反馈任务运行的监控数据 
3.可以取消动作  
4.向客户端发送任务的执行结果（只发布一次） 
5.发布任务目标
![image](https://user-images.githubusercontent.com/62461065/132931908-1e23f4f0-163d-49a5-bf2d-bb01884a7287.png)

使用rosdep install  （功能包名称）安装功能包的时候会同时安装相关依赖 这样安装起来就很方便


































































































