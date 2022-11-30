// 1-1-base.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include <iomanip>
using std::setw;

#include <cstring>

void getSeconds(unsigned long* par);
double getAverage(int* arr, int size);

void swap(int& a, int& b);

double vals[] = { 10.1, 12.6, 33.1, 24.1, 50.0 };

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};



int main_guess_number()
{
    int guess = 0;

    // set seed
    srand((unsigned)time(NULL));
    int answer = rand() % 100;
    
    while (true)
    {
        cout << "please guess a number: ";
        cin >> guess;
        if (guess == answer) {
            break;
        }
        else {
            if (guess > answer) 
            {
                cout << "Sorry, too large\n";
            }
            else {
                cout << "Sorry, too small\n";
            }
        }
    }

    cout << "Congratulations";
    return 0;
}



int main_struct_Books()
{
    Books Book1;        // 定义结构体类型 Books 的变量 Book1
    Books Book2;        // 定义结构体类型 Books 的变量 Book2

    // Book1 详述
    strcpy_s(Book1.title, "C++ 教程");
    strcpy_s(Book1.author, "Runoob");
    strcpy_s(Book1.subject, "编程语言");
    Book1.book_id = 12345;

    // Book2 详述
    strcpy_s(Book2.title, "CSS 教程");
    strcpy_s(Book2.author, "Runoob");
    strcpy_s(Book2.subject, "前端技术");
    Book2.book_id = 12346;

    // 输出 Book1 信息
    cout << "第一本书标题 : " << Book1.title << endl;
    cout << "第一本书作者 : " << Book1.author << endl;
    cout << "第一本书类目 : " << Book1.subject << endl;
    cout << "第一本书 ID : " << Book1.book_id << endl;

    // 输出 Book2 信息
    cout << "第二本书标题 : " << Book2.title << endl;
    cout << "第二本书作者 : " << Book2.author << endl;
    cout << "第二本书类目 : " << Book2.subject << endl;
    cout << "第二本书 ID : " << Book2.book_id << endl;

    return 0;
}

// cout cerr clog
int main_cout_cin()
{
    char name[50];
    cout << "please enter your name:";
    cin >> name;
    cout << "your name is: " << name << endl;
    char str[] = "unable to read...";
    cerr << "Error message: " << str << endl;
    clog << "Error message: " << str << endl;
    return 0;
}
//time
int main_time()
{
    struct tm tmnow;
    char dt[100];

    // 基于当前系统的当前日期/时间
    time_t now = time(0);

    // 把 now 转换为字符串形式
    ctime_s(dt, 100, &now);

    cout << "本地日期和时间：" << dt << endl;

    // 把 now 转换为 tm 结构
    gmtime_s(&tmnow, &now);
    asctime_s(dt, &tmnow);
    cout << "UTC 日期和时间：" << dt << endl;
    return 0;
}

double& setValues(int i)
{
    double& ref = vals[i];
    return ref;//返回第i个元素的引用，ref是一个引用变量，ref引用vals[i]
}

// 引用2
int main_quote_2()
{
    cout << "改变前的值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }

    setValues(1) = 20.23;
    setValues(3) = 70.8;

    cout << "改变后的值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    return 0;
}
// 引用
int main_quote()
{
    // local var
    int a = 100;
    int b = 200;

    cout << "交换前, a的值: " << a << endl;
    cout << "交换前, b的值: " << b << endl;

    swap(a, b);

    cout << "交换后, a的值: " << a << endl;
    cout << "交换后, b的值: " << b << endl;
    return 0;
}
// 引用 交换
void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

    return;
}

// 指针做函数参数
int main_func_pointer()
{
    unsigned long sec;
    getSeconds(&sec);
    cout << "Number of seconds :" << sec << endl;

    int a = 10;
    int* ptr;
    ptr = &a;
    double ave = getAverage(ptr, 1);

    cout << ave << endl;

    return 0;
}

double getAverage(int* arr, int size)
{
    double average = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    average = sum / size;
    return average;
}

void getSeconds(unsigned long *ptr)
{
    *ptr = time(NULL);
    return;
}   
// 指向指针的指针
int main_pointer_pointer()
{
    int var = 3000;
    int *ptr;
    int **pptr;
    // 获取 var 的地址
    ptr = &var;

    // 使用运算符 & 获取 ptr 的地址
    pptr = &ptr;

    // 使用 pptr 获取值
    cout << "var 值为 :" << var << endl;
    cout << "*ptr 值为:" << *ptr << endl;
    cout << "**pptr 值为:" << **pptr << endl;

    return 0;



}

