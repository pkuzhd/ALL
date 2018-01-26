#include <vector>
#include <iomanip>
#include <iostream>
#ifndef MAGIC_CUBE_H
#define MAGIC_CUBE_H

using namespace std;

//专门用于交换四个元素的change函数，效果是非反转下b变为a值，c变为b值，以此类推。
template <class T>
void change(T&a,T&b,T&c,T&d,bool reversed = false)
{
    T tmp;
    switch(reversed)
    {
    case false:
        tmp=d;
        d=c;
        c=b;
        b=a;
        a=tmp;
        break;
    case true:
        tmp = a;
        a=b;
        b=c;
        c=d;
        d=tmp;
        break;
    }
}

//颜色
enum Color {Red,Blue,Green,Yellow,White,Orange};

//操作，用于Cube和MagicCube
enum Operation {R=0,R_,L,L_,U,U_,D,D_,F,F_,B,B_};

//自定义公式类型
typedef vector<Operation> Formula;
//提前声明MagicCube
class MagicCube;

//小方块
class Cube
{
    void rotate(Operation);//将rotate函数设为私有，因为块是不能单独旋转的。
    Color up,down,left,right,front,back;
    friend class MagicCube;//为了能够在MagicCube类里面访问Cube类的私有成员，将MagicCube声明为友元类。
    friend ostream &operator<<(ostream &,MagicCube &);//为了能够在输出魔方时访问Cube类的状态，将流输出运算符声明为友元函数。

public:
    //初始化时使得所有的方块都朝向同一方向
    Cube():up(Yellow),down(White),left(Green),right(Blue),front(Orange),back(Red) {}
};

//Cube旋转操作，正向操作时是偶数，反向操作时是奇数，则op%2表示是否是反向
void Cube::rotate(Operation op)
{
    switch(op)
    {
    case R:
    case R_:
        change(up,back,down,front,op%2);
        break;
    case L:
    case L_:
        change(up,front,down,back,op%2);
        break;
    case U:
    case U_:
        change(front,left,back,right,op%2);
        break;
    case D:
    case D_:
        change(front,right,back,left,op%2);
        break;
    case F:
    case F_:
        change(up,right,down,left,op%2);
        break;
    case B:
    case B_:
        change(up,left,down,right,op%2);
        break;
    }
}

//魔方类
class MagicCube
{
    friend ostream &operator<<(ostream &,MagicCube &);
    /*想法是列出一个方块的指针数组，每个指针都指向一个方块对象。
    指针在数组中的位置唯一地映射到魔方上的一个位置，因此Cube类无需记载位置。
    而使用指针数组使得交换方块时只需交换指针，速度快。
    魔方使用通常的右手系，上黄下白前橙后红左绿右蓝，从零开始标记。如DLB块就是(0,0,0)。
    9*x+3*y+z就等于方块在数组中的序号。*/

    //Cube指针数组
    Cube *cube_pointers[27];

    //将坐标直接转换为Cube指针
    Cube *to_pointer(int x,int y,int z)
    {
        return cube_pointers[9*x+3*y+z];
    }

    //将坐标转换为数组序号
    int to_ord(int x,int y,int z)
    {
        return 9*x+3*y+z;
    }

public:
    //构造函数，为数组中的每一个指针分配一个对象。
    MagicCube()
    {
        for(Cube* &p:cube_pointers) p=new Cube;
    }

    /*用于检查魔方是否还原。遵循一般的魔方检查规则，(1,1,1)中心块不可见，
    而中心块则只检查露出来的一块，角块和棱块只需要检查不相对的两面就可以保证六面正确。*/
    bool check()
    {
        for(int i=1; i<27; i++)
        {
            if(i==13)
                continue;
            else if(i==to_ord(0,1,1) &&cube_pointers[i]->back != cube_pointers[0]->back)
                return false;
            else if(i==to_ord(2,1,1)&&cube_pointers[i]->front != cube_pointers[0]->front)
                return false;
            else if(i==to_ord(1,0,1)&&cube_pointers[i]->left != cube_pointers[0]->left)
                return false;
            else if(i==to_ord(1,2,1)&&cube_pointers[i]->right != cube_pointers[0]->right)
                return false;
            else if(i==to_ord(1,1,2)&&cube_pointers[i]->up != cube_pointers[0]->up)
                return false;
            else if(i==to_ord(1,1,0)&&cube_pointers[i]->down != cube_pointers[0]->down)
                return false;
            else if(cube_pointers[i]->up != cube_pointers[0]->up || cube_pointers[i]->front != cube_pointers[0]->front)
                return false;
        }
        return true;
    }
    void operate(Operation op);
    //以公式进行操作的重载operate函数
    void operate(const Formula& formula)
    {
        for(Operation op:formula)
            operate(op);
    }
    //析构函数，删除动态分配的Cube对象
    ~MagicCube()
    {
        for(Cube* &ptr:cube_pointers)
            delete ptr;
    }
};

