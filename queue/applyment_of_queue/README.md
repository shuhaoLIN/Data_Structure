队列应用：银行业务模拟
========

### 介绍：

根据设定的服务台数量，营业时间，结束事件，顾客到达最大间隔，顾客最长服务时间，模拟银行一天中客户在银行逗留的平均时间（计算方法：平均逗留时间=总逗留时间/总人数）

### 数据类型：

优先队列

### 分析：

采用事件驱动模拟，用一张事件表记录客户的事件类型(到达还是离开)和事件时间。

### 过程：

检查事件表，若还有事件，则取得事件结点，判断到达事件还是离开事件，分别进行处理。若是到达事件，则生成一个随机数为客户办理业务所需时间，并将客户安排到服务时间最少的窗口中(需记住各窗口服务时间)，同时，生成另一随机数为下一个客户到达的间隔时间，计算下一个客户到达的时间，若在营业时间内，则生成一个到达事件按时间先后顺序插入到事件表中(优先队列自动调整)；若是离开事件，则进行统计，最后当事件表为空时，释放数据，并统计最终的人均服务时间
