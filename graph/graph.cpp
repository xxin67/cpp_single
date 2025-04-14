#include<iostream>
using namespace std;

//图抽象类
class Graph
{
    public:
        Graph() {}
        virtual ~Graph() {}

        virtual void init(int n) =0; //初始化具有n个顶点的图

        virtual int n() = 0;    //返回顶点数
        virtual int e() = 0;    //返回边数

        virtual int first_neighbor(int v) =0;   //返回第一个邻接点
        virtual int next_neighbor(int v,int w) =0; //返回下一个邻接点

        virtual void setEdge(int v1,int v2,int weight) =0; //给边设置权重
        virtual void delEdge(int v1,int v2) =0; //删除边的权重
         
}