string color_to_string(Color c)
{
    switch(c)
    {
    case Red:
        return "红";
        break;
    case Orange:
        return "橙";
        break;
    case Blue:
        return "蓝";
        break;
    case Green:
        return "绿";
        break;
    case White:
        return "白";
        break;
    case Yellow:
        return "黄";
        break;
    }
}

ostream &operator<<(ostream &o,MagicCube &mc)
{
    /*格式：
                 红  红  红

                 红  红  红

                 红  红  红


    绿  绿  绿   黄  黄  黄    蓝  蓝  蓝   白  白  白

    绿  绿  绿   黄  黄  黄    蓝  蓝  蓝   白  白  白

    绿  绿  绿   黄  黄  黄    蓝  蓝  蓝   白  白  白


                 橙  橙  橙

                 橙  橙  橙

                 橙  橙  橙                           */

    o<<endl;
    //输出背面
    for(int i=0; i<3; i++)
    {
        o<<setw(13)<<'\0';
        for(int j=0; j<3; j++)
            o<<color_to_string(mc.to_pointer(0,j,i)->back)<<setw(2)<<'\0';
        o<<endl<<endl;
    }
    o<<endl;
    //输出左，上，右，下面
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)

            o<<color_to_string(mc.to_pointer(i,0,j)->left)<<setw(2)<<'\0';
        o<<' ';
        for(int j=0; j<3; j++)
            o<<color_to_string(mc.to_pointer(i,j,2)->up)<<setw(2)<<'\0';
        o<<' ';
        for(int j=0; j<3; j++)
            o<<color_to_string(mc.to_pointer(i,2,2-j)->right)<<setw(2)<<'\0';
        o<<' ';
        for(int j=0; j<3; j++)
            o<<color_to_string(mc.to_pointer(i,2-j,0)->down)<<setw(2)<<'\0';
        o<<endl<<endl;

    }
    o<<endl;
    //输出前面
    for(int i=0; i<3; i++)
    {
        o<<setw(13)<<'\0';
        for(int j=0; j<3; j++)
            o<<color_to_string(mc.to_pointer(2,j,2-i)->front)<<setw(2)<<'\0';
        o<<endl<<endl;
    }
    return o;
}

//魔方最为关键的函数，接收一个动作指令，改变魔方状态。
void MagicCube::operate(Operation op)
{
    //a,b,c,d是角块指针,e,f,g,h是棱块指针。
    Cube *a,*b,*c,*d,*e,*f,*g,*h;
    switch(op)
    {
    case R:
    case R_:
        a=to_pointer(0,2,2);
        b=to_pointer(0,2,0);
        c=to_pointer(2,2,0);
        d=to_pointer(2,2,2);
        e=to_pointer(1,2,2);
        f=to_pointer(0,2,1);
        g=to_pointer(1,2,0);
        h=to_pointer(2,2,1);
        break;

    case L:
    case L_:
        a=to_pointer(0,0,2);
        b=to_pointer(2,0,2);
        c=to_pointer(2,0,0);
        d=to_pointer(0,0,0);
        e=to_pointer(1,0,2);
        f=to_pointer(2,0,1);
        g=to_pointer(1,0,0);
        h=to_pointer(0,0,1);
        break;

    case F:
    case F_:
        a=to_pointer(2,0,2);
        b=to_pointer(2,2,2);
        c=to_pointer(2,2,0);
        d=to_pointer(2,0,0);
        e=to_pointer(2,1,2);
        f=to_pointer(2,2,1);
        g=to_pointer(2,1,0);
        h=to_pointer(2,0,1);
        break;

    case U:
    case U_:
        a=to_pointer(0,0,2);
        b=to_pointer(0,2,2);
        c=to_pointer(2,2,2);
        d=to_pointer(2,0,2);
        e=to_pointer(0,1,2);
        f=to_pointer(1,2,2);
        g=to_pointer(2,1,2);
        h=to_pointer(1,0,2);
        break;

    case D:
    case D_:
        a=to_pointer(0,0,0);
        b=to_pointer(2,0,0);
        c=to_pointer(2,2,0);
        d=to_pointer(0,2,0);
        e=to_pointer(1,0,0);
        f=to_pointer(2,1,0);
        g=to_pointer(1,2,0);
        h=to_pointer(0,1,0);
        break;

    case B:
    case B_:
        a=to_pointer(0,0,0);
        b=to_pointer(0,2,0);
        c=to_pointer(0,2,2);
        d=to_pointer(0,0,2);
        e=to_pointer(0,1,2);
        f=to_pointer(0,0,1);
        g=to_pointer(0,1,0);
        h=to_pointer(0,2,1);
        break;
    }
    //用类似与Cube旋转的方法判断是否为逆向操作。
    change(*a,*b,*c,*d,int(op)%2);//交换角块
    change(*e,*f,*g,*h,int(op)%2);//交换棱块
    //角块和棱块都自身旋转
    a->rotate(op),b->rotate(op),c->rotate(op),d->rotate(op);
    e->rotate(op),f->rotate(op),g->rotate(op),h->rotate(op);
}
#endif // MAGIC_CUBE_H
