#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include<iomanip>
#include <chrono>
using namespace std;
using namespace chrono;
#define R 4 // 设晶胞长度为4,可分为4部分,从晶体结构可知每一部分各有特点,故可用取模来分别处理每一部分

// 递归方法

vector<int> cul_n(int n) // 平方预制表制作函数
{
    vector<int> temp(n + 2);
    generate(temp.begin(), temp.end(), [init = -1]() mutable
             { return ++init * init; });
    return temp;
}
vector<int> n_num;      // 平方预制表
vector<double> a_array; // 结果存放表
static long cnt = 0;    // 循环计数

inline int convertflag_k(long x) // 电荷翻转
{
    return (x % 2 == 1) ? 1 : -3;
}

double iter_1(int num, int boudary) // 第一类晶体递归函数
{
    int m, l = num, i, j, k, flag, n1, n2, n3;
    const int b_const = boudary;
    long long x;
    double r, a = 0;

    if (l != 2) // 递归条件
    {
        if (l % 4 == 0)
        {
            flag = 1;
            x = 0;
        }
        else
        {
            flag = -3;
            x = 1;
        }

        for (i = -l; i <= l; i += 2)
        {
            n1 = i;
            for (j = -l; j <= l; j += 2)
            {
                n2 = j;
                for (k = -l; k <= l; k += 2)
                {
                    if (!(abs(i) == abs(l) || abs(j) == abs(l) || abs(k) == abs(l)))
                    {
                        flag = convertflag_k(x++);
                        continue;
                    }
                    n3 = k;
                    double r = sqrt(n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)]);
                    int edge_count = (abs(i) == boudary) + (abs(j) == boudary) + (abs(k) == boudary);
                    double ratio = 1.0 / (1 << edge_count);
                    a += -flag * ratio * R / r;
                    flag = convertflag_k(x++);
                }
            }
        }
        // 处理K2面，无需边界判断
        for (i = -l + 1; i <= l - 1; i += 2)
        {
            for (j = -l + 1; j <= l - 1; j += 2)
            {
                for (k = -l + 1; k <= l - 1; k += 2)
                {
                    if (!(abs(i) == abs(-l + 1) || abs(j) == abs(-l + 1) || abs(k) == abs(-l + 1)))
                    {
                        continue;
                    }
                    double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                    double r = sqrt(sum_sq);
                    a += -1.0 * R / r; // ratio = 1.0
                }
            }
        }
        a += iter_1(num - 2, b_const);
        return a;
    }

    if (l == 2) // 递归终点
    {
        flag = -3;
        x = 1;

        for (i = -l; i <= l; i += 2)
        {
            n1 = i;
            for (j = -l; j <= l; j += 2)
            {
                n2 = j;
                for (k = -l; k <= l; k += 2)
                {
                    n3 = k;
                    double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                    if (sum_sq == 0)
                    {
                        flag = convertflag_k(x++);
                        continue;
                    }
                    double r = sqrt(sum_sq);
                    int edge_count = (abs(i) == boudary) + (abs(j) == boudary) + (abs(k) == boudary);
                    double ratio = 1.0 / (1 << edge_count);
                    a += -flag * ratio * R / r;
                    flag = convertflag_k(x++);
                }
            }
        }

        // 处理K2面，无需边界判断
        for (i = -l + 1; i <= l - 1; i += 2)
        {
            for (j = -l + 1; j <= l - 1; j += 2)
            {
                for (k = -l + 1; k <= l - 1; k += 2)
                {
                    double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                    double r = sqrt(sum_sq);
                    a += -1.0 * R / r; // ratio = 1.0
                }
            }
        }
        return a;
    }
}

double iter_2(int num, int boudary) // 第二类晶体递归函数
{
    int m, l = num, i, j, k, flag, n1, n2, n3;
    long long x;
    const int b_const = boudary;
    double r, a = 0;

    if (l != 3)
    {
        for (i = -l; i <= l; i += 2)
        {
            n1 = i;
            for (j = -l; j <= l; j += 2)
            {
                n2 = j;
                for (k = -l; k <= l; k += 2)
                {
                    if (!(abs(i) == abs(l) || abs(j) == abs(l) || abs(k) == abs(l)))
                        continue;
                    n3 = k;
                    double r = sqrt(n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)]);
                    int edge_count = (abs(i) == boudary) + (abs(j) == boudary) + (abs(k) == boudary);
                    double ratio = 1.0 / (1 << edge_count);
                    a += -1.0 * ratio * R / r;
                }
            }
        }

        if ((l - 1) % 4 == 0)
        {
            flag = 1;
            x = 0;
        }
        else
        {
            flag = -3;
            x = 1;
        }

        for (i = -l + 1; i <= l - 1; i += 2)
        {
            for (j = -l + 1; j <= l - 1; j += 2)
            {
                for (k = -l + 1; k <= l - 1; k += 2)
                {
                    if (!(abs(i) == abs(-l + 1) || abs(j) == abs(-l + 1) || abs(k) == abs(-l + 1)))
                    {
                        flag = convertflag_k(x++);
                        continue;
                    }
                    double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                    double r = sqrt(sum_sq);
                    a += -flag * R / r; // ratio = 1.0
                    flag = convertflag_k(x++);
                }
            }
        }
        a += iter_2(num - 2, b_const);
        return a;
    }

    if (l == 3)
    {
        // 处理K2面，无需边界判断
        for (i = -l; i <= l; i += 2)
        {
            n1 = i;
            for (j = -l; j <= l; j += 2)
            {
                n2 = j;
                for (k = -l; k <= l; k += 2)
                {
                    n3 = k;
                    double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                    int edge_count = (abs(i) == boudary) + (abs(j) == boudary) + (abs(k) == boudary);
                    double ratio = 1.0 / (1 << edge_count);
                    double r = sqrt(sum_sq);
                    a += -1.0 * ratio * R / r;
                }
            }
        }

        flag = -3;
        x = 1;
        for (i = -l + 1; i <= l - 1; i += 2)
        {
            for (j = -l + 1; j <= l - 1; j += 2)
            {
                for (k = -l + 1; k <= l - 1; k += 2)
                {
                    double sum_sq = n_num[abs(i)] + n_num[abs(j)] + n_num[abs(k)];
                    if (sum_sq == 0)
                    {
                        flag = convertflag_k(x++);
                        continue;
                    }
                    double r = sqrt(sum_sq);
                    a += -flag * R / r;
                    flag = convertflag_k(x++);
                }
            }
        }
        return a;
    }
}

int main()
{
    auto start = high_resolution_clock::now();
    int n;
    vector<double> average;
    cin >> n;
    n_num = cul_n(n);
    for (int i = 2; i <= n; i = i + 2)
    {
        a_array.push_back(iter_1(i, i));
        a_array.push_back(iter_2(i + 1, i + 1)); // 循环存储结果
        cnt = cnt + 2;
        if (cnt % 4 == 0) // 每四次计算循环
        {
            double sum = accumulate(a_array.end() - 8, a_array.end(), 0.0);
            double aver = sum / 8;
            average.push_back(aver);
            cout << "K1 result's average = " <<setprecision(10)<< aver << endl;
        }
    }
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end - start);
    cout << "time=" << duration1.count() << " ms" << endl;
    system("pause");
    return 0;
}
