##### 点击[查看项目代码](https://github.com/Q10Viking/haircut)  

> 感谢彭波老师的教学，本次数据结构小学期项目由： 黄壮壮，李正云，徐瑞坤和张笑若共同完成   

####  1.项目简介  

+  **问题描述** 
   为理发馆的排队模拟问题添加预测经营状况的功能。每个顾客有选择理发师的服务要求，理发室分三分等级（一级、二级和三级），对应不同的服务收费。当顾客进门时，如果想选择某级理发师，只要该级别的理发师不空闲，就将排队候理。程序将统计每天的营业额和不同级别理发师的创收。

+ **基本要求**  
每个顾客进门时将生成三个随机数（durtime,intertime,select）。其中：durtime为进门顾客理发所需要的时间（简称理发时间），intertime为下一个顾客将到达的时间间隔（简称间隔时间),select是服务选项。R为由产生的随机数。Durtime、intertime和select可以分别由下式确定：  
Durtime =15+R%50
Intertime=2+R%10
Select=1+R%3 
服务费由durtime*(4-select)*0.4（元）计算，该式包含着服务需要的时间和理发师级别两项因素      

+ **测试数据**  
测试数据：在营业时间480分钟，7把理发椅，1-2号、3-4号，5-7号理发椅分别对应一级，二级和三级理发师。

#### 2.抽象模型  
![](http://upload-images.jianshu.io/upload_images/3908237-9b65f18c9c4e0eee.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)   


#### 3.模块关系  
![](http://upload-images.jianshu.io/upload_images/3908237-7516cddca663b012.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

+ queue模块: 


![](http://oqyoidw83.bkt.clouddn.com/table1.PNG)

----------  

+ store模块：  

![](http://oqyoidw83.bkt.clouddn.com/table2.PNG)


+ customer模块  


![](http://oqyoidw83.bkt.clouddn.com/table3.PNG)


+ result模块  
 
![](http://oqyoidw83.bkt.clouddn.com/table4.PNG)

#### 4.函数调用  
![](http://upload-images.jianshu.io/upload_images/3908237-37e53dbfe9d47596.PNG?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)  

#### 5.结果展示  
![](http://upload-images.jianshu.io/upload_images/3908237-4d7ce78c0a1a1ca1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)