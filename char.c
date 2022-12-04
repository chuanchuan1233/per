
#define CHRDEVBASE_MAJOR 	200
#define CHRDEVBASE_NAME  "chrdevbase"
static char readbuf[100];
static char writebuf[100];
static char kerneldata[] = {"kernel data!"};

static int chrdevbase_open(struct inode *inode, struct file *filp)
{
    return 0;

};

static ssize_t chrdevbase_read(struct file *filp,char _user *buf,size_t cnt,loff_t *offt)
{
    int retvalue=0;
    memcpy(readbuf,kerneldata,sizeof(kerneldata));
        //#memcpy 函数用于 把资源内存（src所指向的内存区域） 拷贝到目标内存（dest所指向的内存区域）；
        //函数原型：void memcpy(void dest, void src, unsigned int count);
        //用法：（1）可以拷贝任何类型的对象，因为函数的参数类型是void（未定义类型指针），也就是说传进去的实参可以是int，short，char等等，
    retvalue=copy_to_user(buf,readbuf,cnt);
    if(retvalue==0)
        {printk("kernel senddata ok!\r\n");}
    else{
        printk("kernel senddata fail!\r\n");
    }
    /*内核空间与用户空间数据传递的通道是copy_to_user和copy_from_user
      static inline long copy_to_user(void __user *to, const void *from, unsigned long n)
       参数 to 表示目的，参数 from 表示源，参数 n 表示要复制的数据长度。如果复制成功，返
回值为 0，如果复制失败则返回负数。*/
    return 0;

};

