# WSApiInvoker
一个完美封装AFNetworking的网络请求Demo

##简介
- AFWSApiInvoker

  主要负责调用AFN做网络请求以及返回错误信息和请求结果
  
- ApiInvoker

  所有api请求类的父类，用于填充请求相关信息以及统一接口
  
- ApiRequest

  网络请求实例
  包含请求的所有信息
  
- ApiResponse
  
  服务器回应实例
  
- WSApi
  
  单例 
  继成ApiInvoker，负责提供请求相关接口
  
- WSDevApi

  分类api，继承WSApi，负责提供分类里的请求接口


##目录
![](https://github.com/yuhanle/WSApiInvoker/blob/master/Screen.png)

##其他
有问题，欢迎提issue，或者微博探讨

新浪微博:
[煜寒了](http://weibo.com/208484538/home?wvr=5)
