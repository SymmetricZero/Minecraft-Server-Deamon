# Minecraft-Server-Deamon
Minecraft服务器守护进程

## v3
增加日志系统。
现在，服务器每次重新启动，都将在MSDError.log添加一条时间记录。

## v2
优化代码结构<br>
现在每当MC服务器退出后，5秒内的任何输入都将终止进程。<br>
不输入则自动重启。

## v1
每次MC服务器退出后，5秒内询问是否重启。<br>
如果不输入任何字符，则自动重启。<br>
输入y则不重启。
