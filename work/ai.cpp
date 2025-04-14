#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

const int R = 4;

inline int convertflag_k(long x)
{
    return (x % 2 == 1) ? 1 : -3;
}

void result_k1(int n)
{
    int l, i, j, k, flag, n1, n2, n3;
    long x;
    double a = 0.0, aver;// 将a归0求晶体结构递增后的马德隆常数
    vector<double> a_array;
    vector<double> average;
    long cnt = 0;

    for (l = 2; l <= n / 2; l++)
    {
        int m = 2 * l;
        cnt++;
        a = 0.0; // 重置a为当前层的累加

        if (l % 2 == 0) // 判断最外层是c60-k1面(=0)还是k2面(!=0)
        {
            // 处理C60-K1面
            if (l % 4 == 0) // 判断最外层顶点是否同号(=0同!=0不同)
            {
                flag = 1;   // 电荷因子异同标记
                x = 0;  // x为转化信号量,用以根据条件快速变化flag
            }
            else
            {
                flag = -3;
                x = 1;
            }

            for (i = -l; i <= l; i += 2)// 从最左向最有右遍历
            {
                n1 = i;
                int abs_n1 = abs(n1);
                for (j = -l; j <= l; j += 2)// 从最外向最里遍历
                {
                    n2 = j;
                    int abs_n2 = abs(j);
                    for (k = -l; k <= l; k += 2)// 从最下向最上遍历
                    {
                        n3 = k;
                        int abs_n3 = abs(k);
                        double sum_sq = n1 * n1 + n2 * n2 + n3 * n3;
                        if (sum_sq == 0)
                        {
                            flag = convertflag_k(x++);
                            continue;
                        }
                        double r = sqrt(sum_sq);
                        int edge_count = (abs_n1 == l) + (abs_n2 == l) + (abs_n3 == l);
                        double ratio = 1.0 / (1 << edge_count); //判断边缘离子
                        a += -flag * ratio * R / r; // 依次计算c60与k1的作用势能
                        flag = convertflag_k(x++);// 由晶体结构可知相邻点的电荷相反,故循环每进一步,flag进行变化
                    }
                }
            }
            // 处理K2面，无需边界判断
            for (i = -l + 1; i <= l - 1; i += 2)// 因为起始位c60与k1面,故下一部分为k2面
            {
                for (j = -l + 1; j <= l - 1; j += 2)
                {
                    for (k = -l + 1; k <= l - 1; k += 2)
                    {
                        double sum_sq = i * i + j * j + k * k;
                        double r = sqrt(sum_sq);
                        a += -1.0 * R / r; // ratio = 1.0,k2面肯定不是边缘,故无需权重
                    }
                }
            }
        }

        else// 起始面为k2
        {
            // 处理K2面（作为起始面）
            for (i = -l; i <= l; i += 2)
            {
                n1 = i;
                int abs_n1 = abs(n1);
                for (j = -l; j <= l; j += 2)
                {
                    n2 = j;
                    int abs_n2 = abs(j);
                    for (k = -l; k <= l; k += 2)
                    {
                        n3 = k;
                        int abs_n3 = abs(k);
                        double sum_sq = n1 * n1 + n2 * n2 + n3 * n3;
                        double r = sqrt(sum_sq);
                        int edge_count = (abs_n1 == l) + (abs_n2 == l) + (abs_n3 == l);
                        double ratio = 1.0 / (1 << edge_count);
                        a += -1.0 * ratio * R / r;
                    }
                }
            }

            // 处理K1和C60面
            if ((l - 1) % 4 == 0)// 判断次外层顶点同号
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
                        double sum_sq = i * i + j * j + k * k;
                        if (sum_sq == 0)
                        {
                            flag = convertflag_k(x++);
                            continue;
                        }
                        double r = sqrt(sum_sq);
                        a += -flag * R / r; // ratio = 1.0
                        flag = convertflag_k(x++);
                    }
                }
            }
        }

        a_array.push_back(a);// 存放每一次循环结果
        cout << "m=" << m << "\ta=" << a << endl;// 输出m,a

        if (cnt % 8 == 0)// 每八次求一次均值
        {
            double sum = accumulate(a_array.end() - 8, a_array.end(), 0.0);
            aver = sum / 8.0;
            average.push_back(aver);//将每个均值记录
            cout << "K1 result's average = " << setprecision(10) << aver << endl;
        }
    }

    cout<<endl;
    if (!a_array.empty())   //将最后十个均值求平均
    {
        double sum = accumulate(average.end() - 10, average.end(), 0.0);
        aver = sum / 10;
        cout << "K1 final result = " << aver << endl;
    }
    cout<<endl;
}

int main()
{
    auto start = high_resolution_clock::now();
    result_k1(200);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end - start);
    cout << "time=" << duration1.count() << " ms" << endl;
    system("pause");
    return 0;
}