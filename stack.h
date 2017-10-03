#ifndef STACK_H
#define STACK_H
#include<iostream>
class Stack
{
public:
    Stack();
    void initstack(sqstack &s)//建立一个空栈
    {
        s.base=(int *)malloc(100*sizeof(int));
        s.top=s.base;
        s.stacksize=100;
    }
    int gettop(sqstack &s)//返回栈顶元素
    {
        int e =*(s.top-1);
        return e;
    }
    void push(sqstack &s,int e)//插入元素e为新的栈顶元素
    {
        if(s.top-s.base>=100)
        {
            s.base=(int *)realloc(s.base,110*sizeof(int));
            s.stacksize+=10;
            s.top=s.base+s.stacksize;

        }
        *(s.top)=e;
        s.top++;
     }
     int  pop(sqstack &s )//返回并删除栈顶元素
     {
        int e=*(s.top-1);
        delete (s.top-1);//*********
        s.top--;
        return e;
      }
      int getelem(sqstack s)//遍历每一个元素
      {
        int *p;
        p=s.top;
        for(;p!=s.base;p--)
        cout<<*(p-1)<<"  ";
          }
    int stacklength(sqstack s)//长度函数
    {
        int *p,count=0;
        p=s.top;
        for(;p!=s.base;p--)
        count++;
        return count;
          }
    void createstack(sqstack &s,int n)//建立一个n个元素的栈
    {   int x;
       s.base=(int *)malloc((n+1)*sizeof(int));
       s.top=s.base;
       s.stacksize=n+1;
        for(int i=0;i<n;i++)
        {
            cout<<"请输入元素";
            cin>>x;
            *s.top=x;
            s.top++;
        }
    }
        void conversion(sqstack s,int n, int m) //十进制数转化为任意进制数
        {
           initstack(s);
            while(n)
            {
                push(s,n%m);
                n=n/m;
            }
            cout<<"转化后的数是";
            int *p;
            p=s.top;
           for(;p!=s.base;p--)
            cout<<*(p-1);
        }
private:
    int *top;
    int *base;
    int stacksize;
};

#endif // STACK_H