// 指针数组
int main_pointer_3()
{
    const int MAX = 3;
    int var[MAX] = { 10, 100, 200 };
    int* ptr[MAX]{};
    for (int i = 0; i < MAX; i++)
    {
        ptr[i] = &var[i]; // 赋值为整数的地址
    }
    for (int i = 0; i < MAX; i++)
    {
        cout << "Value of var[" << i << "] = ";
        cout << *ptr[i] << endl;
    }
    return 0;
}

// 数组var[]在不用方括号时其实表达了数组第一位的存储位置，也是一个指针
// 指针递减 遍历数组
int main_pointer_2()
{
    const int MAX = 3;
    int  varnum[MAX] = { 10, 100, 200 };
    int* ptr;

    // 指针中的数组地址
    ptr = varnum;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;

        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;

        // 移动到下一个位置
        ptr++;
    }

    return 0;
}

// 指针
int main_pointer()
{
    int a = 10;

    int *b = NULL;
    b = &a;
    cout << *b << endl;
    a = 20;
    cout << a << endl;
    cout << *b << endl;
    int  var = 20;   // 实际变量的声明
    int* ip;        // 指针变量的声明

    ip = &var;       // 在指针变量中存储 var 的地址

    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;

    return 0;
}

// string
int main_string()
{
    string str1 = "runoob";
    string str2 = "google";
    string str3;
    int  len;

    // 复制 str1 到 str3
    str3 = str1;
    cout << "strcpy( str3, str1) : " << str3 << endl;

    // 连接 str1 和 str2
    str1 += str2;
    cout << "strcat( str1, str2): " << str1 << endl;

    // 连接后，str1 的总长度
    len = str1.size();
    cout << "strlen(str1) : " << len << endl;

    return 0;
}

// 数组与格式化输出
int main_number_group()
{
    int n[10]; // n 是一个包含 10 个整数的数组

    // 初始化数组元素          
    for (int i = 0; i < 10; i++)
    {
        n[i] = i + 100; // 设置元素 i 为 i + 100
    }
    cout << "Element" << setw(13) << "Value" << endl;

    // 输出数组中每个元素的值                     
    for (int j = 0; j < 10; j++)
    {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    // 一个带有 5 行 2 列的数组
    int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8} };

    // 输出数组中每个元素的值                      
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 2; j++)
        {
            cout << "a[" << i << "][" << j << "]: ";
            cout << a[i][j] << endl;
        }

    return 0;
}

// generate random  number
int main_random_number()
{
    int i, j;

    // set seed
    srand((unsigned)time(NULL));
    
    // generate 10 random number
    for (i = 0; i < 10; i++)
    {
        j = rand();
        cout << "random number is " << j << endl;
    }
    return 0;
}

// 左移右移运算符
int main_left_move_right_move()
{
    int c= 10;
    c <<= 2;
    cout << c;
    c >>= 2;
    cout << '\n';
    cout << c;
    c >>= 2;
    cout << '\n';
    cout << c;
    return 0;
}

// 修饰符
int main_modify()
{
    // 修饰符
    // signed unsigned short long
    
    
    short int i;
    short unsigned int j;
    j = 50000;
    i = 50000;
    short x = i + j;
    cout << i << " " << j;
    cout << "\n" << x;
    
    //const volatile restrict
    const int WIDTH = 1080;
    return 0;
}

// 打印各种类型的大小
int main_size_of_data_type()
{
    cout << "type: \t\t" << "************size**************" << endl;
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
    cout << "\t最大值：" << (numeric_limits<bool>::max)();
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);
    cout << "\t最大值：" << (numeric_limits<char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);
    cout << "\t最大值：" << (numeric_limits<short>::max)();
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);
    cout << "\t最大值：" << (numeric_limits<int>::max)();
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);
    cout << "\t最大值：" << (numeric_limits<long>::max)();
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "所占字节数：" << sizeof(double);
    cout << "\t最大值：" << (numeric_limits<double>::max)();
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);
    cout << "\t最大值：" << (numeric_limits<long double>::max)();
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);
    cout << "\t最大值：" << (numeric_limits<float>::max)();
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "************size**************" << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
