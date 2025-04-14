#include <iostream>
#include <math.h>
#include <vector>
#include <numeric>
using namespace std;
#define R 4 // 设晶胞长度为4,可分为4部分,从晶体结构可知每一部分各有特点,故可用取模来分别处理每一部分


int convertflag_k(long x) // 用以转化flag
{
    int flag_k;
    if (x % 2 == 1)
        flag_k = 1;
    else
        flag_k = -3;
    return flag_k;
}


void result_k1(int n)
    {
        int m, l, i, j, k, flag, n1, n2, n3;
        long x;
        double r, a = 0, ratio = 1, aver;
        vector<double> a_array;
        long cnt = 0;
    
        

        for (l = 2; l <= n / 2; l++)
        {
            m = 2 * l;
            cnt++;
            if (l % 2 == 0) // 判断最外层是c60-k1面(=0)还是k2面(!=0)
            {
                // 计算c60与k1之间的作用能
                if (l % 4 == 0) // 判断最外层顶点是否同号(=0同!=0不同)
                {
                    flag = 1; // 电荷因子异同标记
                    x = 0;    // x为转化信号量,用以根据条件快速变化flag
                }
                else
                {
                    flag = -3;
                    x = 1;
                }

                for (i = -l; i <= l; i += 2) // 从最左向最有右遍历
                {
                    n1 = i;

                    for (j = -l; j <= l; j += 2) // 从最外向最里遍历
                    {
                        n2 = j;
                        for (k = -l; k <= l; k += 2) // 从最下向最上遍历
                        {
                            n3 = k;
                            if (n1 * n1 + n2 * n2 + n3 * n3 == 0)
                            {
                                flag = convertflag_k(x++);
                                continue;
                            }
                            r = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
                            if (n1 == l || n1 == -l) // 当仅有一个方向在边缘时为中心点,被两个晶胞共享,即在边缘面上
                                ratio /= 2;
                            if (n2 == l || n2 == -l) // 当有两个方向在边缘时为中心点,被四个晶胞共享,即在边缘边上
                                ratio /= 2;
                            if (n3 == l || n3 == -l) // 当有三个方向在边缘时为中心点,被八个晶胞共享,即在边缘顶点
                                ratio /= 2;
                            a += -flag * ratio * R / r; // 依次计算c60与k1的作用势能
                            flag = convertflag_k(x++);  // 由晶体结构可知相邻点的电荷相反,故循环每进一步,flag进行变化
                            ratio = 1;
                        }
                    }
                }
                // 计算与k2的作用能
                for (i = -l + 1; i <= l - 1; i += 2) // 因为起始位c60与k1面,故下一部分为k2面
                {
                    n1 = i;
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        n2 = j;
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            n3 = k;
                            r = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
                            a += -1 * R / r; // k2面肯定不是边缘,故无需权重
                        }
                    }
                }
            }
            else // 起始面为k2
            {
                /* 计算与k2相互作用 */
                for (i = -l; i <= l; i += 2)
                {
                    n1 = i;
                    for (j = -l; j <= l; j += 2)
                    {
                        n2 = j;
                        for (k = -l; k <= l; k += 2)
                        {
                            n3 = k;
                            r = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
                            if (n1 == l || n1 == -l)
                                ratio /= 2;
                            if (n2 == l || n2 == -l)
                                ratio /= 2;
                            if (n3 == l || n3 == -l)
                                ratio /= 2;
                            a += -1 * ratio * R / r; // 同理
                            ratio = 1;
                        }
                    }
                }
                /* 计算与k1,c60面相互作用 */
                if ((l - 1) % 4 == 0) // 判断次外层顶点同号
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
                    n1 = i;
                    for (j = -l + 1; j <= l - 1; j += 2)
                    {
                        n2 = j;
                        for (k = -l + 1; k <= l - 1; k += 2)
                        {
                            n3 = k;
                            if (n1 * n1 + n2 * n2 + n3 * n3 == 0)
                            {
                                flag = convertflag_k(x++);
                                continue;
                            }
                            r = sqrt(n1 * n1 + n2 * n2 + n3 * n3);
                            a += -flag * R / r;
                            flag = convertflag_k(x++);
                            ratio = 1;
                        }
                    }
                }
            }
            a_array.push_back(a);                           // 存放每一次循环结果
            cout << "m=" << m << "\t" << "a=" << a << endl; // 输出m,a
            if (cnt % 4 == 0)                               // 每四次求一次均值
            {
                double sum = accumulate(a_array.begin(), a_array.end(), 0.0);
                aver = sum / cnt;
                cout << "K1 result's average =" << aver << endl;
            }
            a = 0; // 将a归0求晶体结构递增后的马德隆常数
        }
        cout << endl;
        cout << "K1 final result's =" << aver << endl;
        cout << endl;
    }

int main()
{
    result_k1(177);
    system("pause");
    return 0;
}